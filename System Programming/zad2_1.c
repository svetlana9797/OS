//3 дескриптора как се движат във файла-независимо 1 от друг
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

main()
{
        char buffer[16];
        int fd1=open("ff",O_RDONLY|O_CREAT,0775);
        int fd2=open("ff",O_WRONLY);
        int fd3=open("ff",O_RDWR);

        write(fd2,"hello world",11);
        read(fd3,buffer,6);
        write(1,buffer,6);

        read(fd1,buffer,5);
        write(1,buffer,5);

        write(fd3,"chil",4);
        write(fd2,"bro",3);

        read(fd1,buffer,9);
        write(1,buffer,9);
        close(fd1);
        close(fd2);
        close(fd3);

        return 0;
}
