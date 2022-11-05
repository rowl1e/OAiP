#include <stdio.h>

int main(){
    float a, sum=0;
    printf("Enter a, a must be more than 1 and less than 3:\n");
    
    if(scanf("%f", &a)==1 && a>1 && a<3){
        
        for(int i=1; sum<=a; i++){
            sum += 1.0/i;
        }
        printf("Sum:\n%f\n", sum);

    }
    else
        printf("Invalid input\n");

    system("pause");
    return 0;
}