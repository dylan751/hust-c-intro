#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>

int nhap(){
    int n;
    printf("Nhap so nguyen duong N: ");
    scanf("%d", &n);
    while(n <= 0 || n >= 100){
        printf("Khong hop le! Nhap lai: ");
        scanf("%d", &n);
    }
    return n;
}

void input(int *a, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("So thu-%d: ", i+1);
        scanf("%d", &a[i]);
    }
}

void output(int *a, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void nhap_ten(char a[50][50], int n){
    int i;
    for(i = 0; i < n; i++){
        __fpurge(stdin);
        printf("Ten - %d: ", i+1);
        scanf("%s", a[i]);
    }
    
}

void xuat_ten(char a[50][50], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%s ", a[i]);
    }

    printf("\n");
}

void dao_nguoc(int *a, int n){
    int i, j, tg;
    for(i = 0, j = n-1; i <= n/2, j >= n/2; i++, j--){
        tg = a[i];
        a[i] = a[j];
        a[j] = tg;
    }
}


void in_1_lan(char a[50][50], int n){
    int i, j;
    int mark = 0;

    for(i = 0; i < n; i++){
        mark = 0;
        for(j = i-1; j >= 0; j--){
            if(strcmp(a[i], a[j]) == 0){
                mark = 1;
                break;
            }
        }

        if(mark == 0){
            printf("%s ", a[i]);
            mark = 0;
        }
    }
    printf("\n");
}

void main(){
    char luaChon;
    int n = 0;
    int a[50];
    char name[50][50];

    while(luaChon != '6'){
        printf("                   ===MENU===\n"
               "|1. Nhap mang so nguyen duong.                        |\n"
               "|2. Nhap N ten.                                       |\n"
               "|3. Dao nguoc mang so nguyen.                         |\n"
               "|4. Dem so lan xuat hien cua chu cai trong mang ten.  |\n"
               "|5. In cac ten trong mang ten 1 lan.                  |\n"
               "|6. Thoat chuong trinh.                               |\n");
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
                n = nhap();
                input(a, n);
                output(a, n);
                break;
            }

            case '2': {
                if(n == 0){
                    printf("Xin hay quay lai chuc nang 1!\n");
                }
                else{
                    nhap_ten(name, n);
                    xuat_ten(name, n);
                }
                break;
            }

            case '3': {
                dao_nguoc(a, n);
                output(a, n);
                break;
            }

            case '4': {
                
                break;
            }

            case '5': {
                in_1_lan(name, n);
                break;
            }
        }
    }
}