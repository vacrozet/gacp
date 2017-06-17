
#include "../includes/gacp.h"

static	char		*read_file(const int fd, char *str)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	ret = 0;
	while (!(ft_strchr(str, '\n')) && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = str;
		if (!(str = ft_strjoin(tmp, buf)))
			return (NULL);
		free(tmp);
	}
	if (ret == -1)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	return (str);
}

static	int			fill_save_line(char *save, char **line)
{
	int		count;
	char	*tmp;

	count = 0;
	while (save[count] != '\n' && save[count] != '\0')
		count++;
	*line = ft_strsub(save, 0, count);
	tmp = ft_strnew(ft_strlen(save));
	if (tmp == NULL)
		return (-1);
	tmp = ft_strcpy(tmp, &save[count + 1]);
	ft_strclr(save);
	save = ft_strcpy(save, tmp);
	free(tmp);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static	char	*save[FD_SIZE];

	if (BUFF_SIZE <= 0 || fd < 0 || fd > 2147483647 || line == NULL
			|| BUFF_SIZE >= 10000000)
		return (-1);
	if (!save[fd] && (save[fd] = ft_strnew(2))
			== NULL)
		return (-1);
	if ((save[fd] = read_file(fd, save[fd])) == NULL)
		return (-1);
	if (save[fd][0] == '\0')
	{
		*line = NULL;
		return (0);
	}
	if (fill_save_line(save[fd], line) < 0)
		return (-1);
	return (1);
}