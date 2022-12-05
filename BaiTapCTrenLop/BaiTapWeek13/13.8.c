#include<stdio.h>
#include<string.h>
/*-----Ham kiem tra xem co phai ky tu ,.;:!? khong*/
int check(char c){
    if(c == ',' || c == '.' || c == ';' || c == ':' || c == '!' || c == '?'){
        return 1;
    }
    else{
        return 0;
    }
}

void change(char *str){
    int i;
    for(i = 0; i < strlen(str)-1; i++){
        if(check(str[i])){
            str[i] = ' ';
        }
    }
}

int main(){
    char str[50];

    printf("Input a string: ");
    fgets(str, 49, stdin);

    printf("Former string: %s", str);
    change(str);
    printf("Latter string: %s", str);
}