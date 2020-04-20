
test3: 1b3
	./1b3 < 1b3.in > /tmp/out
	cat /tmp/out
	diff /tmp/out 1b3.out

1b3:	1b3.cpp
	g++ -g -O0 1b3.cpp -o 1b3 -lstdc++ -std=c++1z


1b2:	1b2.cpp
	g++ -g -O0 1b2.cpp -o 1b2 -lstdc++ -std=c++1z


test1: 1b1
	./1b1 < 1b1.in > /tmp/out
	cat /tmp/out
	diff /tmp/out 1b1.out

1b1:	1b1.cpp
	g++ -g -O0 1b1.cpp -o 1b1 -lstdc++ -std=c++1z
