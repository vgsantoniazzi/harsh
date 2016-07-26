#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tools/debug.h"

#define COPY(d,s,a) memcpy(d, s, a)

#define STDIN 0

#define MAXLOOK 16
#define MAXLEX 1024
#define BUFSIZE ((3 * MAXLEX)+(2 * MAXLOOK))
#define DANGER ( _end_buf - MAXLOOK )
#define END (&_start_buf[BUFSIZE])
#define NO_MORE_CHARS() (_eof_read && _next >= _end_buf)

typedef unsigned char uchar;

PRIVATE uchar _start_buf[BUFSIZE];
PRIVATE uchar *_end_buf = END;
PRIVATE uchar *_next  = END;
PRIVATE uchar *_s_mark = END;
PRIVATE uchar *_e_mark = END;
PRIVATE uchar *p_mark = NULL;
PRIVATE int _p_line_number = 0;
PRIVATE int _p_length = 0;

PRIVATE int _input_file = STDIN;
PRIVATE int _line_number = 1;
PRIVATE int _mark_line = 1;
PRIVATE int _termchar = 0;

PRIVATE int _eof_read = 0;

extern int close(), read(), open();

PRIVATE int (*_open_p)() = open;
PRIVATE int (*_close_p)() = close;
PRIVATE int (*_read_p) () = read;
