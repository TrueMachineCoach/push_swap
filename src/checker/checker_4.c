/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by gtapioca          #+#    #+#             */
/*   Updated: 2020/02/02 20:57:51 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../includes/libft.h"

int		stack_rules_checker(t_list1 *first_stack, char **argv)
{
	int i;

	i = 0;
	if (!(first_stack) && !sort_checker(argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!(first_stack) && sort_checker(argv))
		return (0);
	while (first_stack->next != 0)
	{
		if (!(validation_rules(first_stack->action)))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		first_stack = first_stack->next;
	}
	if (!(validation_rules(first_stack->action)))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int		stack_numbers_checker(char **argv, char **argv_helper)
{
	char *l;

	if (!(*argv))
		return (0);
	while (*argv)
	{
		if (!(validation_integers(*argv)))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		argv++;
	}
	while (*argv_helper)
	{
		if (ft_strcmp(l = ft_itoa(ft_atoi(*argv_helper)), *argv_helper))
		{
			free(l);
			write(1, "Error\n", 6);
			return (0);
		}
		argv_helper++;
		free(l);
	}
	return (1);
}

t_list1	*stack_creator_helper(int *y, char *str, t_list1 **r)
{
	y[0] = 0;
	while ((y[1] = get_next_line(0, &str)))
	{
		if (y[0] == 0)
		{
			r[1] = stack_creator(str, y[0], r[0]);
			r[0] = r[1];
		}
		else
			r[0] = stack_creator(str, y[0], r[0]);
		y[0]++;
		free(str);
	}
	if (str != 0)
		free(str);
	return (r[1]);
}

int		prevchek(t_list1 **r, char **argv, int y[4], t_list2 *t[4])
{
	char *str;

	str = NULL;
	if (!(check_duplication(t[0])))
	{
		write(1, "Error\n", 6);
		stack_deleter(t[0]);
		return (0);
	}
	r[1] = stack_creator_helper(y, str, r);
	if (!stack_rules_checker(r[1], argv))
	{
		if (sort_checker(argv) && r[1] == 0)
			write(1, "OK\n", 3);
		stack_deleter(t[0]);
		stack_action_deleter(r[1]);
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		y[4];
	char	*str;
	t_list1	*r[2];
	t_list2	*t[4];

	str = NULL;
	if (argc > 1)
	{
		if (!stack_numbers_checker(argv + 1, argv + 1))
			return (0);
		t[0] = stacks_int_creator_a(t[0], t[3], argv, y);
		t[1] = 0;
		if (!(prevchek(r, argv, y, t)))
			return (0);
		stack_sort(&(t[0]), &(t[1]), r[1]);
		if (!(stack_validator(t[0], y[2])))
		{
			stack_deleter_help(t[0], t[1], r[1]);
			return (0);
		}
		stack_deleter_help(t[0], t[1], r[1]);
		write(1, "OK\n", 3);
	}
	return (0);
}
