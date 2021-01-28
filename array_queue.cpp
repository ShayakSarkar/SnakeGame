#include <bits/stdc++.h>
#include "./includes/array_queue.hpp"

array_queue::array_queue(){
    //std::cout<<"constructor called"<<std::endl;
    queue.push_back(-1);
    queue.push_back(-1);
    cap=2;
    head=0;
    tail=0;
    filled=0;
}

void array_queue::enqueue(int k){
    if(filled>=cap){
        std::cout<<"array_queue:enqueue: overflow"<<std::endl;
        return;
    }
    filled++;
    queue[tail]=k;
    tail++;
    tail%=cap;
}

int array_queue::dequeue(){
    if(filled<=0){
        std::cout<<"array_queue:enqueue: underflow"<<std::endl;
        return -1;
    }
    int ret_val=queue[head++]; 
    head%=cap;
    filled--;
    return ret_val;
}
