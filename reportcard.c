#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    int m1, m2, m3;
    int total;
    char grade;
    struct Student *next;
};

// Function to calculate grade from total
char getGrade(int total) {
    if (total >= 270) return 'A';
    else if (total >= 240) return 'B';
    else if (total >= 200) return 'C';
    else if (total >= 150) return 'D';
    else return 'F';
}

// Create new node
struct Student* createNode(char name[], int roll, int m1, int m2, int m3) {
    struct Student *newNode = (struct Student*)malloc(sizeof(struct Student));

    strcpy(newNode->name, name);
    newNode->roll = roll;
    newNode->m1 = m1;
    newNode->m2 = m2;
    newNode->m3 = m3;

    newNode->total = m1 + m2 + m3;
    newNode->grade = getGrade(newNode->total);

    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insert(struct Student **head, char name[], int roll, int m1, int m2, int m3) {
    struct Student *newNode = createNode(name, roll, m1, m2, m3);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Student *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Display all students
void display(struct Student *head) {
    if (head == NULL) {
        printf("\nNo records available.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    struct Student *temp = head;

    while (temp != NULL) {
        printf("\nName: %s", temp->name);
        printf("\nRoll No: %d", temp->roll);
        printf("\nMarks: %d %d %d", temp->m1, temp->m2, temp->m3);
        printf("\nTotal: %d", temp->total);
        printf("\nGrade: %c\n", temp->grade);
        printf("-----------------------\n");

        temp = temp->next;
    }
}

int main() {
    struct Student *head = NULL;
    int n, roll, m1, m2, m3;
    char name[50];

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter name: ");
        scanf(" %[^\n]", name);
        printf("Enter roll number: ");
        scanf("%d", &roll);
        printf("Enter 3 subject marks: ");
        scanf("%d %d %d", &m1, &m2, &m3);

        insert(&head, name, roll, m1, m2, m3);
    }

    display(head);

    return 0;
}
