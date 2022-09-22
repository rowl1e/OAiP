#include <stdio.h>

int main(){
    int a, b, c, n;
    printf("Enter the lengths of the sides of the triangle\nSide 1st-a, 2nd-b, 3rd-c:\n"); 
    n=scanf("%d\n%d\n%d", &a, &b, &c);

    if(a>0 && b>0 && c>0 && n==3){
            
        if(a+b>c && a+c>b && b+c>a){
               
            if(a == b && b == c && c == a)
                printf("This triangle is equilateral\n");

            if(a == b && b != c || b == c && c != a || c == a && a != b)
                printf("This triangle is isosceles\n");

            else if(a != b && b != c && c != a)
                printf("This is a triangle with all sides different\n");
        }
        else
            printf("A triangle with such sides does not exist\n");
    }
    else
        printf("Invalid input\n");

    system("pause");
    return 0;
}