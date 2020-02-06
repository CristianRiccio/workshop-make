#include <stdio.h>

#include "this.h"
#include "that.h"

#define VERSION_NUMBER 1

int main(void) {
#ifdef DEBUG
    printf("Debug build -- not for release\n");
#endif
    printf("I'd like more of %s and %s.\n", this(), that());
    printf("Everything (version %d) worked!\n", VERSION_NUMBER);
    return 0;
}