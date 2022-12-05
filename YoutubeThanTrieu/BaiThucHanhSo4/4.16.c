#include<stdio.h>
#include<math.h>

int nhap(){
    int n;
    printf("Input the number of elements: ");
    scanf("%d", &n);
    return n;
}

int main(){
    int a[50], i;
    int n, x;
    int sum = 0;

    n = nhap();

    printf("Input a number: ");
    scanf("%d", &x);

    for(i = n-1; i >= 0; i--){
        printf("Element-%d: ", i+1);
        scanf("%d", &a[i]);

        sum += a[i]*pow(x, i+1);
    }
    
    printf("P(x) = %d\n", sum);

}