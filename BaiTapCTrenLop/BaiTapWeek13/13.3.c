#include<stdio.h>
#include<string.h>

/*----Ham kiem tra so hieu-----*/
int check(char *str){
    int i;
    int mark = 1;

    if(strlen(str) != 8){
        return 0;       //Neu so ki tu khac 7 -> sai
    }

    for(i = 0; i < 3; i++){
        if(str[i] >= '0' && str[i] <= '9'){     //Neu 3 phan tu dau khac ki tu -> sai
            return 0;
        }
        else{
            continue;
        }
    }
    
    for(i = 3; i < 7; i++){
        if(str[i] < '0' || str[i] > '9'){       //Neu 4 phan tu sau khac so -> sai
            return 0;
        }
        else{
            continue;
        }
    }

    if(mark == 1){
        return 1;
    }
}

int main(){
    char num[50];

    printf("Input a string: ");
    fgets(num, 49, stdin);

    if(check(num)){
        printf("The customer number is valid!");
    }
    else{
        printf("The customer number is invalid!");
    }
}