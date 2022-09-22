#include <stdio.h>

int main(){
    int choice, n;
    float res, num;
    printf("Enter the number of units.\nThen select units:\n\tdecimeter-1, kilometer-2, millimeter-3, centimeter-4\n");
    n=scanf("%f", &num);

    if(n==1 && num>0){

        scanf("%d", &choice);

        switch(choice){

            case 1:
                res = num / 10;
                printf("There are %f meters in  %f decimeters\n", res, num);
                break;
        
            case 2:
                res = num * 1000;
                printf("There are %f meters in  %f kilometers\n", res, num);
                break;

            case 3:
                res = num / 1000;
                printf("There are %f meters in  %f millimeters\n", res, num);
                break;

            case 4:
                res = num / 100;
                printf("There are %f meters in  %f centimeters\n", res, num);
                break;

            default:
                printf("Invalid input\n");
        }
    }
    else
        printf("Invalid input\n");

    system("pause");
    return 0;
}