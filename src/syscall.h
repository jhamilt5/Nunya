/*
Copyright (C) 2015 The University of Notre Dame
This software is distributed under the GNU General Public License.
See the file LICENSE for details.
*/

#ifndef SYSCALL_H
#define SYSCALL_H

#include "kerneltypes.h"
#include "graphics.h"

#define SYSCALL_exit     1
#define SYSCALL_testcall 2
#define SYSCALL_yield    3

#define SYSCALL_window_create 200
#define SYSCALL_window_set_border_color 201
#define SYSCALL_window_draw_line 202
#define SYSCALL_window_draw_arc 203
#define SYSCALL_window_draw_circle 204
#define SYSCALL_window_draw_char 205
#define SYSCALL_window_draw_string 206

uint32_t syscall(uint32_t n, uint32_t a, uint32_t b, uint32_t c, uint32_t d,
                 uint32_t e);

static inline int32_t exit(uint32_t status) {
    return syscall(SYSCALL_exit, status, 0, 0, 0, 0);
}

static inline int32_t testcall(int x) {
    return syscall(SYSCALL_testcall, x, 0, 0, 0, 0);
}

static inline int32_t yield() {
    return syscall(SYSCALL_yield, 0, 0, 0, 0, 0);
}

// Window System Calls
static inline int32_t create_window(int x, int y, int width, int height) {
	return syscall(SYSCALL_window_create, x, y, width, height, 0);
}

static inline int32_t set_border_color(const struct graphics_color *border_color) {
	return syscall(SYSCALL_window_set_border_color, (int)border_color, 0, 0, 0, 0);
}

static inline int32_t draw_line(int x1, int y1, int x2, int y2, const struct graphics_color *color) {
	return syscall(SYSCALL_window_draw_line, x1, y1, x2, y2, (int)color);
}

static inline int32_t draw_char(int x, int y, char c, const struct graphics_color *fgcolor, const struct graphics_color *bgcolor) {
	return syscall(SYSCALL_window_draw_char, x, y, c, (int)fgcolor, (int)bgcolor);
}

static inline int32_t draw_string(int x, int y, const char *str, const struct graphics_color *fgcolor,
	const struct graphics_color *bgcolor) {
	return syscall(SYSCALL_window_draw_string, x, y, (int)str, (int)fgcolor, (int)bgcolor);
}




#endif
