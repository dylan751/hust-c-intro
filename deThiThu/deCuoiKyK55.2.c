#include<stdio.h>
#include<stdio_ext.h>

#define MAX 10

typedef struct times{
    int hour;   /*Gia tri tu 0-23*/
    int minute; /*Gia tri tu 0-59*/
} time_t;

typedef struct com_type{
    int number; /*So hieu*/
    int free; /*Trang thai may roi-ban neu free la 1-0*/
    time_t beginTime;
    time_t endTime;
    long fee; /*Tien thu duoc tai may tu dau ngay*/
    int time_used; /*Tong so phut may chay trong ngay*/
} computer;

void khoi_tao(computer *a, int n){
    int i;
    for(i = 0; i < n; i++){
        a[i].number = i+1;;
        a[i].free = 1;
        a[i].beginTime.hour = 0;
        a[i].beginTime.minute = 0;
        a[i].endTime.hour = 0;
        a[i].endTime.minute = 0;
        a[i].fee = 0;
        a[i].time_used = 0;
    }

    printf("%-10s%-10s%-10s%-10s%-10s%-10s\n", "STT", "status", "begin", "end", "fee", "time_used");
    for(i = 0; i < n; i++){
        printf("%-10d%-10s%-10s%-10s%-10ld%-10d\n", a[i].number, "free", "00:00", "00:00", a[i].fee, a[i].time_used);
    }
}

/*---Ham kiem tra tinh hop le thoi gian---*/
int invalidTime(time_t a){
    if(a.hour < 0 || a.hour > 23 || a.minute < 0 || a.minute > 59){
        return 1; //Thoi gian khong hop le
    }
    else{
        return 0; //Thoi gian hop le
    }
}

/*---Ham so sanh 2 thoi gian---*/
int timeCompare(time_t a, time_t b){
    if(a.hour < b.hour){
        return -1;//a truoc b
    }
    else if(a.hour > b.hour){
        return 1;//a sau b
    }
    else{
        if(a.minute < b.minute){
            return -1;//a truoc b
        }
        else if(a.minute > b.minute){
            return 1;//a sau b
        }
        else return 0;//a trung b
    }
}

void dung_may(computer *a, int n){
    int x;
    int i;
    printf("Nhap so hieu may muon su dung: ");
    scanf("%d", &x);
    while(x < 1 || x > 10){
        printf("Khong hop le! Nhap lai: ");
        scanf("%d", &x);
    }

    while(a[x-1].free == 0){
        printf("May ban! Chon may khac: ");
        scanf("%d", &x);
    }

    if(a[x-1].free == 1){
        printf("Nhap thoi gian bat dau (Gio:phut): ");     
        scanf("%d:%d", &a[x-1].beginTime.hour, &a[x-1].beginTime.minute);

        /*---Neu thoi gian khong hop le -> nhap lai---*/
        while(invalidTime(a[x-1].beginTime)){
            printf("Thoi gian khong hop le! Nhap lai: ");
            scanf("%d:%d", &a[x-1].beginTime.hour, &a[x-1].beginTime.minute);
        }
        a[x-1].free = 0;//May tro thanh may ban
    }

    /*---Neu tat ca cac may deu ban---*/
    int mark = 1;
    for(i = 0; i < n; i++){
        if(a[i].free == 0){
            continue;
        }
        else{/*---Neu co may roi -> mark = 0---*/
            mark = 0; 
            break;
        }
    }
    if(mark == 1){
        printf("Tat ca may deu ban! Quay lai sau!");
    }
}

void nghi_choi(computer *a, int n){
    int x;
    int i;
    printf("Nhap so hieu may muon nghi: ");
    scanf("%d", &x);
    while(x < 1 || x > 10){
        printf("Khong hop le! Nhap lai: ");
        scanf("%d", &x);
    }

    while(a[x-1].free == 1){
        printf("May nay chua duoc su dung! Nhap lai: ");
        scanf("%d", &x);
    }

    if(a[x-1].free == 0){
        printf("Nhap thoi gian ket thuc (Gio:phut):  ");
        scanf("%d:%d", &a[x-1].endTime.hour, &a[x-1].endTime.minute);
    
        /*---Neu thoi gian khong hop le -> nhap lai---*/
        while(invalidTime(a[x-1].endTime) || timeCompare(a[x-1].beginTime, a[x-1].endTime) > -1){
            printf("Thoi gian khong hop le! Nhap lai: ");
            scanf("%d:%d", &a[x-1].endTime.hour, &a[x-1].endTime.minute);
        }
    }

    
    /*---So phut su dung dich vu---*/
    int phut = (a[x-1].endTime.hour - a[x-1].beginTime.hour)*60 + (a[x-1].endTime.minute - a[x-1].beginTime.minute);
    a[x-1].time_used += phut; //Tong thoi gian su dung may thu x
    
    long tien = phut*100;//So tien 1 lan su dung
    a[x-1].fee += tien;//Tong so tien thu duoc tai may thu x
    /*---In ra hoa don---*/
    printf("\nHOA DON THANH TOAN\n");
    printf("%-25s:%d:%d\n", "Thoi gian bat dau", a[x-1].beginTime.hour, a[x-1].beginTime.minute);
    printf("%-25s:%d:%d\n", "Thoi gian ket thuc", a[x-1].endTime.hour, a[x-1].endTime.minute);
    printf("%-25s:%d\n", "So phut dung dich vu", phut);
    printf("%-25s:%dx100 = %ld VND\n", "Tien phai tra", phut, tien);
    
    a[x-1].free = 1;//May thanh roi
}

