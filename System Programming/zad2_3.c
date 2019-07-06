#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

main()
{
        int fd1=open("fff",O_RDONLY);
        int fd2=open("fff",O_WRONLY);
        char buffer[30];

        lseek(fd2,-2,SEEK_END);
        write(fd2,"xywz",5);

        lseek(fd2,5,SEEK_SET);
        write(fd2,"12",2);

        while(fd1!=NULL)
                {
                  read(fd1,buffer,1);
                  write(1,buffer,1);
                }

        close(fd1);
        close(fd2);
        return 0;
}
