#include<stdio.h>
#include<string.h>

char lastName(char *str){
    int i = 0;
    char lastName[50];

    while(str[i] != ' '){
        lastName[i] = str[i];
        i++;
    }
    printf("%s\n", lastName);
}

int main(){
    char name[50];

    printf("Input your full name: ");
    fgets(name, 49, stdin);


    printf("Your last name is: ");
    lastName(name);
}