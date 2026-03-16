#include "head.h"
#include "utils.h"

void print_error(char *str, ...)
{
    va_list ap;
    char buf[200];
    va_start(ap, str);
    vsnprintf(buf, 200, str, ap);

    va_end(ap);

    perror(buf);
}
