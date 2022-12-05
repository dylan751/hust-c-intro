#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include<strings.h>

#define Total 4

typedef struct {
    char Name[25];
    int Old;
    int Score[5];
} Game;

void khoi_tao(Game *a, int n){
    int i;
    for(i = 0; i < n; i++){
        a[i].Score[0] = 0;
        a[i].Score[1] = 0;
        a[i].Score[2] = 0;
        a[i].Score[3] = 0;
        a[i].Score[4] = 0;
    }
}

int nhap_nguoi(){
    int n;
    printf("Nhap so nguoi choi: ");
    scanf("%d", &n);
    while(n < 1 || n > 4){
        printf("Khong hop le! Nhap lai: ");
        scanf("%d", &n);
    }
    return n;
}

char* nhap_xau(char *S){
    __fpurge(stdin);
    printf("Nhap xau ky tu [20,40]: ");
    scanf("%s", S);

    while(strlen(S) < 20 || strlen(S) > 40){
        __fpurge(stdin);
        printf("Khong hop le! Nhap lai xau [20,40]: ");
        scanf("%s", S);
    }
    return S;
}

/*---Ham nhap thong tin nguoi choi---*/
void input(Game *a, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("Nguoi choi-%d: \n", i+1);
        __fpurge(stdin);
        printf("Ho ten: ");                 scanf("%[^\n]s", a[i].Name);
        
        printf("Tuoi: ");                   scanf("%d", &a[i].Old);
    }
}

void output(Game *a, int n){
    int i;
    printf("%-20s%-20s\n", "Ho va ten", "Tuoi");
    for(i = 0; i < n; i++){
        printf("%-20s%-20d\n", a[i].Name, a[i].Old);
    }
}

/*---Ham kiem tra ki tu bang nhau khong phan biet hoa thuong---*/
int check(char a, char b){
    if(a == b || a == b+32 || a == b-32){
        return 1;
    }
    else{
        return 0;
    }
}

void doan_ky_tu(Game *a, int n, char *S){
    int i, j;
    char choice[3];
    int mark = 0;//De kiem tra co ky tu day trong chuoi khong
    char result[40]; //Dap an

    printf("Chuoi ky tu can doan: \n");
    for(i = 0; i < strlen(S); i++){
        printf("*");
    }
    printf("\n");

    for(i = 0; i < n; i++){
        printf("%s: \n", a[i].Name);

        /*---Luot choi thu 1---*/
        __fpurge(stdin);
        printf("Nhap lua chon 1: ");
        scanf("%c", &choice[0]);
        mark = 0;
        for(j = 0; j < strlen(S); j++){
            if(check(choice[0], S[j]) == 1){
                printf("%c", S[j]);
                a[i].Score[0] += 1;
                a[i].Score[4] += 1;
                mark = 1;
            }
            else{
                printf("*");
            }
        }
        if(mark == 0){
            printf("\nKhong co ky tu nay!");
        }
        printf("\n");
        
        /*---Luot choi thu 2---*/
        __fpurge(stdin);
        printf("Nhap lua chon 2: ");
        scanf("%c", &choice[1]);

        mark = 0;
        for(j = 0; j < strlen(S); j++){
            if(check(choice[1], S[j]) == 1){
                printf("%c", S[j]);
                a[i].Score[1] += 1;
                a[i].Score[4] += 1;
                mark = 1;
            }
            else if(check(choice[0], S[j]) == 1){
                printf("%c", S[j]);
            }
            else{
                printf("*");
            }
        }
        if(mark == 0){
            printf("\nKhong co ky tu nay!");
        }
        printf("\n");

        /*---Luot choi thu 3---*/
        __fpurge(stdin);
        printf("Nhap lua chon 3: ");
        scanf("%c", &choice[2]);
        
        mark = 0;
        for(j = 0; j < strlen(S); j++){
            if(check(choice[2], S[j]) == 1){
                printf("%c", S[j]);
                a[i].Score[2] += 1;
                a[i].Score[4] += 1;
                mark = 1;
            }
            else if(check(choice[0], S[j]) == 1 || check(choice[1], S[j]) == 1){
                printf("%c", S[j]);
            }
            else{
                printf("*");
            }
        }
        if(mark == 0){
            printf("\nKhong co ky tu nay!");
        }
        printf("\n");

        /*---Luot choi thu 4---*/
        __fpurge(stdin);
        printf("Nhap lua chon 4: ");
        scanf("%c", &choice[3]);

        mark = 0;
        for(j = 0; j < strlen(S); j++){
            if(check(choice[3], S[j]) == 1){
                printf("%c", S[j]);
                a[i].Score[3] += 1;
                a[i].Score[4] += 1;
                mark = 1;
            }
            else if(check(choice[0], S[j]) == 1 || check(choice[1], S[j]) == 1 || check(choice[2], S[j]) == 1){
                printf("%c", S[j]);
            }
            else{
                printf("*");
            }
        }
        if(mark == 0){
            printf("\nKhong co ky tu nay!");
        }
        printf("\n");

        /*---Luot choi cuoi---*/
        __fpurge(stdin);
        printf("Nhap dap an ban doan: ");
        scanf("%s", result);
        if(strcasecmp(result, S) == 0){
            printf("Chuc mung! Ban da doan dung!\n");
            a[i].Score[4] += 20;
        } 
        else{
            printf("That tiec! Ban doan sai\n");
            printf("Dap an dung la: %s\n", S);
        }
    }

    /*---In ket qua---*/
    printf("%-20s%-10s%-10s%-10s%-10s%-20s\n", "Ho va ten", "L1", "L2", "L3", "L4", "Ket qua");
    for(i = 0; i < n; i++){
        printf("%-20s%-10d%-10d%-10d%-10d%-10d\n", a[i].Name, a[i].Score[0], a[i].Score[1], a[i].Score[2], a[i].Score[3], a[i].Score[4]);
    }
}

void in_ket_qua(Game *a, int n){
    int i;
    printf("%-10s%-20s%-20s\n", "STT", "Ho va ten", "Do sai lech");
    for(i = 0; i < n; i++){
        printf("%-10d%-20s%-20d\n", i+1, a[i].Name, a[i].Score[4]);
    }
}

void main(){
    Game person[Total];
    char luaChon;
    char S[40]; //Xau ki tu dap an
    int M; //So nguoi choi
    while(luaChon != '4'){
        printf("       ===MENU===\n"
               "|1. Khoi dong tro choi.  |\n"
               "|2. Choi doan ky tu.     |\n"
               "|3. Tong hop ket qua.    |\n"
               "|4. Thoat chuong trinh.  |\n");

        __fpurge(stdin);
        printf("Nhap lua chon: ");
        scanf("%c", &luaChon);
        while(luaChon < '1' || luaChon > '4'){
            printf("Khong hop le! Nhap lai: ");
            scanf("%c", &luaChon);
        }

        switch(luaChon){
            case '1': {
                nhap_xau(S);
                M = nhap_nguoi();
                input(person, M);
                output(person, M);
                break;
            }

            case '2': {
                khoi_tao(person, M);
                doan_ky_tu(person, M, S);
                break;
            }

            case '3': {
                in_ket_qua(person, M);
                break;
            }
        }
    }
}