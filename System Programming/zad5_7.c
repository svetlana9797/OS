#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

main(int argc, char* argv[])
{
        for(int i=0;i<5;i++)
        {
                execlp("ls","ls","-l",0);//if we have a cycle exec is called only one time
        }
}
