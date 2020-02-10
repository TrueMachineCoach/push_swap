/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by gtapioca          #+#    #+#             */
/*   Updated: 2020/02/10 22:50:45 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../includes/push_swap.h"
#include "../../includes/libft.h"

char	**stack_numbers_checker_helper(char **argv)
{
	if (!(validation_digits(*argv)))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	argv++;
	return (argv);
}

void	bonus_function1(t_list3 **on_display1, t_list3 **copier_stack)
{
	t_list3 *buff_stack;
	t_list3 *buff_stack2;

	buff_stack2 = *copier_stack;
	buff_stack = 0;
	while (buff_stack2)
	{
		if (buff_stack == 0)
		{
			if (!(buff_stack = (t_list3 *)malloc(sizeof(t_list3))))
				return ;
			*on_display1 = buff_stack;
		}
		else
		{
			if (!(buff_stack->next = (t_list3 *)malloc(sizeof(t_list3))))
				return ;
			buff_stack = buff_stack->next;
		}
		if (!(buff_stack->a = (int *)malloc(sizeof(int))))
			return ;
		*(buff_stack->a) = *(buff_stack2->a);
		buff_stack2 = buff_stack2->next;
	}
	buff_stack->next = 0;
}

void	stack_sort_helper(t_list3 **first_int_stack_a,
		t_list3 **first_int_stack_b, t_list1 **first_stack)
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

void	stacks_status_print1(t_list3 *buff_stack, int *b, int *i)
{
	char *lol;

	write(1, "|           ", 13);
	if (buff_stack)
	{
		lol = ft_itoa(*((buff_stack)->a));
		if (*b == 2)
			write(1, "\033[1;33m", 7);
		write(1, lol, ft_strlen(lol));
		while (((unsigned long)*i) <
			13 - ft_strlen(lol))
		{
			write(0, " ", 1);
			(*i)++;
		}
		free(lol);
	}
	else
		write(1, "              ", 13);
	*i = 0;
	if (*b == 2)
		write(1, "\033[1;32m", 7);
}

void	stacks_status_print(t_list3 **first_int_stack_a,
	t_list3 **first_int_stack_b, int *b)
{
	t_list3 *buff_stack1;
	t_list3 *buff_stack2;
	int		i;

	i = 0;
	buff_stack1 = *first_int_stack_a;
	buff_stack2 = *first_int_stack_b;
	if (*b == 2)
		write(1, "\033[1;32m", 7);
	if (buff_stack1 || buff_stack2)
		write(1, "|-----------A------------|-----------B------------|\n", 52);
	while (buff_stack1 || buff_stack2)
	{
		stacks_status_print1(buff_stack1, b, &i);
		stacks_status_print1(buff_stack2, b, &i);
		write(1, "|\n", 2);
		if (buff_stack2)
			buff_stack2 = (buff_stack2)->next;
		if (buff_stack1)
			buff_stack1 = (buff_stack1)->next;
	}
	write(1, "|------------------------|------------------------|\n", 52);
	if (*b == 2)
		write(1, "\033[0m", 4);
}
