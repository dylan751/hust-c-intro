#include<stdio.h>
#include<string.h>

/*-----Change x by y-----*/
void change(char *str, char *x, char *y){
    int i;
    for(i = 0; i < strlen(str)-1; i++){
        if(str[i] == x[0]){
            str[i] = y[0];
        }
    }
}

int main(){
    char str[50];
    char a[2], b[2];

    printf("Input a string: ");
    scanf("%s", str);

    printf("Input 2 characters\n");
    printf("Char 1: "); scanf("%s", a);    
    printf("Char 2: "); scanf("%s", b);

    printf("Former string: %s\n", str);

    change(str, a ,b);

    printf("Latter string: %s\n", str);
}