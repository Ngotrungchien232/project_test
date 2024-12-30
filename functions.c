#include <stdio.h>
#include "functions.h"
#include <string.h>
#include "datatype.h"

void menuStart() {
    printf("\n***Student Management System Using C***\n");
    printf("\n");
    printf("\t  CHOOSE YOUR ROLE\n");
    printf("\t=====================\n");
    printf("\t[1] Admin.\n");
    printf("\t[2] Student.\n");
    printf("\t[3] Teacher. \n");
    printf("\t[0] Exit the Program.\n");
    printf("\t=====================\n");
}

void menuAdmin() {
    printf("\n***Student Management System Using C***\n");
    printf("\n");
    printf("\t          MENU\n");
    printf("\t==========================\n");
    printf("\t[1] Students management.\n");
    printf("\t[2] Classrooms management.\n");
    printf("\t[3] Teacher management.\n");
    printf("\t[4] User Guideline.\n");
    printf("\t[5] About Us.\n");
    printf("\t[0] Back.\n");
    printf("\t==========================\n");
}

void menuStudents() {
    printf("\n***Student Management System Using C***\n");
    printf("\n");
    printf("\t    STUDENT MENU\n");
    printf("\t======================\n");
    printf("\t[1] Add A new student.\n");
    printf("\t[2] Show All students.\n");
    printf("\t[3] Delete A student.\n");
    printf("\t[4] Edit A student.\n");
    printf("\t[5] Search A student.\n");
    printf("\t[6] Sort A student.\n");
    printf("\t[0] Back.\n");
    printf("\t======================\n");
}

void addStudent(int *length, struct Student sv[]) {
    printf("\n\t***Add A New Student***\n");
    int newStudents;
    printf("\nAdd number of Students: ");
    scanf("%d", &newStudents);
    getchar(); 
    int i;
    for (i = *length; i < *length + newStudents; i++) {
        printf("\n       Student %d\n", i + 1);
        printf("Enter the ID: ");
        fgets(sv[i].studentId, 10, stdin);
        sv[i].studentId[strcspn(sv[i].studentId, "\n")] = '\0'; 
        printf("Enter the Name: ");
        fgets(sv[i].fullName, 30, stdin);
        sv[i].fullName[strcspn(sv[i].fullName, "\n")] = '\0';
        printf("Enter the date of birth (dd / mm / yyyy): \n");
        printf("   Enter the day: ");
        scanf("%d", &sv[i].dateOfBrith.day);
        printf("   Enter the month: ");
        scanf("%d", &sv[i].dateOfBrith.month);
        printf("   Enter the year: ");
        scanf("%d", &sv[i].dateOfBrith.year);
        printf("Enter the Gender(1 for Male, 0 for Female): ");
        scanf("%d", &sv[i].gender);
        getchar(); 
        printf("Enter the Class: ");
        fgets(sv[i].classroomId, 10, stdin);
        sv[i].classroomId[strcspn(sv[i].classroomId, "\n")] = '\0';
        printf("Enter the Email: ");
        fgets(sv[i].email, 30, stdin);
        sv[i].email[strcspn(sv[i].email, "\n")] = '\0';
        printf("Enter the Phone: ");
        fgets(sv[i].phone, 20, stdin);
        sv[i].phone[strcspn(sv[i].phone, "\n")] = '\0';
        printf("Enter the Password: ");
        fgets(sv[i].password, 20, stdin);
        sv[i].password[strcspn(sv[i].password, "\n")] = '\0';
    }
    *length += newStudents;
    printf("\nStudent Added Successfully.\n");
}

void printHeader() {
    printf("\n\t  ***All Student***\n");
    printf("|============|=============|============================|=======================|============|============================|=====================|=====================|\n");
    printf("| ID         | ID Class    | FullName                   | Date Of Brith         | Gender     | Email                      | Phone               | Password            |\n");
    printf("|============|=============|============================|=======================|============|============================|=====================|=====================|\n");
}

void printStudent(int length, struct Student sv[]) {
    int i;
    for (i = 0; i < length; i++) {
        printf("| %-11s| %-12s| %-27s| %02d/%02d/%04d            | %-11s| %-27s| %-20s| %-20s|\n",
                sv[i].studentId,
                sv[i].classroomId,
                sv[i].fullName,
                sv[i].dateOfBrith.day,
                sv[i].dateOfBrith.month,
                sv[i].dateOfBrith.year,
                sv[i].gender ? "Male" : "Female",
                sv[i].email,
                sv[i].phone,
                sv[i].password);
        printf("|------------|-------------|----------------------------|-----------------------|------------|----------------------------|---------------------|---------------------|\n");
    }
}

