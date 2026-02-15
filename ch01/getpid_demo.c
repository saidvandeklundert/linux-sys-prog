// gcc getpid_demo.c -o getpid_demo
#include <stdio.h>
#include <unistd.h>

void main() {
    printf("I am the process with process-id %d\n", getpid());
}