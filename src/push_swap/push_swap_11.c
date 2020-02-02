/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_11.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by gtapioca          #+#    #+#             */
/*   Updated: 2020/02/02 18:54:52 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../includes/push_swap.h"
#include "../../includes/libft.h"

void	stack_sort_less_2_2_help_3(t_list3 **stack_int_first_a,
	t_list3 **stack_int_first_b, t_list1 **a)
{
	*stack_int_first_a = stack_sort_s(*stack_int_first_a);
	make_entry_stack(a, "sa");
	stack_sort_p(stack_int_first_b, stack_int_first_a);
	make_entry_stack(a, "pb");
	*stack_int_first_a = stack_sort_s(*stack_int_first_a);
	make_entry_stack(a, "sa");
	stack_sort_p(stack_int_first_a, stack_int_first_b);
	make_entry_stack(a, "pa");
	return ;
}

void	stack_sort_less_2_2_help_2(t_list3 **stack_int_first_a,
	t_list3 **stack_int_first_b, t_list1 **a)
{
	*stack_int_first_a = stack_sort_s(*stack_int_first_a);
	make_entry_stack(a, "sa");
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

void	stack_sort_less_2_2_help_1(t_list3 **stack_int_first_a,
	t_list1 **a)
{
	*stack_int_first_a = stack_sort_rr(*stack_int_first_a);
	*stack_int_first_a = stack_sort_rr(*stack_int_first_a);
	*stack_int_first_a = stack_sort_rr(*stack_int_first_a);
	make_entry_stack(a, "rra");
	make_entry_stack(a, "rra");
	make_entry_stack(a, "rra");
}

void	stack_sort_less_2_3_help(t_list3 **st_a, t_list3 **st_b,
	t_list1 **a)
{
	if (*((*st_a)->next->a) > *((*st_a)->next->next->a) &&
		*((*st_a)->next->next->a) > *((*st_a)->a))
	{
		stack_sort_less_2_2_help_4(st_a, st_b, a);
		return ;
	}
	if (*((*st_a)->next->next->a) > *((*st_a)->a) &&
		*((*st_a)->a) > *((*st_a)->next->a))
	{
		*st_a = stack_sort_s(*st_a);
		make_entry_stack(a, "sa");
		return ;
	}
	if (*((*st_a)->next->a) > *((*st_a)->a) &&
		*((*st_a)->a) > *((*st_a)->next->next->a))
	{
		stack_sort_less_2_2_help_6(st_a, st_b, a);
		return ;
	}
}

void	stack_sort_less_2_2_help(t_list3 **st_a,
	t_list3 **st_b, t_list1 **a, t_list4 *point[4])
{
	if (point[2] && point[2]->number == 1)
		stack_sort_less_2_2_help_1(st_a, a);
	if (*((*st_a)->a) > *((*st_a)->next->a) &&
		*((*st_a)->next->a) > *((*st_a)->next->next->a))
	{
		stack_sort_less_2_2_help_2(st_a, st_b, a);
		return ;
	}
	if (*((*st_a)->a) > *((*st_a)->next->next->a) &&
		*((*st_a)->next->next->a) > *((*st_a)->next->a))
	{
		stack_sort_less_2_2_help_3(st_a, st_b, a);
		return ;
	}
	stack_sort_less_2_3_help(st_a, st_b, a);
}
