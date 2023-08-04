#include <stdio.h>
#include <stdlib.h>

typedef struct Person {
    const char* name;
    struct Person* next;
} Person;

Person* gen(struct Person* person) {
    const char* names[] = {"Ana", "Pedro", "Mariana", "Carlos", "Joana", "Rafael", "Lucia", "Daniel", "Juliana", "Luiz"};
    for(unsigned int i=0;i <= (sizeof(names)/sizeof(names[0]))-1; i++) {
        Person* p = malloc(sizeof(Person));
        p->name = names[i];
        person->next = p;
        person = p;
    }

    return person;
}

Person* pushBackLK(struct Person* lastPerson, const char* name) {
    Person* p = malloc(sizeof(Person));
    p->name = name;
    lastPerson->next = p;
    lastPerson = p;
    lastPerson->next = NULL;

    return lastPerson;
}

void insertPos(struct Person* person, const char* name, int pos) {
    for(int i=0; i != pos -1; i++) {
        person = person->next;
    }

    Person* newPerson = malloc(sizeof(Person));
    newPerson->name = name;
    newPerson->next = person->next;
    person->next = newPerson;
}

int main() {
    Person* person = malloc(sizeof(Person));
    person->name = "me";
    Person* last = gen(person);
    last = pushBackLK(last, "charizard");
    insertPos(person,"pikachu", 3);
    return 0;
}