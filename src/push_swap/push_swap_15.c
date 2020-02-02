/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_15.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by gtapioca          #+#    #+#             */
/*   Updated: 2020/02/02 19:31:02 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../includes/push_swap.h"
#include "../../includes/libft.h"

int		main_addition_helper(t_list3 **t, int y[4])
{
	t[2] = 0;
	y[0] = stack_size(t[0]);
	y[1] = 0;
	y[2] = 1;
	y[3] = y[0];
	return (1);
}

void	st_sort_3_1(t_list3 **st_a, t_list1 **a)
{
	if (*((*st_a)->next->a) > *((*st_a)->next->next->a) &&
		*((*st_a)->next->next->a) > *((*st_a)->a))
	{
		*st_a = stack_sort_rr(*st_a);
		make_entry_stack(a, "rra");
		*st_a = stack_sort_s(*st_a);
		make_entry_stack(a, "sa");
		return ;
	}
	if (*((*st_a)->next->next->a) > *((*st_a)->a) &&
		*((*st_a)->a) > *((*st_a)->next->a))
	{
		*st_a = stack_sort_s(*st_a);
		make_entry_stack(a, "sa");
		return ;
	}
	if (*((*st_a)->next->a) > *((*st_a)->a) &&
		*((*st_a)->a) > *((*st_a)->next->next->a))
	{
		*st_a = stack_sort_rr(*st_a);
		make_entry_stack(a, "rra");
		return ;
	}
}

void	st_sort_3(t_list3 **st_a, t_list1 **a)
{
	if (*((*st_a)->a) > *((*st_a)->next->a) &&
		*((*st_a)->next->a) > *((*st_a)->next->next->a))
	{
		make_entry_stack(a, "ra");
		*st_a = stack_sort_r(*st_a);
		*st_a = stack_sort_s(*st_a);
		make_entry_stack(a, "sa");
		return ;
	}
	if (*((*st_a)->a) > *((*st_a)->next->next->a) &&
		*((*st_a)->next->next->a) > *((*st_a)->next->a))
	{
		*st_a = stack_sort_r(*st_a);
		make_entry_stack(a, "ra");
		return ;
	}
	st_sort_3_1(st_a, a);
}

bool	sort_checker(char **argv)
{
	char	**buff;

	buff = argv;
	while (buff[0] && buff[1])
	{
		if (ft_atoi(buff[0]) > ft_atoi(buff[1]))
			return (false);
		buff++;
	}
	return (true);
}
