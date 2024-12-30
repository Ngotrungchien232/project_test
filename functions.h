#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "datatype.h"

//menu
void menuStart();
void menuAdmin();
void menuStudents();
void menuTeacher();

//sinh vien
void inputStudent(int *length, struct Student sv[]);
void printHeader();
void printStudent(int length, struct Student sv[]);
void addStudent(int *length, struct Student sv[]);
void saveStudentToFile(int length, struct Student sv[]);
void loadStudentFromFile(int *length, struct Student sv[]);
void deleteStudent(int *length, struct Student sv[]);
void editStudent(int length, struct Student sv[]);
void searchStudent(int length, struct Student sv[]);
void sortStudentsByName(int length, struct Student sv[]);

//giao vien
void menuTeacher();
void printTeacher(int length, struct Teacher tv[]);
void addTeacher(int *length, struct Teacher tv[]);
void printHeader2();
void saveTeacherToFile(int length, struct Teacher tv[]);
void deleteTeacher(int *length, struct Teacher tv[]);
void editTeacher(int length, struct Teacher tv[]);
void searchTeacher(int length, struct Teacher tv[]);
void sortTeachersByName(int length, struct Teacher tv[]);

//lop
void addClass(struct Classroom *classes, int *classCount);
void deleteClass(struct Classroom *classes, int *classCount);
void editClass(struct Classroom *classes, int classCount);
void viewClassDetails(struct Classroom *classes, int classCount);
void addStudentToClass(struct Classroom *classes, int classCount, struct Student *students, int studentCount);
void removeStudentFromClass(struct Classroom *classes, int classCount, struct Student *students, int studentCount);

#endif // FUNCTIONS_H

