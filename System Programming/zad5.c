#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

main(int argc, char* argv[])
{
        int fdi,fdo,k,broi,i=0,status;
        char buff[40],c;
        if((fdi=open("fileA",O_RDWR))==-1)
        {
                printf("\nCannot open\n"); exit(1);
        }

        if((fdo=open(argv[1],O_CREAT|O_TRUNC|O_RDWR,0666))==-1)
        {
                printf("\n cannot open\n"); exit(1);
        }

        if(fork()==0)
        {
          k=dup(1);//save stdout
          close(1);//close stdout
          dup(fdi);
          broi=read(fdi,buff,40);
          printf("broi=%d\n",broi);
          c=buff[i++];
          printf("\nc=%s",c);
          if(c<='0'||c>='9')
          {
            while(buff[i++]!='\n'&&i<broi)
              write(1,"*",1);//write in fdi
            write(1,"\n",1); //write in fdi
            close(1);
            dup(k);//връщаме си стандартния изход
            write(1,"*\n",2);
          }

          else
          {
            write(1,buff,broi);
            close(1);
            dup(k);
            write(1,"\n",1);
          }

          write(fdo,"*\n",2);
          close(fdi);
          close(fdo);
        }

        else
        {
                wait(&status);
                close(1);
                dup(fdo);
                execlp("wc","wc","-c",argv[1],0);
        }
}
