/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_9.c                                      :+:      :+:    :+:   */
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

void	stack_sort_less_2_2_help1_5(t_list3 **stack_int_first_a,
	t_list3 **stack_int_first_b, t_list1 **a)
{
	stack_sort_p(stack_int_first_a, stack_int_first_b);
	make_entry_stack(a, "pa");
	*stack_int_first_b = stack_sort_s(*stack_int_first_b);
	make_entry_stack(a, "sb");
	stack_sort_p(stack_int_first_a, stack_int_first_b);
	make_entry_stack(a, "pa");
	*stack_int_first_a = stack_sort_s(*stack_int_first_a);
	make_entry_stack(a, "sa");
	stack_sort_p(stack_int_first_a, stack_int_first_b);
	make_entry_stack(a, "pa");
	return ;
}

void	stack_sort_less_2_2_help1_4(t_list3 **stack_int_first_a,
	t_list3 **stack_int_first_b, t_list1 **a)
{
	*stack_int_first_b = stack_sort_s(*stack_int_first_b);
	make_entry_stack(a, "sb");
	stack_sort_p(stack_int_first_a, stack_int_first_b);
	make_entry_stack(a, "pa");
	*stack_int_first_b = stack_sort_s(*stack_int_first_b);
	make_entry_stack(a, "sb");
	stack_sort_p(stack_int_first_a, stack_int_first_b);
	make_entry_stack(a, "pa");
	*stack_int_first_a = stack_sort_s(*stack_int_first_a);
	make_entry_stack(a, "sa");
	stack_sort_p(stack_int_first_a, stack_int_first_b);
	make_entry_stack(a, "pa");
	return ;
}

void	stack_sort_less_2_2_help1_3(t_list3 **stack_int_first_a,
	t_list3 **stack_int_first_b, t_list1 **a)
{
	*stack_int_first_b = stack_sort_s(*stack_int_first_b);
	make_entry_stack(a, "sb");
	stack_sort_p(stack_int_first_a, stack_int_first_b);
	make_entry_stack(a, "pa");
	*stack_int_first_b = stack_sort_s(*stack_int_first_b);
	make_entry_stack(a, "sb");
	stack_sort_p(stack_int_first_a, stack_int_first_b);
	make_entry_stack(a, "pa");
	stack_sort_p(stack_int_first_a, stack_int_first_b);
	make_entry_stack(a, "pa");
	return ;
}

void	stack_sort_less_2_2_help1_2(t_list3 **stack_int_first_a,
	t_list3 **stack_int_first_b, t_list1 **a)
{
	stack_sort_p(stack_int_first_a, stack_int_first_b);
	make_entry_stack(a, "pa");
	*stack_int_first_b = stack_sort_s(*stack_int_first_b);
	make_entry_stack(a, "sb");
	stack_sort_p(stack_int_first_a, stack_int_first_b);
	make_entry_stack(a, "pa");
	stack_sort_p(stack_int_first_a, stack_int_first_b);
	make_entry_stack(a, "pa");
	return ;
}

void	stack_sort_less_2_2_help1_1(t_list3 **stack_int_first_a,
	t_list3 **stack_int_first_b, t_list1 **a)
{
	stack_sort_p(stack_int_first_a, stack_int_first_b);
	make_entry_stack(a, "pa");
	stack_sort_p(stack_int_first_a, stack_int_first_b);
	make_entry_stack(a, "pa");
	stack_sort_p(stack_int_first_a, stack_int_first_b);
	make_entry_stack(a, "pa");
	return ;
}
