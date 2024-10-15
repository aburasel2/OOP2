#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
                                    //Student Structure;

struct Student {
    int Id;
    char Name[50];
    int Age;
    char Contact[20];
    char attendance[50];
    char classSection[10];
    float grades[5];
};
                            //Global array to store students

struct Student students[MAX_STUDENTS];

int totalStudents;


                            // Function add a students
void addStudent() {
    if(totalStudents >= MAX_STUDENTS) {
        printf("student list is full\n");
        return;
    }
    struct Student newStudent;
    printf("Enter student id:");
    scanf("%d", &newStudent.Id);
    printf("Enter student name:");
    scanf("%s", newStudent.Name);
    printf("Enter student age:");
    scanf("%d", &newStudent.Age);
    printf("Enter student contact:");
    scanf("%s", newStudent.Contact);

    students[totalStudents] = newStudent;
    totalStudents++;
    printf("Student added successfully\n");
}
                                       //Function to view a student by id

void viewStudent() {
    int id;
    printf("Enter student id for view:");
    scanf("%d", &id);


    for(int i = 0; i < totalStudents; i++) {
        if(students[i].Id == id) {
            printf("Student Details:\n");
            printf("ID: %d\n", students[i].Id);
            printf("Name: %s\n", students[i].Name);
            printf("Age: %d\n", students[i].Age);
            printf("Contact: %s\n", students[i].Contact);
            return;
        }
    }
    printf("Student not found\n");
}
void deleteStudent() {
    int id;
    printf("Enter student id for delete:");
    scanf("%d", &id);

    for(int i = 0; i < totalStudents; i++) {
        if(students[i].Id == id) {
            for(int j = i; j < totalStudents - 1; j++) {
                students[j] = students[j + 1];
            }
            totalStudents--;
            printf("Student deleted successfully\n");
            return;
        }
    }
    printf("Student not found\n");
}

void modifyStudent() {
    int id;
    printf("Enter student id for Modify:");
    scanf("%d", &id);
    for(int i = 0; i < totalStudents; i++) {
        if(students[i].Id == id) {
            printf("Modify Student Details for ID %d:\n", id);
            printf("Enter new Name:\n");
            scanf(" %[^\n]%*c", students[i].Name); // To take multi-word input
            printf("Enter new Age:\n");
            scanf("%d", &students[i].Age);
            printf("Enter new Contact Number:\n");
            scanf("%s", students[i].Contact);
            printf("Student details updated successfully!\n");
            return;
        }
    }
    printf("Student not found\n");
}

void listAllStudents() {
    if(totalStudents == 0){
        printf("No Students is available\n");
        return;
    }
    printf("All students\n");
    for(int i = 0; i < totalStudents; i++) {
        printf("ID: %d, name: %s, Age: %d, Contact: %s\n",students[i].Id, students[i].Name,
            students[i].Age,
            students[i].Contact);
    }
    printf("\n");

}
                                   //Function to save students to a file
void saveToFile() {
    FILE *file = fopen("Students.dat", "wb");
    if (file == NULL) {
        printf("Error: File could not be opened for writing.\n");
        return;
    }

    // Write totalStudents to the file first
    if (fwrite(&totalStudents, sizeof(int), 1, file) != 1) {
        printf("Error: Could not write total number of students to file.\n");
        fclose(file);
        return;
    }

    // Write the students array to the file
    if (fwrite(students, sizeof(struct Student), totalStudents, file) != (size_t)totalStudents) {
        printf("Error: Could not write student data to file.\n");
        fclose(file);
        return;
    }

    fclose(file);
    printf("Data saved to file successfully!\n");
}



void loadFromFile() {
    FILE *file = fopen("Students.dat", "rb");
    if (file == NULL) {
        printf("File not found. Starting with an empty student list.\n");
        totalStudents = 0; // Initialize to 0 if file doesn't exist
        return;
    }

    // Read totalStudents from the file first
    if (fread(&totalStudents, sizeof(int), 1, file) != 1) {
        printf("Error: Could not read total number of students from file.\n");
        fclose(file);
        return;
    }

    // Validate totalStudents
    if (totalStudents < 0 || totalStudents > MAX_STUDENTS) {
        printf("Error: Invalid number of students in file.\n");
        fclose(file);
        totalStudents = 0; // Reset to prevent undefined behavior
        return;
    }

    // Read the students array from the file
    if (fread(students, sizeof(struct Student), totalStudents, file) != (size_t)totalStudents) {
        printf("Error: Could not read student data from file.\n");
        fclose(file);
        totalStudents = 0; // Reset to prevent undefined behavior
        return;
    }

    fclose(file);
    printf("Data loaded from file successfully!\n");
}


