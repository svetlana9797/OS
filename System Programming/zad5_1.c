#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

main()
{
        int proc=fork();
        if(proc<0)
        {
                printf("Creation of Child process Unsuccessful!!");
                exit(-1);
        }

        if(proc==0) //child
        {
                //sleep(5);
                int pid=getpid();
                int ppid=getppid();
                printf("in child getpid,getppid -> %d, %d \n",pid,ppid);
        }
        else //parent
        {
                int pid=getpid();
                int ppid=getppid();
                printf("In parent pid, ppid ->%d,%d \n",pid,ppid);
        }

}
