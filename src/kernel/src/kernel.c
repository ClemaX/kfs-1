#include "utils.h"
#include <kernel.h>
#include <terminal.h>
/*
static void test_memmove(void)
{
	const unsigned	delta = 8;
	char			buff[512];

	for (unsigned i = 0; i < sizeof(buff) - 2; ++i)
	{
		buff[i] = '0' + i % 10;
	}

	buff[sizeof(buff) - 2] = '\n';
	buff[sizeof(buff) - 1] = '\0';

	terminal_puts(buff);

	memmove(buff, buff + delta, sizeof(buff) - delta);

	terminal_puts(buff);
} */
/*
static void test_terminal(void)
{
	int		i = 0;
	size_t	row;
	size_t	j;

	while (i != 27)
	{
		row = terminal_get_row();
		terminal_putchar('0' + row / 10);
		terminal_putchar('0' + row % 10);
		terminal_putchar(' ');
		terminal_putchar('0' + i++ % 10);
		terminal_newline();

		j = 0;
		while (j++ < 100000000)
			;
	}
} */

void kernel_main(void)
{
	terminal_initialize();

	//test_memmove();
	//test_terminal();

}
