#include <string.h>
#include <stdio.h>

#include "Domain.h"


Info createNewElement(const char* name, const char* subj, int mk) {

    Info newElement;
    strncpy_s(newElement.studName, sizeof(newElement.studName), name, _TRUNCATE);
    strncpy_s(newElement.subjectName, sizeof(newElement.subjectName), subj, _TRUNCATE);

    newElement.mark = mk;
    return newElement;
}


const char* getStudName(const Info* info) {
    return (*info).studName;
}

const char* getSubjectName(const Info* info) {
    return (*info).subjectName;
}



int getMark(const Info* info) {
    return (*info).mark;
}

void setMark(Info* info, int newMark) {
    (*info).mark = newMark;
}