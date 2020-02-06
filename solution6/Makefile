# Write a rule that builds the target 'everythingworkplease' using 'everything.c' as a dependency
CFLAGS:=
C_OBJS:=everything.o this.o that.o thing.o

everythingworkplease: $(C_OBJS)
	$(info Building everythingworkplease...)
	gcc -o $@ $^

debug: CFLAGS+=-g -O0 -DDEBUG
debug: $(C_OBJS)
	gcc -o $@ $^

everything.o: everything.c
	gcc $(CFLAGS) -o $@ -c $<

%.o: %.c thing.h
	gcc $(CFLAGS) -o $@ -c $<

.PHONY: test
test: everythingworkplease
	./everythingworkplease

.PHONY: clean
clean:
	rm -f everythingworkplease debug *.o