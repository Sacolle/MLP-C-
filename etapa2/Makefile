
main: main.o classes.o
	g++ $^ -o $@ -g
	

*.o: *.cpp
	g++ -c $@ $^

.PHONY: run clean

run: main
	./main

clean:
	rm main