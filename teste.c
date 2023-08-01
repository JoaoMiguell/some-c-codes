#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p;
    //p = malloc(sizeof(int) + 99999999999999999); Exploded the memory KEKW - don't do this
    p = malloc(sizeof(int));
    if(!p) printf("Error on memory allocation\n");
    else printf("Memory allocation successfully on address: %p\n",p);
    return 0;
}