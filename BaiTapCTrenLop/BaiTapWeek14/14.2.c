#include<stdio.h>
#include<stdio_ext.h>

#define MONTH_NUM 12

typedef struct {
    float totalRainfall;   //Tong luong mua
    float tempMax;         //Nhiet do cao nhat
    float tempMin;         //Nhiet do thap nhat
    float tempAvg;         //Nhiet do trung binh
} weather;

/*-----Ham kiem tra xem du lieu nhap vao co hop le khong-----*/
int check(float x){
    if(x < -40 || x > 50){
        return 0;
    }
    else{
        return 1;
    }
}

/*-----Ham nhap du lieu-----*/
void input(weather *a){
    int i;

    for(i = 0; i < MONTH_NUM; i++){
        printf("Month-%d: \n", i+1);

        printf("Input total rainfall: ");      scanf("%f", &a[i].totalRainfall);
        while(!check(a[i].totalRainfall)){
            printf("Khong hop le! Nhap lai: ");
            scanf("%f", &a[i].totalRainfall);
        }
        
        printf("Input max temperature: ");     scanf("%f", &a[i].tempMax);
        while(!check(a[i].tempMax)){
            printf("Khong hop le! Nhap lai: ");
            scanf("%f", &a[i].tempMax);
        }

        printf("Input min temperature: ");     scanf("%f", &a[i].tempMin);
        while(!check(a[i].tempMin)){
            printf("Khong hop le! Nhap lai: ");
            scanf("%f", &a[i].tempMin);
        }

        printf("Input average temperature: "); scanf("%f", &a[i].tempAvg);
        while(!check(a[i].tempAvg)){
            printf("Khong hop le! Nhap lai: ");
            scanf("%f", &a[i].tempAvg);
        }
    }
}

/*----Ham tinh tong luong mua-----*/
float muaTong(weather *a){
    int i;
    float sum = 0;

    for(i = 0; i < MONTH_NUM; i++){
        sum += a[i].totalRainfall;
    }
    return sum;
}

/*-----Ham tinh luong mua trung binh-----*/
float muaTB(weather *a){
    float muaTB;
    muaTB = muaTong(a) / MONTH_NUM;
    return muaTB;
}

/*-----Ham tinh nhiet do cao nhat nam-----*/
float nhietDoMax(weather *a){
    int i;
    float max;
    max = a[0].tempMax;

    for(i = 1; i < MONTH_NUM; i++){
        max = max > a[i].tempMax ? max : a[i].tempMax;
    }

    return max;
}

/*-----Ham tinh nhiet do thap nhat nam-----*/
float nhietDoMin(weather *a){
    int i;
    float min;
    min = a[0].tempMin;

    for(i = 1; i < MONTH_NUM; i++){
        min = min < a[i].tempMin ? min : a[i].tempMin;
    }

    return min;
}

/*-----Ham in ra bang thong ke-----*/
void output(weather *a){
    printf("%-25s|%-25s|%-25s|%-25s|\n", "Luong mua TB", "Tong luong mua", "Nhiet do cao nhat nam", "Nhiet do thap nhat nam");
    printf("%-25.2f|%-25.2f|%-25.2f|%-25.2f|\n", muaTB(a), muaTong(a), nhietDoMax(a), nhietDoMin(a));
}

int main(){
    weather month[12];
    char luaChon;

    while(luaChon != '3'){
        printf("\t\t\t                 =======MENU=======\n");
        printf("\t\t\t|1. Nhap thong tin luong mua 12 thang.               |\n");
        printf("\t\t\t|2. In ra luong mua TB, tong mua, nhiet do max, min. |\n");
        printf("\t\t\t|3. Thoat chuong trinh.                              |\n");

        printf("Input your choice: ");
        __fpurge(stdin);
        scanf("%c", &luaChon);
        __fpurge(stdin);
    
        switch(luaChon){
            case '1':{
                input(month);
                printf("\n");
                break;
            }

            case '2':{
                muaTB(month);
                muaTong(month);
                nhietDoMax(month);
                nhietDoMin(month);

                output(month);
                printf("\n");
        
                break;
            }

            case '3':{
                break;
            }

            default: {
                while(luaChon != '1' && luaChon != '2' && luaChon != '3'){
                    printf("Khong hop le! Moi nhap lai: ");
                    scanf("%c", &luaChon);
                    __fpurge(stdin);
                }
                break;
            }
        }
    }
}