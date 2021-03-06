#include <bits/stdc++.h>
#include "./includes/snake.hpp"
#include "./includes/food.hpp"
#include "./includes/array_queue.hpp"
#include <ncurses.h>

void setup_win(WINDOW *win,int r,int c){
    for(int i=0;i<r+1;i++){
        wmove(win,c,i);
        waddstr(win,"|");
        wmove(win,0,i);
        waddstr(win,"|");
    }
    for(int i=0;i<c+1;i++){
        wmove(win,i,0);
        waddstr(win,"=");
        wmove(win,i,r);
        waddstr(win,"=");
    }
    wrefresh(win);
}

void render_thread_action(snake& snk,food& fd,WINDOW* win,array_queue& key_buffer,int& should_terminate){
    int score=0;
    int sleep_updated=false;
    int sleep_time=250;  //indicative of the level;
    while(true){
        if(score%10==0 && !sleep_updated){
            sleep_time-=50;
            sleep_updated=true;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
        wclear(win);
        setup_win(win,30,20);
        wmove(win,10,40);
        wrefresh(win);
        waddstr(win,"Score\n");
        wmove(win,11,40);
        waddstr(win,std::to_string(score).c_str());
        wmove(win,13,40);
        std::string level_string="Level: ";
        level_string+=std::to_string((score/10)+1);
        waddstr(win,level_string.c_str());
        wrefresh(win);
        if(key_buffer.filled==0){
            snk.last_action();
            if(snk.is_dead()){
                should_terminate=true;
                return;
            }
            if(snk.body[0].first==fd.r && snk.body[0].second==fd.c){
                fd.respawn(snk.body);
                snk.grow();
                score++;
                sleep_updated=false;
            }
            snk.render(win);
            fd.render(win);
        }
        else{
            int key=key_buffer.dequeue();
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
                    score++;
                    sleep_updated=false;
                }
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
                    score++;
                    sleep_updated=false;
                }
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
                    score++;
                    sleep_updated=false;
                }
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
                    score++;
                    sleep_updated=false;
                }
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
