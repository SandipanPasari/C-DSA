#include <stdio.h>

struct student {
    char name[50];
    int roll;
};

void display(struct student stu) {
    printf("Student details \n");
    printf("Name: %s\n", stu.name);
    printf("Roll number: %d\n", stu.roll);
}

int main() { 
    struct student students[3];
    for (int i = 0; i < 3; i++) {
        printf("Enter student %d name: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter student %d roll: ", i + 1);
        scanf("%d", &students[i].roll);
    }
    
    for (int i = 0; i < 3; i++) {
        display(students[i]);
    }
    
    return 0;
}
