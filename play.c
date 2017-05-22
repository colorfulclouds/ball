/*************************************************************************
	> File Name: play.c
	> Author: 
	> Mail: 
	> Created Time: 2017年05月14日 星期日 16时17分30秒
 ************************************************************************/

#include<stdio.h>
#include <termios.h>

#define QUESTION "do you"

void tty_mode(int how)
{
    static struct termios original_mode;

    if( how == 0   )
        tcgetattr(0 , &original_mode);
    else
        tcsetattr(0 , TCSANOW , &original_mode);
}

int get_response(char * question)
{
    int input;

    printf("%s (y/n)?", question);

    while(1)
    {
        switch(input = getchar())
        {
            case 'y':
            case 'Y': return 0;
            case 'n':
            case 'N': 
            case EOF: return 1;

          //  default:
            //    printf("\n cannot understand %c,", input);
              //  printf("please type y or n\n");
        }
    }

}

void set_crmode()
{
    struct termios ttystate;
    tcgetattr(0 , &ttystate);

    ttystate.c_lflag &= ~ICANON;
ttystate.c_lflag &= ~ECHO; //关闭回显
    ttystate.c_cc[VMIN] =1;

    tcsetattr(0 , TCSANOW , &ttystate);

}

int main()
{
    int response;

    tty_mode(0);

    set_crmode();

    response = get_response(QUESTION);

    tty_mode(1);

    return response;

}
