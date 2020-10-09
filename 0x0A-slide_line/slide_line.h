#ifndef _SLIDE_LINE_H_
#define _SLIDE_LINE_H_

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

#include <stdlib.h>

int slide_line(int *, size_t, int);
void slide_line_left(int *, int);
void slide_line_right(int *, int);

#endif /* _SLIDE_LINE_H_ */
