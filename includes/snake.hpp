#include <ncurses.h>
#include <bits/stdc++.h>

#ifndef SNAKE_DEF 
#define SNAKE_DEF 1
class snake{
public:
    std::vector<std::pair<int,int>> body;
    int last_action_id;
    enum{
        MOVE_LEFT,
        MOVE_RIGHT,
        MOVE_UP,
        MOVE_DOWN
    };
    snake();
    void last_action();
    void move_up();
    void move_down();
    void move_left();
    void move_right();
    int is_dead();
    void render(WINDOW* win);
    void grow();
    int can_move(int movement);
};
#endif