#include<stdio.h>

typedef struct{
    int ngay;
    int thang;
    int nam;
} Date;

/*-----Ham nhap du lieu ngay thang-----*/
void input(Date *a){
    printf("Day: "); scanf("%d", &a[0].ngay);
    while(a[0].ngay > 31 || a[0].ngay < 1){
        printf("Invalid day\nPlease input again: ");
        scanf("%d", &a[0].ngay);
    }

    printf("Month: "); scanf("%d", &a[0].thang);
    while(a[0].thang > 12 || a[0].thang < 1){
        printf("Invalid month\nPlease input again: ");
        scanf("%d", &a[0].thang);
    }

    printf("Year: "); scanf("%d", &a[0].nam);
    while(a[0].nam < 0){
        printf("Invalid year\nPlease input again: ");
        scanf("%d", &a[0].nam);
    }
}

/*-----Ham so sanh 2 ngay bat ki-----*/
int dateCmp(Date *a, Date *b){
    int i;
    for(i = 0; i < 1; i++){
        if(a[i].nam < b[i].nam){
            return -1;
        }
        else if(a[i].nam > b[i].nam){
            return 1;
        }
        else if(a[i].nam == b[i].nam){
            if(a[i].thang < b[i].thang){
                return -1;
            }
            else if(a[i].thang > b[i].thang){
                return 1;
            }
            else if(a[i].thang == b[i].thang){
                if(a[i].ngay < b[i].ngay){
                    return -1;
                }
                else if(a[i].ngay > b[i].ngay){
                    return 1;
                }
                else if(a[i].ngay == b[i].ngay){
                    return 0;
                }
            }
        }
    }
}

int main(){
    Date day1[1], day2[1];
    
    printf("Date 1: \n");
    input(day1);

    printf("Date 2: \n");
    input(day2);

    int check = dateCmp(day1, day2);

    if(check == -1){
        printf("%d/%d/%d < %d/%d/%d!\n", day1[0].ngay, day1[0].thang, day1[0].nam, day2[0].ngay, day2[0].thang, day2[0].nam);
    }
    else if(check == 1){
        printf("%d/%d/%d > %d/%d/%d!\n", day1[0].ngay, day1[0].thang, day1[0].nam, day2[0].ngay, day2[0].thang, day2[0].nam);
    }
    else if(check == 0){
        printf("%d/%d/%d = %d/%d/%d!\n", day1[0].ngay, day1[0].thang, day1[0].nam, day2[0].ngay, day2[0].thang, day2[0].nam);
    }
    
}