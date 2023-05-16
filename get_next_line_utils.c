#include "get_next_line.h"

void	*ft_bzero(void *s, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n--)
		*str++ = '\0';
	return (s);
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len] == '\n')
		len++;
	return (len);
}

int	check_newline(char *buff)
{
	int	i;
	int	j;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			buff[i] = '\0';
			j = i + 1;
			while (j < BUFFER_SIZE)
			{
				buff[j - (i + 1)] = buff[j];
				buff[j] = '\0';
				j++;
			}
			return (1);
		}
		buff[i] = '\0';
		i++;
	}
	return (0);
}

char	*thats_line(char *s1, char *s2)
{
	char *str3;
	size_t i;
	size_t j;
	size_t len_s1;

	i = 0;
	j = 0;
	len_s1 = 0;
	if (s1 != NULL)
		len_s1 = ft_strlen(s1);
	str3 = (char *)malloc(len_s1 + ft_strlen(s2) + 1);
	if (!str3)
		return (NULL);
	while (s1 != NULL && s1[i])
	{
		str3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str3[i] = s2[j];
		i++;
		if (s2[j] == '\n')
			break ;
		j++;
	}
	str3[i] = '\0';
	free(s1);
	return (str3);
}