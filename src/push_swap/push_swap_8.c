/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_8.c                                      :+:      :+:    :+:   */
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

void	stack_divide_2_2_1(t_list3 **stack_int_first_a,
	t_list3 **stack_int_first_b, int *c, t_list1 **a)
{
	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
	while (c[0] < c[3])
	{
		if (*((*stack_int_first_b)->a) <= c[4])
		{
			stack_sort_p(stack_int_first_a, stack_int_first_b);
			make_entry_stack(a, "pb");
			c[2]++;
		}
		else
		{
			*stack_int_first_b = stack_sort_r(*stack_int_first_b);
			make_entry_stack(a, "ra");
			c[1]++;
		}
		c[0]++;
	}
}

void	stack_divide_2_2(t_list3 **d, int pivvot,
	t_list4 *point[4], t_list1 **a)
{
	int c[5];

	c[3] = point[0]->number;
	c[4] = pivvot;
	if (point[2] && point[2]->number == 1
		&& point[0]->number != stack_size(d[2]))
	{
		stack_divide_helper_2(d, point, pivvot, a);
		return ;
	}
	stack_divide_2_2_1(&(d[2]), &(d[0]), c, a);
	if (c[1] != stack_size(d[0]))
	{
		while (c[1] > 0)
		{
			d[0] = stack_sort_rr(d[0]);
			make_entry_stack(a, "rra");
			c[1]--;
		}
	}
}

void	stack_divide_1(t_list3 **stack_int_first_a,
	t_list3 **stack_int_first_b, int *c, t_list1 **a)
{
	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
	while (c[0] < c[3])
	{
		if (*((*stack_int_first_b)->a) <= c[4])
		{
			stack_sort_p(stack_int_first_a, stack_int_first_b);
			make_entry_stack(a, "pb");
			c[2]++;
		}
		else
		{
			*stack_int_first_b = stack_sort_r(*stack_int_first_b);
			make_entry_stack(a, "ra");
			c[1]++;
		}
		c[0]++;
	}
}

void	stack_divide(t_list3 **d, int pivvot, t_list4 *point[4], t_list1 **a)
{
	int c[5];

	c[3] = point[0]->number;
	c[4] = pivvot;
	if (point[2] && point[2]->number == 1
		&& point[0]->number < stack_size(d[0]))
	{
		stack_divide_helper(d, point, pivvot, a);
		return ;
	}
	stack_divide_1(&(d[2]), &(d[0]), c, a);
	if (c[1] != stack_size(d[0]))
		st_n(point, 1, 2);
	else
		st_n(point, 0, 2);
	st_n(point, c[2], 1);
	st_n(point, c[1], 0);
	st_n(point, 0, 3);
}

void	stack_sort_less_2_2_help1_6(t_list3 **stack_int_first_a,
	t_list3 **stack_int_first_b, t_list1 **a)
{
	*stack_int_first_b = stack_sort_s(*stack_int_first_b);
	make_entry_stack(a, "sb");
	stack_sort_p(stack_int_first_a, stack_int_first_b);
	make_entry_stack(a, "pa");
	stack_sort_p(stack_int_first_a, stack_int_first_b);
	make_entry_stack(a, "pa");
	stack_sort_p(stack_int_first_a, stack_int_first_b);
	make_entry_stack(a, "pa");
	return ;
}
