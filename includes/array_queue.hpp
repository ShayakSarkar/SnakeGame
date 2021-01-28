#include <bits/stdc++.h>

#ifndef ARRAY_QUEUE_DEF
#define ARRAY_QUEUE_DEF 1
class array_queue{
public:
    std::vector<int> queue;
    int head,tail;
    int cap;
    int filled;
    array_queue();
    void enqueue(int);
    int dequeue();
};
#endif