#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

main(int argc, char* argv[])
{
        if(argc<3)
        {
                printf("Not enough arguments!!");
                exit(-1);
        }

        close(0);
        int fd1=open(argv[1],O_RDWR);//stdin

        close(1);
        int fd2=open(argv[2],O_WRONLY|O_APPEND);//stdout

        char buffer[100];
        read(0, buffer,10);//read 10 bytes from stdin(=fd1) and save them in the buffer
        write(1,buffer,10);
        printf("finished");

}
