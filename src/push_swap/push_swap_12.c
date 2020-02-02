/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_12.c                                     :+:      :+:    :+:   */
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

int		stack_sort_less_2_2_2(t_list3 **st_a,
	t_list3 **st_b, t_list1 **a)
{
	if (*((*st_a)->a) > *((*st_a)->next->a))
	{
		*st_a = stack_sort_s(*st_a);
		make_entry_stack(a, "sa");
	}
	if (*((*st_b)->a) < *((*st_b)->next->a))
	{
		*st_b = stack_sort_s(*st_b);
		make_entry_stack(a, "sb");
	}
	stack_sort_p(st_a, st_b);
	make_entry_stack(a, "pa");
	stack_sort_p(st_a, st_b);
	make_entry_stack(a, "pa");
	if (*st_b == 0)
		return (0);
	return (1);
}

void	stack_sort_less_2_2_1_2(t_list3 **st_a, t_list3 **st_b,
	t_list4 *point[4], t_list1 **a)
{
	if (point[3] && point[3]->number == 1)
	{
		*st_b = stack_sort_rr(*st_b);
		*st_b = stack_sort_rr(*st_b);
		make_entry_stack(a, "rrb");
		make_entry_stack(a, "rrb");
	}
	if (*((*st_b)->a) < *((*st_b)->next->a))
	{
		*st_b = stack_sort_s(*st_b);
		make_entry_stack(a, "sb");
	}
	stack_sort_p(st_a, st_b);
	make_entry_stack(a, "pa");
	stack_sort_p(st_a, st_b);
	make_entry_stack(a, "pa");
}

void	stack_sort_less_2_2_1(t_list3 **st_a, t_list3 **st_b,
	t_list4 *point[4], t_list1 **a)
{
	if (point[0] && point[0]->number == 2
		&& *((*st_a)->a) > *((*st_a)->next->a))
	{
		if (point[2] && point[2]->number == 1)
		{
			*st_a = stack_sort_rr(*st_a);
			*st_a = stack_sort_rr(*st_a);
			make_entry_stack(a, "rra");
			make_entry_stack(a, "rra");
		}
		*st_a = stack_sort_s(*st_a);
		make_entry_stack(a, "sa");
	}
	if (point[1] && point[1]->number == 2)
		stack_sort_less_2_2_1_2(st_a, st_b, point, a);
}

int		stack_sort_less_2_2(t_list3 **d, t_list4 *point[4], t_list1 **a)
{
	int i;

	i = 2;
	if (point[0] && point[0]->number == 4)
	{
		stack_divide_2_2(d, pivvot_finder(&(d[0]), 4, point, 2), point, a);
		if (!stack_sort_less_2_2_2(&(d[0]), &(d[2]), a))
			return (0);
	}
	if (point[1] && point[1]->number == 4)
	{
		stack_divide_2_2_2(d, pivvot_finder(&(d[2]), 4, point, 3), point, a);
		if (!stack_sort_less_2_2_2(&(d[0]), &(d[2]), a))
			return (0);
	}
	if (point[0] && point[0]->number == 3)
		stack_sort_less_2_2_help(&(d[0]), &(d[2]), a, point);
	if (point[1] && point[1]->number == 3)
		stack_sort_less_2_2_help1(&(d[0]), &(d[2]), a, point);
	stack_sort_less_2_2_1(&(d[0]), &(d[2]), point, a);
	if (d[2] == 0)
		return (0);
	return (1);
}

void	prev_point_stack_1(t_list4 *buff_stack[4], t_list4 *point[4])
{
	if (buff_stack[0] != 0 && buff_stack[0]->next != 0)
	{
		point[0] = point[0]->next;
		free(buff_stack[0]);
	}
	if (buff_stack[1] != 0 && buff_stack[1]->next != 0)
	{
		point[1] = point[1]->next;
		free(buff_stack[1]);
	}
	if (buff_stack[2] != 0)
	{
		point[2] = point[2]->next;
		free(buff_stack[2]);
	}
	if (buff_stack[3] != 0)
	{
		point[3] = point[3]->next;
		free(buff_stack[3]);
	}
}
