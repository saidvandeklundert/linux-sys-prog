// gcc getenv_demo.c -o getenv_demo
#include <stdio.h>
#include <stdlib.h>

void main() {
    char *shell = getenv("SHELL");
    printf("The current shell is %s.\n", shell);

    char *logname = getenv("LOGNAME");
    printf("Currently logged in as %s.\n", logname);    
}