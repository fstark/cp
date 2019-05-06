test3: 1c3
	./1c3 < 1c3.in > /tmp/out
	diff /tmp/out 1c3.out

test2: 1c2
	python3 interactive_runner.py python3 testing_tool.py 0 -- ./1c2

test1: 1c1
	./1c1 < 1c1.in > /tmp/out
	diff /tmp/out 1c1.out

1c1:	1c1.cpp
	g++ -O3 1c1.cpp -o 1c1 -lstdc++ -std=c++1z

1c2:	1c2.cpp
	g++ -O3 1c2.cpp -o 1c2 -lstdc++ -std=c++1z

1c3:	1c3.cpp
	g++ -O3 1c3.cpp -o 1c3 -lstdc++ -std=c++1z

# 1b3g:	1b3.cpp
# 	g++ -g 1b3.cpp -o 1b3g -lstdc++ -std=c++1z
# 	gdb ./1b3g 
