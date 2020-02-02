/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtapioca <gtapioca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:44:49 by gtapioca          #+#    #+#             */
/*   Updated: 2020/02/02 13:53:57 by gtapioca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/get_next_line.h"
#include "../../includes/libft.h"
#include <stdlib.h>
#include <fcntl.h>

static int	memory_deleter(t_list **ptr, int fd)
{
	t_list *buff1;
	t_list *buff2;

	buff1 = *ptr;
	if ((*ptr)->content_size == (size_t)fd)
	{
		buff1 = buff1->next;
		free((*ptr)->content);
		free(*ptr);
	}
	while (*ptr)
	{
		if ((*ptr)->next && (*ptr)->next->content_size == (size_t)fd)
		{
			buff2 = (*ptr)->next->next;
			free((*ptr)->next->content);
			free((*ptr)->next);
			(*ptr)->next = buff2;
			break ;
		}
		(*ptr) = (*ptr)->next;
	}
	*ptr = buff1;
	return (0);
}

static char	*ft_strjoin_until_linebreak(char **s1, char *s2, int k)
{
	char	*s3;
	int		i;

	i = 0;
	while (s2[i] != '\n' && s2[i] != '\0' && k == 1)
		i++;
	s3 = *s1;
	if (s2[i] == '\n' && k == 1)
	{
		s2[i] = '\0';
		*s1 = ft_strjoin(*s1, s2);
		s2[i] = '\n';
	}
	else
		*s1 = ft_strjoin(*s1, s2);
	free(s3);
	s3 = s2;
	if (s2[i] == '\0' && k == 1)
		s2 = ft_strjoin("", s2 + i);
	if (s2[i] == '\n' && k == 1)
		s2 = ft_strjoin("", s2 + i + 1);
	if (k == 1)
		free(s3);
	return (s2);
}

t_list		*get_begin_pointer(int fd, t_list **ptr1)
{
	t_list *tmp;

	tmp = *ptr1;
	if (tmp)
	{
		if ((int)(tmp->content_size) == fd)
			return (*ptr1);
		while (tmp->next)
		{
			if ((int)(tmp->content_size) == fd)
				return (*ptr1);
			tmp = tmp->next;
		}
		tmp->next = ft_lstnew("\0", 1);
		tmp->next->content_size = (size_t)fd;
		return (*ptr1);
	}
	else
	{
		tmp = ft_lstnew("\0", 1);
		tmp->content_size = (size_t)fd;
		return (tmp);
	}
}

t_list		*get_current_pointer(int fd, t_list *ptr, char **line)
{
	t_list	*tmp;

	tmp = ptr;
	while ((int)(tmp->content_size) != fd)
		(tmp) = (tmp)->next;
	*line = ft_strnew(1);
	return (tmp);
}

int			get_next_line(const int fd, char **line)
{
	t_list			*ptr;
	static t_list	*ptr1;
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if ((ptr1 = get_begin_pointer(fd, &ptr1)) &&
		ft_strrchr((ptr = get_current_pointer(fd, ptr1, line))->content, '\n'))
	{
		ptr->content = ft_strjoin_until_linebreak(line, ptr->content, 1);
		return (1);
	}
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		ft_strjoin_until_linebreak(&(ptr->content), buff, 0);
		if (ft_strrchr(buff, '\n'))
			break ;
	}
	ptr->content = ft_strjoin_until_linebreak(line, ptr->content, 1);
	if (!ret && !ft_strlen(*line))
		return (memory_deleter(&ptr1, fd));
	return (1);
}
