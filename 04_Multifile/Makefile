GENERATES = prog prog-a prog-so README *.so
TRASH = *.o *~ o.* *.a
LOG = log.txt

all: README prog prog-a prog-so

test:
	make all
	./prog >> out_1 && ./prog 1 >> out_1 && ./prog 1 2 3 >> out_1
	./prog-a >> out_2 && ./prog-a 1 >> out_2 && ./prog-a 1 2 3 >> out_2
	./prog-so >> out_3 && ./prog-so 1 >> out_3 && ./prog-so 1 2 3 >> out_3

	if cmp out_1 out_2; then echo("prog and prog-a outputs differ") > $(LOG); fi
	if cmp out_1 out_3; then echo("prog and prog-so outputs differ") >> $(LOG); fi
	if cmp out_2 out_3; then echo("prog-a and prog-so outputs differ") >> $(LOG); fi

prog: const.o fun.o prog.o

prog-a: libout.a prog.o
	cc -L. prog.o -lout -o prog-a

prog-so: liboutput.so prog.o
	cc -L. prog.o -lout -o prog-so

libout.a: const.o fun.o
	ar -rcs libout.a const.o fun.o

liboutput.so: const.o fun.o
	cc -fPIC fun.o -shared const.o -o libout.so

README: prog
	./$< 2> $@

fun.o: outlib.h

clean: logclean trashclean genclean

logclean:
	rm -f $(LOG)

trashclean:
	rm -f $(TRASH)

genclean:
	rm -rf $(GENERATES)



