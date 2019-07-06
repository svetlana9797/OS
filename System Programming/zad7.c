#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

main(int argc, char* argv[])
{
        int pid1, pid2;
        int pd[2];

        if(argc<3)
        {
                perror("argc");exit(1);
        }
        int fd=open(argv[1],O_CREAT|O_TRUNC,0777);

        if(fd==-1)
        {
                perror("fd"); exit(1);
        }

        if((pid1=fork())==-1)
        {
                perror("pid1");
                exit(1);
        }

        if(pid1>0) //parent
        {
                int status;
                wait(&status);
                execlp("mv","mv",argv[1],"/home/svetlana9797/pt2/pt3",(char*)NULL);
                perror("execlp");
                exit(1);
        }

        else //child
        {
                if(pipe(pd)==-1)
                {
                        perror("pipe"); exit(1);
                }
                if((pid2=fork())==-1)
                {
                        perror("pid2"); exit(1);
                }
                if(pid2>0)//parent2
                {
                        int status2;
                        wait(&status2);
                        close(0);
                        dup(pd[0]);
                        close(pd[0]);
                        close(pd[1]);
                        close(1);
                        dup(fd);
                        close(fd);
                        execvp(argv[3],&argv[3]);
                        perror("execvp");
                        exit(1);
                }
                if(pid2==0)//child2
                {
                        close(1);
                        dup(pd[1]);
                        close(pd[1]);
                        close(pd[0]);
                        close(fd);
                        execlp(argv[2],argv[2],(char*)NULL);
                        perror("execlp");
                        exit(1);
                }
        }
}
