#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

main()
{
        close(1);
        int fd1=open("newFile", O_CREAT|O_TRUNC|O_RDWR,0775);
        printf("%s", "EXAMPLE EXAMPLE EXAMPLE");
        for(int i=0;i<12;i++)
        {
                printf("%d",i);
        }
}
