/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btheia <btheia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:13:04 by btheia            #+#    #+#             */
/*   Updated: 2019/09/18 21:02:34 by btheia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

t_list	*create(int fd, t_list **begin)
{
	t_list	*tmp;
	char	s[BUFF_SIZE + 1];

	ft_bzero(s, BUFF_SIZE + 1);
	tmp = *begin;
	while (tmp)
	{
		if ((int)(tmp->content_size) != fd && tmp->next == NULL)
		{
			tmp->next = ft_lstnew(s, BUFF_SIZE + 1);
			if (tmp->next == NULL)
				return (NULL);
			(tmp->next)->content_size = fd;
			return (tmp->next);
		}
		if ((int)(tmp->content_size) == fd)
			return (tmp);
		tmp = tmp->next;
	}
	*begin = ft_lstnew(s, BUFF_SIZE + 1);
	if (*begin == NULL)
		return (NULL);
	(*begin)->content_size = fd;
	return (*begin);
}

int		del(t_list **begin, int fd)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *begin;
	if (tmp && (int)tmp->content_size == fd)
	{
		next = (*begin)->next;
		free((*begin)->content);
		free(*begin);
		*begin = next;
		return (0);
	}
	while (tmp->next)
	{
		if ((int)tmp->next->content_size == fd)
		{
			next = tmp->next->next;
			free(tmp->next->content);
			free(tmp->next);
			tmp->next = next;
			break ;
		}
		tmp = tmp->next;
	}
	return (0);
}

int		linecat(char **line, char *content, int pos, int check_n)
{
	if (check_n == 0)
	{
		ft_memmove(*line, content, pos);
		ft_memmove(content, content + pos + 1,
			ft_strlen(content + pos + 1) + 1);
		return (1);
	}
	if (check_n == 1)
	{
		ft_memmove(*line, content, ft_strlen(content));
		ft_bzero(content, ft_strlen(content));
		return (0);
	}
	return (0);
}

int		rewrite(char **line, char *buf, int pos, int check_n)
{
	char *tmp;

	if (check_n == 0)
	{
		tmp = ft_strnew(ft_strlen(*line) + pos);
		if (tmp == NULL)
			return (-1);
		ft_memmove(tmp, *line, ft_strlen(*line));
		ft_memmove(tmp + ft_strlen(*line), buf, pos);
		free(*line);
		*line = tmp;
		ft_memmove(buf, buf + pos + 1, ft_strlen(buf) - pos + 1);
		buf[ft_strlen(buf)] = '\0';
		return (1);
	}
	tmp = ft_strnew(ft_strlen(*line) + ft_strlen(buf));
	if (tmp == NULL)
		return (-1);
	ft_memmove(tmp, *line, ft_strlen(*line));
	ft_memmove(tmp + ft_strlen(*line), buf, ft_strlen(buf));
	free(*line);
	*line = tmp;
	ft_bzero(buf, BUFF_SIZE + 1);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*head;
	char			*s;
	t_list			*f;
	int				pos;

	if (fd < 0 || line == NULL || (f = create(fd, &head)) == NULL ||
		!(*line = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (ft_strncmp(f->content, "\0", 1))
	{
		if ((s = ft_strchr(f->content, '\n')) != NULL)
			return (linecat(line, f->content, s - (char*)f->content, 0));
		linecat(line, f->content, s - (char*)f->content, 1);
	}
	while ((pos = read(fd, f->content, BUFF_SIZE)) > 0)
	{
		*((char*)f->content + pos) = '\0';
		if ((s = ft_strchr(f->content, '\n')) != NULL)
			return (rewrite(line, f->content, s - (char*)f->content, 0));
		if (rewrite(line, f->content, s - (char*)f->content, 1) == -1)
			return (-1);
	}
	if (pos < 0)
		return (-1);
	return (pos == 0 && **line != '\0') ? 1 : del(&head, fd);
}
