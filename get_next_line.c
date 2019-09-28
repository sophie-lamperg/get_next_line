/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjohanna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:06:18 by rjohanna          #+#    #+#             */
/*   Updated: 2019/09/28 19:59:20 by rjohanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "libft/libft.h"*/
#include "get_next_line.h"
/*#include <stdio.h>
#include <fcntl.h>*/

void    ft_memory(char *txt[], char *n, const int fd);
int	read_file(char *txt[], const int fd, char *n)
{
	char buf[BUFF_SIZE + 1];
	int kon;
	if (!(kon = read(fd, buf, BUFF_SIZE)))
		return (0);
	buf[kon] = '\0';
	n = ft_strjoin(txt[fd], buf);
	ft_memory(txt, n, fd);
	return (1);
}

void	ft_memory(char *txt[], char *n, const int fd)
{
	ft_strdel(&txt[fd]);
	txt[fd] = ft_strdup(n);
	ft_strdel(&n);
}
 int	null_line(char *txt[], char **line, const int fd)
{
	*line = ft_strdup(txt[fd]);
	ft_strclr(txt[fd]);
	return (1);
}

int get_next_line(const int fd, char **line)
{
	static char *txt[1024];
	char *kon;
	char *n;
	char buf[1];

	n = NULL;
	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
	return (-1);
	if (!txt[fd])
		txt[fd] = ft_strnew(0);
	while((kon = ft_strchr(txt[fd], '\n')) == NULL)
		if ((read_file(txt, fd, n)) == 0)
			break ;
	if (ft_strlen(txt[fd]) != 0)
	{
		if (!(ft_strchr(txt[fd], '\n')))
		return (null_line(txt, &*line, fd));
		*kon = '\0';
		n = ft_strdup(kon + 1);
		*line = ft_strdup(txt[fd]);
		ft_memory(txt, n, fd);
	}
	else
	return (0);
	return (1);
}
/*int		main(int argc, char **argv)
{
	int		fd;
		char	*line;
		if (argc == 1)
		fd = 0;
		else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
		else
		return (2);
		while (get_next_line(fd, &line) == 1)
		{
			printf("%s\n", line);
		}
		if (argc == 2)
			close(fd);
}*/
