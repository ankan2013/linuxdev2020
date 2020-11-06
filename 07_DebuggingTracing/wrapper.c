#define _GNU_SOURCE
#include <dlfcn.h>
#include <errno.h>
#include <string.h>

int unlinkat(int dirfd, const char *pathname, int flags)
{
    typeof(&unlinkat) orig_func = dlsym(RTLD_NEXT, "unlinkat");

    if (strstr(pathname, "FIX") != 0){
        return EPERM;
    }

    return orig_func(dirfd, pathname, flags);
}
