/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
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

void	point_filler(t_list4 *point[4])
{
	point[0] = 0;
	point[1] = 0;
	point[2] = 0;
	point[3] = 0;
}

void	stack_deleter(t_list3 *stack_int_first)
{
	t_list3 *buffer;

	if (!stack_int_first)
		return ;
	while (stack_int_first->next)
	{
		buffer = stack_int_first;
		free(stack_int_first->a);
		stack_int_first = stack_int_first->next;
		free(buffer);
	}
	buffer = stack_int_first;
	free(stack_int_first->a);
	stack_int_first = stack_int_first->next;
	free(buffer);
}

int		validation_digits(char *str)
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
