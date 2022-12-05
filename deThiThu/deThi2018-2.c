#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include<strings.h>

typedef struct {
    char Name[30];
    char Id[12];
    char Home_town[30];
    float GPA;
} student;

int nhap(){
    int n;
    printf("Nhap so sinh vien: ");
    scanf("%d", &n);
    while(n < 0){
        printf("Khong hop le! Nhap lai: ");
        scanf("%d", &n);
    }
    return n;
}

int bo_sung(){
    int k;
    printf("Nhap so sinh vien muon bo sung: ");
    scanf("%d", &k);

    while(k < 0){
        printf("Khong hop le! Nhap lai: ");
        scanf("%d", &k);
    }
    return k;
}

void input(student *a, int n){
    int i;
    for(i = 0; i < n; i++){
        __fpurge(stdin);
        printf("Sinh vien-%d: \n", i+1);
        printf("Ten: ");                    scanf("%[^\n]s", a[i].Name);

        __fpurge(stdin);
        printf("MSSV: ");                   scanf("%[^\n]s", a[i].Id);

        __fpurge(stdin);
        printf("Que quan: ");               scanf("%[^\n]s", a[i].Home_town);

        printf("GPA: ");                    scanf("%f", &a[i].GPA);
        while(a[i].GPA < 0 || a[i].GPA > 4){
            printf("Khong hop le! Nhap lai GPA: ");
            scanf("%f", &a[i].GPA);
        }
    }
}

void add(student *a, int n, int k){
    int i;
    for(i = n-k; i < n; i++){
         __fpurge(stdin);
        printf("Sinh vien-%d: \n", i+1);
        printf("Ten: ");                    scanf("%[^\n]s", a[i].Name);

        __fpurge(stdin);
        printf("MSSV: ");                   scanf("%[^\n]s", a[i].Id);

        __fpurge(stdin);
        printf("Que quan: ");               scanf("%[^\n]s", a[i].Home_town);

        printf("GPA: ");                    scanf("%f", &a[i].GPA);
        while(a[i].GPA < 0 || a[i].GPA > 4){
            printf("Khong hop le! Nhap lai GPA: ");
            scanf("%f", &a[i].GPA);
        }
    }
}

void in(student *a, int n){
    int i;
    /*---Tim GPA trung binh---*/
    float sum = 0, TB = 0;//Diem GPA trung binh
    for(i = 0; i < n; i++){
        sum += a[i].GPA;
    }

    TB = sum/n;

    /*---In---*/
    printf("%-8s%-20s%-20s%-20s%-20s\n", "STT", "Ten", "MSSV", "QueQuan", "GPA");
    for(i = 0; i < n; i++){
        printf("%-8d%-20s%-20s%-20s%-19.1f\n", i+1, a[i].Name, a[i].Id, a[i].Home_town, a[i].GPA);
    }
    printf("Diem GPA trung binh cua tat ca sinh vien: %.1f\n", TB);
}

void tim_kiem_MSSV(student *a, int n){
    char mssv[12];
    int i;
    int mark = 1;

    __fpurge(stdin);
    printf("Nhap ma so sinh vien muon tim: ");
    scanf("%[^\n]s", mssv);

    for(i = 0; i < n; i++){
        if(strcmp(a[i].Id, mssv) == 0){
            printf("%-8s%-20s%-20s%-20s%-20s\n", "STT", "Ten", "MSSV", "QueQuan", "GPA");
            printf("%-8d%-20s%-20s%-20s%-19.1f\n", i+1, a[i].Name, a[i].Id, a[i].Home_town, a[i].GPA);
            mark = 0;
            break;
        }
    }

    if(mark == 1){
        printf("Khong tim thay sinh vien nao!\n");
    }
}

void tim_kiem_GPA_que(student *a, int n){
    int i, mark = 1;
    float sum = 0, TB = 0;//Diem GPA trung binh
    char queQuan[30];

    for(i = 0; i < n; i++){
        sum += a[i].GPA;
    }

    TB = sum/n;

    __fpurge(stdin);
    printf("Nhap que quan: ");
    scanf("%[^\n]s", queQuan);

    for(i = 0; i < n; i++){
        if(strcasecmp(a[i].Home_town, queQuan) == 0){
            if(a[i].GPA > TB){
                printf("%-8s%-20s%-20s%-20s%-20s\n", "STT", "Ten", "MSSV", "QueQuan", "GPA");
                printf("%-8d%-20s%-20s%-20s%-19.1f\n", i+1, a[i].Name, a[i].Id, a[i].Home_town, a[i].GPA);
                mark = 0;
            }
        }
    }

    if(mark == 1){
        printf("Khong tim thay sinh vien nao!\n");
    }
}

void sap_xep(student *a, int n){
    int i, j;
    student tg;

    for(i = n-1; i >= 0; i--){
        for(j = 0; j < i; j++){
            if(a[j].GPA < a[j+1].GPA){
                tg = a[j];
                a[j] = a[j+1];
                a[j+1] = tg;
            }
        }
    }
}

void main(){
    char luaChon;
    student sv[50];
    int n;//So sinh vien
    int k;//So sinh vien bo sung
    while(luaChon != '6'){
        printf("           ===MENU===\n"
               "|1. Nhap thong tin sinh vien.       |\n"
               "|2. In thong tin sinh vien.         |\n"
               "|3. Tim kiem theo ma so sinh vien.  |\n"
               "|4. Tim kiem theo GPA va que quan.  |\n"
               "|5. Sap xep.                        |\n"
               "|6. Thoat.                          |\n");
        __fpurge(stdin);
        printf("Nhap lua chon: ");
        scanf("%c", &luaChon);
        
        while(luaChon < '1' || luaChon > '6'){
            __fpurge(stdin);
            printf("Khong hop le! Nhap lai: ");
            scanf("%c", &luaChon);
        }

        switch(luaChon){
            case '1': {
                if(sv[0].GPA == 0){
                    n = nhap();
                    input(sv, n);
                }
                else{
                    k = bo_sung();
                    n += k;
                    add(sv, n, k);
                }
                break;
            }

            case '2': {
                in(sv, n);
                break;
            }

            case '3': {
                tim_kiem_MSSV(sv, n);
                break;
            }

            case '4': {
                tim_kiem_GPA_que(sv, n);
                break;
            }

            case '5': {
                sap_xep(sv, n);
                in(sv, n);
                break;
            }
        }
    }
}