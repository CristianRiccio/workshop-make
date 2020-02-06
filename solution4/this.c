#include "this.h"

char this_thing[BUF_SIZE];

const char* this(void) {
    strcat(this_thing, "this ");
    strcat(this_thing, thing());
    return this_thing;
}