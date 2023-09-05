#include<stdio.h>
#include<math.h>
 int main(){
  int n,q,x,a,c,y,b,d;
  printf("\nEnter prime numbers condition(n<q):\n"); 
  printf("\nEnter prime numbers q : ");
  scanf("%ld", & q);
  printf("\nEnter prime numbers n : ");
  scanf("%ld", & n);    
  printf("\nEnter the value of x : ");
  scanf("%d",&x);   
  printf("\nEnter the value of y : ");
  scanf("%d",&y);
  c=fmod(pow(n,x),q);
  d=fmod(pow(n,y),q);
  a=fmod(pow(d,x),q);  
  b=fmod(pow(c,y),q); 
  printf("key for the first person is : %d\n",a);
  printf("key for the second person is : %d\n",b);
  return 0;}
