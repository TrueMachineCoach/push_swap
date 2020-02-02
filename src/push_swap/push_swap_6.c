/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by gtapioca          #+#    #+#             */
/*   Updated: 2020/02/02 14:46:54 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../includes/push_swap.h"
#include "../../includes/libft.h"

void	stack_divide_helper_2(t_list3 **d, t_list4 *point[4],
	int pivvot, t_list1 **a)
{
	int		i;
	t_list3	*buff_stack;

	i = 0;
	while (i < point[0]->number)
	{
		buff_stack = last_stack_finder(d[0]);
		if (*(buff_stack->a) <= pivvot)
		{
			d[0] = stack_sort_rr(d[0]);
			make_entry_stack(a, "rra");
			stack_sort_p(&(d[2]), &(d[0]));
			make_entry_stack(a, "pb");
		}
		else
		{
			d[0] = stack_sort_rr(d[0]);
			make_entry_stack(a, "rra");
		}
		i++;
	}
}

void	stack_divide_helper_4_1(t_list4 *point[4],
	int buff_size, int buff_size_2)
{
	st_n(point, buff_size, 0);
	st_n(point, buff_size_2, 1);
	st_n(point, 0, 3);
	st_n(point, 0, 2);
}

void	stack_divide_helper_4_2(t_list3 **stack_int_first_a,
	t_list3 **stack_int_first_b, t_list1 **a)
{
	*stack_int_first_b = stack_sort_rr(*stack_int_first_b);
	make_entry_stack(a, "rrb");
	stack_sort_p(stack_int_first_a, stack_int_first_b);
	make_entry_stack(a, "pa");
}

void	stack_divide_helper_4(t_list3 **d, t_list4 *point[4],
	int pivvot, t_list1 **a)
{
	int		c[5];
	t_list3	*buff_stack;

	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
	while (c[0] < point[1]->number)
	{
		buff_stack = last_stack_finder(d[2]);
		if (*(buff_stack->a) > pivvot)
		{
			stack_divide_helper_4_2(&(d[0]), &(d[2]), a);
			c[2]++;
		}
		else
		{
			d[2] = stack_sort_rr(d[2]);
			make_entry_stack(a, "rrb");
			c[1]++;
		}
		c[0]++;
	}
	stack_divide_helper_4_1(point, c[2], c[1]);
}

void	stack_divide_helper_1(t_list4 *point[4], int buff_size, int buff_size_2)
{
	st_n(point, buff_size_2, 0);
	st_n(point, buff_size, 1);
	st_n(point, 0, 3);
	st_n(point, 0, 2);
}
