#include <stdio.h>

int main()
{
    int a, b, c, res, number2, number1;
    printf("Enter the sides of the rectangle: a side, b side.\nThen enter the side of the square:\n");
    
        if(scanf("%d\n%d\n%d", &a, &b, &c)==3 && a>0 && b>0 && c>0){
            
            for(number1=0; a>=c; number1++){
                a -= c;
            }
            for(number2=0; b>=c; number2++){
                b -= c;
            }
            for(res=0; number2 > 0; number2--){
                res += number1;
            }
            printf("This rectangle will fit %d squares\n", res);
        }
        else
            printf("Invalid input\n");
            
    system ("pause");
    return 0;
}