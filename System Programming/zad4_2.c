#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

main()
{
        int fd2=open("newFile2",O_CREAT|O_TRUNC|O_RDWR,0775);
        close(1);
        dup(fd2);
        write(1,"12345678",8);

        for(int i=0;i<5;i++)
        {
                printf("%d",i);
        }
}
