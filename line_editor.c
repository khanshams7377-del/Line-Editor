#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char lines[MAX_LINES][MAX_LENGTH];
int lineCount = 0;

/* Insert a new line */
void insertLine() {
    int lineNumber;
    char text[MAX_LENGTH];

    printf("\nEnter line number to insert: ");
    scanf("%d", &lineNumber);
    getchar();  // Remove newline from input buffer

    if (lineNumber < 1 || lineNumber > lineCount + 1) {
        printf("Invalid line number!\n");
        return;
    }

    if (lineCount >= MAX_LINES) {
        printf("Document is full!\n");
        return;
    }

    printf("Enter text: ");
    fgets(text, MAX_LENGTH, stdin);

    // Remove newline character
    text[strcspn(text, "\n")] = '\0';

    // Shift lines downward
    for (int i = lineCount; i >= lineNumber; i--) {
        strcpy(lines[i], lines[i - 1]);
    }

    // Insert new line
    strcpy(lines[lineNumber - 1], text);

    lineCount++;

    printf("Line inserted successfully!\n");
}

/* Delete an existing line */
void deleteLine() {
    int lineNumber;

    if (lineCount == 0) {
        printf("\nDocument is empty!\n");
        return;
    }

    printf("\nEnter line number to delete: ");
    scanf("%d", &lineNumber);

    if (lineNumber < 1 || lineNumber > lineCount) {
        printf("Invalid line number!\n");
        return;
    }

    // Shift lines upward
    for (int i = lineNumber - 1; i < lineCount - 1; i++) {
        strcpy(lines[i], lines[i + 1]);
    }

    lineCount--;

    printf("Line deleted successfully!\n");
}

/* Display the document */
void displayDocument() {
    if (lineCount == 0) {
        printf("\nDocument is empty!\n");
        return;
    }

    printf("\n----- DOCUMENT -----\n");

    for (int i = 0; i < lineCount; i++) {
        printf("%d. %s\n", i + 1, lines[i]);
    }

    printf("--------------------\n");
}

/* Main function */
int main() {
    int choice;

    printf("=================================\n");
    printf("       SIMPLE LINE EDITOR\n");
    printf("=================================\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Line\n");
        printf("2. Delete Line\n");
        printf("3. Display Document\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertLine();
                break;

            case 2:
                deleteLine();
                break;

            case 3:
                displayDocument();
                break;

            case 4:
                printf("\nExiting Line Editor...\n");
                return 0;

            default:
                printf("\nInvalid choice! Please enter 1-4.\n");
        }
    }

    return 0;
}