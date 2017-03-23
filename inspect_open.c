#define _GNU_SOURCE
#include <stdio.h>
#include <dlfcn.h>

typedef int (*orig_open_f_type)(const char *pathname, int flags);

int open(const char *pathname, int flags, ...)
{
   /* Some evil injected code goes here. */
   printf("The victim used open(...) to access '%s'!!!\n", pathname);

   orig_open_f_type orig_open;
   orig_open = (orig_open_f_type)dlsym(RTLD_NEXT,"open");
   return orig_open(pathname,flags);
}
