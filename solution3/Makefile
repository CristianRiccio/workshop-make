# Write a rule that builds the target 'everythingworkplease' using 'everything.c' as a dependency
everythingworkplease: everything.c
	$(info Building everythingworkplease...)
	gcc -o everythingworkplease everything.c

.PHONY: clean
clean:
	rm everythingworkplease