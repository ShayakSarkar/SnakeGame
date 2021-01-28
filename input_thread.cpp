#include <bits/stdc++.h>
#include <ncurses.h>
#include "./includes/array_queue.hpp"

static int is_useful(int ch,std::unordered_set<int>& useful_keys){
    if(useful_keys.find(ch)!=useful_keys.end()){
        return true;
    }
    return false;
}

void input_thread_action(array_queue& key_buffer,int& should_terminate){
    std::unordered_set<int> useful_keys{'a','A','s','S','d','D','w','W','q','Q'};

    while(true){
        if(should_terminate){
            return;
        }
        int ch=getch();
        if(is_useful(ch,useful_keys) && key_buffer.filled<2){
            key_buffer.enqueue(ch);
        }
    }
}
