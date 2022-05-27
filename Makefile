main : main.o
	g++ -o main v1.0.cpp IvestisIsvestis.o generavimas.o atsSk.o Tikrinimas.o
main.o :
	g++ -c cppFailai/*.cpp 
clean :
	del main.exe *.o
