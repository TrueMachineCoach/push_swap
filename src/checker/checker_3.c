/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by gtapioca          #+#    #+#             */
/*   Updated: 2020/02/02 20:36:37 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../includes/libft.h"

void	stack_sort_helper(t_list2 **first_int_stack_a,
		t_list2 **first_int_stack_b, t_list1 **first_stack)
{
	if (!(ft_strcmp((*(first_stack))->action, "sa")))
		*first_int_stack_a = stack_sort_s(*first_int_stack_a);
	if (!(ft_strcmp((*(first_stack))->action, "sb")))
		*first_int_stack_b = stack_sort_s(*first_int_stack_b);
	if (!(ft_strcmp((*(first_stack))->action, "pa")))
		stack_sort_p(first_int_stack_a, first_int_stack_b);
	if (!(ft_strcmp((*(first_stack))->action, "pb")))
		stack_sort_p(first_int_stack_b, first_int_stack_a);
	if (!(ft_strcmp((*(first_stack))->action, "ra")))
		*first_int_stack_a = stack_sort_r(*first_int_stack_a);
	if (!(ft_strcmp((*(first_stack))->action, "rb")))
		*first_int_stack_b = stack_sort_r(*first_int_stack_b);
	if (!(ft_strcmp((*(first_stack))->action, "rra")))
		*first_int_stack_a = stack_sort_rr(*first_int_stack_a);
	if (!(ft_strcmp((*(first_stack))->action, "rrb")))
		*first_int_stack_b = stack_sort_rr(*first_int_stack_b);
}

void	stack_sort(t_list2 **first_int_stack_a,
		t_list2 **first_int_stack_b, t_list1 *first_stack)
{
	t_list1 *buff_stack;

	buff_stack = first_stack;
	while (buff_stack)
	{
		stack_sort_helper(first_int_stack_a, first_int_stack_b, &buff_stack);
		stack_sort_helper_2(first_int_stack_a,
			first_int_stack_b, &buff_stack);
		buff_stack = buff_stack->next;
	}
}

t_list2	*stacks_int_creator_a(t_list2 *stack_a,
		t_list2 *first_int_stack_a, char **argv, int *y)
{
	y[2] = 0;
	argv++;
	while (*argv)
	{
		if (y[2] == 0)
		{
			first_int_stack_a = (t_list2*)malloc(sizeof(t_list2));
			stack_a = first_int_stack_a;
		}
		else
		{
			stack_a->next = (t_list2*)malloc(sizeof(t_list2));
			stack_a = stack_a->next;
		}
		y[3] = ft_atoi(*argv);
		stack_a->a = (int *)malloc(sizeof(int));
		*(stack_a->a) = y[3];
		y[2]++;
		argv++;
	}
	stack_a->next = 0;
	return (first_int_stack_a);
}

t_list1	*stack_creator(char *str, int i, t_list1 *stack)
{
	int u;

	u = 0;
	if (i == 0)
	{
		stack = (t_list1*)malloc(sizeof(t_list1));
		stack->next = 0;
	}
	else
	{
		stack->next = (t_list1*)malloc(sizeof(t_list1));
		stack = stack->next;
		stack->next = 0;
	}
	stack->action = (char*)malloc(sizeof(char) * 3);
	while (((size_t)u) < ft_strlen(str))
	{
		stack->action[u] = str[u];
		u++;
	}
	stack->action[u] = 0;
	return (stack);
}
