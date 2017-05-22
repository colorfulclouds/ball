/*************************************************************************
	> File Name: hello5.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月20日 星期六 22时20分21秒
 ************************************************************************/

#include<stdio.h>
#include <curses.h>

#define LEFTEDGE 10
#define RIGHTEDGE 30
#define ROW 10

int main()
{
    char *message="hello";
    char *blank="      ";
    int die=+1;
    int pos = LEFTEDGE;

    initscr();
    clear();

    while(1)
    {

        move(ROW,pos);
        addstr(message);

        move(LINES-1,COLS-1);
        refresh();
        //sleep(1);
       usleep(50000);
        move(ROW , pos);
        addstr(blank);

        pos+=die;

        if(pos>=RIGHTEDGE)
            die -=1;

        if(pos<=LEFTEDGE)
            die +=1;
    }

    return 0;
}
