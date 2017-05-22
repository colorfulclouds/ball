/*************************************************************************
	> File Name: hello3.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月20日 星期六 22时10分40秒
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
        move(i,i+i);

        if(i%2 == 1)
            standout();

        addstr("hello world");

        if(i%2 == 1)
            standend();

       // sleep(1);
        refresh();

        sleep(1);
        move(i,i+i);
        addstr("                      ");
    }

    endwin();

    return 0;
}

