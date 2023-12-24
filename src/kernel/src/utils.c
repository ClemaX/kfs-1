#include <utils.h>

size_t	strlen(const char* str)
{
	size_t len = 0;

	while (str[len] != '\0')
		len++;

	return len;
}

void	memmove(void *restrict dst, const void *restrict src, size_t size)
{
	if (dst < src)
	{
		while (size-- != 0)
			*(char*)dst++ = *(char*)src++;
	}
	else
	{
		while (size-- != 0)
			((char*)dst)[size] = ((char*)src)[size];
	}
}

void	memset(void *dst, int c, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		((char*)dst)[i] = (char)c;
	}
}
