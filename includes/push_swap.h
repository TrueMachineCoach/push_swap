/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by gtapioca          #+#    #+#             */
/*   Updated: 2020/02/02 19:29:54 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>

typedef struct		s_list3
{
	int				*a;
	struct s_list3	*next;
}					t_list3;

typedef struct		s_list1
{
	char			*action;
	struct s_list1	*next;
}					t_list1;

typedef struct		s_list4
{
	int				number;
	struct s_list4	*next;
}					t_list4;

void				stack_deleter(t_list3 *stack_int_first);
int					validation_digits(char *str);
int					pivvot_finder(t_list3 **stack_int_first_a,
					int size, t_list4 *point[4], int index);
void				stack_divide(t_list3 **d,
					int pivvot, t_list4 *point[2], t_list1 **a);
void				stack_divide_2(t_list3 **d,
					int pivvot, t_list4 *point[4], t_list1 **a);
void				quick_sort(t_list3 **d,
					t_list4 *point[2], int *size1, t_list1 **a);
int					stack_size(t_list3 *stack_a);
void				st_n(t_list4 *stack[2], int a, int index);
void				stack_sort_p(t_list3 **first_int_stack_a,
					t_list3 **first_int_stack_b);
t_list3				*stack_sort_r(t_list3 *first_int_stack);
t_list3				*stack_sort_s(t_list3 *first_int_stack);
t_list3				*stack_sort_rr(t_list3 *first_int_stack);
void				st_n(t_list4 *stack[4], int a, int index);
void				make_entry_stack(t_list1 **a, char *str);
t_list3				*stack_sort_rr(t_list3 *first_int_stack);
t_list3				*stack_sort_s(t_list3 *first_int_stack);
t_list3				*stack_sort_r(t_list3 *first_int_stack);
void				stack_sort_p(t_list3 **first_int_stack_a,
					t_list3 **first_int_stack_b);
int					pivvot_finder_help(int *arr, int i);
t_list3				*pivvot_finder_helper(t_list3 **stack_int_first_a,
					int size);
int					pivvot_finder(t_list3 **stack_int_first_a,
					int size, t_list4 *point[4], int index);
t_list3				*last_stack_finder(t_list3 *stack_int_first_b);
t_list3				*stacks_int_creator_a(t_list3 *stack_a,
					t_list3 *first_int_stack_a, char **argv);
void				stack_sort_helper(t_list3 **first_int_stack_a,
					t_list3 **first_int_stack_b, t_list1 **first_stack);
void				stacks_status_print(t_list3 **first_int_stack_a,
					t_list3 **first_int_stack_b, int *b);
void				bonus_function1(t_list3 **on_display1,
					t_list3 **copier_stack);
int					stack_numbers_checker(char **argv, char **argv_helper);
int					stack_validation_help2(t_list3 *stack_int_first);
void				stack_sort_less_2_2_help1_4(t_list3 **stack_int_first_a,
					t_list3 **stack_int_first_b, t_list1 **a);
void				stack_sort_less_2_2_help1_5(t_list3 **stack_int_first_a,
					t_list3 **stack_int_first_b, t_list1 **a);
void				stack_sort_less_2_2_help1_6(t_list3 **stack_int_first_a,
					t_list3 **stack_int_first_b, t_list1 **a);
void				stack_sort_less_2_2_help1_1(t_list3 **stack_int_first_a,
					t_list3 **stack_int_first_b, t_list1 **a);
void				stack_sort_less_2_2_help1_2(t_list3 **stack_int_first_a,
					t_list3 **stack_int_first_b, t_list1 **a);
void				stack_sort_less_2_2_help1_3(t_list3 **stack_int_first_a,
					t_list3 **stack_int_first_b, t_list1 **a);
void				stack_sort_less_2_2_help_4(t_list3 **stack_int_first_a,
					t_list3 **stack_int_first_b, t_list1 **a);
void				stack_sort_less_2_2_help_6(t_list3 **stack_int_first_a,
					t_list3 **stack_int_first_b, t_list1 **a);
void				stack_divide_2_2_1(t_list3 **stack_int_first_a,
					t_list3 **stack_int_first_b, int *c, t_list1 **a);
void				stack_divide_2_2_2(t_list3 **d, int pivvot,
					t_list4 *point[4], t_list1 **a);
void				stack_sort_less_2_2_help(t_list3 **st_a,
					t_list3 **st_b, t_list1 **a, t_list4 *point[4]);
void				stack_sort_less_2_2_help1(t_list3 **st_a,
					t_list3 **st_b, t_list1 **a, t_list4 *point[4]);
void				prev_point_stack_1(t_list4 *buff_stack[4],
					t_list4 *point[4]);
int					stack_sort_less_2_2(t_list3 **d,
					t_list4 *point[4], t_list1 **a);
void				stack_divide_helper_a(t_list3 **stack_int_first_a,
					t_list3 **stack_int_first_b, t_list1 **a);
void				stack_divide_helper_1(t_list4 *point[4],
					int buff_size, int buff_size_2);
void				stack_divide_helper_4(t_list3 **d, t_list4 *point[4],
					int pivvot, t_list1 **a);
void				stack_divide_helper_3(t_list3 **d, t_list4 *point[4],
					int pivvot, t_list1 **a);
void				stack_divide_helper_2(t_list3 **d, t_list4 *point[4],
					int pivvot, t_list1 **a);
void				stack_divide_helper(t_list3 **d, t_list4 *point[4],
					int pivvot, t_list1 **a);
void				stack_divide_2_2(t_list3 **d, int pivvot,
					t_list4 *point[4], t_list1 **a);
void				point_filler(t_list4 *point[4]);
char				**stack_numbers_checker_helper(char **argv);
void				st_sort_3(t_list3 **st_a, t_list1 **a);
bool				sort_checker(char **argv);
int					main_addition_helper(t_list3 **t, int y[4]);

#endif
