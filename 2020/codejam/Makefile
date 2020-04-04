test3: 1c5
	./1c5 < 1c5.in > /tmp/out
	cat /tmp/out
	diff /tmp/out 1c5.out

test4: 1c4
#	python interactive_runner.py python local_testing_tool.py 0 -- ./1c4
#	python interactive_runner.py python local_testing_tool.py 1 -- ./1c4
	python interactive_runner.py python local_testing_tool.py 2 -- ./1c4

test3: 1c3
	./1c3 < 1c3.in > /tmp/out
	cat /tmp/out
	diff /tmp/out 1c3.out

test2: 1c2
	./1c2 < 1c2.in > /tmp/out
	cat /tmp/out
	diff /tmp/out 1c2.out

test1: 1c1
	./1c1 < 1c1.in > /tmp/out
	cat /tmp/out
	diff /tmp/out 1c1.out

1c1:	1c1.cpp
	g++ -g -O0 1c1.cpp -o 1c1 -lstdc++ -std=c++1z

1c2:	1c2.cpp
	g++ -g -O0 1c2.cpp -o 1c2 -lstdc++ -std=c++1z

1c3:	1c3.cpp
	g++ -g -O0 1c3.cpp -o 1c3 -lstdc++ -std=c++1z

1c4:	1c4.cpp
	g++ -g -O0 1c4.cpp -o 1c4 -lstdc++ -std=c++1z

1c5:	1c5.cpp
	g++ -g -O0 1c5.cpp -o 1c5 -lstdc++ -std=c++1z

