#include "push_swap.h"


// sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
// sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
// ss : sa and sb at the same time.

// pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
// pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

// ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
// rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
// rr : ra and rb at the same time.

// rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
//  rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
// rrr : rra and rrb at the same time.

int	main(void)
{

	t_ht	ht;

	init_stack(&ht.a_tail, &ht.a_head);
	add_list(ht.a_tail, 1);
	add_list(ht.a_tail, 4);
	add_list(ht.a_head, 3);
	add_list(ht.a_head, 7);
	add_list(ht.a_tail, 0);
	add_list(ht.a_tail, 2);
	print_list(ht.a_tail, ht.a_head);

	print_error("err!");
	return (0);
}
