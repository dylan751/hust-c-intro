#include<stdio.h>
#include<stdio_ext.h>
#define MAX 10

typedef struct {
    char hoten[30];
    int diem[5];
} ketQuaThiDau; 

int soVanDongVien(){
    int n;
    printf("Nhap so van dong vien: ");
    scanf("%d", &n);
    while(n < 1 || n > 10){
        printf("Khong hop le! Nhap lai: ");
        scanf("%d", &n);
    }

    return n;
}

void nhap_ten(ketQuaThiDau *a, int n){
    int i;
    for(i = 0; i < n; i++){
        __fpurge(stdin); 
        printf("\nVDV - %d: \n", i+1);
        printf("Ho va ten: ");      
        scanf("%[^\n]s", a[i].hoten);
    }
}

void in_danh_sach(ketQuaThiDau *a, int n){
    int i;
    printf("\n---Danh sach van dong vien---\n");
    for(i = 0; i < n; i++){
        printf("%-10d%-10s\n", i+1, a[i].hoten);
    }
}

void nhap_ket_qua(ketQuaThiDau *a, int n){
    int i;
    int j;//So lan ban
    for(i = 0; i < n; i++){
        printf("VDV - %d: \n", i+1);
        
        for(j = 0; j < 5; j++){
            printf("Diem luot ban - %d: ", j+1);    
            scanf("%d", &a[i].diem[j]);

            while(a[i].diem[j] < 0 || a[i].diem[j] > 10){
                printf("Khong hop le! Nhap lai diem: ");
                scanf("%d", &a[i].diem[j]);
            }
        }
    }
}

void in_ket_qua(ketQuaThiDau *a, int n){
    int i;
    printf("---ket qua thi dau---\n");
    printf("%-20s%-10d%-10d%-10d%-10d%-10d\n", "Ho ten", 1, 2, 3, 4, 5);
    for(i = 0; i < n; i++){
        printf("%-20s%-10d%-10d%-10d%-10d%-10d\n", a[i].hoten, a[i].diem[0], a[i].diem[1], a[i].diem[2], a[i].diem[3], a[i].diem[4]);
    }
}

void sap_xep(ketQuaThiDau *a, int *sum, int n){
    int i, j;
    ketQuaThiDau tg;
    int x;
    char thu_hang[10];
    for(i = n-1; i >= 0; i--){
        for(j = 0; j < i; j++){
            if(sum[j] < sum[j+1]){
                tg = a[j];
                a[j] = a[j+1];
                a[j+1] = tg;

                x = sum[j];
                sum[j] = sum[j+1];
                sum[j+1] = x;
            }
        }
    }

}

void xep_hang(ketQuaThiDau *a, int n){
    int i, j;//j: So lan ban
    int sum[MAX];//Tong diem thi dau
    int max1, max2, max3;

    for(i = 0; i < n; i++){
        sum[i] = 0;
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < 5; j++){
            sum[i] += a[i].diem[j];
        }
    }

    /*---Sap xep tu lon -> be de tim max1, max2, max3---*/
    sap_xep(a, sum, n);
    /*Luc nay, sum[0[ > sum[1] > sum[2]*/
    printf("%-20s%-10s%-10d\n", a[0].hoten, "Gold", sum[0]);
    printf("%-20s%-10s%-10d\n", a[1].hoten, "Silver", sum[1]);
    printf("%-20s%-10s%-10d\n", a[2].hoten, "Bronze", sum[2]);
}

void sieu_xa_thu(ketQuaThiDau *a, int n){
    int i, j;//j: So lan ban
    printf("\n---Danh sach cac sieu xa thu---\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < 3; j++){
            if(a[i].diem[j] == 10 && a[i].diem[j+1] == 10 && a[i].diem[j+2] == 10){
                printf("%-10s\n", a[i].hoten);
                break;
            }
        }
    }
}

void main(){
    ketQuaThiDau vdv[MAX];
    char luaChon;
    int n;//So van dong vien

    while(luaChon != '5'){
        printf("\n    =====MENU=====\n"
               "|1. Dang ky van dong vien. |\n"
               "|2. Thi dau.               |\n"
               "|3. Xep hang.              |\n"
               "|4. Sieu xa thu.           |\n"
               "|5. Thoat chuong trinh.    |\n");

        __fpurge(stdin);
        printf("\nNhap lua chon: ");
        scanf("%c", &luaChon);
        while(luaChon < '1' || luaChon > '5'){
            __fpurge(stdin);
            printf("Khong hop le! Nhap lai: ");
            scanf("%c", &luaChon);
        }

        switch(luaChon){
            case '1':{
                n = soVanDongVien();
                nhap_ten(vdv, n);
                in_danh_sach(vdv, n);
                break;
            }

            case '2':{
                nhap_ket_qua(vdv, n);
                in_ket_qua(vdv, n);
                break;
            }

            case '3':{
                xep_hang(vdv, n);
                break;
            }

            case '4':{
                sieu_xa_thu(vdv, n);
                break;
            }
        }


    }

}