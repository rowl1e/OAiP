#include <stdio.h>

int main(){
    int n, sum=0;
    printf("Enter n, n must be a natural number:\n");
    
    if(scanf("%d", &n)==1 && n>0){
        
        for(int factorial=1, i=1; i<=n; i++){
            factorial *= i;
            sum += factorial;
        }
        printf("Sum:\n%d\n", sum);
        
    }
    else
        printf("Invalid input\n");

    system("pause");
    return 0;
}