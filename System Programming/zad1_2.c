// подаваме името на файл като аргумент и четем от него
//извеждаме броя байтове
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

main(int argc, char *argv[])
{
        char buffer[10];
        int fd=open(argv[1],O_RDONLY);

        if(fd==-1)
        {
                printf("Cannot open file!!");
                exit(-1);
        }

        int i=0;
        while(read(fd,buffer,1))
        {
                i++;
        }
        printf("%d",i);
        //lseek(fd,5,SEEK_CUR);
        //read(fd,buffer,10);
        //write(1,buffer,10);

        close(fd);

return 0;
}
