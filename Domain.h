#ifndef DOMAIN_H
#define DOMAIN_H


typedef struct {
    char studName[40];
    char subjectName[20];
    int mark;
} Info;


Info createNewElement(const char* name, const char* subj, int mk);


const char* getStudName(const Info* info);
const char* getSubjectName(const Info* info);

int getMark(const Info* info);
void setMark(Info* info, int newMark);

#endif // DOMAIN_H