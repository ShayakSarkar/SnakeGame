#include "./includes/food.hpp"

void food::respawn(std::vector<std::pair<int,int>>& invalid){
    while(true){
        c=random()%COLS;
        r=random()%ROWS;
        int should_break_outer=true;
        for(auto& pt : invalid){
            if((pt.first==r && pt.second==c) || r==30 || r==0 || c==20 || c==0){
                should_break_outer=false;
                break;
            }
        }
        if(should_break_outer){
            break;
        }
    }
}

void food::render(WINDOW *win){
    wmove(win,c,r);
    wrefresh(win);
    waddstr(win,"@");
    wrefresh(win);
}

food::food(int rows,int cols){
    this->ROWS=rows;
    this->COLS=cols;
    r=5;
    c=5;
}
