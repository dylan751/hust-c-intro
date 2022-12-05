#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>

typedef struct{
    float HD;     //Diem cua giao vien huong dan
    float PB;     //Diem cua giao vien phan bien
    float HDD[3]; //Diem cua 3 giao vien hoi dong
    float giuaKy;
    float cuoiKy;
} point;

typedef struct{
    char MSSV[5];
    char name[30];
    point diem;
} student;

int nhap(){
    int N;
    printf("Nhap so sinh vien: ");
    scanf("%d", &N);

    while(N < 1 || N > 20){
        printf("Khong hop le! Nhap lai: ");
        scanf("%d", &N);
    }
    return N;
}

int check_diem(float n){
    while(n < 0 || n > 10){
        return 0;
    }
}

int check_ho_ten(char *a){
    int i;
    int mark = 0;
    for(i = 0; i < strlen(a); i++){
        if(a[i] != ' '){
            continue;
        }
        else{
            mark = 1;
            break;
        }
    }

    if(a[strlen(a)-1] == ' '){
        return 0;
    }

    if(mark == 0){
        return 0;
    }
    else return 1;
}

int bo_sung(student *a, int n, int k){
    int i, j;
    /*---Lan dau nhap---*/
    if(a[0].diem.HD == 0){
        for(i = 0; i < n; i++){
            __fpurge(stdin);
            printf("Sinh vien - %d: \n", i+1);
            printf("MSSV: ");                        scanf("%s", a[i].MSSV);
            
            for(j = 0; j < n; j++){
                if(i != j){
                    while(strcmp(a[i].MSSV, a[j].MSSV) == 0){
                        __fpurge(stdin);
                        printf("Khong hop le! Nhap lai: ");
                        scanf("%s", a[i].MSSV);
                    }
                }
            }
            
            __fpurge(stdin);
            printf("Ho ten: ");                      scanf("%[^\n]s", a[i].name);
            while(!check_ho_ten(a[i].name)){
                __fpurge(stdin);
                printf("Khong hop le! Nhap lai: ");
                scanf("%[^\n]s", a[i].name);
            }


            printf("Diem huong dan: ");              
            scanf("%f", &a[i].diem.HD);
            while(!check_diem(a[i].diem.HD)){
                printf("Khong hop le! Nhap lai: ");
                scanf("%f", &a[i].diem.HD);
            }
            
            printf("Diem phan bien: ");              
            scanf("%f", &a[i].diem.PB);
            while(!check_diem(a[i].diem.PB)){
                printf("Khong hop le! Nhap lai: ");
                scanf("%f", &a[i].diem.PB);
            }

            printf("3 diem hoi dong (a b c): ");     scanf("%f%f%f", &a[i].diem.HDD[0], &a[i].diem.HDD[1], &a[i].diem.HDD[2]);
            while(!check_diem(a[i].diem.HDD[0]) || !check_diem(a[i].diem.HDD[1]) || !check_diem(a[i].diem.HDD[2])){
                printf("Khong hop le! Nhap lai: ");
                scanf("%f%f%f", &a[i].diem.HDD[0], &a[i].diem.HDD[1], &a[i].diem.HDD[2]);
            }

            /*---Dieu kien de diem giua ki va cuoi ky = 0---*/
            if(a[i].diem.HD < 5.5 || a[i].diem.PB < 5.5 || a[i].diem.HDD[0] < 5.5 || a[i].diem.HDD[1] < 5.5 || a[i].diem.HDD[2] < 5.5){
                a[i].diem.giuaKy = 0;
                a[i].diem.cuoiKy = 0;
            }
            else{
                a[i].diem.giuaKy = (a[i].diem.HD + a[i].diem.PB)/2;
                a[i].diem.cuoiKy = (a[i].diem.HDD[0] + a[i].diem.HDD[1] + a[i].diem.HDD[2])/3;
            }           
        }
    }
    else{
        for(i = n-k; i < n; i++){
             __fpurge(stdin);
            printf("Sinh vien - %d: \n", i+1);
            printf("MSSV: ");                        scanf("%s", a[i].MSSV);

            for(j = 0; j < n; j++){
                if(i != j){
                    while(strcmp(a[i].MSSV, a[j].MSSV) == 0){
                        __fpurge(stdin);
                        printf("Khong hop le! Nhap lai: ");
                        scanf("%s", a[i].MSSV);
                    }
                }
            }

            __fpurge(stdin);
            printf("Ho ten: ");                      scanf("%[^\n]s", a[i].name);
            while(!check_ho_ten(a[i].name)){
                __fpurge(stdin);
                printf("Khong hop le! Nhap lai: ");
                scanf("%[^\n]s", a[i].name);
            }
           
            printf("Diem huong dan: ");              
            scanf("%f", &a[i].diem.HD);
            while(!check_diem(a[i].diem.HD)){
                printf("Khong hop le! Nhap lai: ");
                scanf("%f", &a[i].diem.HD);
            }
            
            printf("Diem phan bien: ");              
            scanf("%f", &a[i].diem.PB);
            while(!check_diem(a[i].diem.PB)){
                printf("Khong hop le! Nhap lai: ");
                scanf("%f", &a[i].diem.PB);
            }

            printf("3 diem hoi dong (a b c): ");     scanf("%f%f%f", &a[i].diem.HDD[0], &a[i].diem.HDD[1], &a[i].diem.HDD[2]);
        
            while(!check_diem(a[i].diem.HDD[0]) || !check_diem(a[i].diem.HDD[1]) || !check_diem(a[i].diem.HDD[2])){
                printf("Khong hop le! Nhap lai: ");
                scanf("%f%f%f", &a[i].diem.HDD[0], &a[i].diem.HDD[1], &a[i].diem.HDD[2]);
            }
            
            /*---Dieu kien de diem giua ki va cuoi ky = 0---*/
            if(a[i].diem.HD < 5.5 || a[i].diem.PB < 5.5 || a[i].diem.HDD[0] < 5.5 || a[i].diem.HDD[1] < 5.5 || a[i].diem.HDD[2] < 5.5){
                a[i].diem.giuaKy = 0;
                a[i].diem.cuoiKy = 0;
            }
            else{
                a[i].diem.giuaKy = (a[i].diem.HD + a[i].diem.PB)/2;
                a[i].diem.cuoiKy = (a[i].diem.HDD[0] + a[i].diem.HDD[1] + a[i].diem.HDD[2])/3;
            }     
        }
    }
    return n;
}

