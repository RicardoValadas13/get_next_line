#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	bytes_read = 1;
	line = NULL;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
    {
        ft_bzero(buff, BUFFER_SIZE);
		return (NULL);
    }
	while ( *buff || (bytes_read = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		line = thats_line(line, buff);
		if (check_newline(buff))
			break ;
	}
	return (line);
}

/* int	main(void)
{
    int     fd;
    char    *line;
    int      i;

    fd = open("read_error.txt", O_RDONLY);
    i = 1;
    while (1)
    {
        line = get_next_line(fd);
        printf("Line %d:%s", i, line);
        if (line == NULL)
        {
            printf("\n");
            break ;
        }
        i++;
        free(line);
    } 
    return (0);
}
 */