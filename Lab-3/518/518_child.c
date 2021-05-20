#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(){

 FILE *fp,*fs;
 int numbers[100];
 for(int i = 0;i<100;i++){
  numbers[i] = i+1;
 }
 fp = fopen("task2.txt","r+");
 if(fp == NULL){
  printf("file doesn't exist\n");
 return -1;
 }
 /*fs = fopen("dup_task2.txt","w");
 if(fs == NULL){
  printf("file dup_task1 doesn't exist\n");
 return -1;
 }*/
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
 // fprintf(fs,"%d",index);
 // fprintf(fs," ");
  }
 fclose(fp);
 exit(0);

return 0;
}
