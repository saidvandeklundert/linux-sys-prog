// gcc glibc_info.c -o glibc_info ; ./glibc_info
#include <stdio.h>
#include <gnu/libc-version.h>

int main() {
    printf("The version of glibc is %s.\n", gnu_get_libc_version());
    return 0;
}