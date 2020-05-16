all: test1 test2 test3

test1: 21 21.in 21.sol
	@./21 < 21.in > /tmp/out
	@cat /tmp/out
	@diff /tmp/out 21.sol
	@echo "OK!"

test2: 22 22.in 22.sol
	@./22 < 22.in > /tmp/out
	@cat /tmp/out
	@diff /tmp/out 22.sol
	@echo "OK!"

test3: 23 23.in 23.sol
	@./23 < 23.in > /tmp/out
	@cat /tmp/out
	@diff /tmp/out 23.sol
	@echo "OK!"

21:	21.cpp
	g++ -g -O0 21.cpp -o 21 -lstdc++ -std=c++1z

22:	22.cpp
	g++ -g -O0 22.cpp -o 22 -lstdc++ -std=c++1z

23:	23.cpp
	g++ -g -O0 23.cpp -o 23 -lstdc++ -std=c++1z

clean:
	rm -f 21 22 23
