//Програма, която взима 2 команди без аргументи от командния ред и ги изпълнява като pipe

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

main(int argc, char* argv[])
{
        if(argc<3)
        {
                printf("need more parameters");
                exit(1);
        }
        int pd[2];
        pipe(pd); //create a pipe
        int pid =fork();
        if(pid==-1)
        {
                printf("Could not fork!\n");
                exit(1);
        }

        if(pid==0) //child = writing
        {
                close(1); // close stdout
                dup(pd[1]);//пренасочваме ст. изход да отива към pipe-a
                close(pd[0]);//затваряме
                close(pd[1]);
                execlp(argv[1],argv[1],(char*)NULL);
                printf("could not execute first cmd\n");
                exit(1);
        }

        else //parent  = reading
        {
                int status;
                wait(&status);//wait for child to finish
                close(0);
                dup(pd[0]);//пренасочваме ст. вход да идва откъм pipe-a
                close(pd[1]);//затваряме
                close(pd[0]);
                execlp(argv[2],argv[2],(char*)NULL);
                printf("Could not execute second cmd\n");
                exit(1);
        }

}
