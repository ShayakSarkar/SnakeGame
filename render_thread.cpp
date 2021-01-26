#include <bits/stdc++.h>
#include "./includes/snake.hpp"
#include "./includes/food.hpp"
#include <ncurses.h>

void setup_win(WINDOW *win,int r,int c){
    for(int i=0;i<r+1;i++){
        wmove(win,c,i);
        waddstr(win,"#");
        wmove(win,0,i);
        waddstr(win,"#");
    }
    for(int i=0;i<c+1;i++){
        wmove(win,i,0);
        waddstr(win,"#");
        wmove(win,i,r);
        waddstr(win,"#");
    }
    wrefresh(win);
}

void render_thread_action(snake& snk,food& fd,WINDOW* win,std::queue<int>& key_buffer,int& should_terminate){
    while(true){
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        wclear(win);
        if(key_buffer.size()==0){
            snk.last_action();
            if(snk.is_dead()){
                should_terminate=true;
                return;
            }
            if(snk.body[0].first==fd.r && snk.body[0].second==fd.c){
                fd.respawn(snk.body);
                snk.grow();
            }
            setup_win(win,30,20);
            snk.render(win);
            fd.render(win);
        }
        else{
            int key=key_buffer.front();
            key_buffer.pop();
            if(key=='w' || key=='W'){
                if(snk.can_move(snk.MOVE_UP)){
                    snk.move_up();
                }
                else{
                    snk.last_action();
                }
                if(snk.is_dead()){
                    should_terminate=true;
                    return;
                }
                if(snk.body[0].first==fd.r && snk.body[0].second==fd.c){
                    std::vector<std::pair<int,int>> points;
                    for(auto& pt : snk.body){
                        points.push_back(pt);
                    }
                    fd.respawn(points);
                    snk.grow();
                }
                setup_win(win,30,20);
                snk.render(win);
                fd.render(win);
            }
            else if(key=='a' || key=='A'){
                if(snk.can_move(snk.MOVE_LEFT)){
                    snk.move_left();
                }
                else{
                    snk.last_action();
                }
                if(snk.is_dead()){
                    should_terminate=true;
                    return;
                }
                if(snk.body[0].first==fd.r && snk.body[0].second==fd.c){
                    std::vector<std::pair<int,int>> points;
                    for(auto& pt : snk.body){
                        points.push_back(pt);
                    }
                    fd.respawn(points);
                    snk.grow();
                }
                setup_win(win,30,20);
                snk.render(win);
                fd.render(win);
            } 
            else if(key=='d' || key=='D'){
                if(snk.can_move(snk.MOVE_RIGHT)){
                    snk.move_right();
                }
                else{
                    snk.last_action();
                }
                if(snk.is_dead()){
                    should_terminate=true;
                    return;
                }
                if(snk.body[0].first==fd.r && snk.body[0].second==fd.c){
                    std::vector<std::pair<int,int>> points;
                    for(auto& pt : snk.body){
                        points.push_back(pt);
                    }
                    fd.respawn(points);
                    snk.grow();
                }
                setup_win(win,30,20);
                snk.render(win);
                fd.render(win);
            }
            else if(key=='s' || key=='S'){
                if(snk.can_move(snk.MOVE_DOWN)){
                    snk.move_down();
                }
                else{
                    snk.last_action();
                }
                if(snk.is_dead()){
                    should_terminate=true;
                    return;
                }
                if(snk.body[0].first==fd.r && snk.body[0].second==fd.c){
                    std::vector<std::pair<int,int>> points;
                    for(auto& pt : snk.body){
                        points.push_back(pt);
                    }
                    fd.respawn(points);
                    snk.grow();
                }
                setup_win(win,30,20);
                snk.render(win);
                fd.render(win);
            }
            else if(key=='q' || key=='Q'){
                should_terminate=true;
                return;
            }
        }
    }
}
