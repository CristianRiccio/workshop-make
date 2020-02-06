# Write a rule that builds the target 'everythingworkplease' using 'everything.c' as a dependency
everythingworkplease: 
	$(info Building everythingworkplease...)
	gcc -o $@ $^

everything.o: 
	gcc -o $@ -c $<

this.o: 
	gcc -o $@ -c $<

that.o: 
	gcc -o $@ -c $<

thing.o: 
	gcc -o $@ -c $<

.PHONY: test
test: everythingworkplease
	./everythingworkplease

.PHONY: clean
clean:
	rm -f everythingworkplease *.o