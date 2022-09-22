#include <stdio.h>

int main(){
    int n;
    float r, l, h, a, b, c, s, pi = 3.14159265359;
    printf("Enter the radius of the cone:\n");
    n=scanf("%f", &r);

    if(r>0 && n==1){
        printf("Enter the slant height of the cone:\n");
        n=scanf("%f", &l);
    }
    else{
        printf("Invalid input\n");
        system("pause");
        return 0;
    }

    if(l>0 && n==1){
        printf("Enter the height of the cone:\n");
        n=scanf("%f", &h);
    }
    else{
        printf("Invalid input\n");
        system("pause");
        return 0;
    }

    if(h>0 && n==1){
        s = pi * r * r; //area of ​​the circle of the cone
    
        a = pi * r * l;
        printf("Lateral surface area of the cone: %.3f\n", a);
    
        b = a + s;
        printf("Total surface area of the cone: %.3f\n", b);
    
        c = 0.3333333333333333 * s * h;
        printf("Volume of the cone: %.3f\n", c);
    }
    else{
        printf("Invalid input\n");
        system("pause");
        return 0;
    }
    system("pause");
    return 0;
}