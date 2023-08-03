#include <stdio.h>
#include <stdlib.h>

typedef struct Person {
    const char* name;
    struct Person* next;
} Person;

void gen(Person* person) {
    const char* names[] = {"Ana", "Pedro", "Mariana", "Carlos", "Joana", "Rafael", "Lucia", "Daniel", "Juliana", "Luiz"};
    for(unsigned int i=0;i <= (sizeof(names)/sizeof(names[0]))-1; i++) {
        Person* p = malloc(sizeof(Person));
        p->name = names[i];
        person->next = p;
        person = p;
    }
}

int main() {
    Person person;
    person.name = "me";
    gen(&person);
    
    return 0;
}