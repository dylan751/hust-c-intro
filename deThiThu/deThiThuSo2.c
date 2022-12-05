#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>

typedef struct {
    char name[30];
    char description[500];
    float rating;
    char address[100];
} restaurant;

void input(restaurant *a, int n){
    int i;
    for(i = 0; i < n; i++){
        __fpurge(stdin);
        printf("Restaurant-%d: \n", i+1);
        printf("Name: ");          scanf("%[^\n]s", a[i].name);
        printf("Description: ");   scanf("%*c%[^\n]s", a[i].description);
        printf("Rating: ");        scanf("%*c%f", &a[i].rating);
        printf("Address: ");       scanf("%*c%[^\n]s", a[i].address);
    }
}

void add(restaurant *a, int n, int N){
    int i;
    for(i = n-N; i < n; i++){
        printf("Restaurant-%d: \n", i+1);
        printf("Name: ");          scanf("%*c%[^\n]s", a[i].name);
        printf("Description: ");   scanf("%*c%[^\n]s", a[i].description);
        printf("Rating: ");        scanf("%*c%f", &a[i].rating);
        printf("Address: ");       scanf("%*c%[^\n]s", a[i].address);
        __fpurge(stdin);
    }
}

/*---Ham in ra 1 thanh phan---*/
void print(restaurant a, int n){
    printf("Name: %s\n", a.name);
    printf("Description: %s\n", a.description);
    printf("Rating: %.2f\n", a.rating);
    printf("Address: %s\n\n", a.address);
}

/*---Ham in ra ca mang---*/
void output(restaurant *a, int n){
    int i;
    
    for(i = 0; i < n; i++){
        printf("Nha hang %d\n", i+1);
        printf("Name: %s\n", a[i].name);
        printf("Description: %s\n", a[i].description);
        printf("Rating: %.2f\n", a[i].rating);
        printf("Address: %s\n\n", a[i].address);
    }
}

/*---Ham kiem tra 2 xau ki tu co giong nhau khong*/
int check(char *a, char *b){
    int i;
    int mark = 1;

    for(i = 0; i < strlen(a); i++){
        /*---Theo bang ma ascii de phan biet chu hoa chu thuong---*/
        if(a[i] == b[i] || a[i] == b[i]-32 || a[i] == b[i]+32){
            continue;
        }
        else{
            mark = 0;
            break;
        }
    }
    if(mark == 1){
        return 1;
    }
    else{
        return 0;
    }
}

void find(restaurant *a, int n, char *x){
    int i;
    int mark;
    for(i = 0; i < n; i++){
        mark = 1;
        if(check(a[i].name, x)){
            print(a[i], n);
            mark = 0;
            break;
        }
        else{
            continue;
        }
    }
    if(mark == 1){
        printf("Can't find any restaurant!\n");
    }
}

void sort(restaurant *a, int n){
    int i, j;
    restaurant tg;
    for(i = n-1; i >= 0; i--){
        for(j = 0; j < i; j++){
            if(a[j].rating < a[j+1].rating){
                tg = a[j];
                a[j] = a[j+1];
                a[j+1] = tg;
            }
        }
    }
    output(a, n);
}

int main(){
    char choice;
    restaurant res[50];
    int n;/*---So nha hang---*/
    int N;/*---So nha hang muon nhap them*/
    while(choice != '6'){
        printf("\n     =====MENU=====\n"
               "|1. Nhap thong tin cac nha hang.|\n"
               "|2. In thong tin cac nha hang.  |\n"
               "|3. Tim kiem theo ten.          |\n"
               "|4. Tim kiem theo mo ta.        |\n"
               "|5. Sap xep.                    |\n"
               "|6. Thoat                       |\n");

        __fpurge(stdin);
        printf("\nInput your choice: ");
        scanf("%c", &choice);

        while(choice > '6' || choice < '1'){
            printf("Invalid! Input again: ");
            __fpurge(stdin);
            scanf("%c", &choice);
        }

        switch(choice){
            case '1': {
                /*---Neu nhap lan dau---*/
                if(res[0].rating == 0){
                    __fpurge(stdin);
                    printf("Input the number of restaurants: ");
                    scanf("%d", &n);
                    while(n <= 0){
                        printf("Invalid number! Input again: ");
                        scanf("%*c%d", &n);
                    }
                    input(res, n);                                                              
                }
                /*---Neu nhap lan 2 tro di---*/
                else{
                    __fpurge(stdin);
                    printf("Input the number of restaurants you want to add: ");
                    scanf("%d", &N);

                    n += N;

                    add(res, n, N);
                }
                break;
            }

            case '2': {
                output(res, n);
                break;
            }

            case '3': {
                char find_name[30];
                printf("Input the name of the restaurant: ");
                scanf("%*c%[^\n]s", find_name);   

                find(res, n, find_name);
                break;
            }

            case '4': {
                
                break;
            }    

            case '5': {
                printf("After being sorted: \n");
                sort(res, n);
                break;
            }        
        }
    }
}