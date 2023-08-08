#include <stdio.h>
#include <stdlib.h>

typedef struct sPerson {
    const char* name;
    int age;
    struct sPerson* prev;
    struct sPerson* next;
} Person;

void gen(Person* person) {
    const char* names[] = {"Ana", "Pedro", "Mariana", "Carlos", "Joana", "Rafael", "Lucia", "Daniel", "Juliana", "Luiz"};
    const int ages[] = {12,23,43,65,76,65,17,49,51,28};
    for(unsigned int i=0; i< (sizeof names)/(sizeof names[0]); i++) {
        Person* temp = malloc(sizeof(struct sPerson));
        temp->name = names[i];
        temp->age = ages[i];
        temp->prev = person;
        temp->next = NULL;
        person->next = temp;
        person = person->next;
    }
}

Person* insert(Person* person, const char* name, int age, int pos) {
    Person* newP = malloc(sizeof(struct sPerson));
    newP->name = name;
    newP->age = age;

    if(pos == 0) {
        newP->next = person;
        newP->prev = NULL;
        person->prev = newP;
        return newP;
    }

    for(int i=0;i<pos-1;i++)  person = person->next;

    newP->next = person->next;
    newP->prev = person;
    person->next = newP;
    newP = newP->next;
    newP->prev = person->next;
    while(person->prev) {
        person = person->prev;
    }

    return person;
}

void pushBack(Person* person, const char* name, int age) {
    while(person->next) person = person->next;

    Person* newPerson = malloc(sizeof(struct sPerson));
    newPerson->name = name;
    newPerson->age = age;
    newPerson->next = NULL;
    newPerson->prev = person;
    person->next = newPerson;
}

int searchPos(Person* person, const char* nameToSearch) {
    int res = 0;
    while(person->next) {
        if(person->name == nameToSearch) return res;

        person = person->next;
        res++;
    }

    return -1;
}

Person* deleteLK(Person* person, const char* name) {
    int pos = searchPos(person,name);
    if(pos == -1) return person;

    for(int i=0; i<pos-1;i++) person = person->next;

    Person* toRemoveTemp = person->next;
    person->next = toRemoveTemp->next;
    free(toRemoveTemp);
    toRemoveTemp = person;
    person = person->next;
    person->prev = toRemoveTemp;

    while(person->prev) person = person->prev;

    return person;
}

int main() {
    Person* person = malloc(sizeof(struct sPerson));
    person->name = "me";
    person->age = 32;
    person->prev = NULL;
    gen(person);
    person = insert(person,"Pikachu", 9, 0);
    person = insert(person,"ratata", 2, 4);
    pushBack(person, "charizard",8);
    person = deleteLK(person, "me");
    return 0;
}