#include "ViewerInterface.h"
#include <stdio.h>
#include <string.h>



static void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}



int getMenu() {

    int number;

    printf("\n--- Журнал оценок ----------------------\n");
    printf("1. Добавить новый элемент\n");
    printf("2. Удалить элемент (по имени и предмету)\n");
    printf("3. Поиск по предмету (отобразить оценки)\n");
    printf("4. Выход\n");
    printf("Выберите пункт меню: ");


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

    printf("Введите имя ученика: ");
    if (fgets(name, sizeof(name), stdin) == NULL) return;

    for (int i = 0; i < sizeof(name); i++)
    {
        if (name[i] == '\n')
        {
            name[i] = '\0';
            break;
        }
    }

    printf("Введите предмет: ");
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
        printf("Введите оценку (число от 1 до 5): ");

        if (scanf_s("%d", &grade) != 1) {
            printf("Ошибка ввода. Введите целое число.\n");

            clearBuffer();
            grade = 0;
        }

        else if (grade < 1 || grade > 5) {
            printf("Оценка должна быть от 1 до 5.\n");
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
        printf("Добавление записи отменено из-за неверного ввода оценки.\n");
    }

}



void RemoveElementFromJournal(Journal* journal) {

    char name[40], subject[20];

    printf("Введите имя ученика для удаления: ");
    if (fgets(name, sizeof(name), stdin) == NULL) return;

    for (int i = 0; i < sizeof(name); i++)
    {
        if (name[i] == '\n')
        {
            name[i] = '\0';
            break;
        }
    }

    printf("Введите предмет для удаления: ");
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

    printf("Введите предмет для поиска: ");
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