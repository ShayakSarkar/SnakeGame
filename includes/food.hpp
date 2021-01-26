#include <bits/stdc++.h>
#include <ncurses.h>

#ifndef food

class food{
public:
    int r,c;
    int ROWS;
    int COLS;
    food(int rows,int cols);
    void respawn(std::vector<std::pair<int,int>>& invalid);
    void render(WINDOW *win);
};

#endif