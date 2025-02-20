#include<stdio.h>
#include<string.h>
//Made by PIYUSH RAJNISH
// Function to convert grade to grade point
int getGradePoint(char grade[]) { 
    if (strcmp(grade, "S") == 0 || strcmp(grade, "s") == 0) return 10;
    if (strcmp(grade, "A") == 0 || strcmp(grade, "a") == 0) return 9;
    if (strcmp(grade, "B") == 0 || strcmp(grade, "b") == 0) return 8;
    if (strcmp(grade, "C") == 0 || strcmp(grade, "c") == 0) return 7;
    if (strcmp(grade, "D") == 0 || strcmp(grade, "d") == 0) return 6;
    if (strcmp(grade, "E") == 0 || strcmp(grade, "e") == 0) return 5;
    if (strcmp(grade, "F") == 0 || strcmp(grade, "I") == 0 || strcmp(grade, "DT") == 0 || strcmp(grade, "MP") == 0) return 0;
    return -1; // Invalid grade
}

int main() {
    // Print Title at the Center
    printf("\n============================================\n");
    printf("              GPA CALCULATOR               \n");
    printf("============================================\n");
    int numSubjects;
    printf("Enter the number of subjects: ");
    scanf("%d", &numSubjects);

    float credits[numSubjects];
    char grades[numSubjects][3];
    int gradePoints[numSubjects];
    
    float totalWeightedGradePoints = 0;
    float totalCredits = 0;

    // Input subject-wise credits and grades
    for (int i = 0; i < numSubjects; i++) {
        printf("\nEnter credits for subject %d: ", i + 1);
        scanf("%f", &credits[i]);

        printf("Enter grade for subject %d (S, A, B, C, D, E, F/I/DT/MP): ", i + 1);
        scanf("%s", grades[i]);  // Space before %c to consume any newline character
        
        // Convert grade to grade point
        gradePoints[i] = getGradePoint(grades[i]);
        
        // Check for invalid grade input
        if (gradePoints[i] == -1) {
            printf("Invalid grade entered! Please use only S, A, B, C, D, E, F, I, DT, MP.\n");
            return 1; // Exit with error
        }

        // Compute total weighted grade points and total credits
        totalWeightedGradePoints += credits[i] * gradePoints[i];
        totalCredits += credits[i];
    }

    // Calculate GPA
    float GPA = totalWeightedGradePoints / totalCredits;

    // Output result
    printf("\nTotal Credits: %.2f", totalCredits);
    printf("\nTotal Weighted Grade Points: %.2f", totalWeightedGradePoints);
    printf("\nGPA: %.2f\n", GPA);

    return 0;
}