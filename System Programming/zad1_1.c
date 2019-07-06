#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

main()
{
        char buffer[10];
        int fd=open("aa",O_RDONLY);
        for(int i=5;i>0;i--)
        {
                read(fd,buffer,i);
                //printf("%s\n", buffer);
                //write(1,buffer,i);
                printf("%s\n",buffer);
        }
        close(fd);
        return 0;
}
