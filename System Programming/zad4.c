//Получаваме от командния ред 2 команди- първата е без параметри, втората е със
//и ги изпълняваме едновременно
//връщаме кода на завършване на всяка от командите
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

void main(int argc, char* argv[])
{
        if(argc<3)
        {
                perror("argc");
                exit(1);
        }

        int pid1;
        int pid2;
        pid1=fork();

        if(pid1==-1)
        {
                perror("pid1");
                exit(1);
        }

        if(pid1>0) //parent
        {
                int status1;
                int status2;
                pid2=fork();//стартираме втория процес
                if(pid2>0)//родител2
                {
                  waitpid(pid1,&status1,0);//изчакваме процесите да завършат
                  waitpid(pid2,&status2,0);
                  printf("Status1=%d, Status2=%d", status1, status2);
                  exit(0);//програмата завършва с успех
                }
                if(pid2==0)//дете2
                {
                        execlp(argv[1],argv[1],(char*)NULL);
                        perror("first cmd");
                        exit(1);
                }
        }

        else //child
        {
                execvp(argv[2],&argv[2]); //втората команда е с параметри и ги подаваме като втори аргумент на execvp
                perror("second cmd");
                exit(1);
        }
}
