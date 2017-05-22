/*************************************************************************
	> File Name: sigdemo3.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月21日 星期日 21时20分44秒
 ************************************************************************/

#include<stdio.h>
#include <signal.h>
#define INPUTLEN 100

void inthandler(int s)
{
    printf("receied signal %d ..waiting\n", s);
    sleep(2);

    printf("leaving inthandler\n");
}

void quithandler(int s)
{
    printf("recevied signal %d waaaaaa\n", s);

    sleep(3);

    printf("leaving quithandler\n");
}

int main()
{
    char input[INPUTLEN];
    int nchars;

    signal(SIGINT , inthandler);
    signal(SIGQUIT , quithandler);

    do
    {
        printf("\ntype a meeage\n");
        nchars = read(0,input,INPUTLEN-1);

        if(nchars == -1)
            perror("read return error");
        else
        {
            input[nchars]='\0';
            printf("your typed:%s", input);
        }
    }
    while( strncmp(input, "quit",4) != 0 );

    return 0;
}
