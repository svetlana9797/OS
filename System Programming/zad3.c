//подава се файл като аргумент в командния ред и в него се
//Извежда инфо за процесите, в които е стартиран vi
//прехвърля се новополучения файл в директория /procinfo
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

main(int argc, char* argv[])
{
int pd[2];
int pid;
if(argc<2)
{
        perror("not enough arguments");
        exit(1);
}

int fd = open(argv[1],O_WRONLY|O_CREAT|O_TRUNC, 0775); //отваря подадения като аргумент файл
if(fd==-1)
{
        perror("file descriptor");
        exit(1);
}

if(pipe(pd)==-1)
{
        perror("pipe");
        exit(1);
}

pid=fork();
if(pid==-1)
{
        perror("fork");
        exit(1);
}

if(pid==0) //child
{
        if(pipe(pd)==-1)//в детето правим pipe-a и там извършваме записа във файл,а в родителя местим файла
        {
                perror("pipe");
                exit(1);
        }

        int pid2=fork();

        if(pid2==-1)
        {
                perror("pid2");
                exit(1);
        }

        if(pid2==0) //дете2 взима всички процеси
        {
         close(1);
         dup(pd[1]);
         close(pd[1]);
         close(pd[0]);
         close(fd);
         execlp("ps","ps","aux",(char*)NULL);
         perror("error");
         exit(1);
        }

       else //родител2 взима всички процеси, в които е стартирал vi
        {
         int status; //чакаме детето да приключи работа
         wait(&status);
         close(0);//пренасочваме входа откъм pipe-a да идва
         dup(pd[0]);
         close(pd[0]);//затваряме ненужното
         close(pd[1]);
         close(1);//пренасочваме ст. изход към файла
         dup(fd);
         close(fd);
         execlp("grep","grep","vi",(char*)NULL);
         perror("error");
         exit(1);
        }
}

else //pid>0  parent
{
        int status;
        wait(&status);//чакаме детето да свърши
        execlp("mv","mv",argv[1],"/home/svetlana9797/pt2/pt3",(char*)NULL);
        perror("error");
        exit(1);

}
}
