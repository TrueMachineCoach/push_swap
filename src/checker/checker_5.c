/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by gtapioca          #+#    #+#             */
/*   Updated: 2020/02/02 20:50:14 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../includes/libft.h"

int	check_duplication(t_list2 *stack_int_first)
{
	t_list2 *stack_int_control1;
	t_list2 *stack_int_control2;

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

int	stack_validation_help2(t_list2 *stack_int_first)
{
	if (stack_int_first == 0)
	{
		write(1, "KO\n", 3);
		return (0);
	}
	return (1);
}

int	stack_validator_help(t_list2 *stack_int_first, t_list2 *buft_list1_1)
{
	if (*(stack_int_first->a) < *(buft_list1_1->a))
	{
		write(1, "KO\n", 3);
		return (0);
	}
	return (1);
}

int	stack_validator(t_list2 *stack_int_first, int j)
{
	int			i;
	t_list2		*buft_list1_1;

	i = 0;
	if (!(stack_validation_help2(stack_int_first)))
		return (0);
	while (stack_int_first->next != 0)
	{
		buft_list1_1 = stack_int_first;
		stack_int_first = stack_int_first->next;
		if (!(stack_validator_help(stack_int_first, buft_list1_1)))
			return (0);
		i++;
	}
	i++;
	if (i != j)
	{
		write(1, "KO\n", 6);
		return (0);
	}
	if (i > 1)
		if (!(stack_validator_help(stack_int_first, buft_list1_1)))
			return (0);
	return (1);
}
