/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:50:19 by cado-car          #+#    #+#             */
/*   Updated: 2021/09/14 18:28:43 by cado-car         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
ssize_t	read_file(int fd, char **buffer, char **buff_read, char **line);
char	*get_line(char **buff_read, char **line);

/* 
*	GET_NEXT_LINE
*	-------------
*	DESCRIPTION
*	This function takes an opened file descriptor and returns its next line. 
*	This function has undefined behavior when reading from a binary file.
*	PARAMETERS
*	#1. A file descriptor 
*	RETURN VALUES
*	If successful, get_next_line returns a string with the full line ending in
*	a line break (`\n`) when there is one.
*	If an error occurs, or there's nothing more to read, it returns NULL.
*	----------------------------------------------------------------------------
*	AUXILIARY FUNCTIONS
*	-------------------
*	READ_FILE
*	---------
*	Checks if there's a line break in the buffer from the static variable 
*	`buff_read` from previous runs of get_next_line. If yes, sends the buffer to 
*	the get_line function. If not, reads file in loop until it reaches the next
*	line break `\n` or the end of the file. In this version, get_next_line must 
*	be able to manage multiple file descriptors opened at the same time.
*	PARAMETERS
*	#1. A file descriptor
*	#2. The buffer to be passed to the `read` function
*	#3. The cumulative static buffer from previous runs of get_next_line
*	#4. The pointer to the line to be extracted from buffer
*	RETURN VALUES
*	The number of bytes read during the function call, or 0 if EOF.
*	---------
*	GET_LINE
*	---------
*	Extracts the line (ending in either line break and `\0` or only `\0` in EOF)
*	from static buffer.
*	PARAMETERS
*	#1. The cumulative static buffer from previous runs of get_next_line
*	#4. The pointer to the line to be extracted from buffer
*	RETURN VALUES
*	The new updated buffer with whatever is left from the original, minus the
*	line extracted.
*/

char	*get_next_line(int fd)
{
	static char		*buff_read[OPEN_MAX];
	char			*buffer;
	char			*line;
	ssize_t			n;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!buff_read[fd])
		buff_read[fd] = ft_strdup("");
	n = read_file(fd, &buffer, &buff_read[fd], &line);
	if (n == 0 && !line)
		return (NULL);
	return (line);
}

ssize_t	read_file(int fd, char **buffer, char **buff_read, char **line)
{
	char	*temp;
	ssize_t	n;

	n = 1;
	while (!ft_strchr(*buff_read, '\n') && n)
	{
		n = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[n] = '\0';
		temp = *buff_read;
		*buff_read = ft_strjoin(temp, *buffer);
		free(temp);
	}
	free(*buffer);
	*buffer = NULL;
	*buff_read = get_line(buff_read, line);
	if (**line == '\0')
	{
		free(*line);
		*line = NULL;
	}
	return (n);
}

char	*get_line(char **buff_read, char **line)
{
	size_t	i;
	char	*new_buff;

	i = 0;
	new_buff = NULL;
	while ((*(*buff_read + i) != '\n') && (*(*buff_read + i) != '\0'))
		i++;
	if (*(*buff_read + i) == '\n')
	{
		i++;
		*line = ft_substr(*buff_read, 0, i);
		new_buff = ft_strdup(*buff_read + i);
	}
	else
		*line = ft_strdup(*buff_read);
	free(*buff_read);
	*buff_read = NULL;
	return (new_buff);
}
