#include "Collections.h"
#include "ViewerInterface.h"
#include <stdio.h>
#include <windows.h>

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Journal journal;
    initializateJournal(&journal);
    int number;

    printf("Программа 'Журнал оценок'\n\n");


    Info student1 = createNewElement("Сергеев Кирилл Петрович", "Алгебра", 3);
    Info student2 = createNewElement("Алексеев Анатолий Кириллович", "Физ-ра", 5);

    addElement(&journal, &student1);
    addElement(&journal, &student2);


    do {
        number = getMenu();

        switch (number){
        
        case 1:
            AddElementToJournal(&journal);
            break;
        
        case 2:
            RemoveElementFromJournal(&journal);
            break;
        
        case 3:
            SearchElementInJournal(&journal);
            break;
        
        case 4:
            printf("Выход из программы.\n");
            break;
        
        default:
            printf("Некорректный выбор. Пожалуйста, введите число от 1 до 4.\n");
            break;
        }

    } while (number != 4);


    freeJournal(&journal);

    return 0;
}