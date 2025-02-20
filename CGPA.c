#include <stdio.h>

// Function to convert grade to grade point
int getGradePoint(char grade) {
    switch (grade) {
        case 'S': return 10;
        case 'A': return 9;
        case 'B': return 8;
        case 'C': return 7;
        case 'D': return 6;
        case 'E': return 5;
        default: return 0; // Any other grade (F, I, DT, MP) returns 0
    }
}

// Function to calculate GPA for a semester
float calculateGPA(int numSubjects) {
    float credits[numSubjects];
    char grades[numSubjects];
    int gradePoints[numSubjects];

    float totalWeightedGradePoints = 0;
    float totalCredits = 0;

    for (int i = 0; i < numSubjects; i++) {
        printf("\nEnter credits for subject %d: ", i + 1);
        scanf("%f", &credits[i]);

        printf("Enter grade for subject %d (S, A, B, C, D, E, F/I/DT/MP): ", i + 1);
        scanf(" %c", &grades[i]); // Space before %c to consume any newline character

        // Convert grade to grade point
        gradePoints[i] = getGradePoint(grades[i]);

        // Compute total weighted grade points and total credits
        totalWeightedGradePoints += credits[i] * gradePoints[i];
        totalCredits += credits[i];
    }

    // Calculate GPA
    return totalWeightedGradePoints / totalCredits;
}

int main() {
    // Print CGPA Title at the Center
    printf("\n============================================\n");
    printf("              CGPA CALCULATOR               \n");
    printf("============================================\n");

    int numSemesters;
    printf("\nEnter the number of semesters: ");
    scanf("%d", &numSemesters);

    float GPAs[numSemesters];
    float totalCredits = 0;
    float totalWeightedGPA = 0;

    // Loop through each semester to calculate GPA
    for (int i = 0; i < numSemesters; i++) {
        int numSubjects;
        printf("\nEnter the number of subjects for semester %d: ", i + 1);
        scanf("%d", &numSubjects);

        // Calculate GPA for the semester
        GPAs[i] = calculateGPA(numSubjects);

        // Ask for total credits of that semester
        float semesterCredits;
        printf("Enter total credits for semester %d: ", i + 1);
        scanf("%f", &semesterCredits);

        // Compute CGPA-related values
        totalWeightedGPA += GPAs[i] * semesterCredits;
        totalCredits += semesterCredits;
    }

    // Calculate CGPA
    float CGPA = totalWeightedGPA / totalCredits;

    // Output the CGPA result
    printf("\n============================================\n");
    printf("              CGPA RESULT                    \n");
    printf("============================================\n");
    printf("Total Credits: %f\n", totalCredits);
    printf("Total Weighted GPA: %.2f\n", totalWeightedGPA);
    printf("CGPA: %.2f\n", CGPA);
    printf("============================================\n");

    return 0;
}