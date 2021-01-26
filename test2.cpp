#include <bits/stdc++.h>

class snake{
    enum{
        MOVE_LEFT,
        MOVE_RIGHT,
        MOVE_UP,
        MOVE_DOWN
    };
    public: void show_enum(){
        std::cout<<MOVE_LEFT<<std::endl;
        std::cout<<MOVE_RIGHT<<std::endl;
        std::cout<<MOVE_UP<<std::endl;
        std::cout<<MOVE_DOWN<<std::endl;
    }
};
int main(){
    std::vector<std::pair<int,int>> v;
    int a=100;
    int b=200;
    std::pair<int,int> p{1,2};
    v.push_back(std::make_pair(p.first,p.second));
    int i=0;
    std::cout<<v[i].first<<" "<<v[i].second<<std::endl;
}