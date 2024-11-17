#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_n;

	total_n = size * nmemb;
	ptr = malloc(total_n);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, total_n);
	return (ptr);
}
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p1;

	i = 0;
	p1 = (unsigned char *)s;
	while (i < n)
	{
		p1[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*str_total;

	if (!s1 && !s2)
	{
		return (NULL);
	}
	if (!s1)
	{
		return (ft_strdup(s2));
	}
	if (!s2)
	{
		return (ft_strdup(s1));
	}
	total_len = ft_strlen(s1) + ft_strlen(s2);
	str_total = ft_calloc((total_len + 1), sizeof(char));
	if (!str_total)
	{
		return (NULL);
	}
	ft_memcpy(str_total, s1, ft_strlen(s1));
	ft_memcpy(str_total + ft_strlen(s1), s2, ft_strlen(s2));
	return (str_total);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char		*reserve;
	size_t		len;
	size_t		i;

	len = ft_strlen(src);
	reserve = (char *)malloc((len + 1) * sizeof(char));
	if (reserve == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		reserve[i] = src[i];
		i++;
	}
	reserve[len] = '\0';
	return (reserve);
}
char	*ft_strchr(const char *s, int c)
{
	unsigned char	target;
	const char		*ptr;

	target = (unsigned char)c;
	ptr = s;
	while (*ptr)
	{
		if (*ptr == target)
		{
			return ((char *)ptr);
		}
		ptr++;
	}
	if (*ptr == target)
	{
		return ((char *)ptr);
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub_str;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s + start))
	{
		len = ft_strlen(s + start);
	}
	sub_str = (char *)malloc((len + 1) * sizeof(char));
	if (sub_str == NULL)
		return (NULL);
	i = 0;
	while (start + i < ft_strlen(s) && i < len)
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
