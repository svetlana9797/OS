#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

main()
{
        printf("shared actions0\n");
        int proc=fork();
        int status;
        printf("shared actions1\n");

        if(proc==0)
        {
                printf("child actions\n");
        }
        if(proc>0)
        {
                waitpid(proc,&status,0);
                printf("parent actions\n");
        }
        printf("shared actions2\n");
}
