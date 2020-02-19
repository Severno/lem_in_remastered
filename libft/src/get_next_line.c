/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sapril <sapril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:47:34 by sapril            #+#    #+#             */
/*   Updated: 2019/12/06 14:59:56 by sapril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*join_free(char *arr, char *buf)
{
	char	*ret;
	size_t	len;

	if (!arr || !buf)
		return (NULL);
	len = ft_strlen(arr) + ft_strlen(buf);
	if (!(ret = ft_strnew(len)))
		return (NULL);
	ft_strcpy(ret, arr);
	ft_strcat(ret, buf);
	free(arr);
	return (ret);
}

static int		add_line(char **line, char *buff_line[])
{
	char	*temp;
	size_t	i;

	i = 0;
	while ((*buff_line)[i] != '\n' && (*buff_line)[i])
		i++;
	if ((ft_strchr(*buff_line, '\n')) != NULL)
	{
		*line = ft_strsub(*buff_line, 0, i);
		temp = ft_strdup(ft_strchr(*buff_line, '\n') + 1);
		free(*buff_line);
		*buff_line = temp;
	}
	else
	{
		*line = ft_strdup(*buff_line);
		ft_bzero(*buff_line, i);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*buff_line[MAX_FD];
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (BUFF_SIZE <= 0 || fd < 0 || fd > MAX_FD || !(line))
		return (-1);
	while (((ret = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[ret] = '\0';
		if (buff_line[fd] == NULL)
			buff_line[fd] = ft_strsub(buf, 0, ret);
		else
			buff_line[fd] = join_free(buff_line[fd], buf);
		if (ft_strchr(buff_line[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if ((buff_line[fd] == NULL || buff_line[fd][0] == '\0'))
		return (0);
	else
		return (add_line(line, &buff_line[fd]));
}
