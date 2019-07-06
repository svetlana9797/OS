//3 дескриптора как се движат по файла
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

main()
{
        int fd1=open("ff",O_RDONLY|O_TRUNC);
        int fd2=open("ff",O_WRONLY);
        int fd3=open("ff",O_RDWR);
        char buffer[16];

        write(fd3,"hello",5);
        write(fd2,"worlds",5);

        read(fd1,buffer,6);
        write(1,buffer,6);
        close(fd2);
        write(fd3,"oops",4);
        read(fd1,buffer,6);
        write(1,buffer,6);

        close(fd1);
        close(fd2);
        return 0;
}
