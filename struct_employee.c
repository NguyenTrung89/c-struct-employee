#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct details
{
    char name[30];
    int id;
    float salary;
} emp[5];
int n;

void menu() {
    int ch;
    while(1) {
        printf("--------------------------------\n");
        printf("\t\tMenu\n");
        printf("--------------------------------\n");
        printf("\n 1. Insert employee");
        printf("\n 2. Display all employee");
        printf("\n 3. Display employee Name by salary");
        printf("\n 4. Search");
        printf("\n 5. Exit");
        printf("\nEnter your choice:");
        scanf("\n %d", &ch);

        switch(ch){
            case 1:
                insertEmployee();
                break;
            case 2:
                getAllEmployee(n);
                break;
            case 3:
                employeeCheckSalary(n);
                break;
            case 4:
                employeeSearch(n);
                break;
            case 5:
                exit(0);

        }
    }

}

void insertEmployee(){
    int i;
    printf("Enter the number of employee: \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter employee details: \n");
        printf("ID: ");
        scanf("%d", &emp[i].id);
        fflush(stdin);
        printf("Name of Employee: ");
        gets(emp[i].name);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }

}

void getAllEmployee(int ida){
    int i;
    for (i = 0; i < ida; i++) {
        printf("%d\t%s\t%f\n", emp[i].id, emp[i].name, emp[i].salary);
    }
}

void employeeCheckSalary(int ida){
    int i;
    float salaryCheck;
    printf("\nDetails of Employee whose salary = ?\n>>");
    scanf("%f", &salaryCheck);
    for (i = 0; i < ida ; i++) {
        if (emp[i].salary > salaryCheck) {
            // printf("Employee id: %d\n", emp[i].id);
            // printf("Name: %s\n", emp[i].name);
            // printf("Salary: %f\n", emp[i].salary);
            printf("%d\t%s\t%f\n", emp[i].id, emp[i].name, emp[i].salary);
        }
    }
}

void employeeSearch(int ida){
    int idf, i;
    int ch = 0;
    printf("\nEnter employee id: ");
    scanf("%d", &idf);
    for (i = 0; i < ida; i++) {
        if (emp[i].id == idf) {
            // printf("Employee id: %d\n", emp[i].id);
            // printf("Name: %s\n", emp[i].name);
            // printf("Salary: %f\n", emp[i].salary);
            ch = 1;
            printf("%d\t%s\t%f\n", emp[i].id, emp[i].name, emp[i].salary);
        }
    }
    if (ch == 0) printf("No employee with ID: %d\n", idf);
}

int main() {
    menu();
    return 0;
}
