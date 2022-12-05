#include<stdio.h>
#include<string.h>

int strend(char *s, char *t){
    int i, j;
    int mark = 1;

    for(i = 0, j = strlen(s) - strlen(t); i < strlen(t)-1, j < strlen(s)-1; i++, j++){
        if(t[i] == s[j]){
            continue;
        }
        else{
            return 0;
        }
    }
    if(mark == 1){
        return 1;
    }
}

int main(){
    char str1[50], str2[50];

    printf("Input the first string: ");
    fgets(str1, 49, stdin);

    printf("Input the second string: ");
    fgets(str2, 49, stdin);

    printf("Number return: %d\n", strend(str1, str2));
}