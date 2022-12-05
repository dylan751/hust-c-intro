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

void print(int *a, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%5d", a[i]);
    }
    printf("\n");
    a[n] = '\0';
}

void add(int *a, int n, int x, int k){
    int i;
    for(i = n-1; i > k-1; i--){
        a[i] = a[i-1];
    }
    a[k-1] = x;
}

void main(){
    int a[50];
    int n, x, k;

    n = nhap();
    input(a, n);

    printf("Former: ");
    print(a, n-1);

    x = nhap();
    k = nhap();
    /*---Add x into k position---*/
    add(a, n, x, k);

    printf("Latter: ");
    print(a, n);
}
