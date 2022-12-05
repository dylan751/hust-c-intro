#include<stdio.h>
#include<string.h>
/*-----Check if arr[i] is a space or not-----*/
int isSpace(char c){
    return (c == ' ' || c == '\t'); //Neu an "tab" thi van tinh la khoang trang
}

int countSpace(char *str){
    int i, count = 0;
    for(i = 0; i < strlen(str)-1; i++){
        if(!isSpace(str[i]) && isSpace(str[i+1])){
            count++;
        }
    }
    return count;
}

int main(){
    char str[50];

    printf("Input a string: ");
    fgets(str, 49, stdin);

    int result = countSpace(str);
    printf("The number of spaces in the string = %d\n", result);
}