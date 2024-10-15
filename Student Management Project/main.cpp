#include <stdio.h>
#include <stdlib.h>
#include <string.h>
                                    // Define max users for registration
#define MAX_STUDENTS 100
#define MAX_USERS 100

// Student Structure
struct Student {
    int Id;
    char Name[50];
    int Age;
    char Contact[20];
    char attendance[10];
    char classSection[10];
    float grades[5];
};

// User Structure
struct User {
    char username[50];
    char password[50];
};

// Global arrays to store students and users
struct Student students[MAX_STUDENTS];
struct User users[MAX_USERS];
int totalStudents = 0;
int totalUsers = 0;

                                        // Function prototypes
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
void registerUser();
int loginUser();
void mainMenu();

void addStudent() {
    if(totalStudents >= MAX_STUDENTS) {
        printf("Student list is full\n");
        return;
    }
    struct Student newStudent;
    printf("Enter student id: ");
    scanf("%d", &newStudent.Id);
    printf("Enter student name: ");
    scanf(" %[^\n]%*c", newStudent.Name); // Use this to accept multi-word names
    printf("Enter student age: ");
    scanf("%d", &newStudent.Age);
    printf("Enter student contact: ");
    scanf("%s", newStudent.Contact);

    students[totalStudents] = newStudent;
    totalStudents++;
    printf("Student added successfully\n");
}

void viewStudent() {
    int id;
    printf("Enter student id for view: ");
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
    printf("Enter student id for delete: ");
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
    printf("Enter student id for Modify: ");
    scanf("%d", &id);
    for(int i = 0; i < totalStudents; i++) {
        if(students[i].Id == id) {
            printf("Modify Student Details for ID %d:\n", id);
            printf("Enter new Name: ");
            scanf(" %[^\n]%*c", students[i].Name); // To take multi-word input
            printf("Enter new Age: ");
            scanf("%d", &students[i].Age);
            printf("Enter new Contact Number: ");
            scanf("%s", students[i].Contact);
            printf("Student details updated successfully!\n");
            return;
        }
    }
    printf("Student not found\n");
}

void listAllStudents() {
    if(totalStudents == 0){
        printf("No Students are available\n");
        return;
    }
    printf("All students\n");
    for(int i = 0; i < totalStudents; i++) {
        printf("ID: %d, Name: %s, Age: %d, Contact: %s\n", students[i].Id, students[i].Name,
            students[i].Age, students[i].Contact);
    }
    printf("\n");
}

void saveToFile() {
    FILE *file = fopen("Students.dat", "wb");
    if(file == NULL) {
        printf("File could not be opened\n");
        return;
    }
    fwrite(students, sizeof(struct Student), totalStudents, file);
    fclose(file);
    printf("Data saved to file successfully!\n");
}

void loadFromFile() {
    FILE *file = fopen("Students.dat", "rb");
    if(file == NULL) {
        printf("File could not be opened\n");
        return;
    }
    fread(students, sizeof(struct Student), MAX_STUDENTS, file);
    fclose(file);
    // Set totalStudents based on how many records were actually read
    totalStudents = 0;
    while (totalStudents < MAX_STUDENTS && students[totalStudents].Id != 0) {
        totalStudents++;
    }
    printf("Data loaded from file successfully!\n");
}

