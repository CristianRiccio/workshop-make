# Content for make workshop

# Introduction

Beginner and experienced developers alike want to build cool applications, tools, and products. A build system is helps to manage the compile and linking process when preparing to test or distribute your code.

Diagram: A C source file is compiled into a binary object file.

Useful Make cheatsheet: https://devhints.io/makefile

# Concepts

## Commands

A simple Makefile might look like this:
```Makefile
hello:
	echo "Hello world!"
	echo "This computer is running: "
	uname -sm
```
It's surprisingly simple, isn't it? The build system simply runs several commands in succession to achieve a given objective.

It's worth noting that you must use *tabs* and not spaces.

### Exercise 1
Try it yourself: Complete the [Makefile](../exercise1/Makefile) ([solution](../solution1/Makefile)) by defining the `hello` target.

## Targets

The objective of a build system is to build something. Let's change the definition of the target `hello` and see what happens:
```Makefile
hello:
	echo "Hello world!"
	echo "This computer is running: "
	uname -sm
	touch hello
```
Run `make hello` — notice that a new file has appeared.
```shell
$ tree
.
├── Makefile
└── hello
```

If you run `make hello` again, nothing happens. That's because the target has already been built, and its dependencies (nothing) have not changed since it was last built.
```shell
make: `hello' is up to date.
```

It is generally good practice to include a 'clean' rule which cleans up any output of the build process.
```Makefile
.PHONY: clean
clean:
    rm hello
```

### Exercise 2
Try it yourself: Complete the [Makefile](../exercise2/Makefile) ([solution](../solution2/Makefile)) with a rule that creates the 'hello' file and a clean rule that removes it.

## Dependencies I

Let's define `everythingworkplease` in terms of the source file `everything.c`.
```Makefile
everythingworkplease: everything.c
	$(info Building everythingworkplease...)
	gcc -o everythingworkplease everything.c
```
Build and run `everythingworkplease`.
```shell
$ make everythingworkplease && ./everythingworkplease
Building everythingworkplease...
gcc -o everythingworkplease everything.c
Everything (version 1) worked!
```

Notice that if you run `make` again, nothing happens.

Change the `VERSION_NUMBER` in `everything.c` and run `make` again.
```shell
$ make everythingworkplease && ./everythingworkplease
Building everythingworkplease...
gcc -o everythingworkplease everything.c
Everything (version 2) worked!
```

When `make` is run a second time, it notices that the dependency's modified-time is later than the target's modified-time, and `make` will automatically rebuild the target.

### Exercise 3
Try it yourself: Complete the [Makefile](../exercise3/Makefile) ([solution](../solution3/Makefile)) with rules that:
- define a target `everythingworkplease`
- which depends on `everything.c`
- and compiles it with gcc.

## Dependencies II

If your project has plenty of files, like most projects do, Make handles a lot of the complexity for us.
```shell
.
├── Makefile
├── everything.c
├── that.c
├── that.h
├── thing.c
├── thing.h
├── this.c
└── this.h
```

We can define a simple Makefile to capture all the dependencies:
```Makefile
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
```

Automatic variables help us be more concise: `$@` expands to the target, `$<` is the first dependency, and `$^` all dependencies.

List of useful automatic variables: https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html

Make will automatically figure out what to recompile (and in what order):
```shell
$ make everythingworkplease
gcc -o everything.o -c everything.c
gcc -o this.o -c this.c
gcc -o that.o -c that.c
gcc -o thing.o -c thing.c
Building everythingworkplease...
gcc -o everythingworkplease everything.o this.o that.o thing.o
```

### Exercise 4
Try it yourself: Fill in the dependencies for each target in [Makefile](../exercise4/Makefile) ([solution](../solution4/Makefile)).

## Pattern matching
We've got a pretty big project on our hands right now.
```shell
.
├── Makefile
├── everything.c
├── that.c
├── that.h
├── thing.c
├── thing.h
├── this.c
└── this.h
```

With this many files, we could take advantage of a feature called pattern matching.

We can define a simple `%.o` target by using a pattern:
```Makefile
%.o: %.c thing.h
	gcc -o $@ -c $<
```
Run `make`, and watch it automatically build the object files from source files.

### Exercise 5
Try it yourself: Write a simple rule to build all object (`%.o`) files from their source (`%.c`) files and their global dependencies (`thing.h`) in [Makefile](../exercise5/Makefile) ([solution](../solution5/Makefile)).

## Variables

Variables make it incredibly easy to configure your application:
```Makefile
debug: CFLAGS+=-g
debug: CFLAGS+=-O0
debug: a.o b.o
	gcc $(LFLAGS) -o $@ $<
```