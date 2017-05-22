/*************************************************************************
	> File Name: ticker_demo.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月21日 星期日 17时14分27秒
 ************************************************************************/

#include <stdlib.h>
#include<stdio.h>
#include <signal.h>
#include <sys/time.h>

void countdown(int sig)
{
    static int num=10;
    printf("%d..",num--);

    fflush(stdout);

    if(num<0)
    {
        printf("DONE!\n");
        exit(0);
    }
}

int set_ticker(int n_msecs)
{
    struct itimerval new_timeset;

    long n_sec,n_usecs;
    n_sec = n_msecs / 1000;
    n_usecs = (n_msecs%1000)*1000L;

    new_timeset.it_interval.tv_sec= n_sec;
    new_timeset.it_interval.tv_usec = n_usecs;

    new_timeset.it_value.tv_sec=n_sec;
    new_timeset.it_value.tv_usec = n_usecs;

    return setitimer(ITIMER_REAL , &new_timeset, NULL);
}

int main()
{
    signal(SIGALRM ,countdown);

    if(set_ticker(500) == -1)
        perror("set");
    else
        while(1)
            pause();

    return 0;
}