void searchByCriteria() {
    int choice;
    char searchName[50];
    int searchAge;
    char searchContact[50];

    printf("Enter search name:");
    printf("1. name\n2. Age\n3. Contact\n");
    scanf("%d",&choice);

    if (choice == 1) {
        printf("Enter name to search: ");
        scanf(" %[^\n]%*c", searchName);
        for (int i = 0; i < totalStudents; i++) {
            if (strcmp(students[i].Name, searchName) == 0) {
                printf("ID: %d, Name: %s, Age: %d, Contact: %s, Attendance: %s\n", students[i].Id,
                    students[i].Name, students[i].Age, students[i].Contact, students[i].attendance);
            }
        }
    } else if (choice == 2) {
        printf("Enter age to search: ");
        scanf("%d", &searchAge);
        for (int i = 0; i < totalStudents; i++) {
            if (students[i].Age == searchAge) {
                printf("ID: %d, Name: %s, Age: %d, Contact: %s, Attendance: %s\n", students[i].Id,
                    students[i].Name, students[i].Age, students[i].Contact, students[i].attendance);
            }
        }
    } else if (choice == 3) {
        printf("Enter contact to search: ");
        scanf("%s", searchContact);
        for (int i = 0; i < totalStudents; i++) {
            if (strcmp(students[i].Contact, searchContact) == 0) {
                printf("ID: %d, Name: %s, Age: %d, Contact: %s, Attendance: %s\n", students[i].Id,
                students[i].Name, students[i].Age, students[i].Contact, students[i].attendance);
            }
        }
    } else {
        printf("Invalid choice!\n");
    }
}

                            //fuction to mark attendance for a student by Id
void markAttendance() {
    int id;
    char attendance[10];
    printf("Enter Student Id to mark attendance: ");
    scanf("%d", &id);


    for(int i = 0; i < totalStudents; i++) {
        if(students[i].Id == id) {
            printf("Mark Attendance (present/Absent)");
            scanf("%s", attendance);
            strcpy(students[i].attendance, attendance);
            saveToFile();
            printf("Student Details saved to file successfully!",id,attendance);
            return;
        }
    }
    printf("Student with ID %d not found!\n", id);
}
                   //Function to manage class for a student
void manageClass() {
    int id;
    char classSection[10];

    printf("Enter student ID to assign class: ");
    scanf("%d", &id);

    for(int i = 0; i < totalStudents; i++) {
        if(students[i].Id == id) {
            printf("Enter class section: ");
            scanf("%9s", classSection);  // Prevent buffer overflow

            // Safely copy class section
            strncpy(students[i].classSection, classSection, sizeof(students[i].classSection) - 1);
            students[i].classSection[sizeof(students[i].classSection) - 1] = '\0';

            printf("Class updated for student ID %d\n", id);
            return;
        }
    }
    printf("Student with ID %d not found!\n", id);
}


void updateGrades(){
    int id;
    printf("Enter student id to update grade: ");
    scanf("%d", &id);


    for(int i = 0; i < totalStudents; i++) {
        if(students[i].Id == id) {
            printf("Enter grades for 5 subjects: \n");
            for(int j=0; j < 5; j++) {
                printf("Subject  %d: ",j+1);
                scanf("%f", &students[i].grades[j]);  // Use %f for float
            }
            printf("Grade updated for student ID %d\n", id);
            return;
        }


    }
    printf("Student with ID %d not found!\n", id);
}

void viewGrades() {
    int id;
    printf("Enter student id to view grades: ");
    scanf("%d", &id);
    for(int i = 0; i < totalStudents; i++) {
        if(students[i].Id == id) {
            printf("Grades for Student Id %d:\n", id);
            for(int j = 0; j < 5; j++) {
                printf("Subject %d: %f\n", j + 1, students[i].grades[j]);  // Use %f for float
            }

            return;
        }
    }
    printf("Student with ID %d not found!\n", id);
}


                                            //function phototype
void addStudent();
void viewStudent();
void deleteStudent();
void modifyStudent();
void listAllStudents();
void markAttendance();
void saveToFile();
void loadFromFile();
void searchByCriteria();
void manageClass();
void updateGrades();
void viewGrades();

int main() {
    int choice;

    loadFromFile();

    while(1) {
        printf("1. Add Student\n");
        printf("2. View Student\n");
        printf("3. Delete Student\n");
        printf("4. Modify Student\n");
        printf("5. List All Students\n");
        printf("6. Search by Criteria\n");
        printf("7. Mark Attendance\n");
        printf("8. Manage Class\n");
        printf("9. Update Grades\n");
        printf("10. View Grades\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudent();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                modifyStudent();
                break;
            case 5:
                listAllStudents();
                break;
            case 6:
                searchByCriteria();
                break;
            case 7:
                markAttendance();
                break;
            case 8:
                manageClass();
                break;
            case 9:
                updateGrades();
                break;
            case 10:
                viewGrades();
                break;
            case 11:
                saveToFile();
            return 0;
            default:
                printf("Invalid choice\n");

        }
    }

}