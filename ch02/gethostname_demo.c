// gcc gethostname_demo.c -o gethostname_demo ; ./gethostname_demo
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

void main(){
    char name[4]; /* Declare string to hold return value */
    size_t len = 3; /* Purposely too small to generate error */
    int returnvalue;

    returnvalue = gethostname(name, len); /* make the call */
    if(-1 == returnvalue){
        switch(errno){
            case EFAULT:
                printf("A bad address was passed for the string name\n");break;
            case EINVAL:
                printf("The length argument was neative.\n");
            case ENAMETOOLONG:
                printf("The hostname is too long for the allocated array.\n");
        }
    }
    else
        printf("%s\n", name);
}