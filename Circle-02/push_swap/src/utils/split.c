#include "library.h"

size_t	ps_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (dstsize)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	while (src[i])
		++i;
	return (i);
}

static size_t	ps_check_size(char const *s, char *delim)
{
	size_t	cnt;
	int		i;

	cnt = 0;
	i = -1;
	if (!*s)
		return (0);
	while (*(++i + s + 1))
		if (!ps_strchr(delim, *(i + s)) && ps_strchr(delim, *(i + s + 1)))
			++cnt;
	if (!ps_strchr(delim, *(s + i)))
		return (cnt + 1);
	return (cnt);
}

char	**ps_free_split(char **s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!*s)
	{
		free(s);
		s = 0;
		return (NULL);
	}
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
	s = 0;
	return (NULL);
}

char	*ps_substr(char *s, unsigned int start, size_t len)
{
	char	*dest;

	dest = (char *)malloc(len + 1);
	if (!s || !dest)
		return (NULL);
	if ((int)start >= ps_strlen(s) || \
			!(ps_strlcpy(dest, s + start, len + 1)))
		dest[0] = '\0';
	return (dest);
}

char	**ps_split(char *s, char *delim)
{
	char	**ret;
	char	*from;
	int		i;

	ret = malloc(sizeof(char *) * (ps_check_size(s, delim) + 1));
	if (!s || !ret)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (!ps_strchr(delim, *s))
		{
			from = (char *)s;
			while (*s && !ps_strchr(delim, *s))
				++s;
			ret[i] = ps_substr(from, 0, (s - from));
			if (!ret[i++])
				return (ps_free_split(ret));
		}
		else
			++s;
	}
	ret[i] = NULL;
	return (ret);
}
