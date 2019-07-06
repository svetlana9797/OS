#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>

main(int argc, char* argv[])
{
        if(argc<2)
        {
                printf("Not enough arguments!!");
                exit(1);
        }

        int status;
        int pid=fork();
        if(pid>0)
        {
                waitpid(&status);
                execlp(argv[2],argv[2],NULL);
                printf("Child exit status=%d\n",status);
                int p=getpid();
                printf("Parent exit status=%d\n",p);
        }
        else
        {
                close(1);
                int fd=open("f1",O_CREAT|O_TRUNC|O_WRONLY,0775);
                execlp(argv[1],argv[1],NULL);
        }

}