void searchByCriteria() {
    int choice;
    char searchName[50];
    int searchAge;
    char searchContact[20];

    printf("Search criteria:\n");
    printf("1. Name\n2. Age\n3. Contact\n");
    scanf("%d", &choice);

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

void markAttendance() {
    int id;
    char attendance[10];
    printf("Enter Student Id to mark attendance: ");
    scanf("%d", &id);

    for(int i = 0; i < totalStudents; i++) {
        if(students[i].Id == id) {
            printf("Mark Attendance (present/Absent): ");
            scanf("%s", attendance);
            strcpy(students[i].attendance, attendance);
            printf("Attendance marked successfully!\n");
            return;
        }
    }
    printf("Student with ID %d not found!\n", id);
}

void manageClass() {
    int id;
    char classSection[10];

    printf("Enter student ID to assign class: ");
    scanf("%d", &id);

    for(int i = 0; i < totalStudents; i++) {
        if(students[i].Id == id) {
            printf("Enter class section: ");
            scanf("%9s", classSection);  // Prevent buffer overflow
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
            for(int j = 0; j < 5; j++) {
                printf("Subject  %d: ", j + 1);
                scanf("%f", &students[i].grades[j]);
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
                printf("Subject %d: %.2f\n", j + 1, students[i].grades[j]);
            }
            return;
        }
    }
    printf("Student with ID %d not found!\n", id);
}

void registerUser() {
    FILE *file = fopen("Users.dat", "ab"); // 'ab' to append binary data
    if (file == NULL) {
        printf("Error opening file for registration!\n");
        return;
    }

    struct User user;
    printf("Enter a username: ");
    scanf("%s", user.username);
    printf("Enter a password: ");
    scanf("%s", user.password);

    fwrite(&user, sizeof(struct User), 1, file);
    fclose(file);

    printf("Registration successful!\n");
}

int loginUser() {
    FILE *file = fopen("Users.dat", "rb");
    if (file == NULL) {
        printf("Error opening file for login!\n");
        return 0; // Return 0 for failed login
    }

    struct User user;
    char username[50], password[50];

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    while (fread(&user, sizeof(struct User), 1, file)) {
        if (strcmp(username, user.username) == 0 && strcmp(password, user.password) == 0) {
            fclose(file);
            printf("Login successful!\n");
            return 1; // Return 1 for successful login
        }
    }

    fclose(file);
    printf("Invalid username or password!\n");
    return 0; // Failed login
}

void mainMenu() {
    int choice, loggedIn = 0;

    while (1) {
        printf("\n--- Main Menu ---\n");
        printf("1. Register\n");
        printf("2. Login\n");
        if (loggedIn) {
            printf("3. Add Student\n");
            printf("4. View Student\n");
            printf("5. Delete Student\n");
            printf("6. Modify Student\n");
            printf("7. List All Students\n");
            printf("8. Mark Attendance\n");
            printf("9. Manage Class\n");
            printf("10. Update Grades\n");
            printf("11. View Grades\n");
            printf("12. Save Data\n");
            printf("13. Load Data\n");
            printf("14. Search By Criteria\n");
        }
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loggedIn = loginUser();
                break;
            case 3:
                if (loggedIn) {
                    addStudent();
                } else {
                    printf("You must be logged in to perform this action.\n");
                }
                break;
            case 4:
                if (loggedIn) {
                    viewStudent();
                } else {
                    printf("You must be logged in to perform this action.\n");
                }
                break;
            case 5:
                if (loggedIn) {
                    deleteStudent();
                } else {
                    printf("You must be logged in to perform this action.\n");
                }
                break;
            case 6:
                if (loggedIn) {
                    modifyStudent();
                } else {
                    printf("You must be logged in to perform this action.\n");
                }
                break;
            case 7:
                if (loggedIn) {
                    listAllStudents();
                } else {
                    printf("You must be logged in to perform this action.\n");
                }
                break;
            case 8:
                if (loggedIn) {
                    markAttendance();
                } else {
                    printf("You must be logged in to perform this action.\n");
                }
                break;
            case 9:
                if (loggedIn) {
                    manageClass();
                } else {
                    printf("You must be logged in to perform this action.\n");
                }
                break;
            case 10:
                if (loggedIn) {
                    updateGrades();
                } else {
                    printf("You must be logged in to perform this action.\n");
                }
                break;
            case 11:
                if (loggedIn) {
                    viewGrades();
                } else {
                    printf("You must be logged in to perform this action.\n");
                }
                break;
            case 12:
                if (loggedIn) {
                    saveToFile();
                } else {
                    printf("You must be logged in to perform this action.\n");
                }
                break;
            case 13:
                if (loggedIn) {
                    loadFromFile();
                } else {
                    printf("You must be logged in to perform this action.\n");
                }
                break;
            case 14:
                if (loggedIn) {
                    searchByCriteria();
                } else {
                    printf("You must be logged in to perform this action.\n");
                }
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

int main() {
    mainMenu();
    return 0;
}
