#include <stdbool.h>
#include<stdio.h>
#include<string.h>

struct *Date {
    int day, month, year;
};

struct Student {
    char studentId[10];
    char classroomId[10];
    char fullName[30];
    struct Date *dateOfBirth; 
    bool gender;
    char email[30];
    char phone[20];
    char password[20];
};

struct Classroom {
    char classroomId[10];
    char teacherId[10];
    char classroomName[20];
    struct Student *students; 
    int studentCount; 
};

struct Teacher {
    char teacherId[10];
    char classroomId[10];
    char fullName[30];
    struct Date *dateOfBirth; 
    bool gender;
    char email[30];
    char phone[20];
    char password[20];
    struct Classroom *classrooms; 
    int classroomCount; 
};

