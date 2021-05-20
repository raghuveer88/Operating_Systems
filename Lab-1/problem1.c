//linear congruential


#include<stdio.h>
#include<stdlib.h>


void problem1(int a,int c,int m,int n){
  int x;
  int j = 0;
  int k = 2;
  
  x = rand()%1000;

  for(int i = 1;i<=n;i++){
        a = a+j;            // updating the coefficents
        c = c+k;            // updating the coefficents      
  	x = (a*x-1+c)%m;    // calculating x using linear congurential formula
  	printf("%d, ",x);
  	
  }
  printf("-------------------sequence-------------------\n\n\n");
}


int main(){
  int a = 3;    //coefficents
  int c = 0;    // coefficents 
  int m = 100;   // range
  int n;           // user input no of random numbers
  printf("enter how many random numbers do you want\n");
  scanf("%d",&n);
  problem1(a,c,m,n);
return 0;
}


