CC = zcc +zx -vn -create-app -m --list --c-code-in-asm
SRC = test.c assert.c

test.tap: $(SRC)
	$(CC) $(SRC) -o test

run:
	fuse test.tap

clean:
	@-rm *.tap *.lis *.c.lis *.map test
