#include "philo.h"

int	init_argv(char **argv, t_condition *cond)
{
	cond->num_of_philo = ph_atoi(argv[1]);
	if (cond->num_of_philo < 2)
		return (FALSE);
	cond->time_to_die = ph_atoi(argv[2]);
	cond->time_to_eat = ph_atoi(argv[3]) * 1000;
	cond->time_to_sleep = ph_atoi(argv[4]) * 1000;
	if (argv[5])
		cond->num_of_philo_must_eat = ph_atoi(argv[5]);
	else
		cond->num_of_philo_must_eat = -1;
	return (TRUE);
}

// 인자 처리 (1이냐, 숫자가 아닌게 들어왔나, 인자 개수가 잘못되거나)
t_bool	check_error(int argc, char** argv)
{
	int 	i;

	i = 0;
	if (argc < 5)
		return (FALSE);
	while (argv[++i])
	{
		if (!ph_isnum(argv[i]))
			return (FALSE);
	}
	return (TRUE);
}

void	solution(t_condition *cond)
{
	print_condition(cond);
	philo(cond);
}

void	start_philo(int argc, char **argv)
{
	t_condition	cond;

	if (!check_error(argc, argv) || !init_argv(argv, &cond))
		return ;
	solution(&cond);
}

int	main(int argc, char **argv)
{
	if (argc < 5)
		printf("argument error\n");
	else
		start_philo(argc, argv);
	return (0);
}
