#include <stdio.h>
#include <math.h>

int main(){
    int n;
    float c, s, halfdiagonal, radius, side, pi = 3.14159265359;
    printf("Enter the area of the circle and then the area of the square:\n");
    n=scanf("%f\n%f", &c, &s);

    if (c>0 && s>0 && n==2){
        radius = sqrt(c/pi);
        side = sqrt(s);
        halfdiagonal = side * sqrt(2) / 2;

        if(2 * radius <= side)
            printf("The circle fits into the square\n");
        else
            printf("The circle does not fit into the square\n");
            
        if(halfdiagonal <= radius)
            printf("The square fits into the circle\n");
        else
            printf("The square does not fit into the circle\n");
    }
    else
        printf("Invali input\n");

    system("pause");
    return 0;
}