#include <stdio.h>

void runGWACalculator();
struct Subject {
  char name[20];
  float grade;
  int numOfUnits;
};
float computeGWA(struct Subject subjectsToCompute[], int length);



int main() {

  runGWACalculator();

}

void runGWACalculator() {
  
  int numOfSubjects;
  printf("Enter number of subjects: ");
  scanf("%d", &numOfSubjects);

  struct Subject subjects[numOfSubjects];
  
  for (int i = 0; i < numOfSubjects; i++) {
    printf("-----------------------------------\n");
    printf("Subject #%d\n\n", i+1);
    printf("Subject Name    : ");
    scanf("%s", &subjects[i].name);
    printf("Subject Grade   : ");
    scanf("%f", &subjects[i].grade);
    printf("Number of Units : ");
    scanf("%d", &subjects[i].numOfUnits);
  }

  printf("\n----------------------------------------------------------------------------\n");
  printf("GRADES\n\n");
  for (int i = 0; i < numOfSubjects; i++) {
    printf("%s\n\n", subjects[i].name);
    printf("Grade: %.2f\n", subjects[i].grade);
    printf("Units: %d\n", subjects[i].numOfUnits);
    printf("-----------------------------------\n");
  }
  printf("GWA: %f\n", computeGWA(subjects, numOfSubjects));

 
}

float computeGWA(struct Subject subjectsToCompute[], int length) {

  float units = 0;
  float totalGrades = 0;
  float gwa;
  for (int i = 0; i < length; i++) {
    units += subjectsToCompute[i].numOfUnits;
    totalGrades += (subjectsToCompute[i].grade * subjectsToCompute[i].numOfUnits);
  }

  gwa = totalGrades/units;
  return gwa;
}