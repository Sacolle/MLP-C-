
main: main.o pessoa.o aluno.o data.o
	g++ $^ -o $@ -g
	

*.o: *.c
	g++ -c $@ $^

.PHONY: run clean

run: main
	./main

clean:
	rm main