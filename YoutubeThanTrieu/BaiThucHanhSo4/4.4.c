#include<stdio.h>

int nhap(){
    int n;
    printf("Input a number: ");
    scanf("%d", &n);

    return n;
}

void input(int *a, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("Element-%d: ", i+1);
        scanf("%d", &a[i]);
    }
}

void count(int *a, int n, int x){
    int i;
    int count = 0;
    for(i = 0; i < n; i++){
        if(a[i] == x){
            count++;
        }
    }
    printf("The number of times %d occurs: %d\n", n, count);
}

void main(){
    int a[50];
    int n, x;

    n = nhap();
    input(a, n);
    x = nhap();
    count(a, n, x);
}