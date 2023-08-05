#include <stdio.h>
#include <stdlib.h>

typedef struct Person {
    const char* name;
    struct Person* next;
} Person;

Person* gen(struct Person* person) {
    const char* names[] = {"Ana", "Pedro", "Mariana", "Carlos", "Joana", "Rafael", "Lucia", "Daniel", "Juliana", "Luiz"};
    for(unsigned short int i=0;i <= (sizeof(names)/sizeof(names[0]))-1; i++) {
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

Person* insertPos(struct Person* person, const char* name, int pos) {
    Person* newPerson = malloc(sizeof(Person));
    newPerson->name = name;
    if(pos == 0) {
        newPerson->next = person;
        person = newPerson;
    }
    else {
        for(int i=0; i < pos; i++) {
            person = person->next;
        }

        newPerson->next = person->next;
        person->next = newPerson;
    }

    return person;
}

void deletePos(struct Person* person, int pos) {
    Person* nextP;
    if(pos == 0) {
        nextP = person->next;
        free(person);
    }
    else {
        for(int i=0; i<pos-1;i++) {
            person = person->next;
        }
        nextP = person->next;
        person->next = nextP->next;

        free(nextP);
    }

}

int main() {
    Person* person = malloc(sizeof(Person));
    person->name = "me";
    Person* last = gen(person);
    last = pushBackLK(last, "charizard");
    person = insertPos(person,"pikachu", 0);
    deletePos(person,4);
    return 0;
}