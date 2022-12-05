#include<stdio.h>
#include<string.h>

void main(){
    char str[50];
    int i = 0;
    int mark = 0;
    printf("Input a string: ");
    fgets(str, 49, stdin);

    int count = 0;

    for(i = 0; i < strlen(str) - 1; i++){
        if(str[i] != ' ' && mark == 0){
            count++;
            mark = 1;
        }

        if(str[i] == ' '){
            mark = 0;
        }
    }

    printf("Words = %d\n", count);
}