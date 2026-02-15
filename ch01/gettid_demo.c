// gcc gettid_demo.c -o gettid_demo
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>

int main() {
    printf("I am a thread with thread ID %ld\n", syscall(SYS_gettid));
    return 0;
}