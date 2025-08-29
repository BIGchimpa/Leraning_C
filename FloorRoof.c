#include <stdio.h>
#include <stdlib.h>

double Floor(double x);
double Roof(double x);

int main()
{
    double x1;
    puts("insert a number:");
    scanf("%lf", &x1);
    
    printf("the floor function of this number is %.0lf \n", Floor(x1));
    printf("the roof function of this number is %.0lf", Roof(x1));
    return 0;
}

double Floor(double x){
    double xCopy = x;
    while(x > 1){
        x -= 1;
    }
    if(x == 1){
        return xCopy;
    } else {
       return (xCopy - x); 
    }
}

double Roof(double x){
    double xCopy = x;
    while(x > 1){
        x -= 1;
    }
    if(x == 1){
        return xCopy;
    } else {
        return (xCopy - x + 1);
    }
    
    
    
}





