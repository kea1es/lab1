#include "Collections.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void addElement(Journal* journal, const Info* info) {

    Uzel* newUzel = (Uzel*)malloc(sizeof(Uzel));

    if (newUzel == NULL) {
        fprintf(stderr, "������ ��������� ������ ��� ������ ����.\n");
        return;
    }

    (*newUzel).record = *info;
    (*newUzel).nextUzel = (*journal).firstUzel;

    (*journal).firstUzel = newUzel;
    (*journal).amount++;

    printf("������ ���������: %s, %s, %d\n", info->studName, info->subjectName, info->mark);
}



void searchElement(const Journal* journal, const char* subject) {

    Uzel* currentUzel = (*journal).firstUzel;
    int found = 0;

    printf("\n--- ������ �� �������� '%s' ---\n", subject);
    
    while (currentUzel != NULL) {

        if (strcmp(currentUzel->record.subjectName, subject) == 0) 
        {
            printf("������: %s, ������: %d\n", currentUzel->record.studName, currentUzel->record.mark);
            found = 1;
        }

        currentUzel = (*currentUzel).nextUzel;
    }

    if (!found) {
        printf("�� �������� '%s' ������� �� �������.\n", subject);
    }

    printf("--------------------------------\n");
}



int removeElement(Journal* journal, const char* name, const char* subject) {

    Uzel* currentUzel = (*journal).firstUzel;
    Uzel* priviousUzel = NULL;

    while (currentUzel != NULL) {

        if (strcmp(currentUzel->record.studName, name) == 0 && strcmp(currentUzel->record.subjectName, subject) == 0) {
            if (priviousUzel == NULL)
            {
                (*journal).firstUzel = (*currentUzel).nextUzel;
            }

            else 
            {
                priviousUzel->nextUzel = (*currentUzel).nextUzel;
            }

            printf("������ �������: %s, %s\n", name, subject);

            free(currentUzel);

            (*journal).amount--;
            return 1;
        }

        priviousUzel = currentUzel;
        currentUzel = (*currentUzel).nextUzel;

    }

    printf("������ �� �������: %s, %s\n", name, subject);
    return 0;
}



void initializateJournal(Journal* journal) {
    (*journal).firstUzel = NULL;
    (*journal).amount = 0;
}



void freeJournal(Journal* journal) {

    Uzel* currentUzel = (*journal).firstUzel;
    Uzel* nextUzel;

    while (currentUzel != NULL) {

        nextUzel = (*currentUzel).nextUzel;
        free(currentUzel);
        currentUzel = nextUzel;
    }

    (*journal).firstUzel = NULL;
    (*journal).amount = 0;
}