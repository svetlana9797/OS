#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

main()
{
        int pid=fork();
        if(pid==0) //child
        {
                int pid2=fork();
                int c1,c2;
                c1=getpid();
                c2=getppid();
                printf("getchild pid, ppid->%d,%d\n",c1,c2);
        }
        if(pid>0)
        {
                int p1=getpid();
                int p2=getppid();
                printf("getpid,getppid->%d,%d\n",p1,p2);
        }
}
