/*************************************************************************
	> File Name: hello2.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月19日 星期五 23时26分56秒
 ************************************************************************/

#include<stdio.h>
#include <curses.h>

int main()
{
    int i;

    initscr();
    clear();

    for(i=0;i<LINES;i++)
    {

        move(i,i+1);

        if(i%2 == 1)
            standout();

        addstr("hello world");

        if(i%2 == 1)
            standend();
    }

    refresh();
    getch();
    endwin();

    return 0;
}
