#include<stdio.h>
#include<string.h>

void printStr(char *str){
    printf("%s", str);
}

void strend(char str[5][50]){
    char code[10];
    printf("Input a product code: ");
    fgets(code, 9, stdin);
    
    if((strcmp(code, "TV127"))){
        printf("Product: ");
        printStr(str[0]);
    }
    else if((strcmp(code, "CD057"))){
        printf("Product: ");
        printStr(str[1]);
    }
    else if((strcmp(code, "TA877"))){
        printf("Product: ");
        printStr(str[2]);
    }
    else if((strcmp(code, "CS409"))){
        printf("Product: ");
        printStr(str[3]);
    }
    else if((strcmp(code, "PC655"))){
        printf("Product: ");
        printStr(str[4]);
    }
         
}
    
int main(){
    char str1[5][50] ={
        "TV127 31 inch Television",
        "CD057 CD Player",
        "TA877 Answering Machine",
        "CS409 Car Stereo",
        "PC655 Personal Computer"
    };

    strend(str1);
}