void chuyen_may(computer *a, int n){
    int x, y; //x: May dang dung`, y: May muon chuyen sang
    printf("Nhap so hieu may dang su dung: ");
    scanf("%d", &x);
    while(x < 1 || x > 10){
        printf("Khong hop le! Nhap lai: ");
        scanf("%d", &x);
    }

    printf("Nhap so hieu may muon chuyen sang: ");
    scanf("%d", &y);
    while(y < 1 || y > 10){
        printf("Khong hop le! Nhap lai: ");
        scanf("%d", &y);
    }

    if(a[x-1].free == 0 && a[y-1].free == 1){//Neu may dang dung` ban + may chuyen toi roi~
        a[y-1].beginTime = a[x-1].beginTime;
        a[y-1].endTime = a[x-1].endTime;
        
        a[y-1].free = 0;//Thanh may ban
        a[x-1].free = 1;//Thanh may roi

        /*---Khoi tao lai may cu---*/
        a[x-1].beginTime.hour = 0;
        a[x-1].beginTime.minute = 0;
        a[x-1].endTime.hour = 0;
        a[x-1].endTime.minute = 0;
    }
    else{
        printf("Xin loi! Khong the chuyen may!");
        return;
    }
}

void sap_xep(computer *a, int n){
    int i, j;
    computer tg;

    for(i = n-1; i >= 0; i--){
        for(j = 0; j < i; j++){
            if(a[j].fee < a[j+1].fee){
                tg = a[j];
                a[j] = a[j+1];
                a[j+1] = tg;
            }
        }
    }
}

void in_trang_thai(computer *a, int n){
    int i;

    printf("%-10s%-10s%-10s%-10s%-10s%-10s\n", "STT", "status", "begin", "end", "fee", "time_used");
    for(i = 0; i < n; i++){
        if(a[i].free == 1){
            printf("%-10d%-10s%-d:%-8d%-d:%-8d%-10ld%-10d\n", i+1, "free", a[i].beginTime.hour, a[i].beginTime.minute, a[i].endTime.hour, a[i].endTime.minute, a[i].fee, a[i].time_used);
        }
        else{
            printf("%-10d%-10s%-d:%-8d%-d:%-8d%-10ld%-10d\n", i+1, "busy", a[i].beginTime.hour, a[i].beginTime.minute, a[i].endTime.hour, a[i].endTime.minute, a[i].fee, a[i].time_used);
        }
    }
}

void goi_y(computer *a, int n){
    int i;
    int min;//Thoi gian dung it nhat
    int num; //So thu tu cua may duoc goi y
    int mark = 1;
    for(i = 0; i < n; i++){
        if(a[i].free == 1){
            min = a[i].time_used; //Tim may dau tien roi~
            num = i;
            mark = 0;//Neu tim duoc may roi~ -> mark = 0
            break;
        }
        else{
            continue;
        }
    }
    if(mark == 1){
        printf("Khong co may nao dang roi~!");
        return;
    }

    /*---Tim may co thoi gian su dung it nhat---*/
    int count;

    for(i = 0; i < n; i++){
        count = 1;
        while(count < n-i){
            if(a[i].free == 1 && a[i+count].free == 1){
                min = min < a[i+count].time_used ? min : a[i+count].time_used;
                num = min < a[i+count].time_used ? num : i+count;
            }
            else count++;
        }
    }

    printf("Ban nen su dung may - %d!\n", num+1);
}

void main(){
    computer com[50];
    char luaChon;
    int x;  //So hieu may nguoi dung muon su dung

    while(luaChon != '8'){
        printf("\n    =====MENU=====\n"
               "|1. Khoi tao du lieu.                   |\n"
               "|2. Dung may.                           |\n"
               "|3. Nghi choi.                          |\n"
               "|4. Chuyen may.                         |\n"
               "|5. In ra trang thai toan bo phong may. |\n"
               "|6. Sap xep theo so tien giam dan.      |\n"
               "|7. Goi y dung may.                     |\n"
               "|8. Thoat chuong trinh.                 |\n");
        __fpurge(stdin);
        printf("Nhap lua chon: ");
        scanf("%c", &luaChon);
        while(luaChon < '1' || luaChon > '8'){
            __fpurge(stdin);
            printf("Khong hop le! Nhap lai: ");
            scanf("%c", &luaChon);
        }    

        switch(luaChon){
            case '1': {
                khoi_tao(com, MAX);
                break;
            }

            case '2': {
                dung_may(com, MAX);
                break;
            }
            
            case '3': {
                nghi_choi(com, MAX);
                break;
            }

            case '4': {
                chuyen_may(com, MAX);
                break;
            }

            case '5': {
                in_trang_thai(com, MAX);
                break;
            }

            case '6': {
                sap_xep(com, MAX);
                in_trang_thai(com,MAX);
                break;
            }

            case '7': {
                goi_y(com, MAX);
                break;
            }
        }
    }
}