/*************************************************************************
	> File Name: echo.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月13日 星期六 21时22分20秒
 ************************************************************************/
#include<stdio.h>
#include <termios.h>
#include <stdlib.h>
int main()
{
    struct termios info;
    int rv;
    rv = tcgetattr(0 , &info);
    if( rv == -1)
    {
        perror("ff");
        exit(EXIT_FAILURE);
    }
    if(info.c_lflag & ECHO)
        printf("echo on\n");
    else
        printf("echo off\n");
    return 0;
}
