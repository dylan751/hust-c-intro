#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#define max 5

typedef struct qt {
    char cauhoi[120];
    char pa1[30];
    char pa2[30];
    char pa3[30];
    int dapan;
} qt_type;

typedef struct {
    char name[30];
    int choice[3];
    int diem;
} person;

void check_cau_hoi(int x){
    while(x < 1 || x > 5){
        printf("Khong hop le! Nhap lai: ");
        scanf("%d", &x);
    }
}

void check_dap_an(int x){
    while(x < 1 || x > 3){
        printf("Khong hop le! Nhap lai: ");
        scanf("%d", &x);
    }
}

int check(int x){
    if(x < 1 || x > 5)
        return 1;
    else return 0;
}

void tao_cau_hoi(qt_type *a, int n){
    int i;
    for(i = 0; i < n; i++){
        __fpurge(stdin);
        printf("Cau hoi - %d: ", i+1);  scanf("%[^\n]s", a[i].cauhoi);

        __fpurge(stdin);
        printf("Dap an 1: ");           scanf("%[^\n]s", a[i].pa1);
        
        __fpurge(stdin);
        printf("Dap an 2: ");           scanf("%[^\n]s", a[i].pa2);

        __fpurge(stdin);
        printf("Dap an 3: ");           scanf("%[^\n]s", a[i].pa3);  

        __fpurge(stdin);
        printf("Dap an dung: ");        scanf("%d", &a[i].dapan);
        check_dap_an(a[i].dapan);/*---Dap an phai tu 1 -> 3---*/
    }
}

void in_cau_hoi(qt_type *a, int x){
    printf("Cau %d. %s\n", x, a[x-1].cauhoi);
    printf("1.%-10s2.%-10s3.%-10s\n", a[x-1].pa1, a[x-1].pa2, a[x-1].pa3);
}

void swap(char *a, char *b){
    char *tg;
    
    tg = a;
    a = b;
    b = tg;
}

void dao_dap_an(qt_type *a, int n){
    int i;
    int x;//So hieu cau hoi muon sua
    int y;//So hieu dap an moi
    printf("Nhap so hieu cau hoi muon sua: ");
    scanf("%d", &x);
    check_cau_hoi(x);

    printf("Nhap so hieu dap an moi: ");
    scanf("%d", &y);
    check_dap_an(y); 

    /*---Neu dap an moi trung dap an cu -> khong hop le---*/
    if(y == a[x-1].dapan){
        printf("Khong hop le! Nhap lai: ");
        scanf("%d", &y);
    }

    /*---Dao vi tri dap an moi vs cu cho nhau---*/
    int tg;
    if((y == 1 && a[x-1].dapan == 2) || (y == 2 && a[x-1].dapan == 1)){
        swap(a[x-1].pa1, a[x-1].pa2);
    }
    else if((y == 1 && a[x-1].dapan == 3) || (y == 3 && a[x-1].dapan == 1)){
        swap(a[x-1].pa1, a[x-1].pa3);
    }
    else if((y == 2 && a[x-1].dapan == 3) || (y == 3 && a[x-1].dapan == 2)){
        swap(a[x-1].pa2, a[x-1].pa3);
    }

    printf("Sau khi cap nhat: \n");
    in_cau_hoi(a, x);   
}

void thuc_hien_choi(qt_type *a, int n){
    int i;//So nguoi choi
    int x, y, z;//So hieu cau hoi
    person per[3];//nguoi choi
    
    __fpurge(stdin);
    printf("Nhap ten nguoi choi - 1: ");
    scanf("%[^\n]s", per[1].name);

    printf("Nhap so hieu 3 cau hoi: ");
    scanf("%d%d%d", &x, &y, &z);

    while(x == y || x == z || y == z || check(x) || check(y) || check(z)){
        printf("Khong hop le! Nhap lai so hieu: ");
        scanf("%d%d%d", &x, &y, &z);
    }

    /*---Thuc hien choi---*/
    in_cau_hoi(a, x);

    printf("Nhap cau tra loi : ");
    scanf("%d", &per[1].choice[1]);

    if(per[1].choice[1] == a[x-1].dapan){
        per[1].diem += 1;
    }
    else{
        printf("Tra loi sai!\n");
    }

    in_cau_hoi(a, y);

    printf("Nhap cau tra loi: ");
    scanf("%d", &per[1].choice[2]);

    if(per[1].choice[2] == a[y-1].dapan){
        per[1].diem += 1;
    }
    else{
        printf("Tra loi sai!\n");
    }

    in_cau_hoi(a, z);

    printf("Nhap cau tra loi: ");
    scanf("%d", &per[1].choice[3]);

    if(per[1].choice[3] == a[z-1].dapan){
        per[1].diem += 1;
    }
    else{
        printf("Tra loi sai!\n");
    }

    /*---In ket qua---*/
    printf("Nguoi choi: %-20s - Tong diem: %-10d\n", per[1].name, per[1].diem);
    printf("%-20s%-20s%-20s%-20s\n", "Cau hoi", "P/a lua chon", "P/a dung", "Diem");
    printf("%-20d%-20d%-20d%-20d\n", 1, per[1].choice[1], a[x-1].dapan, per[1].diem);
    printf("%-20d%-20d%-20d%-20d\n", 2, per[1].choice[2], a[y-1].dapan, per[1].diem);
    printf("%-20d%-20d%-20d%-20d\n", 3, per[1].choice[3], a[z-1].dapan, per[1].diem);

}

void main(){
    qt_type question[max];

    char luaChon;

    while(luaChon != '5'){
        printf("\n    =====MENU=====\n"
               "|1. Khoi tao cau hoi.   |\n"
               "|2. In cau hoi.         |\n"
               "|3. Dao dap an.         |\n"
               "|4. Thuc hien choi.     |\n"
               "|5. Thoat chuong trinh. |\n\n");
        __fpurge(stdin);
        printf("Nhap lua chon: ");
        scanf("%c", &luaChon);

        while(luaChon < '1' || luaChon > '5'){
            __fpurge(stdin);
            printf("Khong hop le! Nhap lai: ");
            scanf("%c", &luaChon);
        }

        switch(luaChon){
            case '1': {
                tao_cau_hoi(question, max);
                break;
            }

            case '2': {
                int x;//So hieu cau hoi
                printf("Nhap so hieu cau hoi: ");
                scanf("%d", &x);
                check_cau_hoi(x);

                in_cau_hoi(question, x);
                break;
            }

            case '3': {
                dao_dap_an(question, max);
                break;
            }

            case '4': {
                thuc_hien_choi(question, max);
                break;
            }
        }
    }

}