/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by gtapioca          #+#    #+#             */
/*   Updated: 2020/02/02 14:16:11 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../includes/libft.h"

t_list2	*stack_sort_rr(t_list2 *first_int_stack)
{
	t_list2	*stack_buff;
	t_list2	*stack_buff2;

	if (!first_int_stack)
		return (0);
	if (first_int_stack->next == 0)
		return (first_int_stack);
	stack_buff = first_int_stack;
	while (stack_buff->next->next != 0)
		stack_buff = stack_buff->next;
	stack_buff->next->next = first_int_stack;
	stack_buff2 = stack_buff->next;
	stack_buff->next = 0;
	return (stack_buff2);
}

t_list2	*stack_sort_r(t_list2 *first_int_stack)
{
	t_list2	*stack_buff;
	t_list2	*stack_buff2;

	if (!first_int_stack)
		return (0);
	if (first_int_stack->next == 0)
		return (first_int_stack);
	stack_buff = first_int_stack;
	stack_buff2 = first_int_stack->next;
	while (stack_buff->next != 0)
		stack_buff = stack_buff->next;
	stack_buff->next = first_int_stack;
	first_int_stack->next = 0;
	return (stack_buff2);
}

void	stack_sort_p(t_list2 **first_int_stack_a, t_list2 **first_int_stack_b)
{
	t_list2 *stack_buff;

	if (!(*first_int_stack_b))
		return ;
	if (*first_int_stack_a == 0)
	{
		*first_int_stack_a = *first_int_stack_b;
		*first_int_stack_b = (*(first_int_stack_b))->next;
		(*first_int_stack_a)->next = 0;
	}
	else
	{
		stack_buff = (*(first_int_stack_b))->next;
		(*(first_int_stack_b))->next = *(first_int_stack_a);
		*first_int_stack_a = *first_int_stack_b;
		*first_int_stack_b = stack_buff;
	}
}

t_list2	*stack_sort_s(t_list2 *first_int_stack)
{
	t_list2 *stack_buff;
	t_list2 *stack_buff2;

	if (first_int_stack->next == 0)
		return (first_int_stack);
	stack_buff = first_int_stack->next->next;
	stack_buff2 = first_int_stack->next;
	stack_buff2->next = first_int_stack;
	first_int_stack->next = stack_buff;
	return (stack_buff2);
}

void	stack_sort_helper_2(t_list2 **first_int_stack_a,
		t_list2 **first_int_stack_b, t_list1 **first_stack)
{
	if (!(ft_strcmp((*(first_stack))->action, "rrr")))
	{
		*first_int_stack_b = stack_sort_rr(*first_int_stack_b);
		*first_int_stack_a = stack_sort_rr(*first_int_stack_a);
	}
	if (!(ft_strcmp((*(first_stack))->action, "ss")))
	{
		*first_int_stack_b = stack_sort_s(*first_int_stack_b);
		*first_int_stack_a = stack_sort_s(*first_int_stack_a);
	}
}
