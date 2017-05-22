/*************************************************************************
	> File Name: sleep.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月20日 星期六 22时36分17秒
 ************************************************************************/

#include<stdio.h>
#include <signal.h>


void wakeup(int sig)
{
    #ifndef SHHHH
        printf("this SIGALRM\n");
    #endif
}

int main()
{
    printf("sleep 4s\n");
    signal(SIGALRM , wakeup);

    alarm(4);
 //   pause();

    printf("soon\n");

    return 0;
}
