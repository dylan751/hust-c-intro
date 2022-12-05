#include<stdio.h>
#include<stdio_ext.h>
#include<math.h>
#include<string.h>

typedef struct {
    int phan_nguyen;
    int tu_so;
    int mau_so;
} hon_so;

int size(){
    int n;
    printf("Input the size of the array: ");
    scanf("%d", &n);

    while(n < 0){
        printf("Invalid size! Input again: ");
        scanf("%d", &n);
    }
    return n;
}

void input(int a[50][50], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("arr[%d][%d]: ", i+1, j+1);
            scanf("%d", &a[i][j]);
        }
    }
}

void check(int a[50][50], int n){
    int i, j;
    int mark;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            mark = 1;
            if(i == j){
                if(a[i][j] == 1){
                    continue;
                }
                else{
                    mark = 0;
                    break;
                }
            }
            else if(i != j){
                if(a[i][j] == 0){
                    continue;
                }
                else{
                    mark = 0;
                    break;
                }
            }
        }
        if(mark == 0){
            break;
        }
    }

    if(mark == 1){
        printf("It's a unit matrix!");
    }
    else{
        printf("It'not a unit matrix!");
    }
}

void print_triangle(char a[50][50], int h, char b){
    int i, j;
    
    if(b == 'X'){
        for(i = 0; i < h; i++){
            for(j = 0; j < (2*h-1); j++){
                if(fabs(j - (h-1)) <= i){
                    a[i][j] = '*';
                }
                else{
                    a[i][j] = ' ';
                }
            }
        }

        for(i = 0; i < h; i++){
            for(j = 0; j < 2*h-1; j++){
                printf("%c", a[i][j]);
            }
            printf("\n");
        }
    }
    else if(b == 'N'){
        /*---Lon nguoc lai---*/
        for(i = h-1; i >= 0; i--){
            for(j = (2*h-1) - 1; j >=0; j--){
                if(fabs(j - (h-1)) <= h-i-1){
                    a[i][j] = '*';
                }
                else{
                    a[i][j] = ' ';
                }
            }
        }

        for(i = 0; i < h; i++){
            for(j = 0; j < 2*h-1; j++){
                printf("%c", a[i][j]);
            }
            printf("\n");
        }
    }
}

int change_num(){
    char num[20];
    int i;
    __fpurge(stdin);
    printf("Input a number: ");
    scanf("%s", num);

    /*---Neu so dau la 0 -> loai bo---*/
    if(num[0] == '0'){
        for(i = 0; i < strlen(num)-1; i++){
            num[i] = num[i+1];
        }
        /*---Xoa ki tu cuoi---*/
        num[strlen(num)-1] = '\0';
    }
    
    /*---11 so thi thay doi---*/
    if(strlen(num) == 11){
        if(num[0] == '1' && num[1] == '6'){
            num[0] = ' ';
            num[1] = '3';
        }
        else{
            printf("Khac nha mang!\n");
            return 0;
        }
    }
    /*---10 so thi giu nguyen---*/
    else if(strlen(num) == 10){
        num[0] = num[0];
        num[1] = num[1];
    }
    /*---Neu nhieu hon 11 so thi chi xet 11 so dau---*/
    else{
        num[11] = '\0';
        if(num[0] == '1' && num[1] == '6'){
            num[0] = ' ';
            num[1] = '3';
        }
    }

    printf("After change: %s", num);
    return 0;
}

/*---Ham nhap hon so---*/
void nhap_hon_so(hon_so *a, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("Hon so thu - %d: \n", i+1);
        printf("Phan nguyen: ");    scanf("%d", &a[i].phan_nguyen);
        printf("Tu so: ");          scanf("%d", &a[i].tu_so);
        printf("Mau so: ");          scanf("%d", &a[i].mau_so);
    }
}

/*---Ham tinh thuong cua 2 hon so---*/
void thuong(hon_so x1, hon_so x2){
    hon_so a;

    if(x2.tu_so == 0){
        printf("Invalid\n");
        return ;
    }

    a.phan_nguyen = ((x1.phan_nguyen*x1.mau_so + x1.tu_so) * x2.mau_so) / (x1.mau_so*(x2.phan_nguyen*x2.mau_so + x2.tu_so));
    a.mau_so = x1.mau_so*(x2.phan_nguyen*x2.mau_so + x2.tu_so);
    a.tu_so = ((x1.phan_nguyen*x1.mau_so + x1.tu_so) * x2.mau_so) - (a.phan_nguyen * a.mau_so);

    printf("%d %d/%d", a.phan_nguyen, a.tu_so, a.mau_so);
}

void main(){
    char choice;
    int n;
    int arr[50][50];
    
    while(choice != '5'){
        printf("\n    =====MENU=====\n"
               "|1. Ma tran.            |\n"
               "|2. Tam giac.           |\n"
               "|3. Chuyen doi so.      |\n"
               "|4. Phan so.            |\n"
               "|5. Thoat chuong trinh. |\n");

        __fpurge(stdin);
        printf("Input your choice: ");
        scanf("%c", &choice);

        while(choice < '1' || choice > '5'){
            __fpurge(stdin);
            printf("Invalid! Input again: ");
            scanf("%c", &choice);
        }

        switch(choice){
            case '1': {
                n = size();
                input(arr, n);
                check(arr, n);
                break;
            }

            case '2': {
                int h;
                char a, arr2[50][50];

                printf("Input the height: ");
                scanf("%d", &h);
                __fpurge(stdin);
                printf("Input 'X' or 'N': ");
                scanf("%c", &a);
                
                print_triangle(arr2, h, a);
                break;
            }

            case '3': {
                change_num();
                break;
            }

            case '4': {
                hon_so hs[2];
                nhap_hon_so(hs, 2);
                thuong(hs[0], hs[1]);
                break;
            }
        }
    }
}