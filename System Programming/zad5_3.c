#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

main()
{
        int status;
        printf("startng with i=0\n"); // the actions before the fork are executed only once
        int i=0;
        int pid=fork();//all the actions after the fork() are shared
        i++;

        if(pid<0)
        {
                printf("Cannnot open child process!!");
                exit(-1);
        }

        if(pid==0) //child
        {
                i--;
                printf("child %d\n",i);
        }

        else
        {
                waitpid(pid,&status,0);
                i++;
                printf("parent %d\n",i);
        }
        printf("i=%d\n",i);
}
