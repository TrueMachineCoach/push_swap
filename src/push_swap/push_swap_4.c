/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_4.c                                      :+:      :+:    :+:   */
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

void	st_n(t_list4 *stack[4], int a, int index)
{
	t_list4		*buff_stack;

	if (!a && (index < 2))
		return ;
	if (!(stack[index]))
	{
		if (!(stack[index] = (t_list4 *)malloc(sizeof(t_list4))))
			exit(EXIT_FAILURE);
		stack[index]->number = a;
		stack[index]->next = 0;
	}
	else
	{
		if (!(buff_stack = (t_list4 *)malloc(sizeof(t_list4))))
			exit(EXIT_FAILURE);
		buff_stack->number = a;
		buff_stack->next = stack[index];
		stack[index] = buff_stack;
	}
}

void	make_entry_stack(t_list1 **a, char *str)
{
	t_list1 *buff;

	buff = *a;
	if (!(*a))
	{
		*a = (t_list1 *)malloc(sizeof(t_list1));
		(*a)->action = str;
		(*a)->next = 0;
	}
	else
	{
		while (buff->next)
			buff = buff->next;
		buff->next = (t_list1 *)malloc(sizeof(t_list1));
		buff->next->action = str;
		buff->next->next = 0;
	}
}

t_list3	*stack_sort_rr(t_list3 *first_int_stack)
{
	t_list3	*stack_buff;
	t_list3	*stack_buff2;

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

t_list3	*stack_sort_s(t_list3 *first_int_stack)
{
	t_list3 *stack_buff;
	t_list3 *stack_buff2;

	if (first_int_stack->next == 0)
		return (first_int_stack);
	stack_buff = first_int_stack->next->next;
	stack_buff2 = first_int_stack->next;
	stack_buff2->next = first_int_stack;
	first_int_stack->next = stack_buff;
	return (stack_buff2);
}

t_list3	*stack_sort_r(t_list3 *first_int_stack)
{
	t_list3			*stack_buff;
	t_list3			*stack_buff2;

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
