wrapper.so:
	cc -shared -fPIC wrapper.c -ldl -o wrapper.so

test_wrapper: wrapper.so
	touch file
	touch FIX
	-LD_PRELOAD=./wrapper.so rm file
	-LD_PRELOAD=./wrapper.so rm FIX
	make clean

test_no_wrapper: wrapper.so
	touch file
	touch FIX
	rm file
	rm FIX
	make clean

clean:
	rm wrapper.so
	if test -f FIX; then rm FIX; fi
