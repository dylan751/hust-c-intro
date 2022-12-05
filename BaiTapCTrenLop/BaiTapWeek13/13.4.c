#include<stdio.h>

int copy(char *str1, char *str2){
    int i = 0;

    while(str1[i] != '\0'){
        str1[i] = str2[i];
        i++;
    }
}

int main(){
    char str1[50];
    char str2[50];

    printf("Input first string: ");
    fgets(str1, 49, stdin);
    printf("Input second string: ");
    fgets(str2, 49, stdin);

    printf("Before, str1 = %s", str1);

    copy(str1, str2);

    printf("After, str1 = %s", str1);
}