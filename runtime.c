#include "runtime.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void runtime_fmt(char *fmt, va_list);

void runtime_panic(int code, char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    puts("Runtime panicked: ");

    runtime_fmt(fmt, args);

    exit(code);
}

void runtime_warn(char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    puts("Warning: ");

    runtime_fmt(fmt, args);
}

void runtime_fmt(char *fmt, va_list list) {
    char *p, *sval;

    for (p = fmt; *p; ++p) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }

        switch(*(++p)) {
            case 'd':
                printf("%d", va_arg(list, int));
                break;
            case 's':
                for (sval = va_arg(list, char *); *sval; ++sval)
                    putchar(*sval);
                break;
            case 'c':
                putchar(va_arg(list, int));
                break;
        }
    }
    putchar('\n');
}
