TRASH = *.o *~ o.* main
CFLAGS = -lglib-2.0

all: main.c
	cc main.c `pkg-config --cflags glib-2.0` $(CFLAGS) -o main
	
clean:
	rm -f $(TRASH)
