# Content for make workshop

# Introduction

Beginner and experienced developers alike want to build cool applications, tools, and products. A build system is helps to manage the compile and linking process when preparing to test or distribute your code.

Diagram: A C source file is compiled into a binary object file.

# Concepts

## Commands

A simple Makefile might look like this:
```
    hello:
    	echo "Hello world!"
    	echo "This computer is running: "
    	uname -a
```
It's surprisingly simple, isn't it? The build system simply runs several commands in succession to achieve a given objective.

It's worth noting that you must use *tabs* and not spaces.

## Targets

The objective of a build system is to build something. Let's change the definition of the target `hello` and see what happens:
```
    hello:
    	echo "Hello world!"
    	echo "This computer is running: "
    	uname -a
    	touch hello
```
Run `make hello` — notice that a new file has appeared.

If you run `make` again, nothing happens. That's because the target has already been built, and its dependencies (nothing) have not changed since it was last built.

## Dependencies I

Let's define `everythingworkplease` in terms of the source file `everything.c`.
```
    everythingworkplease: everything.c
    	echo "Building everythingworkplease..."
    	gcc -o everythingworkplease everything.c
```
Run the executable.

Notice that if you run `make` again, nothing happens.

Change the `VERSION_NUMBER` in `everything.c` and run `make` again.

When `make` is run a second time, it notices that the dependency's modified-time is later than the target's modified-time, and. Make will automatically rebuild the target.

## Dependencies II


## Pattern matching

Suppose we have a bunch of source files:
```
    tree .
    |-- a.c
    |-- b.c
    |-- c.c
```
We can define a simple `.o` target by using a pattern:
```
    %.o: %.c
    	gcc -o $@ -c $1
```
Run `make`, and watch it automatically build the object files from source files.

## Variables and Build flags

Variables allow flexible builds
```
    debug: CFLAGS+=-g
    debug: CFLAGS+=-O0
    debug: a.o b.o
    	gcc $(LFLAGS) -o $@ $<
```