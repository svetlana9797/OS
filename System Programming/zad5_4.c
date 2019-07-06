#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
main()
{
        int i=0;
        int pid=fork();
        i++;
        if(pid==0) //child
        {
                i--;
                printf("child\n");
                exit(1);
        }
        if(pid>0) //parent
        {

                i++;
                printf("parent\n");
                exit(1);
        }
        printf("i=%d\n",i);
}
