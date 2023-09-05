#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int i=0,k=0,j=0,f=0,d ;
	char str[100];
	char A[100];
	char B[100];
	char C[100];
	printf("\nEnter the Plain Text : ");
	gets(str);
    printf("\nEnter the depth value : ");
	scanf("%d",&d);
	for(i=0;i<=strlen(str);i++){
		if(i%d == 0){
			A[k]=str[i];
			k++;
		}
		else if(i%2 != 0){
			B[j]=str[i];
			j++;
		} 
		else if(i%d == 2){
			C[f]=str[i];
			f++;
		}
	}
	printf("Your encrypted Text is :%s",A);
	printf("%s",B);
	printf("%s",C);
}