void saveStudentToFile(int length, struct Student sv[]) {
    FILE *fptr = fopen("studentsData.dat", "wb");
    if (fptr == NULL) {
        printf("Cannot open file\n");
        return;
    }
    fwrite(sv, sizeof(struct Student), 50, fptr);
    printf("Student data saved successfully\n");
    fclose(fptr);
}

void loadStudentFromFile(int *length, struct Student sv[]) {
    FILE *fptr = fopen("studentsData.dat", "rb");
    if (fptr == NULL) {
        printf("No data found.\n");
        return;
    }
    *length = fread(sv, sizeof(struct Student), 50, fptr);
    fclose(fptr);
}

void deleteStudent(int *length, struct Student sv[]) {
    printf("\n\t***Delete a Student***\n");
    getchar();
    char id[10];
    printf("\nEnter the student ID to delete: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    int findIndex = -1;
    int i;
    for (i = 0; i < *length; i++) {
        if (strcmp(sv[i].studentId, id) == 0) {
            findIndex = i;
            break;
        }
    }
    if (findIndex == -1) {
        printf("\nStudent with ID %s not found.\n", id);
    } else {
        printf("\nOne Student Found for ID: %s\n", id);
        printf("  Student Information:\n");
        printf("----------------------\n");
        printf("ID Class: %s\n", sv[findIndex].classroomId);
        printf("FullName: %s\n", sv[findIndex].fullName);
        printf("Date Of Brith: %02d/%02d/%04d\n", sv[findIndex].dateOfBrith.day, sv[findIndex].dateOfBrith.month, sv[findIndex].dateOfBrith.year);
        printf("Gender: %s\n", sv[findIndex].gender ? "Male" : "Female");
        printf("Email: %s\n", sv[findIndex].email);
        printf("Phone: %s\n", sv[findIndex].phone);
        printf("Password: %s\n", sv[findIndex].password);
        for (i = findIndex; i < *length - 1; i++) {
            sv[i] = sv[i + 1];
        }
        (*length)--;
        printf("\n\t***Updated The New Student ***\n");
        printHeader();
        printStudent(*length, sv);
        printf("\nStudent Deleted Successfully.\n");
    }
}

void editStudent(int length, struct Student sv[]) {
    printf("\n\t***Edit a Student***\n");
    getchar();
    char id[10];
    printf("\nEnter the student ID to edit: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    int findIndex = -1;
    int i;
    for (i = 0; i < length; i++) {
        if (strcmp(sv[i].studentId, id) == 0) {
            findIndex = i;
            break;
        }
    }
    if (findIndex == -1) {
        printf("\nStudent with ID %s not found.\n", id);
    } else {
        printf("\nOne Student Found for ID: %s\n", id);
        printf("  Student Information:\n");
        printf("----------------------\n");
        printf("ID Class: %s\n", sv[findIndex].classroomId);
        printf("FullName: %s\n", sv[findIndex].fullName);
        printf("Date Of Brith: %02d/%02d/%04d\n", sv[findIndex].dateOfBrith.day, sv[findIndex].dateOfBrith.month, sv[findIndex].dateOfBrith.year);
        printf("Gender: %s\n", sv[findIndex].gender ? "Male" : "Female");
        printf("Email: %s\n", sv[findIndex].email);
        printf("Phone: %s\n", sv[findIndex].phone);
        printf("Password: %s\n", sv[findIndex].password);
        printf("\nEnter new details for student ID: %s\n", id);

        printf("Enter the new Name: ");
        fgets(sv[findIndex].fullName, 30, stdin);
        sv[findIndex].fullName[strcspn(sv[findIndex].fullName, "\n")] = '\0';
        printf("Enter the new Class: ");
        fgets(sv[findIndex].classroomId, 10, stdin);
        sv[findIndex].classroomId[strcspn(sv[findIndex].classroomId, "\n")] = '\0';
        printf("Enter the new Email: ");
        fgets(sv[findIndex].email, 30, stdin);
        sv[findIndex].email[strcspn(sv[findIndex].email, "\n")] = '\0';
        printf("Enter the new Phone: ");
        fgets(sv[findIndex].phone, 20, stdin);
        sv[findIndex].phone[strcspn(sv[findIndex].phone, "\n")] = '\0';
        printf("Enter the new Password: ");
        fgets(sv[findIndex].password, 20, stdin);
        sv[findIndex].password[strcspn(sv[findIndex].password, "\n")] = '\0';
        printf("\n\t***Updated The New Student ***\n");
        printHeader();
        printStudent(length, sv);
        printf("\nStudent Edited Successfully.\n");
    }
}

// giao vien
void menuTeachers() {
    printf("\n***Student Management System Using C***\n");
    printf("\n");
    printf("\t    TEACHER MENU\n");
    printf("\t======================\n");
    printf("\t[1] Add A new teacher.\n");
    printf("\t[2] Show All teachers.\n");
    printf("\t[3] Delete A teacher.\n");
    printf("\t[4] Edit A teacher.\n");
    printf("\t[0] Back.\n");
    printf("\t======================\n");
}

void addTeacher(int *length, struct Teacher teachers[]) {
    printf("\n\t***Add A New Teacher***\n");
    int newTeachers;
    printf("\nAdd number of Teachers: ");
    scanf("%d", &newTeachers);
    getchar(); 
    int i;
    for (i = *length; i < *length + newTeachers; i++) {
        printf("\n       Teacher %d\n", i + 1);
        printf("Enter the ID: ");
        fgets(teachers[i].teacherId, 10, stdin);
        teachers[i].teacherId[strcspn(teachers[i].teacherId, "\n")] = '\0';  // remove newline
        printf("Enter the Name: ");
        fgets(teachers[i].fullName, 30, stdin);
        teachers[i].fullName[strcspn(teachers[i].fullName, "\n")] = '\0';
        printf("Enter the date of birth (dd / mm / yyyy): \n");
        printf("   Enter the day: ");
        scanf("%d", &teachers[i].dateOfBirth.day);
        printf("   Enter the month: ");
        scanf("%d", &teachers[i].dateOfBirth.month);
        printf("   Enter the year: ");
        scanf("%d", &teachers[i].dateOfBirth.year);
        printf("Enter the Gender(1 for Male, 0 for Female): ");
        scanf("%d", &teachers[i].gender);
        getchar();  // consume newline
        printf("Enter the Subject: ");
        fgets(teachers[i].subject, 30, stdin);
        teachers[i].subject[strcspn(teachers[i].subject, "\n")] = '\0';
        printf("Enter the Email: ");
        fgets(teachers[i].email, 30, stdin);
        teachers[i].email[strcspn(teachers[i].email, "\n")] = '\0';
        printf("Enter the Phone: ");
        fgets(teachers[i].phone, 20, stdin);
        teachers[i].phone[strcspn(teachers[i].phone, "\n")] = '\0';
        printf("Enter the Password: ");
        fgets(teachers[i].password, 20, stdin);
        teachers[i].password[strcspn(teachers[i].password, "\n")] = '\0';
    }
    *length += newTeachers;
    printf("\nTeacher Added Successfully.\n");
}

void printTeacherHeader() {
    printf("\n\t  ***All Teachers***\n");
    printf("|============|============================|============================|========================|============|============================|=====================|=====================|\n");
    printf("| ID         | FullName                   | Date Of Birth             | Gender                 | Subject    | Email                      | Phone               | Password            |\n");
    printf("|============|============================|============================|========================|============|============================|=====================|=====================|\n");
}

void printTeacher(int length, struct Teacher teachers[]) {
    int i;
    for (i = 0; i < length; i++) {
        printf("| %-11s| %-27s| %02d/%02d/%04d            | %-11s| %-10s| %-27s| %-20s| %-20s|\n",
                teachers[i].teacherId,
                teachers[i].fullName,
                teachers[i].dateOfBirth.day,
                teachers[i].dateOfBirth.month,
                teachers[i].dateOfBirth.year,
                teachers[i].gender ? "Male" : "Female",
                teachers[i].subject,
                teachers[i].email,
                teachers[i].phone,
                teachers[i].password);
        printf("|------------|----------------------------|----------------------------|------------------------|------------|----------------------------|---------------------|---------------------|\n");
    }
}

void saveTeacherToFile(int length, struct Teacher teachers[]) {
    FILE *fptr = fopen("teachersData.dat", "wb");
    if (fptr == NULL) {
        printf("Cannot open file\n");
        return;
    }
    fwrite(teachers, sizeof(struct Teacher), 50, fptr);
    printf("Teacher data saved successfully\n");
    fclose(fptr);
}

void loadTeacherFromFile(int *length, struct Teacher teachers[]) {
    FILE *fptr = fopen("teachersData.dat", "rb");
    if (fptr == NULL) {
        printf("No data found.\n");
        return;
    }
    *length = fread(teachers, sizeof(struct Teacher), 50, fptr);
    fclose(fptr);
}

void deleteTeacher(int *length, struct Teacher teachers[]) {
    printf("\n\t***Delete a Teacher***\n");
    getchar();
    char id[10];
    printf("\nEnter the teacher ID to delete: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';  
    int findIndex = -1;
    int i;
    for (i = 0; i < *length; i++) {
        if (strcmp(teachers[i].teacherId, id) == 0) {
            findIndex = i;
            break;
        }
    }
    if (findIndex == -1) {
        printf("\nTeacher with ID %s not found.\n", id);
    } else {
        printf("\nOne Teacher Found for ID: %s\n", id);
        printf("  Teacher Information:\n");
        printf("----------------------\n");
        printf("FullName: %s\n", teachers[findIndex].fullName);
        printf("Date Of Birth: %02d/%02d/%04d\n", teachers[findIndex].dateOfBirth.day, teachers[findIndex].dateOfBirth.month, teachers[findIndex].dateOfBirth.year);
        printf("Gender: %s\n", teachers[findIndex].gender ? "Male" : "Female");
        printf("Subject: %s\n", teachers[findIndex].subject);
        printf("Email: %s\n", teachers[findIndex].email);
        printf("Phone: %s\n", teachers[findIndex].phone);
        printf("Password: %s\n", teachers[findIndex].password);
        for (i = findIndex; i < *length - 1; i++) {
            teachers[i] = teachers[i + 1];
        }
        (*length)--;
        printf("\n\t***Updated The New Teacher ***\n");
        printTeacherHeader();
        printTeacher(*length, teachers);
        printf("\nTeacher Deleted Successfully.\n");
    }
}

void editTeacher(int length, struct Teacher teachers[]) {
    printf("\n\t***Edit a Teacher***\n");
    getchar();
    char id[10];
    printf("\nEnter the teacher ID to edit: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';  
    int findIndex = -1;
    int i;
    for (i = 0; i < length; i++) {
        if (strcmp(teachers[i].teacherId, id) == 0) {
            findIndex = i;
            break;
        }
    }
    if (findIndex == -1) {
        printf("\nTeacher with ID %s not found.\n", id);
    } else {
        printf("\nOne Teacher Found for ID: %s\n", id);
        printf("  Teacher Information:\n");
        printf("----------------------\n");
        printf("FullName: %s\n", teachers[findIndex].fullName);
        printf("Date Of Birth: %02d/%02d/%04d\n", teachers[findIndex].dateOfBirth.day, teachers[findIndex].dateOfBirth.month, teachers[findIndex].dateOfBirth.year);
        printf("Gender: %s\n", teachers[findIndex].gender ? "Male" : "Female");
        printf("Subject: %s\n", teachers[findIndex].subject);
        printf("Email: %s\n", teachers[findIndex].email);
        printf("Phone: %s\n", teachers[findIndex].phone);
        printf("Password: %s\n", teachers[findIndex].password);
        printf("\nEnter new details for teacher ID: %s\n", id);

        printf("Enter the new Name: ");
        fgets(teachers[findIndex].fullName, 30, stdin);
        teachers[findIndex].fullName[strcspn(teachers[findIndex].fullName, "\n")] = '\0';
        printf("Enter the new Subject: ");
        fgets(teachers[findIndex].subject, 30, stdin);
        teachers[findIndex].subject[strcspn(teachers[findIndex].subject, "\n")] = '\0';
        printf("Enter the new Email: ");
        fgets(teachers[findIndex].email, 30, stdin);
        teachers[findIndex].email[strcspn(teachers[findIndex].email, "\n")] = '\0';
        printf("Enter the new Phone: ");
        fgets(teachers[findIndex].phone, 20, stdin);
        teachers[findIndex].phone[strcspn(teachers[findIndex].phone, "\n")] = '\0';
        printf("Enter the new Password: ");
        fgets(teachers[findIndex].password, 20, stdin);
        teachers[findIndex].password[strcspn(teachers[findIndex].password, "\n")] = '\0';
        printf("\n\t***Updated The New Teacher ***\n");
        printTeacherHeader();
        printTeacher(length, teachers);
        printf("\nTeacher Edited Successfully.\n");
    }
}

//class
#include <stdio.h>
#include "functions.h"
#include <string.h>

void menuClasses() {
    printf("\n***Student Management System Using C***\n");
    printf("\n");
    printf("\t    CLASS MENU\n");
    printf("\t======================\n");
    printf("\t[1] Add A new class.\n");
    printf("\t[2] Show All classes.\n");
    printf("\t[3] Delete A class.\n");
    printf("\t[4] Edit A class.\n");
    printf("\t[0] Back.\n");
    printf("\t======================\n");
}

void addClass(int *length, struct Class classes[]) {
    printf("\n\t***Add A New Class***\n");
    int newClasses;
    printf("\nAdd number of Classes: ");
    scanf("%d", &newClasses);
    getchar(); // consume newline
    int i;
    for (i = *length; i < *length + newClasses; i++) {
        printf("\n       Class %d\n", i + 1);
        printf("Enter the Class ID: ");
        fgets(classes[i].classId, 10, stdin);
        classes[i].classId[strcspn(classes[i].classId, "\n")] = '\0';  // remove newline
        printf("Enter the Class Name: ");
        fgets(classes[i].className, 30, stdin);
        classes[i].className[strcspn(classes[i].className, "\n")] = '\0';
        printf("Enter the number of students in this class: ");
        scanf("%d", &classes[i].numStudents);
        getchar();  // consume newline
    }
    *length += newClasses;
    printf("\nClass Added Successfully.\n");
}

void printClassHeader() {
    printf("\n\t  ***All Classes***\n");
    printf("|============|============================|========================|\n");
    printf("| Class ID   | Class Name                | Number of Students      |\n");
    printf("|============|============================|========================|\n");
}

void printClass(int length, struct Class classes[]) {
    int i;
    for (i = 0; i < length; i++) {
        printf("| %-11s| %-27s| %-22d|\n",
                classes[i].classId,
                classes[i].className,
                classes[i].numStudents);
        printf("|------------|----------------------------|------------------------|\n");
    }
}

void saveClassToFile(int length, struct Class classes[]) {
    FILE *fptr = fopen("classesData.dat", "wb");
    if (fptr == NULL) {
        printf("Cannot open file\n");
        return;
    }
    fwrite(classes, sizeof(struct Class), 50, fptr);
    printf("Class data saved successfully\n");
    fclose(fptr);
}

void loadClassFromFile(int *length, struct Class classes[]) {
    FILE *fptr = fopen("classesData.dat", "rb");
    if (fptr == NULL) {
        printf("No data found.\n");
        return;
    }
    *length = fread(classes, sizeof(struct Class), 50, fptr);
    fclose(fptr);
}

void deleteClass(int *length, struct Class classes[]) {
    printf("\n\t***Delete a Class***\n");
    getchar();
    char id[10];
    printf("\nEnter the class ID to delete: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0'; 
    int findIndex = -1;
    int i;
    for (i = 0; i < *length; i++) {
        if (strcmp(classes[i].classId, id) == 0) {
            findIndex = i;
            break;
        }
    }
    if (findIndex == -1) {
        printf("\nClass with ID %s not found.\n", id);
    } else {
        printf("\nOne Class Found for ID: %s\n", id);
        printf("  Class Information:\n");
        printf("----------------------\n");
        printf("Class Name: %s\n", classes[findIndex].className);
        printf("Number of Students: %d\n", classes[findIndex].numStudents);
        for (i = findIndex; i < *length - 1; i++) {
            classes[i] = classes[i + 1];
        }
        (*length)--;
        printf("\n\t***Updated The Classes List ***\n");
        printClassHeader();
        printClass(*length, classes);
        printf("\nClass Deleted Successfully.\n");
    }
}

void editClass(int length, struct Class classes[]) {
    printf("\n\t***Edit a Class***\n");
    getchar();
    char id[10];
    printf("\nEnter the class ID to edit: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0'; 
    int findIndex = -1;
    int i;
    for (i = 0; i < length; i++) {
        if (strcmp(classes[i].classId, id) == 0) {
            findIndex = i;
            break;
        }
    }
    if (findIndex == -1) {
        printf("\nClass with ID %s not found.\n", id);
    } else {
        printf("\nOne Class Found for ID: %s\n", id);
        printf("  Class Information:\n");
        printf("----------------------\n");
        printf("Class Name: %s\n", classes[findIndex].className);
        printf("Number of Students: %d\n", classes[findIndex].numStudents);
        printf("\nEnter new details for class ID: %s\n", id);

        printf("Enter the new Class Name: ");
        fgets(classes[findIndex].className, 30, stdin);
        classes[findIndex].className[strcspn(classes[findIndex].className, "\n")] = '\0';
        printf("Enter the new number of Students: ");
        scanf("%d", &classes[findIndex].numStudents);
        printf("\n\t***Updated The Class List ***\n");
        printClassHeader();
        printClass(length, classes);
        printf("\nClass Edited Successfully.\n");
    }
}

