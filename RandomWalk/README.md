#for running
``
gcc -Wall -Wextra -g $(sdl2-config --cflags --libs)  -o random-walk main.c
./random-walk <number_of_agents>
``
