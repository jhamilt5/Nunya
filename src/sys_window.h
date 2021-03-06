/*
Copyright (C) 2016 The University of Notre Dame
This software is distributed under the GNU General Public License.
See the file LICENSE for details.
*/

#ifndef SYS_WINDOW_H
#define SYS_WINDOW_H

#include "sys_window_struct.h"

/**
 * @brief A struct to hold information needed to draw an arc
 * @details This struct holds data that can be passed to draw_arc
 * to indicate the radius and start/end angles. This information
 * is collected here as alone, draw_arc would need more parameters
 * than are available to system calls
 */
struct arc_info {
	double r;
	double start_theta;
	double end_theta;
};

// Window System Calls

/**
 * @brief Creates a window for the process
 * @details Invokes the window_create function with given parameters and assigns
 * the resulting window to calling process
 * 
 * @param x The x position of the window, relative to its parent
 * @param y The y position of the window, relative to its parent
 * @param width The width of the window
 * @param height The height of the window
 * @return 0 if a window was created, -1 if the process already has a widnow, otherwise error
 */
static inline int32_t create_window(int x, int y, uint32_t width, uint32_t height) {
	return syscall(SYSCALL_window_create, x, y, width, height, 0);
}

/**
 * @brief Sets the border color of the process' window
 * @details Invokes the window_set_border_color function to change window color
 * 
 * @param graphics_color The color to set the border to
 * @return 0 on success, or -1 if the calling process has no window
 */
static inline int32_t set_border_color(const struct graphics_color *border_color) {
	return syscall(SYSCALL_window_set_border_color, (int)border_color, 0, 0, 0, 0);
}

/**
 * @brief Draws a line in the current process' window
 * @details Invokes the window_draw_line function to draw into the current window
 * 
 * @param x1 The x position of the first point in the line
 * @param y1 The y position of the first point in the line
 * @param x2 The x position of the second point in the line
 * @param y2 The y position of the second point in the line
 * @param color The color of the line
 * @return 0 on success, or -1 if the calling process has no window
 */
static inline int32_t draw_line(int x1, int y1, int x2, int y2, const struct graphics_color *color) {
	return syscall(SYSCALL_window_draw_line, x1, y1, x2, y2, (int)color);
}

/**
 * @brief Draws an arc in the current process' window
 * @details Invokes the window_draw_arc function to draw into the current window
 * 
 * @param x The x position of the center of the arc
 * @param y The y position of the center of the arc
 * @param arc The arc_info describing the arc length and radius
 * @param color The color to draw in
 * @return 0 on success, or -1 if the calling process has no window
 */
static inline int32_t draw_arc(int x, int y, const struct arc_info *arc, const struct graphics_color *c) {
	return syscall(SYSCALL_window_draw_arc, x, y, (int)arc, (int)c, 0);
}

/**
 * @brief Draws a circle in the current process' window
 * @details Invokes the window_draw_circle function to draw into the current window
 * 
 * @param x The x position of the center of the circle, relative to the window
 * @param y The y position of the center of the circle, relative to the window
 * @param r The radius of the circle
 * @param c The color to draw in
 * @return 0 on success, or -1 if the calling process has no window
 */
static inline int32_t draw_circle(int x, int y, const double *r, const struct graphics_color *c) {
	return syscall(SYSCALL_window_draw_circle, x, y, (int)r, (int)c, 0);
}

/**
 * @brief Draws a character in the current process' window
 * @details Invokes the window_draw_char function to draw into the current window
 * 
 * @param x The x position of the top left corner of the char
 * @param y The y position of the top left corner of the char
 * @param c The character to draw
 * @param fgcolor The color to draw the character
 * @param bgcolor The color to draw the negative space
 * @return 0 on success, or -1 if the calling process has no window
 */
static inline int32_t draw_char(int x, int y, char c, const struct graphics_color *fgcolor, const struct graphics_color *bgcolor) {
	return syscall(SYSCALL_window_draw_char, x, y, c, (int)fgcolor, (int)bgcolor);
}

/**
 * @brief Draws a string in the current process' window
 * @details Invokes the window_draw_string function to draw into the current window
 * 
 * @param x The x position of the top left corner of the first character
 * @param y The y position of the top right corner of the first character
 * @param str The text to be drawn, null terminated
 * @param fgcolor The color to draw the characters
 * @param bgcolor The color to draw the negative space
 * @return 0 on success, or -1 if the calling process has no window
 */
static inline int32_t draw_string(int x, int y, const char *str, const struct graphics_color *fgcolor,
	const struct graphics_color *bgcolor) {
	return syscall(SYSCALL_window_draw_string, x, y, (int)str, (int)fgcolor, (int)bgcolor);
}


#endif