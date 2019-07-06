//redirect standard output to file
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

main(int argc, char *argv[])
{
        int sout=dup(1); //save the value of the stdout
        int fd1=open("testFile1",O_CREAT|O_APPEND|O_WRONLY,0775);
        close(1); //close the standard output stream->does not close the copy
        dup(fd1);//copy fd1 -> the copy takes the lowest available value for an ID which is 1
        write(1,"example text!!",12); //fd1 and it's copy share file offset and status flag

        for(int i=0;i<=10;i++)
        {
                printf("--sometext--"); //printf prints in stdout = the copy which did not close
                printf("%d",i);
                printf("\n");
        }

        char buffer[10];
        int fd2=open("testFile1",O_RDONLY);
        read(fd2,buffer,10);//read the first 10 bytes from testFile1
        write(1,buffer,10);//and print them on the standard output(=testFile1)
        close(fd1);//closes the original fd1. the copy does not close
        close(1);//closes 1=copy of fd1
        dup(sout);
        printf("something");//prints it on the screen
        close(sout);

}
