/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by gtapioca          #+#    #+#             */
/*   Updated: 2020/02/02 20:05:04 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define BUFF 200
# include <stdbool.h>

typedef struct		s_list1
{
	char			*action;
	struct s_list1	*next;
}					t_list1;

typedef struct		s_list2
{
	int				*a;
	struct s_list2	*next;
}					t_list2;

void				stack_sort_helper_2(t_list2 **first_int_stack_a,
					t_list2 **first_int_stack_b, t_list1 **first_stack);
t_list2				*stack_sort_s(t_list2 *first_int_stack);
void				stack_sort_p(t_list2 **first_int_stack_a,
					t_list2 **first_int_stack_b);
t_list2				*stack_sort_r(t_list2 *first_int_stack);
t_list2				*stack_sort_rr(t_list2 *first_int_stack);
t_list1				*stack_creator(char *str, int i, t_list1 *stack);
t_list2				*stacks_int_creator_a(t_list2 *stack_a,
					t_list2 *first_int_stack_a, char **argv, int *y);
void				stack_sort(t_list2 **first_int_stack_a,
					t_list2 **first_int_stack_b, t_list1 *first_stack);
void				stack_sort_helper(t_list2 **first_int_stack_a,
					t_list2 **first_int_stack_b, t_list1 **first_stack);
int					get_next_line(const int fd, char **line);
int					validation_integers(char *str);
int					validation_rules(char *str);
int					stack_validator(t_list2 *stack_int_first, int j);
int					check_duplication(t_list2 *stack_int_first);
void				stack_deleter(t_list2 *stack_int_first);
void				stack_action_deleter(t_list1 *stack_first);
void				stack_deleter_help(t_list2 *t0, t_list2 *t1, t_list1 *r1);
bool				sort_checker(char **argv);

#endif
