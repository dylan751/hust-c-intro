#include<stdio.h>
#include<stdio_ext.h>

void main(){
    char luaChon;

    while(luaChon != '6'){
        printf("           ===MENU===\n"
               "|1. Nhap thong tin sinh vien.       |\n"
               "|2. In thong tin sinh vien.         |\n"
               "|3. Tim kiem theo ma so sinh vien.  |\n"
               "|4. Tim kiem theo GPA va que quan.  |\n"
               "|5. Sap xep.                        |\n"
               "|6. Thoat.                          |\n");
        __fpurge(stdin);
        printf("Nhap lua chon: ");
        scanf("%c", &luaChon);
        
        while(luaChon < '1' || luaChon > '6'){
            __fpurge(stdin);
            printf("Khong hop le! Nhap lai: ");
            scanf("%c", &luaChon);
        }

        switch(luaChon){
            case '1': {

                break;
            }

            case '2': {

                break;
            }

            case '3': {

                break;
            }

            case '4': {

                break;
            }

            case '5': {

                break;
            }
        }
    }
}