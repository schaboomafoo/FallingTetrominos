//gcc -o tetris tetrominos.c -lncurses;./tetris

#include <ncurses.h>
#include <unistd.h>

#define DELAY 50000

int main() {
    int ch;

    //Init ncurses
    initscr();              //Start curses mode
    noecho();               //Don't echo input chars
    cbreak();               //Disable line buffering
    curs_set(FALSE);        //Hide the cursor
    keypad(stdscr, TRUE);   //Enable arrow keys
    nodelay(stdscr, TRUE);  //Non-blocking getch()

    //Game state variables
    int x = 10, y = 5;

    while (1) {
        clear(); //Clear screen for next frame

        //Draw
        mvprintw(y, x, ":D\nD:");

        refresh(); //Refresh screen

        ch = getch(); //Get key press

        switch (ch) {
            case 'q':
                endwin();
                return 0;
            case KEY_LEFT:
                x--;
                break;
            case KEY_RIGHT:
                x++;
                break;
            case KEY_DOWN:
                y++;
                break;
            case KEY_UP:
                y--;
                break;
        }

        usleep(DELAY); //Delay between frames
    }

    endwin(); //End curses mode
    return 0;
}