#include "../includes/so_long.h"

static int	read_to_text_buffer(int fd, char **text_buffer, char *buffer)
{
	char	*temp;
	int		read_size;

	read_size = read(fd, buffer, BUFFER_SIZE);
	while (read_size > 0)
	{
		buffer[read_size] = '\0';
		if (!*text_buffer)
		{
			*text_buffer = ft_strdup(buffer);
		}
		else
		{
			temp = ft_strjoin(*text_buffer, buffer);
			free(*text_buffer);
			*text_buffer = temp;
		}
		if (ft_strchr(*text_buffer, '\n'))
			break ;
		read_size = read(fd, buffer, BUFFER_SIZE);
	}
	return (read_size);
}

static char	*cut_text_buffer(char *text_buffer, int ln_len)
{
	char	*temp;

	if (!text_buffer)
		return (NULL);
	temp = ft_strdup(text_buffer + ln_len + 1);
	free(text_buffer);
	if (!temp)
		return (NULL);
	return (temp);
}

static char	*pull_line(char *text_buffer, int ln_len)
{
	char	*ln;
	int		i;

	if (!text_buffer)
		return (NULL);
	ln = malloc((ln_len + 2) * sizeof(char));
	if (!ln)
		return (NULL);
	i = 0;
	while (i <= ln_len)
	{
		ln[i] = text_buffer[i];
		i++;
	}
	ln[i] = '\0';
	return (ln);
}

static char	*get_line(char **text_buffer)
{
	char	*ln;
	int		i;

	if (!*text_buffer)
		return (NULL);
	i = 0;
	while ((*text_buffer)[i] && (*text_buffer)[i] != '\n')
		i++;
	if ((*text_buffer)[i] == '\n')
	{
		ln = pull_line(*text_buffer, i);
		*text_buffer = cut_text_buffer(*text_buffer, i);
		if (*text_buffer && (*text_buffer)[0] == '\0')
		{
			free(*text_buffer);
			*text_buffer = NULL;
		}
	}
	else
	{
		ln = ft_strdup(*text_buffer);
		free(*text_buffer);
		*text_buffer = NULL;
	}
	return (ln);
}

char	*get_next_line(int fd)
{
	static char	*text_buffer;
	char		*buffer;
	char		*result;
	int			read_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_size = read_to_text_buffer(fd, &text_buffer, buffer);
	free(buffer);
	if (read_size < 0)
	{
		free(text_buffer);
		return (NULL);
	}
	if (read_size == 0 && !text_buffer)
		return (NULL);
	result = get_line(&text_buffer);
	return (result);
}
