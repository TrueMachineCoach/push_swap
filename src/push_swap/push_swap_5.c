/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_5.c                                      :+:      :+:    :+:   */
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

void	stack_sort_p(t_list3 **first_int_stack_a, t_list3 **first_int_stack_b)
{
	t_list3 *stack_buff;

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

int		pivvot_finder_help(int *arr, int i)
{
	int buff;
	int k;
	int j;

	k = 0;
	while (k < i)
	{
		j = 0;
		while (j < i)
		{
			if (j < i - 1 && arr[j] > arr[j + 1])
			{
				buff = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = buff;
			}
			j++;
		}
		k++;
	}
	buff = arr[(i / 2) - 1];
	free(arr);
	return (buff);
}

t_list3	*pivvot_finder_helper(t_list3 **stack_int_first_a, int size)
{
	int		i;
	int		y;
	t_list3 *buff_stack;

	buff_stack = *stack_int_first_a;
	y = stack_size(buff_stack);
	i = 0;
	while (i < y - size)
	{
		buff_stack = buff_stack->next;
		i++;
	}
	return (buff_stack);
}

int		pivvot_finder(t_list3 **stack_int_first_a,
	int size, t_list4 *point[4], int index)
{
	int		y;
	int		*arr;
	t_list3 *buff_stack;

	buff_stack = *stack_int_first_a;
	if (point[index] && point[index]->number == 1 &&
		size != stack_size(buff_stack))
		buff_stack = pivvot_finder_helper(stack_int_first_a, size);
	if (!(arr = (int *)malloc(sizeof(int) * size)))
		return (0);
	y = size;
	size--;
	while (size >= 0)
	{
		arr[size] = *(buff_stack->a);
		buff_stack = buff_stack->next;
		size--;
	}
	return (pivvot_finder_help(arr, y));
}

t_list3	*last_stack_finder(t_list3 *stack_int_first_b)
{
	while (stack_int_first_b != 0 && stack_int_first_b->next != 0)
		stack_int_first_b = stack_int_first_b->next;
	return (stack_int_first_b);
}