void in(student *a, int n){
    int i;
    printf("%-10s%-20s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "MSSV", "Ho va ten", "HD", "PB", "HDD1", "HDD2", "HDD3", "Giua ky", "Cuoi ky");
    for(i = 0; i < n; i++){
        printf("%-10s%-20s%-10.1f%-10.1f%-10.1f%-10.1f%-10.1f%-10.1f%-10.1f\n", a[i].MSSV, a[i].name, a[i].diem.HD, a[i].diem.PB, a[i].diem.HDD[0], a[i].diem.HDD[1], a[i].diem.HDD[2], a[i].diem.giuaKy, a[i].diem.cuoiKy);
    }
}

void bao_ve_thanh_cong(student *a, int n){
    int i;
    int mark = 0;

    for(i = 0; i < n; i++){
        if(a[i].diem.cuoiKy != 0){
            mark = 1;
        }
    }

    if(mark == 1){
        printf("---Danh sach sinh vien bao ve thanh cong---\n");
        printf("%-10s%-20s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "MSSV", "Ho va ten", "HD", "PB", "HDD1", "HDD2", "HDD3", "Giua ky", "Cuoi ky");
        for(i = 0; i < n; i++){
            if(a[i].diem.giuaKy != 0 && a[i].diem.cuoiKy != 0){
                printf("%-10s%-20s%-10.1f%-10.1f%-10.1f%-10.1f%-10.1f%-10.1f%-10.1f\n", a[i].MSSV, a[i].name, a[i].diem.HD, a[i].diem.PB, a[i].diem.HDD[0], a[i].diem.HDD[1], a[i].diem.HDD[2], a[i].diem.giuaKy, a[i].diem.cuoiKy);
            }
        }
    }
    else{
        printf("Khong co ai bao ve thanh cong!\n");
    }
}

void sap_xep(student *a, int n){
    student b[30];
    int i, j;
    int count;

    /*---Copy ten sang mang b---*/
    for(i = 0; i < n; i++){
        count = 0;
        /*---Dem so ki tu---*/
        j = strlen(a[i].name)-1;
        while(a[i].name[j] != ' '){
            count++;
            j--;
        }

        int k = 0;
        while(count >= 0){
            b[i].name[k] = a[i].name[strlen(a[i].name) - count];
            k++;
            count--;
        }
    }
    student tg;
    for(i = n-1; i >= 0; i--){
        for(j = 0; j < i; j++){
            if(strcmp(b[j].name, b[j+1].name) > 0){
                tg = a[j];
                a[j] = a[j+1];
                a[j+1] = tg;
            }
        }
    }

    printf("%-10s%-20s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "MSSV", "Ho va ten", "HD", "PB", "HDD1", "HDD2", "HDD3", "Giua ky", "Cuoi ky");
    for(i = 0; i < n; i++){
        printf("%-10s%-20s%-10.1f%-10.1f%-10.1f%-10.1f%-10.1f%-10.1f%-10.1f\n", a[i].MSSV, a[i].name, a[i].diem.HD, a[i].diem.PB, a[i].diem.HDD[0], a[i].diem.HDD[1], a[i].diem.HDD[2], a[i].diem.giuaKy, a[i].diem.cuoiKy);
    }    
}

void main(){
    char luaChon;
    student sv[20];
    int N; //So sinh vien

    while(luaChon != '4'){
        printf("               ===MENU===\n"
            "|1. Bo sung sinh vien.                     |\n"
            "|2. Danh sach sinh vien bao ve thanh cong. |\n"
            "|3. Sap xep theo ten sinh vien.            |\n"
            "|4. Thoat chuong trinh.                    |\n");

        __fpurge(stdin);
        printf("Nhap lua chon: ");
        scanf("%c", &luaChon);
        while(luaChon < '1' || luaChon > '4'){
            __fpurge(stdin);
            printf("Khong hop le! Nhap lai: ");
            scanf("%c", &luaChon);
        }

        switch(luaChon){
            case '1': {
                int k = 0;
                if(sv[0].diem.HD == 0){
                    N = nhap();
                    bo_sung(sv, N, k);
                    in(sv, N);
                }
                else{
                    printf("Nhap so sinh vien muon bo sung: ");
                    scanf("%d", &k);
                    while((N + k) > 20){
                        printf("Qua nhieu hoc sinh! Nhap lai: ");
                        scanf("%d", &k);
                    }
                    N = N + k;
                    bo_sung(sv, N, k);
                    in(sv, N);
                }
                
                break;  
            }

            case '2': {
                bao_ve_thanh_cong(sv, N);
                break;
            }

            case '3': {
                sap_xep(sv, N);
                break;
            }
        }
    }
}