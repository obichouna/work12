all: forkin.c
	gcc -o hw12 forkin.c
clean:
	rm *~
	rm a.out
run: all
	./hw12
