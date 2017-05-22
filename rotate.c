/*************************************************************************
	> File Name: rotate.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月13日 星期六 22时42分42秒
 ************************************************************************/

#include<stdio.h>
#include <ctype.h>

int main()
{
    int c;
    while( (c=getchar()) != EOF )
    {
        if(c == 'z')
            c='a';
        else
            if(islower(c))
                c++;

        putchar(c);
    }

    return 0;
}
