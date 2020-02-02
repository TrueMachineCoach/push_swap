/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:37:16 by gtapioca          #+#    #+#             */
/*   Updated: 2020/02/02 20:36:26 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../includes/checker.h"
#include "../../includes/libft.h"

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
