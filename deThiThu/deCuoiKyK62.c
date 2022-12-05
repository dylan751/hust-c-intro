#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>

typedef struct {
    int ClassID;
    char CourseName[30];
    char Room[10];
    int Day;
    char Slots[10];
} quanLy;

int nhap(){
    int n;
    printf("Nhap so lop hoc: ");
    scanf("%d", &n);
    while(n < 1 || n > 200){
        printf("Khong hop le! Nhap lai: ");
        scanf("%d", &n);
    }
    return n;
}

int bo_sung(int n){
    int k;
    printf("Nhap so lop hoc muon bo sung: ");
    scanf("%d", &k);

    while(n+k > 200 || k < 1){
        printf("Khong hop le! Nhap lai: ");
        scanf("%d", &k);
    }
    return k;
}

void input(quanLy *a, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("Lop hoc-%d: \n", i+1);

        printf("Ma lop: ");                 scanf("%d", &a[i].ClassID);
        while(a[i].ClassID <= 0){
            printf("Khong hop le! Nhap lai: ");
            scanf("%d", &a[i].ClassID);
        }

        __fpurge(stdin);
        printf("Ten hoc phan: ");           scanf("%[^\n]s", a[i].CourseName);

        __fpurge(stdin);
        printf("Phong hoc: ");              scanf("%[^\n]s", a[i].Room);

        printf("Ngay hoc: ");               scanf("%d", &a[i].Day);
        while(a[i].Day < 2 || a[i].Day > 7){
            printf("Khong hop le! Nhap lai: ");
            scanf("%d", &a[i].Day);
        }

        __fpurge(stdin);
        printf("Tiet hoc: ");               scanf("%[^\n]s", a[i].Slots);
    }
}

void add(quanLy *a, int n, int k){
    int i;
    for(i = n-k; i < n; i++){
        printf("Lop hoc-%d: \n", i+1);

        printf("Ma lop: ");                 scanf("%d", &a[i].ClassID);
        while(a[i].ClassID <= 0){
            printf("Khong hop le! Nhap lai: ");
            scanf("%d", &a[i].ClassID);
        }

        __fpurge(stdin);
        printf("Ten hoc phan: ");           scanf("%[^\n]s", a[i].CourseName);

        __fpurge(stdin);
        printf("Phong hoc: ");              scanf("%[^\n]s", a[i].Room);

        printf("Ngay hoc: ");               scanf("%d", &a[i].Day);
        while(a[i].Day < 2 || a[i].Day > 7){
            printf("Khong hop le! Nhap lai: ");
            scanf("%d", &a[i].Day);
        }

        __fpurge(stdin);
        printf("Tiet hoc: ");               scanf("%[^\n]s", a[i].Slots);
    }
}

void in(quanLy *a, int n){
    int i;
    printf("%-10s%-20s%-10s%-8s%-8s\n", "Ma lop", "Ten mon hoc", "Ten phong", "Thu", "Tiet hoc");
    for(i = 0; i < n; i++){
        printf("%-10d%-20s%-10s%-8d%-8s\n", a[i].ClassID, a[i].CourseName, a[i].Room, a[i].Day, a[i].Slots);
    }
}

void tim_kiem_phong(quanLy *a, int n){
    char x[10];//Phong can tim
    int i, count = 0;
    int mark = 1;

    __fpurge(stdin);
    printf("Nhap phong can tim: ");
    scanf("%[^\n]s", x);

    for(i = 0; i < n; i++){
        if(strcmp(x, a[i].Room) == 0){
            count++;
            mark = 0;
        }
    }

    if(mark == 1){
        printf("Khong ton tai phong %s trong danh sach!\n", x);
    }
    else{
        printf("So lop hoc: %d", count);
        printf("\nThong tin cac lop hoc:\n");

        for(i = 0; i < n; i++){
            if(strcmp(x, a[i].Room) == 0){
                printf("%-10d%-20s%-10s%-8d%-8s\n", a[i].ClassID, a[i].CourseName, a[i].Room, a[i].Day, a[i].Slots);
            }
        }
    }
}

void sap_xep(quanLy *a, int n){
    int i, j;
    quanLy tg;

    for(i = n-1; i >= 0; i--){
        for(j = 0; j < i; j++){
            if(a[j].ClassID > a[j+1].ClassID){
                tg = a[j];
                a[j] = a[j+1];
                a[j+1] = tg;
            }
        }
    }
}

void main(){
    char luaChon;
    quanLy class[200];
    int n, k;

    while(luaChon != '6'){
        printf("        ===MENU===\n"
               "|1. Bo sung lop hoc.      |\n"
               "|2. In thong tin lop hoc. |\n"
               "|3. Tim kiem theo phong.  |\n"
               "|4. Sap xep.              |\n"
               "|5. Kiem tra trung phong. |\n"
               "|6. Thoat chuong trinh.   |\n");
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
                if(class[0].Day == 0){
                    n = nhap();
                    input(class, n);
                }
                else{
                    k = bo_sung(n);
                    n += k;
                    add(class, n, k);
                }
                break;
            }

            case '2': {
                in(class, n);
                break;
            }

            case '3': {
                tim_kiem_phong(class, n);
                break;
            }

            case '4': {
                sap_xep(class, n);
                in(class, n);
                break;
            }

            case '5': {
                
                break;
            }
        }
    }
}