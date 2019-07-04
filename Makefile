all:	
	arm-linux-g++   -march=armv4t -ldl -c  tinyxml2/tinyxml2.cpp
	arm-linux-g++   -march=armv4t -ldl -c  main.cpp
	arm-linux-g++   -march=armv4t -ldl  main.o so.o  tinyxml2/tinyxml2.o -o main
clean:
	rm  *.o