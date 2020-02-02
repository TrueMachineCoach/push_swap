/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_14.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by gtapioca          #+#    #+#             */
/*   Updated: 2020/02/02 18:45:38 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../includes/push_swap.h"
#include "../../includes/libft.h"

int		check_duplication(t_list3 *stack_int_first)
{
	t_list3 *stack_int_control1;
	t_list3 *stack_int_control2;

	stack_int_control1 = stack_int_first;
	stack_int_control2 = stack_int_first;
	while (stack_int_control2)
	{
		stack_int_control1 = stack_int_first;
		while (stack_int_control1)
		{
			if (stack_int_control1 == stack_int_control2)
			{
				if (stack_int_control1->next)
					stack_int_control1 = stack_int_control1->next->next;
				else
					stack_int_control1 = stack_int_control1->next;
			}
			else if (*(stack_int_control1->a) == *(stack_int_control2->a))
				return (0);
			else
				stack_int_control1 = stack_int_control1->next;
		}
		stack_int_control2 = stack_int_control2->next;
	}
	return (1);
}

int		stack_validation_help2(t_list3 *stack_int_first)
{
	if (!(check_duplication(stack_int_first)))
	{
		write(1, "Error\n", 6);
		stack_deleter(stack_int_first);
		return (0);
	}
	return (1);
}

int		stack_numbers_checker(char **argv, char **argv_helper)
{
	char *l;

	argv++ && argv_helper++;
	if (!(*argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	argv = stack_numbers_checker_helper(argv);
	while (*argv_helper)
	{
		if (ft_strcmp(l = ft_itoa(ft_atoi(*argv_helper)), *argv_helper))
		{
			write(1, "Error\n", 6);
			free(l);
			return (0);
		}
		free(l);
		argv_helper++;
	}
	return (1);
}

int		stack_size(t_list3 *stack_a)
{
	int i;

	i = 0;
	while (stack_a != 0)
	{
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

t_list3	*stacks_int_creator_a(t_list3 *stack_a,
		t_list3 *first_int_stack_a, char **argv)
{
	int	y[2];

	y[0] = 0;
	argv++;
	while (*argv)
	{
		if (y[0] == 0)
		{
			first_int_stack_a = (t_list3*)malloc(sizeof(t_list3));
			stack_a = first_int_stack_a;
		}
		else
		{
			stack_a->next = (t_list3*)malloc(sizeof(t_list3));
			stack_a = stack_a->next;
		}
		y[1] = ft_atoi(*argv);
		stack_a->a = (int *)malloc(sizeof(int));
		*(stack_a->a) = y[1];
		y[0]++;
		argv++;
	}
	stack_a->next = 0;
	return (first_int_stack_a);
}
