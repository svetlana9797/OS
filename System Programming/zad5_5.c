#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

main(int argc,char* argv[])
{
        if(argc<2)
        {
                printf("not enough arguments!\n");
                exit(1);
        }
        close(1);
        int fd2=open(argv[1],O_WRONLY);

        int fd1=open("abc",O_CREAT|O_RDWR,0775);
        int pid=fork();

        if(pid==0)//child
        {
                //write(fd1,"HELLO",5);
                printf("its mee!\n");
        }

        if(pid>0)
        {
        //      close(1);
         //     int fd2=open(argv[1],O_WRONLY);
                printf("heloooo\n");

                //write(fd1,"hello",5);
        }
        close(fd1);
}
