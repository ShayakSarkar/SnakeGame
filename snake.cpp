#include <bits/stdc++.h>
#include <ncurses.h>
#include "./includes/snake.hpp"

snake::snake(){
    std::pair<int,int> pos1{5,5};
    std::pair<int,int> pos2{5,5};
    std::pair<int,int> pos3{5,5};
    std::pair<int,int> pos4{5,5};
    last_action_id=MOVE_RIGHT;
    body.push_back(std::move(pos1));
    body.push_back(std::move(pos2));
    body.push_back(std::move(pos3));
    body.push_back(std::move(pos4));
}
int snake::can_move(int movement){
    if(last_action_id==MOVE_DOWN && movement==MOVE_UP){
        return false;
    }
    if(last_action_id==MOVE_UP && movement==MOVE_DOWN){
        return false;
    }
    if(last_action_id==MOVE_LEFT && movement==MOVE_RIGHT){
        return false;
    }
    if(last_action_id==MOVE_RIGHT && movement==MOVE_LEFT){
        return false;
    }
    return true;
}

int snake::is_dead(){
    for(int i=1;i<body.size();i++){
        if(body[0]==body[i]){
            return true;
        }
    }
    if(body[0].first==30 || body[0].first==0 || body[0].second==20 || body[0].second==0){
        return true;
    }
    return false;
}

void snake::move_up(){
    int tail=body.size()-1;
    int head=0;
    for(int i=tail;i>head;i--){
        body[i]=std::move(body[i-1]);
    }
    int first=body[head+1].first;
    int second=body[head+1].second-1;
    body[head]=std::make_pair<int,int>(first+0,second+0);
    last_action_id=MOVE_UP;
}

void snake::move_down(){
    int tail=body.size()-1;
    int head=0;
    for(int i=tail;i>head;i--){
        body[i]=std::move(body[i-1]);
    }
    int first=body[head+1].first;
    int second=body[head+1].second+1;
    body[head]=std::move(std::make_pair<int,int>(first+0,second+0));
    last_action_id=MOVE_DOWN;
}

void snake::move_left(){
    int tail=body.size()-1;
    int head=0;
    for(int i=tail;i>head;i--){
        body[i]=std::move(body[i-1]);
    }
    int first=body[head+1].first-1;
    int second=body[head+1].second;
    body[head]=std::make_pair<int,int>(first+0,second+0);
    last_action_id=MOVE_LEFT;
}

void snake::move_right(){
    int tail=body.size()-1;
    int head=0;
    for(int i=tail;i>head;i--){
        body[i]=std::move(body[i-1]);
    }
    int first=body[head+1].first+1;
    int second=body[head+1].second;
    body[head]=std::make_pair<int,int>(first+0,second+0);
    last_action_id=MOVE_RIGHT;
}

void snake::render(WINDOW* win){
    for(auto& pos : body){
        wmove(win,pos.second,pos.first);
        wrefresh(win);
        waddstr(win,"#");
        wrefresh(win);    
    }
    wmove(win,body[0].second,body[0].first);
    wrefresh(win);
    waddstr(win,"O");
    wrefresh(win);
}

void snake::grow(){
    int first=body[body.size()-1].first;
    int second=body[body.size()-1].second;
    body.push_back(std::make_pair<int,int>(first+0,second+0));
}

void snake::last_action(){
    switch(last_action_id){
        case MOVE_UP:
            move_up();
            break;
        case MOVE_DOWN:
            move_down();
            break;
        case MOVE_LEFT:
            move_left();
            break;
        case MOVE_RIGHT:
            move_right();
            break;
        default:
            std::cout<<"snake.cpp(snake::last_action):error in snake movement"<<std::endl;
    }
}
