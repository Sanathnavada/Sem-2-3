/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
struct student
{char usn [50];

char name [50];
int marks;
} s[50];

void main()
{
int i, n, countav=0, countbv=0;
float sum=0, average;
printf("Enter number of Students: ");
scanf("%d",&n);
printf ("Enter information of students: \n");
for(i=0; i<n;i++)
{
printf("Enter Student Number %d's \n USN: ",i+1);
scanf("%s", s[i].usn);

printf ("Name: ");
scanf("%s", s[i].name); 
printf ("Marks: ");
scanf("%d",&s[i].marks); 
printf("\n");

}
printf ("Displaying given information");
for(i=0; i<n; i++)
{
printf("\nUSN: %s\n",s[i].usn);
printf ("Name: ");
puts (s[i].name);
printf ("Marks: %d", s[i].marks);
printf("\n");
}
for (i=0;i<n;i++)
{sum=sum+s[i].marks;} 

average=sum/n;

printf ("\nAverage marks: %f", average);
countav=0;
countbv=0;
for (i=0;i<n; i++)
{
if (s[i].marks>=average) countav++; 
else countbv++;

}
printf ("\n Total No of students above average= %d", countav);
printf ("\nTotal No of students below average= %d", countbv);
}

