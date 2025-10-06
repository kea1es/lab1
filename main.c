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

    printf("��������� '������ ������'\n\n");


    Info student1 = createNewElement("������� ������ ��������", "�������", 3);
    Info student2 = createNewElement("�������� �������� ����������", "���-��", 5);

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
            printf("����� �� ���������.\n");
            break;
        
        default:
            printf("������������ �����. ����������, ������� ����� �� 1 �� 4.\n");
            break;
        }

    } while (number != 4);


    freeJournal(&journal);

    return 0;
}