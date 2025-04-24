//gcc -o tetris tetrominos.c -lncurses;./tetris

#include <ncurses.h>
#include <unistd.h>

void titleScreen();

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

    titleScreen();

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


void titleScreen(){
    int ch;

    while (1) {
        clear();
        mvprintw(1,1, "  ______    _ _ _");
        mvprintw(2,1, " |  ____|  | | (_)");
        mvprintw(3,1, " | |__ __ _| | |_ _ __   __ _");
        mvprintw(4,1, " |  __/ _` | | | | '_ \\ / _` |");
        mvprintw(5,1, " | | | (_| | | | | | | | (_| |");
        mvprintw(6,1," |_|__\\__,_|_|_|_|_| |_|\\__, |      _");
        mvprintw(7,1, " |__   __| | |           __/ |     (_)");
        mvprintw(8,1, "    | | ___| |_ _ __ ___|___/_ ___  _ _ __   ___  ___");
        mvprintw(9,1, "    | |/ _ \\ __| '__/ _ \\| '_ ` _ \\| | '_ \\ / _ \\/ __|");
        mvprintw(10,1, "    | |  __/ |_| | | (_) | | | | | | | | | | (_) \\__ \\");
        mvprintw(11,1, "    |_|\\___|\\__|_|  \\___/|_| |_| |_|_|_| |_|\\___/|___/");
        mvprintw(13,1, "Use wasd to move");
        mvprintw(14,1, "Use , and . to rotate ccw and cw respectively");
        mvprintw(16,1, "Press k or l to pause");
        mvprintw(17,1, "Press any gameplay button to start...");

        refresh();
        ch = getch();
        if (ch == KEY_LEFT || ch == KEY_RIGHT || ch == KEY_DOWN || ch == KEY_UP)
            break;
        
        usleep(DELAY);
    }
}