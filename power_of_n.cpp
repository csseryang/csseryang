
#include<stdio.h>

/* Function to calculate x raised to the power y */

// Time Complexity: O(n)
// Space Complexity: O(1)
int power(int x, unsigned int y)
{
    if(y==0)
        return 1;
    else if(y%2==0)
        return power(x, y/2) * power(x, y/2);
    else 
        return x*power(x, y/2) *power(x, y/2);
}

/* Function to calculate x raised to the power y in O(logn) */
int power2(int x, unsigned int y)
{
    int temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}

/* Extended version of power function that can work
 for float x and negative y*/
float power3(float x, int y)
{
    float temp;
    if( y == 0)
       return 1;
    temp = power3(x, y/2);       
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
} 

/* Program to test function power */
int main()
{
    int x = 2;
    unsigned int y = 3;
 
    float x2 = 2;
    int y2 = -3;
    
    printf("%d\n", power(x, y));
    printf("%d\n", power2(x, y));
    printf("%f\n", power3(x2, y2));
    return 0;
}