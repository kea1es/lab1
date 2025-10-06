#ifndef COLLECTIONS_H
#define COLLECTIONS_H

#include "Domain.h"



typedef struct Uzel {
    Info record;
    struct Uzel* nextUzel;
} Uzel;

typedef struct {
    Uzel* firstUzel;
    int amount;
} Journal;



void initializateJournal(Journal* journal);
void freeJournal(Journal* journal);


void addElement(Journal* journal, const Info* info);
int removeElement(Journal* journal, const char* name, const char* subject);
void searchElement(const Journal* journal, const char* subject);

#endif // COLLECTIONS_H