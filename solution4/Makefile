# Write a rule that builds the target 'everythingworkplease' using 'everything.c' as a dependency
everythingworkplease: everything.o this.o that.o thing.o
	$(info Building everythingworkplease...)
	gcc -o $@ $^

everything.o: everything.c
	gcc -o $@ -c $<

this.o: this.c this.h thing.h
	gcc -o $@ -c $<

that.o: that.c that.h thing.h
	gcc -o $@ -c $<

thing.o: thing.c thing.h
	gcc -o $@ -c $<

.PHONY: test
test: everythingworkplease
	./everythingworkplease

.PHONY: clean
clean:
	rm -f everythingworkplease *.o