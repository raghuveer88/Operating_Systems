#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<time.h>

int task1(){
 FILE *fp,*fs;
 fp = fopen("task1.txt","w");
 if(fp == NULL){
  printf("file doesn't exist\n");
 return -1;
 }
 int numbers[100];
 for(int i = 0;i<100;i++){
   numbers[i] = i+1;
   fprintf(fp,"%d",numbers[i]);
   fprintf(fp," ");
 }
 fclose(fp);
 pid_t pid = fork();

 if(pid < 0){
  printf("fork failed\n");
 }

 else if(pid == 0){
  fp = fopen("task1.txt","r+");
 srand(time(0)); 
 for(int i = 0;i<10;i++){
  int index = rand() % 100;
  int location = 0;
  numbers[index] = 0;
  if(index == 0){
   fseek(fp,index,SEEK_SET);
   fprintf(fp,"%d",numbers[index]);
  }
  
 else if(index <10){
   location = 2*index;
   fseek(fp,location,SEEK_SET);
   fprintf(fp,"%d",numbers[index]);
  }
  
  else{
   int zero = 0;
   location = 3*index - 8 -1;
   fseek(fp,location,SEEK_SET);
   fprintf(fp,"%d%d",zero,numbers[index]);
  }

  }
 
 fclose(fp);
 exit(0);
}

else{
 wait(NULL);

   
   fp = fopen("task1.txt","r");
   int num;
   for(int i = 0;i<100;i++){
     fscanf(fp,"%d",&num);
    if(num == 0){
       printf("%d\n",i);
     }
   }
   fclose(fp);
  }

}


int task3(){
  FILE *fp;
 fp = fopen("task3.txt","w");
 if(fp == NULL){
  printf("file doesn't exist\n");
 return -1;
 }
 int numbers[100];
 for(int i = 0;i<100;i++){
  numbers[i] = i+1;
  fprintf(fp,"%d",numbers[i]);
  fprintf(fp," ");
 }
 fclose(fp);
 int pd[2];
 int pipe_check = pipe(pd);
 if(pipe_check ==-1){
  printf("unsuccesfull pipe creation\n");
  return -1;
 }
 pid_t pid = fork();
 if(pid < 0){
  printf("fork failed\n");
 }
 else if(pid == 0){
  fp = fopen("task3.txt","r+");

  srand(time(0)); 
  for(int i = 0;i<10;i++){
    int index = rand() % 100;
    int location = 0;
    numbers[index] = 0;
   if(index == 0){
    fseek(fp,index,SEEK_SET);
    fprintf(fp,"%d",numbers[index]);
   }
  
   else if(index <10){
    location = 2*index;
    fseek(fp,location,SEEK_SET);
    fprintf(fp,"%d",numbers[index]);
    }
  
   else{
    int zero = 0;
    location = 3*index - 8 -1;
    fseek(fp,location,SEEK_SET);
    fprintf(fp,"%d%d",zero,numbers[index]);
    }
   }
 
  close(pd[0]);
  write(pd[1],numbers,sizeof(numbers));
 
  fclose(fp);
  exit(0);
 }

 else{
  wait(NULL);
  close(pd[1]);
  int n = read(pd[0], numbers, sizeof(numbers));
  for(int i = 0;i<n/4;i++){
   if(numbers[i] == 0){
     printf("%d\n",i);
   }
  } 

 }

}


void task2(){
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
 FILE *fp,*fs,*fd;
 fp = fopen("task2.txt","w");
 if(fp == NULL){
  printf("file doesn't exist\n");
 return -1;
 }
 int numbers[100];
 for(int i = 0;i<100;i++){
  numbers[i] = i+1;
  fprintf(fp,"%d",numbers[i]);
  fprintf(fp," ");
 }
 fclose(fp);
 
 
 
 pid_t pid = fork();
 

 if(pid < 0){
  printf("fork failed\n");
 }

 else if(pid == 0){
  char *args[]={"./exec",NULL}; 
  execvp(args[0],args);
  printf("haaaaaaaaaa"); // this won't print 
 }

 else{
  wait(NULL);

  
   fp = fopen("task2.txt","r");
   int num;
   for(int i = 0;i<100;i++){
     fscanf(fp,"%d",&num);
    if(num == 0){
       printf("%d\n",i);
     }
   }
   fclose(fp);

 }


return 0;
}

}


int main(){
 printf("1.task1\n2.task2\n3.task3\n");
 printf("enter the input\n");
 int input;
 scanf("%d",&input);
 printf("-------------------------\n");
 
 switch(input){
    case 1: {
      task1();
      break;
    }
    
    case 2: {
     task2();
     break;
    
    }
    
    case 3:{
      task3();
      break;
    }
    
    default : {
     printf("invalid input\n");
     break;
    }
 
 
 
 }
 



}
