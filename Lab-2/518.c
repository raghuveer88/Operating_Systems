#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct node {
  int data;
  struct node *next;
 }*head,*temp;



void problem1(){
  int x;
  int j = 0;
  int k = 2;
  int a = 3;    //coefficents
  int c = 0;    // coefficents 
  int m = 100;   // range
  int n;           // user input no of random numbers
  printf("enter how many random numbers do you want\n");
  scanf("%d",&n);
  printf("---------------------\n");
  x = rand()%1000;

  for(int i = 1;i<=n;i++){
        a = a+j;            // updating the coefficents
        c = c+k;            // updating the coefficents      
  	x = (a*x-1+c)%m;    // calculating x using linear congurential formula
  	printf("%d, ",x);
  	
  }
  printf("\n\n\n");
}
 
void problem2(){
   int x;
  int count = 1; 
  // below are all the variables which is used in the random number genrator formula.
  int j = 0;
  int k = 2;
  int a = 4;
  int c = 10;
  srand(time(0));
  char alphabets[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  printf("enter the no: of strings you want\n");
  int N; 
  scanf("%d",&N);  // user input which takes the no: of strings
  printf("---------------------\n");
 while(count<=N){
  x = rand()%1000;   // initial seed value to generate rando numbers
  int n = rand()%10; // to set the length of the string
  char str[10];
  a = a+j;
  c = c+k;

  for(int i = 0;i<=n;i++){
  	x = (a*x-1+c)%26; // generate a random number
  	char b = alphabets[x];
      	strncat(str,&b,1); // concatinates the charectors to form a string
  }
  printf("%s\n",str);
  str[0] = '\0'; // emptying the string array
  j++; 
  k = k+2;
  count++;
 }   

}

void problem3(){
  void push(int value){
 temp = (struct node*)malloc(sizeof(struct node));
 if(head == NULL){
   temp->data = value;
   temp->next = NULL;
   head = temp;
   }
 
 else{
   temp->data = value;
   temp->next = head;
   head = temp;
   }
   
   printf("integer %d is pushed\n",value);

}

void pop(){
 struct node* temp;
 int pop_item;
 if(head == NULL){
   printf("stack is empty or underflow\n");
   }
 
 else{
   pop_item = head->data;
   temp = head->next;
   free(head);
   head = temp;
   printf("popped item is %d\n",pop_item);  
 }
 
 }

void display(){
 struct node* temp;
 if(head == NULL){
   printf("stack is empty\n");
   }
 
 else{
   printf("the elements in the stack are\n");
   temp = head;
   while(temp != NULL){
     printf("%d\n",temp->data);
     temp = temp->next;
     }

   }

}

int check_given_int(double number){
  int a;
  a = (int)number;
  number = number - a;
  if(number == 0)
  return 1;
  else{
   printf("please enter an integer number\n");
   return 2;
  }
}

 int ch;
 while( ch != 4){
 printf("------------------choose-----------\n");
printf(" 1. push\n 2.pop\n 3.display\n 4.exit\n");
printf("select one operation\n");

scanf("%d",&ch);

switch(ch){
  case 1 : {
     printf("enter the integer you want to push\n");
     double number;
     scanf("%le",&number);
     int check = check_given_int(number);
     if(check == 1){
     int num = (int)number;
     push(num);
     break;
     }
     else{break;};
     }
  
  case 2 : {
     pop();
     break;
     }
     
  case 3 : {
     display();
     break;
     }
  case 4 :{
     exit(0);
     break;
     }      

  default : {
    printf("invalide input\n");
    break;
    }

}
}



}


int main(){
printf("------problem 1--------\n");
printf("1.random number generator\n");
problem1();

printf("------problem 2--------\n");
printf("2.random string generator\n");
problem2();

printf("------problem 3--------\n");
printf("3. stack\n");
problem3();

 
return 0;
}


