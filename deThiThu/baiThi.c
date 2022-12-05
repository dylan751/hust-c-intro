#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>

typedef struct student{
    int score;
    char name[50];
} studen_t;

int so_sv(){
    int n;
    printf("Nhap so sinh vien: ");
    scanf("%d", &n);

    return n;
}

void nhap(studen_t *a, int n){
    int i;
    for(i = 0; i < n; i++){
        __fpurge(stdin);
        printf("\nSinh vien - %d: \n", i+1);
        printf("Ten: ");    scanf("%[^\n]s", a[i].name);
        printf("Diem: ");   scanf("%d", &a[i].score);
        while(a[i].score < 0 || a[i].score > 10){
            printf("Sai diem! Nhap lai: ");
            scanf("%d", &a[i].score);
        }
    }
}

void in(studen_t *a, int n){
    int i;
    printf("\n------Danh sach sinh vien-----\n");
    for(i = 0; i < n; i++){
        printf("%d\t%s\t%d\n", i+1, a[i].name, a[i].score);
    }
}

void sua_diem(studen_t *a){
    int stt;
    int score2; //Diem moi
    printf("\nNhap STT cua sinh vien muon sua diem: ");
    scanf("%d", &stt);

    printf("Nhap diem moi: ");
    scanf("%d", &score2);
    a[stt-1].score = score2;
}

void sapXep(studen_t *a, int n){
    int i, j;
    studen_t tg;
    for(i = n-1; i >= 0; i--){
        for(j = 0; j < i; j++){
            if(a[j].score < a[j+1].score){
                tg = a[j];
                a[j] = a[j+1];
                a[j+1] = tg;
            }

            else if(a[j].score == a[j+1].score){
                if(strcmp(a[j].name, a[j+1].name) > 0){
                    tg = a[j];
                    a[j] = a[j+1];
                    a[j+1] = tg;
                }
            }
        }
    }
}

void in_diem_cao_nhat(studen_t *a, int n){
    int i;
    int max;

    max = a[0].score;
    for(i = 1; i < n; i++){
        max = max > a[i].score ? max : a[i].score;
    }

    printf("\n---Nhung sinh vien co diem cao nhat---\n");
    for(i = 0; i < n; i++){
        if(a[i].score == max){
            printf("%d\t%s\t%d\n", i+1, a[i].name, a[i].score);
        }
    }
}

int main(){
    char luaChon;
    studen_t stu[50];

    int n; //So sinh vien

    while(luaChon != '6'){
        printf("\n            =====MENU=====\n"
               "|1. Nhap thong tin sinh vien.          |\n"
               "|2. In danh sach sinh vien.            |\n"
               "|3. Sua diem sinh vien.                |\n"
               "|4. Sap xep.                           |\n"
               "|5. In ra sinh vien co score cao nhat. |\n"
               "|6. Thoat chuong trinh.                |\n");

        __fpurge(stdin);
        printf("Nhap lua chon: ");
        scanf("%c", &luaChon);

        while((luaChon > '6' || luaChon < '1')){
            __fpurge(stdin);
            printf("Khong hop le! Nhap lai: ");
            scanf("%c", &luaChon);
        }

        switch(luaChon){
            case '1': {
                n = so_sv();
                nhap(stu, n);
                break;
            }

            case '2': {
                in(stu, n);
                break;
            }

            case '3': {
                sua_diem(stu);
                break;
            }

            case '4': {
                sapXep(stu, n);
                break;
            }

            case '5': {
                in_diem_cao_nhat(stu, n);
                break;
            }
        }
    }
    return 0;
}