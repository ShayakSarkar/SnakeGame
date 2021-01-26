#include <ncurses.h>
#include <bits/stdc++.h>
#include "./includes/snake.hpp"
#include "./includes/food.hpp"
#include "./includes/input_thread.hpp"
#include "./includes/render_thread.hpp"

int main(){
    const int ROWS=43;
    const int COLS=166;
    std::queue<int> key_buffer;
    initscr();
    curs_set(0);
    cbreak();
    noecho();

    WINDOW* win=newwin(ROWS,COLS,0,0);
    int should_terminate=false;
    snake snk;
    food fd{30,20};
    std::thread input_thread(input_thread_action,std::ref(key_buffer),std::ref(should_terminate));
    std::thread render_thread(render_thread_action,std::ref(snk),std::ref(fd),win,std::ref(key_buffer),std::ref(should_terminate));

    input_thread.join();
    render_thread.join();

    std::cout<<"driver.cpp(main):press any key to terminate..."<<std::endl;
    curs_set(1);
}
