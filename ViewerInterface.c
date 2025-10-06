#include "ViewerInterface.h"
#include <stdio.h>
#include <string.h>



static void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}



int getMenu() {

    int number;

    printf("\n--- ������ ������ ----------------------\n");
    printf("1. �������� ����� �������\n");
    printf("2. ������� ������� (�� ����� � ��������)\n");
    printf("3. ����� �� �������� (���������� ������)\n");
    printf("4. �����\n");
    printf("�������� ����� ����: ");


    if (scanf_s("%d", &number) != 1) {
        clearBuffer();
        return 0;
    }

    clearBuffer();
    return number;

}



void AddElementToJournal(Journal* journal) {

    char name[40], subject[20];
    int grade;

    printf("������� ��� �������: ");
    if (fgets(name, sizeof(name), stdin) == NULL) return;

    for (int i = 0; i < sizeof(name); i++)
    {
        if (name[i] == '\n')
        {
            name[i] = '\0';
            break;
        }
    }

    printf("������� �������: ");
    if (fgets(subject, sizeof(subject), stdin) == NULL) return;

    for (int i = 0; i < sizeof(subject); i++)
    {
        if (subject[i] == '\n')
        {
            subject[i] = '\0';
            break;
        }
    }


    do {
        printf("������� ������ (����� �� 1 �� 5): ");

        if (scanf_s("%d", &grade) != 1) {
            printf("������ �����. ������� ����� �����.\n");

            clearBuffer();
            grade = 0;
        }

        else if (grade < 1 || grade > 5) {
            printf("������ ������ ���� �� 1 �� 5.\n");
            clearBuffer();
        }

        else {
            clearBuffer();
            break;
        }

    } while (grade < 1 || grade > 5);

  
    if (grade >= 1 && grade <= 5) {
        Info newEntry = createNewElement(name, subject, grade);
        addElement(journal, &newEntry);
    }

    else {
        printf("���������� ������ �������� ��-�� ��������� ����� ������.\n");
    }

}



void RemoveElementFromJournal(Journal* journal) {

    char name[40], subject[20];

    printf("������� ��� ������� ��� ��������: ");
    if (fgets(name, sizeof(name), stdin) == NULL) return;

    for (int i = 0; i < sizeof(name); i++)
    {
        if (name[i] == '\n')
        {
            name[i] = '\0';
            break;
        }
    }

    printf("������� ������� ��� ��������: ");
    if (fgets(subject, sizeof(subject), stdin) == NULL) return;

    for (int i = 0; i < sizeof(subject); i++)
    {
        if (subject[i] == '\n')
        {
            subject[i] = '\0';
            break;
        }
    }

    removeElement(journal, name, subject);
}



void SearchElementInJournal(const Journal* journal) {

    char subject[20];

    printf("������� ������� ��� ������: ");
    if (fgets(subject, sizeof(subject), stdin) == NULL) return;

    for (int i = 0; i < sizeof(subject); i++)
    {
        if (subject[i] == '\n')
        {
            subject[i] = '\0';
            break;
        }
    }

    searchElement(journal, subject);
}