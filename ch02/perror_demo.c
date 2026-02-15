// gcc perror_demo.c -o perror_demo ; ./perror_demo
#include <unistd.h>
#include <stdio.h>


void main(){
    char name[4]; /* Declare string to hold returned value */
    size_t len = 3; /* Purposely declared too small so error is revealed */
    int returnvalue;
    returnvalue = gethostname(name, len); /* Make the call */

    if (-1 == returnvalue)
        perror("gethostname");
    else
    printf("%s\n", name);
}