#include<stdio.h>
#include<stdio_ext.h>
#include<math.h>

int input(void){
    int n;
    printf("Nhap 1 so nguyen duong: ");
    scanf("%d", &n);

    while(n <= 0){
        printf("Xin hay nhap 1 so nguyen duong: ");
        scanf("%d", &n);
    }
    return n;
}

void in_ngoi_sao(int n){
    char a[20][20];
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(j < (n-i)){
                a[i][j] = '*';
            }
            else{
                a[i][j] = ' ';
            }
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
}

void in_so_chinh_phuong(int n){
    int i;
    
    if(n == 1){
        printf("Khong co so chinh phuong nao nho hon 1\n");
    }
    else{
        printf("So chinh phuong nho hon %d la: ", n);
        for(i = 1; i <= sqrt(n); i++){
            printf("%5d", i*i);
        }
        printf("\n");
    }
}

void check_nguyen_to(int n){
    int i;
    int mark = 1;
    if(n < 2){
        printf("1 khong la so nguyen to!\n");
    }
    else{
        for(i = 2; i < sqrt(n); i++){
            if(n%i == 0){
                mark = 0;
                break;
            }
            else{
                continue;
            }
        }

        if(mark == 1){
            printf("%d la so nguyen to!\n", n);
        }
        else{
            printf("%d khong la so nguyen to!\n", n);
        }
    }
}

void check_so_hoan_thien(int n){
    int i, sum =0;

    /*---Tinh tong cac uoc---*/
    for(i = 1; i < n; i++){
        if(n%i == 0){
            sum += i;
        }
    }

    if(sum == n){
        printf("%d la so hoan thien!\n", n);
    }
    else{
        printf("%d khong la so hoan thien!\n", n);
    }
}

void main(){
    char luaChon = 0;
    int n;

    while(luaChon != '6'){
        printf("         ===MENU===\n"
            "|1. Nhap vao mot so nguyen duong. |\n"
            "|2. In ra hinh ngoi sao.          |\n"
            "|3. In ra cac so chinh phuong.    |\n"
            "|4. Kiem tra tinh nguyen to.      |\n"
            "|5. Kiem tra tinh hoan thien.     |\n"
            "|6. Thoat.                        |\n");
        __fpurge(stdin);
        printf("\nNhap lua chon: ");
        scanf("%c", &luaChon);

        while(luaChon < '1' || luaChon > '6'){
            __fpurge(stdin);
            printf("Khong hop le! Nhap lai: ");
            scanf("%c", &luaChon);
        }

        switch(luaChon){
            case '1': {
                n = input();
                break;
            }

            case '2': {
                in_ngoi_sao(n);
                break;
            }

            case '3': {
                in_so_chinh_phuong(n);
                break;
            }

            case '4': {
                check_nguyen_to(n);
                break;
            }

            case '5': {
                check_so_hoan_thien(n);
                break;
            }
        }
    }
}