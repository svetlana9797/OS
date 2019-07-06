//Програма изпълняваща whoami|wc -c
//
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

main(int argc, char* argv)
{
        int pd[2];
        pipe(pd);
        int pid=fork();
        if(pid==-1)
        {
                perror("pipe");
                exit(1);
        }
        if(pid==0) //child
        {
                close(0); //close stdin
                dup(pd[0]); //pd[0] is for reading from the pipe
                close(pd[0]);
                close(pd[1]); //we do not need pd[1] so we close it
                execlp("wc","wc","-c",0);

        }
        else //parent
        {
                close(1); // close stdout
                dup(pd[1]); //pd[1] is for writing to the pipe          close(pd[1]);
                close(pd[0]); //we do not need pd[0] so we close it
                execlp("whoami","whoami",0);
        }
}
