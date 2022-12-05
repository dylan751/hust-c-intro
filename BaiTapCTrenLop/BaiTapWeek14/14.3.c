#include<stdio.h>

/*-----Dang bi loi phan ten-----*/
typedef struct {
    char id[10];
    char name[31];
    float grade;
    char classement;  //Phan loai
} student;

void input(student *a, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("Student-%d: \n", i+1);
        printf("Name: ");   scanf("%*c%[^\n]s", a[i].name);
        printf("Id: ");     scanf("%*c%[^\n]s", a[i].id);
        printf("Grade: ");  scanf("%*c%f", &a[i].grade);
    }
}

void xepLoai(student *a, int n){
    int i;
    for(i = 0; i < n; i++){
        if(a[i].grade > 9){
            a[i].classement = 'A';
        }
        else if(a[i].grade > 8){
            a[i].classement = 'B';
        }
        else if(a[i].grade > 6.5){
            a[i].classement = 'C';
        }
        else a[i].classement = 'D';
    }
}

void output(student *a, int n){
    int i;
    printf("|%-20s|%-20s|%-20s|%-20s|\n", "Ten", "MSSV", "Diem", "Phan loai");
    
    for(i = 0; i < n; i++){
        printf("|%-20s|%-20s|%-20.2f|%-20c|\n", a[i].name, a[i].id, a[i].grade, a[i].classement);
    }
}

void sapXep(student *a, int n){
    int i, j;
    student tg;
    for(i = n-1; i >= 0; i--){
        for(j = 0; j < i; j++){
            if(a[j].grade < a[j+1].grade){
                tg = a[j];
                a[j] = a[j+1];
                a[j+1] = tg;
            }
        }
    }
    
}

int main(){
    student stu[50];
    int n;

    printf("Input the number of students: ");
    scanf("%d", &n);

    input(stu, n);
    xepLoai(stu, n);
    sapXep(stu, n);
    output(stu, n);
    return 0;
}