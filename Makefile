OBJ := $(patsubst %.c, %.o, $(wildcard *.c))

steganography: ${OBJ}
	gcc -o  $@ $^

clean:
	rm *.o steganography

