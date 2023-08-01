#include <stdio.h>

typedef struct Students{
    const char* name;
    struct Students* prox;
} Students;

int main() {
    Students st;
    st.name = "ze";
    st.prox = &st;
    printf("%p", st.prox);
    printf("\n%p", &st.prox);
    return 0;
}