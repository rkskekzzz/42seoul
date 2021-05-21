#include "minirt.h"

t_world		*init_world()
{
	t_world	*head;

	head = (t_world *)malloc(sizeof(t_world));
	if (!head)
		return (0);
	head->next = 0;
	return (head);
}

int		add_world(t_world *head, t_object obj, int (*hit)(t_world *this, t_ray *ray, double minmax[2], t_hit_record *out), t_material material)
{
	t_world *new;

	new = (t_world *)malloc(sizeof(t_world) * 1);
	if(!new)
		return (ERROR);
	new->obj = obj;
	new->hit = hit;
	new->material = material;
	new->next = head->next;
	head->next = new;
	return (OK);
}

int		hit_world(t_world *head, t_ray *ray, double minmax[2], t_hit_record *out)
{
	t_hit_record	temp_rec;
	t_world			*w;
	int				flag;

	flag = 0;
	w = head;
	while (w->next)
	{
		w = w->next;
		if (w->hit(w, ray, minmax, &temp_rec)) { // min값은 ray의
			minmax[1] = temp_rec.t; // ray가 특정 object에 맞았다면 max value를 바꿔준다.
			*out = temp_rec;		// 이때 위의 함수가 true가 되려면 맞았을때의 t값이 min < t < max 이여야한다.
			flag = 1;
		}
	}
	return (flag);
}

void		set_rec(t_world *this, t_ray *ray, t_hit_record *rec)
{
	rec->rayin = ray->dir;
	rec->front_face = vec_dot_(&ray->dir, &rec->n) < 0;
	if (!rec->front_face) // 만약 위에서 구한 법선벡터와 ray의 방향벡터(어차피 둘다 단위벡터로 만들었음)의 내적값이 양수이면 예각이므로 n의 방향을 반대로 해주어야 한다
		rec->n = vec_oppo(rec->n); //vec_cal((t_vec[1]){rec->n}, (double[1]){ -1}, 1);
	rec->material = &this->material;		// 메터리얼 추가
}
