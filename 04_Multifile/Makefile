GENERATES = prog prog-a prog-so README *.so
TRASH = *.o *~ o.* *.a out*

all: README prog prog-a prog-so

test:
	make all
	./prog >> out_1 && ./prog 1 >> out_1 && ./prog 1 2 3 >> out_1
	./prog-a >> out_2 && ./prog-a 1 >> out_2 && ./prog-a 1 2 3 >> out_2
	./prog-so >> out_3 && ./prog-so 1 >> out_3 && ./prog-so 1 2 3 >> out_3

	if cmp out_1 out_2; then print("prog and prog-a outputs differ"); fi
	if cmp out_1 out_3; then print("prog and prog-so outputs differ"); fi
	if cmp out_2 out_3; then print("prog-a and prog-so outputs differ"); fi

prog: const.o fun.o prog.o

prog-a: libout.a prog.o
	cc -L. prog.o -lout -o prog-a

prog-so: liboutput.so prog.o
	cc -L. prog.o -lout -o prog-so

libout.a: const.o fun.o
	ar -rcs libout.a const.o fun.o

liboutput.so: const.o fun.o
	cc -fPIC -shared fun.o const.o -o libout.so

README: prog
	./$< 2> $@

fun.o: outlib.h

clean:
	rm -f $(TRASH)

distclean: clean
	rm -rf $(GENERATES)



