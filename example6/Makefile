# Write a rule that builds the target 'everythingworkplease' using 'everything.c' as a dependency

everythingworkplease: 
	$(info Building everythingworkplease...)
	gcc -o $@ $^

everything.o: everything.c
	gcc -o $@ -c $<

%.o: %.c thing.h
	gcc -o $@ -c $<

.PHONY: test
test: everythingworkplease
	./everythingworkplease

.PHONY: clean
clean:
	rm -f everythingworkplease debug *.o