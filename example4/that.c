#include "that.h"

char that_thing[BUF_SIZE];

const char* that(void) {
    strcat(that_thing, "that ");
    strcat(that_thing, thing());
    return that_thing;
}