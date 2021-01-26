#include <bits/stdc++.h>
#include <ncurses.h>

class snake{
    enum{
        MOVE_UP,
        MOVE_DOWN,
        MOVE_RIGHT,
        MOVE_LEFT
    };
    std::vector<std::pair<int,int>> body;
    int last_action_id;
    snake(){
        std::pair<int,int> init_pos{50,20};
        std::pair<int,int> second_pos{51,20};
        body.push_back(std::move(init_pos));
        body.push_back(std::move(second_pos));
        last_action_id=MOVE_RIGHT;
    }
    move_left();
    move_right();
    move_up();
    move_down();
    render(WINDOW*);
}
void snake::render(WINDOW *win){
    for(auto& pos : body){
        wmove(win,pos.second,pos.first);
        wrefresh(win);
        waddstr(win,"#");
        wrefresh();
    }
}
void snake::move_left(){
    for(int i=body.size()-1;i>0;i--){
        body[i]=std::move(body[i-1]);
    }
    body[0]=std::make_pair<int,int>(body[1].first-1,body[1].second);
    last_action_id=MOVE_LEFT;
}
void snake::move_right(){
    for(int i=body.size()-1;i>0;i--){
        body[i]=std::move(body[i-1]);
    }
    body[0]=std::make_pair<int,int>(body[1].first+1,body[1].second);
    last_action_id=MOVE_RIGHT;
}
void snake::move_up(){    
    last_action_id=MOVE_UP;
}
void snake::move_down(){
    last_action_id=MOVE_DOWN;
}

void input_thread_action(std::queue<int>& key_buffer,int& should_terminate){
    while(true){
        if(should_terminate){
            return; 
        }
        int elm;
        elm=getch();
        key_buffer.push(elm);
    }
}

void key_buffer_reader_thread_action(std::queue<int>& key_buffer, WINDOW *win,int& should_terminate){
    while(true){
        if(key_buffer.size()!=0){
            int elm=key_buffer.front();
            key_buffer.pop();
            if(elm==49){
                should_terminate=true;
                return;
            }
            std::string msg="key pressed is "+std::to_string(elm);
            wmove(win,0,0);
            wrefresh(win);
            waddstr(win,msg.c_str());
            wrefresh(win);
        }
    }
}

void snake_render_thread_action(snake& snk,std::queue<int>& key_buffer,int& should_terminate){
    while(true){
        if(should_terminate){
            return;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if(key_buffer.size()==0){
            snake.last_action();
            snake.render();
            continue;
        }
        else{
            snake.last_action();
            snake.render();
            continue;
        }
    }
}

int main(){
    const int NCOLS=166,NROWS=43;
    initscr();
    cbreak();
    noecho();
    std::queue<int,std::deque<int>> key_buffer; //buffer for the keystrokes
    WINDOW *win=newwin(NROWS,NCOLS,0,0); //set up window 
    snake snk;
    wrefresh(win);
    int should_terminate=false;
    std::thread input_thread(input_thread_action,std::ref(key_buffer),std::ref(should_terminate));
    std::thread key_buffer_reader_thread(key_buffer_reader_thread_action,std::ref(key_buffer),win,std::ref(should_terminate));
    std::thread snake_render_thread(snk,snake_render_thread_action,std::ref(key_buffer),std::ref(should_terminate));
    input_thread.join();
    key_buffer_reader_thread.join();
    delwin(win);
    std::cout<<"press any key to continue ...."<<std::endl;
    int temp;
    std::cin>>temp;
}

