/*
 * colorbook.h
 *
 * playing with pigments
 *
 * Author: Zex <top_zlynch@yahoo.com>
 */
#ifndef __COLOR_BOOK_H__
#define __COLOR_BOOK_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/*
 *  0x00-0x07:  standard colors (as in ESC [ 30..37 m)
 *  0x08-0x0f:  high intensity colors (as in ESC [ 90..97 m)
 *  0x10-0xe7:  6*6*6=216 colors: 16 + 36*r + 6*g + b (0≤r,g,b≤5)
 *  0xe8-0xff:  grayscale from black to white in 24 steps
 */
extern char *col_prefix[];
extern char *col_surfix;

struct color_table {
	char **color_prefix;
	size_t color_table_size;
	char *color_surfix;
	char *usr_str;
	size_t full_size;
	char *text_buffer;
};
typedef struct color_table color_table;

/* result in [color-prefix][user string][color-surfix] */
#define TEXT_WITH_COLOR(ct, x) \
strcat(strcat(strcat(memset((ct)->text_buffer, 0, 1), *((ct)->color_prefix+x++)), (ct)->usr_str), (ct)->color_surfix)

#define INIT_COLOR_TABLE_SIZE(ct) \
{ \
	size_t x = 0; \
	while (*((ct)->color_prefix+x++)) (ct)->color_table_size++; \
}

struct process_bar {
	size_t cur;    /* current real position */
	size_t max;    /* real max width */
	char *left;    /* symbol for unfinished part */
	char *right;   /* symbol for finished part */
	size_t bar_width; /* corrected max width */
	float bar_cur;   /* corrected max width */
	color_table col_tb;;
};
typedef struct process_bar process_bar;

extern float show_process_bar(process_bar *pb);
extern size_t color_chart_selftest();
extern int show_color_word();



#endif /* __COLOR_BOOK_H__ */

