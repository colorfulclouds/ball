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
    printf("called with signal %d\n", s);
    sleep(2);

    printf("done handling signal %d\n", s);
}


int main()
{
    struct sigaction newhandler;
    sigset_t blocked;
    char x[INPUTLEN];

    newhandler.sa_flags = SA_RESETHAND | SA_RESTART;

    sigemptyset(&blocked);
    sigaddset(&blocked , SIGQUIT);
    newhandler.sa_mask = blocked;

    if(sigaction(SIGINT , &newhandler , NULL) == -1)
    {
        perror("sigaction");
    }
    else
    {
        while(1)
        {
            fgets(x,INPUTLEN,stdin);
            printf("input :%s", x);
        }
    }
    return 0;
}
