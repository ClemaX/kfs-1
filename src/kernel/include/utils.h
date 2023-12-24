#pragma once

#include <stddef.h>

size_t	strlen(const char* str);
void	memmove(void *restrict dst, const void *restrict src, size_t size);
void	memset(void *dst, int c, size_t n);
