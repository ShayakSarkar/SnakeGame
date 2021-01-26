./a.out: driver.o input_thread.o render_thread.o snake.o food.o
	g++ driver.o input_thread.o render_thread.o snake.o food.o -lncurses -pthread

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

input_thread.o: input_thread.cpp
	g++ -c input_thread.cpp  -o input_thread.o

render_thread.o: render_thread.cpp
	g++ -c render_thread.cpp -o render_thread.o -lncurses

snake.o: snake.cpp
	g++ -c snake.cpp -o snake.o -lncurses

food.o: food.cpp	
	g++ -c food.cpp -o food.o -lncurses
