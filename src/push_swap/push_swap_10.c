/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by gtapioca          #+#    #+#             */
/*   Updated: 2020/02/10 19:52:04 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../includes/push_swap.h"
#include "../../includes/libft.h"

void	stack_sort_less_2_2_help1_7(t_list3 **stack_int_first_b,
		t_list1 **a, t_list4 *point[4])
{
	*stack_int_first_b = stack_sort_rr(*stack_int_first_b);
	*stack_int_first_b = stack_sort_rr(*stack_int_first_b);
	*stack_int_first_b = stack_sort_rr(*stack_int_first_b);
	make_entry_stack(a, "rrb");
	make_entry_stack(a, "rrb");
	make_entry_stack(a, "rrb");
	point[3]->number = 0;
}

void	stack_sort_less_2_2_help2(t_list3 **st_a,
	t_list3 **st_b, t_list1 **a)
{
	if (*((*st_b)->next->next->a) > *((*st_b)->next->a) &&
		*((*st_b)->next->a) > *((*st_b)->a))
	{
		stack_sort_less_2_2_help1_4(st_a, st_b, a);
		return ;
	}
	if (*((*st_b)->next->next->a) > *((*st_b)->a) &&
		*((*st_b)->a) > *((*st_b)->next->a))
	{
		stack_sort_less_2_2_help1_5(st_a, st_b, a);
		return ;
	}
	if (*((*st_b)->next->a) > *((*st_b)->a) &&
		*((*st_b)->a) > *((*st_b)->next->next->a))
	{
		stack_sort_less_2_2_help1_6(st_a, st_b, a);
		return ;
	}
}

void	stack_sort_less_2_2_help1(t_list3 **st_a,
	t_list3 **st_b, t_list1 **a, t_list4 *point[4])
{
	if (point[3] && point[3]->number == 1)
		stack_sort_less_2_2_help1_7(st_b, a, point);
	if (*((*st_b)->a) > *((*st_b)->next->a) &&
		*((*st_b)->next->a) > *((*st_b)->next->next->a))
	{
		stack_sort_less_2_2_help1_1(st_a, st_b, a);
		return ;
	}
	if (*((*st_b)->a) > *((*st_b)->next->next->a) &&
		*((*st_b)->next->next->a) > *((*st_b)->next->a))
	{
		stack_sort_less_2_2_help1_2(st_a, st_b, a);
		return ;
	}
	if (*((*st_b)->next->a) > *((*st_b)->next->next->a) &&
			*((*st_b)->next->next->a) > *((*st_b)->a))
	{
		stack_sort_less_2_2_help1_3(st_a, st_b, a);
		return ;
	}
	stack_sort_less_2_2_help2(st_a, st_b, a);
}

void	stack_sort_less_2_2_help_6(t_list3 **stack_int_first_a,
	t_list3 **stack_int_first_b, t_list1 **a)
{
	stack_sort_p(stack_int_first_b, stack_int_first_a);
	make_entry_stack(a, "pb");
	*stack_int_first_a = stack_sort_s(*stack_int_first_a);
	make_entry_stack(a, "sa");
	stack_sort_p(stack_int_first_a, stack_int_first_b);
	make_entry_stack(a, "pa");
	*stack_int_first_a = stack_sort_s(*stack_int_first_a);
	make_entry_stack(a, "sa");
	return ;
}

void	stack_sort_less_2_2_help_4(t_list3 **stack_int_first_a,
	t_list3 **stack_int_first_b, t_list1 **a)
{
	stack_sort_p(stack_int_first_b, stack_int_first_a);
	make_entry_stack(a, "pb");
	*stack_int_first_a = stack_sort_s(*stack_int_first_a);
	make_entry_stack(a, "sa");
	stack_sort_p(stack_int_first_a, stack_int_first_b);
	make_entry_stack(a, "pa");
	return ;
}
