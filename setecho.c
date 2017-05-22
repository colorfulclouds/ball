/*************************************************************************
	> File Name: setecho.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月13日 星期六 21时32分16秒
 ************************************************************************/

#include<stdio.h>
#include <termios.h>
#include <stdlib.h>

#define oops(s,x) {perror(s);exit(x);}

int main( int ac , char *av[] )
{
    struct termios info;
    
    if(ac == 1)
        exit(EXIT_FAILURE);

    if( tcgetattr(0 , &info) == -1) 
      oops("get" , 1);

    if( av[1][0] =='y' )
       info.c_lflag |= ECHO;
    else
       info.c_lflag &= ~ECHO;

    if( tcsetattr(0, TCSANOW,&info) == -1 )
       oops("set" , 2);
    return 0;
}
