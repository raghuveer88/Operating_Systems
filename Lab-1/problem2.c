//lagged fibonacci

#include<stdio.h>
#include<stdlib.h>   
#include<time.h>
   
void problem1(int p,int q){
     int a[1000];
   int count = 1;
   srand(time(0)); 
   while(count<=10){
   int a[1000] = {0};
   for(int i = 0;i<p-1;i++){
   	a[i] = rand()%1000000;
   	printf("%d, ",a[i]);
   }  
   int x;
   int index = p;
   for(int i = 0;i<1000-p;i++){
   	x = a[index-p] ^ a[index-q];
   	a[index] = x;
   	index++;
   	printf("%d, ",x);
   }
   printf("\n\n\n\n");
   count++;
   }
}   


void problem2(int p,int q){
     int a[10000];
   int count = 1;
   srand(time(0)); 
   while(count<=10){
    int a[10000] = {0};
   for(int i = 0;i<p-1;i++){
   	a[i] = rand()%1000000;
   	printf("%d, ",a[i]);
   }  
   int x;
   int index = p;
   for(int i = 0;i<10000-p;i++){
   	x = a[index-p] ^ a[index-q];
   	a[index] = x;
   	index++;
   	printf("%d, ",x);
   }
   printf("\n\n\n\n");
   count++;
   }




}


int main(){
   int p = 10;
   int q = 7;
   int input;
  printf("1. Get 10 sequences each with 1000 pseudo random numbers\n2. Get 10 sequences each with 10000 pseudo random numbers\n");
  printf("enter an input\n");
  scanf("%d",&input);
  
  switch(input){
  	case 1:
  	 problem1(p,q);
  	 
  	case 2:
  	 problem2(p,q);
  
  	default :
  	 printf("invalid input\n");
  }

return 0;
}



