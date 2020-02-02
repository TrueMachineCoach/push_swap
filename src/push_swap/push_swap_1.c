/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by gtapioca          #+#    #+#             */
/*   Updated: 2020/02/02 19:31:17 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../includes/push_swap.h"
#include "../../includes/libft.h"

char	**check_bonus_option(int argc, char **argv, int *b)
{
	int i;

	i = 0;
	*b = 0;
	if (argc > 1 && (!(ft_strcmp(argv[1], "-v"))
	|| !(ft_strcmp(argv[1], "-cv")) || !(ft_strcmp(argv[1], "-vc"))))
		argv += 1;
	while (i < 1 && i < argc - 1)
	{
		if (!(ft_strcmp(*argv, "-v")))
			*b = 1;
		else if (!(ft_strcmp(*argv, "-cv")) || !(ft_strcmp(*argv, "-vc")))
			*b = 2;
		i++;
	}
	return (argv);
}

t_list3	*print_helper(t_list3 *on_display1,
	t_list3 *on_display2, t_list1 **a, int b)
{
	t_list1 *buff;

	buff = *a;
	if (b)
		while (buff)
		{
			if (b == 2)
				write(1, "\033[1;36m", 7);
			write(1, (buff)->action, ft_strlen((buff)->action));
			write(1, "\n", 1);
			stack_sort_helper(&on_display1, &on_display2, &buff);
			stacks_status_print(&on_display1, &on_display2, &b);
			buff = (buff)->next;
		}
	else
		while (buff)
		{
			write(1, (buff)->action, ft_strlen((buff)->action));
			write(1, "\n", 1);
			buff = (buff)->next;
		}
	return (on_display1);
}

void	stack_deleter_1(t_list3 *on_display1, t_list3 *on_display2, t_list1 *a)
{
	t_list3 *buff_1;
	t_list3 *buff_2;
	t_list1 *buff_3;

	while (on_display1)
	{
		buff_1 = on_display1;
		on_display1 = on_display1->next;
		free(buff_1->a);
		free(buff_1);
	}
	while (on_display2)
	{
		buff_2 = on_display2;
		on_display2 = on_display2->next;
		free(buff_2->a);
		free(buff_2);
	}
	while (a)
	{
		buff_3 = a;
		a = a->next;
		free(buff_3);
	}
}

void	main_addition(t_list3 **t, int b, t_list1 *a)
{
	int		q;
	t_list3 *on_display1;
	t_list3 *on_display2;
	int		y[4];
	t_list4 *point[4];

	on_display1 = NULL;
	on_display2 = NULL;
	point_filler(point);
	q = main_addition_helper(t, y);
	st_n(point, stack_size(t[0]), 0);
	st_n(point, stack_size(t[2]), 1);
	if (b > 0)
		bonus_function1(&on_display1, t);
	if (y[0] == 3)
		st_sort_3(t, &a);
	else
		quick_sort(t, point, &q, &a);
	on_display1 = print_helper(on_display1, on_display2, &a, b);
	stack_deleter_1(on_display1, on_display2, a);
	free(point[0]);
	free(point[1]);
}

int		main(int argc, char **argv)
{
	char	**buff;
	int		b;
	t_list3	*t[3];
	t_list1 *a;

	b = 0;
	buff = argv;
	argv = check_bonus_option(argc, argv, &b);
	if (!stack_numbers_checker(argv, argv))
		return (0);
	a = 0;
	t[0] = stacks_int_creator_a(t[0], t[1], argv);
	if (!(stack_validation_help2(t[0])))
		return (0);
	if (!sort_checker(buff += 1))
		main_addition(t, b, a);
	stack_deleter(t[0]);
	return (0);
}
