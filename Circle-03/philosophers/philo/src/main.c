#include "philo.h"
#include "type.h"
#include "debug.h"

static int	init_argv(char **argv, t_condition *cond)
{
	cond->num_of_philo = ph_atoi(argv[1]);
	cond->time_to_die = ph_atoi(argv[2]);
	cond->time_to_eat = ph_atoi(argv[3]);
	cond->time_to_sleep = ph_atoi(argv[4]);
	if (argv[5])
		cond->num_of_philo_must_eat = ph_atoi(argv[5]);
	else
		cond->num_of_philo_must_eat = -1;
	return (cond->num_of_philo > 0);
}

static int	check_error(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
		return (FALSE);
	while (argv[++i])
		if (ph_isnum(argv[i]))
			return (FALSE);
	return (TRUE);
}

static t_bool	run_command(t_condition *cond)
{
	t_resource		res;
	t_philosopher	*philos;

	if (init(cond, &res, &philos) || \
		run(cond, philos) || \
		monitor(cond, &res, philos) || \
		destroy(&res, philos, cond))
		return (FALSE);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_condition	cond;

	if (check_error(argc, argv) || \
		!init_argv(argv, &cond) || \
		run_command(&cond))
		printf("Error\n");
	return (0);
}
