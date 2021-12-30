/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>
int BinaryToDecimal(int n)
{
    if(n==0)
        return 0;
    else
        return (n% 10 + 2* BinaryToDecimal(n / 10));
}
int main()
{
    int n;
    printf("Enter the Binary Value:");
    scanf("%d",&n);
    printf("Decimal Value of Binary number is: %d",BinaryToDecimal(n));
}
