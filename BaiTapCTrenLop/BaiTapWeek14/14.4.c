#include<stdio.h>
#include<stdio_ext.h>

typedef struct {
    int tuSo;
    int mauSo;
} phanSo;



/*-----Ham nhap cac so thap phan-----*/
void input(phanSo *a, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("So thu %d: \n", i+1);
        printf("Nhap tu so: ");    scanf("%d", &a[i].tuSo);
        printf("Nhap mau so: ");   scanf("%*c%d", &a[i].mauSo);
    }
}

/*-----Ham in ra mang cac so thap phan----*/
void output(phanSo *a, int n){
    int i;
    printf("|%-20s|%-21s|\n", "STT", "Phan so");
    for(i = 0; i < n; i++){
        printf("|%-20d|%10d/%-10d|\n", i+1, a[i].tuSo, a[i].mauSo);
    }
}

/*-----Ham dao nguoc cac so thap phan trong mang-----*/
void daoNguoc(phanSo *a, int n){
    int i, tg;
    for(i = 0; i < n; i++){
        tg = a[i].tuSo;
        a[i].tuSo = a[i].mauSo;
        a[i].mauSo = tg;
    }

    printf("Sau khi dao nguoc: \n");
    
    output(a, n);
}

/*-----Ham so sanh 2 so thap phan voi nhau-----*/
void soSanh(phanSo a, phanSo b){
    /*Quy dong roi so sanh tu so*/
    if(a.tuSo*b.mauSo > a.mauSo*b.tuSo){
        printf("%d/%d > %d/%d\n", a.tuSo, a.mauSo, b.tuSo, b.mauSo);
    }
    else if(a.tuSo*b.mauSo < a.mauSo*b.tuSo){
        printf("%d/%d < %d/%d\n", a.tuSo, a.mauSo, b.tuSo, b.mauSo);
    }
    else if(a.tuSo*b.mauSo == a.mauSo*b.tuSo){
        printf("%d/%d = %d/%d\n", a.tuSo, a.mauSo, b.tuSo, b.mauSo);
    }
}

int UCLN(int a, int b){
    //Neu a = 0 -> UCLN(a,b) = b
    //Neu b = 0 -> UCLN(a,b) = a
    if(a == 0 || b == 0){
        return a+b;
    }

    while(a != b){
        if(a > b){
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    return a;
}

void toiGian(phanSo a){
    int i;

    printf("Phan so ban dau: ");
    printf("%d/%d\n", a.tuSo, a.mauSo);

    phanSo a2;

    a2.tuSo = a.tuSo / UCLN(a.tuSo, a.mauSo);
    a2.mauSo = a.mauSo / UCLN(a.tuSo, a.mauSo);

    printf("Phan so toi gian: ");
    printf("%d/%d\n", a2.tuSo, a2.mauSo);
}

void cong(phanSo a, phanSo b){
    phanSo sum;
    sum.tuSo = a.tuSo*b.mauSo + a.mauSo*b.tuSo;
    sum.mauSo = a.mauSo*b.mauSo;

    printf("%d/%d + %d/%d = %d/%d\n", a.tuSo, a.mauSo, b.tuSo, b.mauSo, sum.tuSo, sum.mauSo);
}

void tru(phanSo a, phanSo b){
    phanSo sub;
    sub.tuSo = a.tuSo*b.mauSo - a.mauSo*b.tuSo;
    sub.mauSo = a.mauSo*b.mauSo;
    
    printf("%d/%d - %d/%d = %d/%d\n", a.tuSo, a.mauSo, b.tuSo, b.mauSo, sub.tuSo, sub.mauSo);
}

int main(){
    phanSo num[50];
    int n;
    char luaChon;

    printf("    ==========MENU==========\n");
    printf("|1. Nhap phan so.                |\n");
    printf("|2. In ra bang phan so.          |\n");
    printf("|3. In ra bang phan so dao nguoc.|\n");
    printf("|4. So sanh 2 phan so.           |\n");
    printf("|5. In ra phan so toi gian.      |\n");
    printf("|6. Cong hai phan so.            |\n");
    printf("|7. Tru hai phan so.             |\n");
    printf("|8. Thoat.                       |\n");


    while(luaChon != '8'){
        printf("Nhap lua chon: ");
        __fpurge(stdin);
        scanf("%c", &luaChon); 
        __fpurge(stdin);

        switch(luaChon){
            case '1': {
                printf("Input the number of elements: ");
                scanf("%d", &n);
                __fpurge(stdin);    
                input(num, n);
                break;
            };
            case '2': {
                output(num, n);
                break;
            };
            
            case '3': {
                daoNguoc(num, n);
                break;
            };

            case '4': {
                phanSo a, b;
                printf("Nhap tu so cua a: ");
                fflush(stdin);
                scanf("%d", &a.tuSo);
                printf("Nhap mau so cua a: ");
                fflush(stdin);
                scanf("%d", &a.mauSo);
                printf("Nhap tu so cua b: ");
                fflush(stdin);
                scanf("%d", &b.tuSo);
                printf("Nhap mau so cua b: ");
                fflush(stdin);
                scanf("%d", &b.mauSo);
                soSanh(a, b);
            }

            case '5': {
                phanSo c;
                printf("Nhap tu so cua c: ");
                fflush(stdin);
                scanf("%d", &c.tuSo);
                printf("Nhap mau so cua c: ");
                fflush(stdin);
                scanf("%d", &c.mauSo);
                toiGian(c);
                break;
            }
            
            case '6': {
                phanSo x, y;
                printf("Nhap tu so cua x: ");
                fflush(stdin);
                scanf("%d", &x.tuSo);
                printf("Nhap mau so cua x: ");
                fflush(stdin);
                scanf("%d", &x.mauSo);
                printf("Nhap tu so cua y: ");
                fflush(stdin);
                scanf("%d", &y.tuSo);
                printf("Nhap mau so cua y: ");
                fflush(stdin);
                scanf("%d", &y.mauSo);

                cong(x, y);
                
                break;
            }

            case '7': {
                phanSo x, y;
                printf("Nhap tu so cua x: ");
                fflush(stdin);
                scanf("%d", &x.tuSo);
                printf("Nhap mau so cua x: ");
                fflush(stdin);
                scanf("%d", &x.mauSo);
                printf("Nhap tu so cua y: ");
                fflush(stdin);
                scanf("%d", &y.tuSo);
                printf("Nhap mau so cua y: ");
                fflush(stdin);
                scanf("%d", &y.mauSo);

                tru(x, y);
                break;
            }

            case '8': {
                break;
            }

            default: {
                printf("Khong hop le! Nhap lai!\n ");
            }
        }
    }
}