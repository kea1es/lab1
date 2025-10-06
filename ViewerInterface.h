#ifndef VIEWERINTERFACE_H
#define VIEWERINTERFACE_H

#include "Collections.h"


int getMenu();


void AddElementToJournal(Journal* journal);
void RemoveElementFromJournal(Journal* journal);
void SearchElementInJournal(const Journal* jornal);

#endif // VIEWERINTERFACE_H