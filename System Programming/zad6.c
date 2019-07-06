#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

main(int argc, char* argv[])
{
        int pd[2];
        if(argc<3)
        {
                perror("argc"); exit(1);
        }

        if(pipe(pd)==-1)
        {
                perror("pipe"); exit(1);
        }
        int pid = fork();

        if(pid==-1)
        {
                perror("fork"); exit(1);
        }

        if(pid==0) //child
        {
                close(1);
                dup(pd[1]);//stdout=pd[1]
                close(pd[1]);
                close(pd[0]);
                execlp(argv[1],argv[1],(char*)NULL);
                perror("execlp"); exit(1);

        }

        else //parent
        {
                int status;
                wait(&status);
                close(0);
                dup(pd[0]);
                close(pd[0]);
                close(pd[1]);
                execvp(argv[2],&argv[2]);
                perror("execvp"); exit(1);
        }
}
