#include<stdio.h>
#include<stdio_ext.h>
#include<math.h>

typedef struct {
    int id;
    char name[30];
    int x, y;
    int r;
} station;

void nhap(station *a, int n){
    int i;
    

    for(i = 0; i < n; i++){
        printf("Tram-%d:\n", i+1);
        printf("Nhap ma so cua tram: ");
        scanf("%*c%d", &a[i].id);
        printf("Nhap ten truong tram: ");
        scanf("%*c%[^\n]s", a[i].name);
        printf("Nhap hoanh do cua tram: ");
        scanf("%*c%d", &a[i].x);
        printf("Nhap tung do cua tram: ");
        scanf("%*c%d", &a[i].y);
        printf("Nhap ban kinh phu song: ");
        scanf("%*c%d", &a[i].r);
        while(a[i].r < 1 || a[i].r > 100){
            printf("Khong hop le! Nhap lai: ");
            scanf("%*c%d", &a[i].r);  
        }
    }

}

void boSung(station *a, int n, int N){
    int i;

    for(i = n-N; i < n; i++){
        printf("Nhap ma so cua tram: ");
        scanf("%d", &a[i].id);
        printf("Nhap ten truong tram: ");
        scanf("%*c%[^\n]s", a[i].name);
        printf("Nhap hoanh do cua tram: ");
        scanf("%*c%d", &a[i].x);
        printf("Nhap tung do cua tram: ");
        scanf("%*c%d", &a[i].y);
        printf("Nhap ban kinh phu song: ");
        scanf("%*c%d", &a[i].r);
        while(a[i].r < 1 || a[i].r > 100){
            printf("Khong hop le! Nhap lai: ");
            scanf("%*c%d", &a[i].r);  
        }
    }
}

void xuat1(station *a, int n){
    int i;

    printf("%-20s%-20s%-20s%-20s\n", "ID", "Ho ten", "Toa do", "Ban kinh");

    for(i = 0; i < n; i++){
        printf("%-20d%-20s%c%-d,%-d%-16c%-20d\n", a[i].id, a[i].name, '(', a[i].x, a[i].y, ')', a[i].r);
    }
}

float khoangCach(int x, int y){
    float kc;
    kc = sqrt(pow(x, 2) + pow(y, 2));

    return kc;
}

void xuat2(station *a, int n){
    int i;

    printf("%-20s%-20s%-20s%-20s%-20s\n", "ID", "Ho ten", "Toa do", "Ban kinh", "Khoang cach");

    for(i = 0; i < n; i++){
        printf("%-20d%-20s%c%-d,%-d%-16c%-20d%-20.2f\n", a[i].id, a[i].name, '(', a[i].x, a[i].y, ')', a[i].r, khoangCach(a[i].x, a[i].y));
    }
}

void sapXep(station *a, int n){
    int i, j;
    station tg;
    for(i = n-1; i >= 0; i--){
        for(j = 0; j < i; j++){
            if(khoangCach(a[j].x, a[j].y) < khoangCach(a[j+1].x, a[j+1].y)){
                tg = a[j];
                a[j] = a[j+1];
                a[j+1] = tg;
            }
        }
    }
}

int main(){
    station list[50];
    int n;
    int N;/*---Bo sung them---*/

    printf("      =====MENU=====\n");
    printf("|1. Nhap moi tram thu phat|\n");
    printf("|2. Bo sung tram thu phat |\n");
    printf("|3. Xem danh sach tram    |\n");
    printf("|4. Tinh toan khoang cach |\n");
    printf("|5. Thoat                 |\n");

    char luaChon;
    while(luaChon != '5'){
        printf("Nhap lua chon: ");
        __fpurge(stdin);
        scanf("%c", &luaChon);
        __fpurge(stdin);

        switch(luaChon){
            case '1': {
                printf("Nhap so tram phat: ");
                scanf("%d", &n);

                while(n < 1 || n > 50){
                    printf("Khong hop le! Nhap lai: ");
                    scanf("%d", &n);
                    __fpurge(stdin);
                }

                nhap(list, n);
                break;
            }

            case '2': {
                printf("Nhap so tram muon bo sung: ");
                scanf("%d", &N);

                n += N;

                while(n > 50){
                    printf("Khong hop le! Nhap lai: ");
                    scanf("%d", &N);
                }
                
                boSung(list, n, N);
                break;
            }

            case '3': {
                xuat1(list, n);
                break;
            }

            case '4': {
                xuat2(list, n);

                sapXep(list, n);
                xuat2(list, n);
            }
        }
    }
}
