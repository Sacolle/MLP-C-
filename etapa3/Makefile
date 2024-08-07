
main: main.o classes.o
	g++ $^ -o $@ -g `pkg-config --cflags gtkmm-4.0` `pkg-config --libs gtkmm-4.0`
	

*.o: *.cpp
	g++ -c $@ $^ `pkg-config --cflags gtkmm-4.0`

.PHONY: run clean

run: main
	./main

clean:
	rm main *.o