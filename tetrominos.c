//gcc -o tetris tetrominos.c -lncurses;./tetris
//directly inspires by Tetris on NES
//few subtle changes like missing features, improved piece randomization, and altered rotation logic

#include <ncurses.h>
#include <unistd.h>

void titleScreen();
void initColors();

#define DELAY 50000

int main() {
    int ch;

    //Init ncurses
    initscr();              //Start curses mode
    initColors();           //Create color array
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

    const char* lines[] = {
        "  ______    _ _ _",
        " |  ____|  | | (_)",
        " | |__ __ _| | |_ _ __   __ _",
        " |  __/ _` | | | | '_ \\ / _` |",
        " | | | (_| | | | | | | | (_| |",
        " |_|__\\__,_|_|_|_|_| |_|\\__, |      _",
        " |__   __| | |           __/ |     (_)",
        "    | | ___| |_ _ __ ___|___/_ ___  _ _ __   ___  ___",
        "    | |/ _ \\ __| '__/ _ \\| '_ ` _ \\| | '_ \\ / _ \\/ __|",
        "    | |  __/ |_| | | (_) | | | | | | | | | | (_) \\__ \\",
        "    |_|\\___|\\__|_|  \\___/|_| |_| |_|_|_| |_|\\___/|___/",
        "",
        "Use wasd to move",
        "Use , and . to rotate ccw and cw respectively",
        "",
        "Press k or l to pause",
        "Press any gameplay button to start..."
    };

    int num_lines = sizeof(lines) / sizeof(lines[0]);

    while (1) {

        for (int i = 0; i < num_lines; i++) {
            if (lines[i][0] != '\0') {
                if(i<=10)
                    attron(COLOR_PAIR((i % 7) + 1)); // cycle through color pairs 1–7
                mvprintw(i + 1, 1, "%s", lines[i]);
                if(i<=10)
                    attroff(COLOR_PAIR((i % 7) + 1));
            }
        }

        refresh();
        ch = getch();
        if (ch == KEY_LEFT || ch == KEY_RIGHT || ch == KEY_DOWN || ch == KEY_UP)
            break;
        
        usleep(DELAY);
    }
}

void initColors() {
    start_color();          //Start color mode
    use_default_colors();   //For transparency
    init_pair(1, COLOR_RED,     -1);
    init_pair(2, COLOR_GREEN,   -1);
    init_pair(3, COLOR_YELLOW,  -1);
    init_pair(4, COLOR_BLUE,    -1);
    init_pair(5, COLOR_MAGENTA, -1);
    init_pair(6, COLOR_CYAN,    -1);
    init_pair(7, COLOR_WHITE,   -1);
}