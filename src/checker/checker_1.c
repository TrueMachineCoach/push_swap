/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by gtapioca          #+#    #+#             */
/*   Updated: 2020/02/02 15:50:23 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../includes/libft.h"

void	stack_deleter_help(t_list2 *t0, t_list2 *t1, t_list1 *r1)
{
	stack_deleter(t0);
	stack_deleter(t1);
	stack_action_deleter(r1);
}

void	stack_action_deleter(t_list1 *stack_first)
{
	t_list1 *buffer;

	if (!stack_first)
		return ;
	while (stack_first)
	{
		buffer = stack_first;
		free(stack_first->action);
		stack_first = stack_first->next;
		free(buffer);
	}
}

void	stack_deleter(t_list2 *stack_int_first)
{
	t_list2 *buffer;

	if (!stack_int_first)
		return ;
	while (stack_int_first)
	{
		buffer = stack_int_first;
		free(stack_int_first->a);
		stack_int_first = stack_int_first->next;
		free(buffer);
	}
}

int		validation_integers(char *str)
{
	int i;

	i = 0;
	while (*str != 0)
	{
		if ((*str > '9' || *str < '0') && (i != 0 && *str != '-'))
			return (0);
		str++;
	}
	return (1);
}

int		validation_rules(char *str)
{
	if ((ft_strlen(str)) > 3)
		return (0);
	if (str[0] != 's' && str[0] != 'p' && str[0] != 'r')
		return (0);
	if (str[1] != 'a' && str[1] != 'b' && str[1] != 's' && str[1] != 'r')
		return (0);
	if (str[2] == 0)
		return (1);
	if ((str[2] != 'a' && str[2] != 'b' && str[2] != 'r') || (str[1] != 'r'))
		return (0);
	return (1);
}
