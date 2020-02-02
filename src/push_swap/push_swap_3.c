/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by gtapioca          #+#    #+#             */
/*   Updated: 2020/02/02 13:56:04 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "../../includes/push_swap.h"
#include "../../includes/libft.h"

void	stack_divide_helper_3(t_list3 **d, t_list4 *point[4],
	int pivvot, t_list1 **a)
{
	int			i;
	t_list3		*buff_stack;

	i = 0;
	while (i < point[1]->number)
	{
		buff_stack = last_stack_finder(d[2]);
		if (*(buff_stack->a) > pivvot)
		{
			d[2] = stack_sort_rr(d[2]);
			make_entry_stack(a, "rrb");
			stack_sort_p(&(d[0]), &(d[2]));
			make_entry_stack(a, "pa");
		}
		else
		{
			d[2] = stack_sort_rr(d[2]);
			make_entry_stack(a, "rrb");
		}
		i++;
	}
}

void	stack_divide_helper_a(t_list3 **stack_int_first_a,
	t_list3 **stack_int_first_b, t_list1 **a)
{
	*stack_int_first_a = stack_sort_rr(*stack_int_first_a);
	make_entry_stack(a, "rra");
	stack_sort_p(stack_int_first_b, stack_int_first_a);
	make_entry_stack(a, "pb");
}

void	prev_point_stack(t_list4 *point[4])
{
	t_list4		*buff_stack[4];

	buff_stack[0] = point[0];
	buff_stack[1] = point[1];
	buff_stack[2] = point[2];
	buff_stack[3] = point[3];
	prev_point_stack_1(buff_stack, point);
}

void	quick_sort(t_list3 **d, t_list4 *point[4], int *size1, t_list1 **a)
{
	int k;

	k = 0;
	while (k < 2 && *size1 == 1 && point[0]->number > 4)
	{
		if (k == 0)
		{
			stack_divide(d, pivvot_finder(&(d[0]), point[0]->number,
				point, 2), point, a);
			quick_sort(d, point, size1, a);
			prev_point_stack(point);
		}
		else
		{
			stack_divide_2(d, pivvot_finder(&(d[2]), point[1]->number,
				point, 3), point, a);
			quick_sort(d, point, size1, a);
			prev_point_stack(point);
		}
		k++;
	}
	if (*size1 == 1 && point[0]->number <= 4)
		*size1 = stack_sort_less_2_2(d, point, a);
}
