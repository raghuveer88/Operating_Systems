#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

struct node{
  char* str;
  struct node* next;
}*head,*temp,*end;


void insert(char* arg){              // this function for creating and inserting linked list
	if(head == NULL){
          head = (struct node*)malloc(sizeof(struct node));
          head->str = arg;
          head->next = NULL;
          temp = head;
          printf("%s\n",head->str);
       }
       else{
          end = (struct node*)malloc(sizeof(struct node));
        if(end == NULL){
           printf("memory is not allocated\n");
        }
        else{
           end->str = arg;
           end->next = NULL;
           temp->next = end;
           temp = temp->next;
        }
       }
}

void print_list(){           // function to print linked list
      if(head == NULL){
         printf("list is empty\n");
      }
     else{
        temp = head;
      while(temp !=NULL){
        printf("%s\n",temp->str);
        temp = temp->next;
      }
     }
 }

int main(int argc,char *argv[]){          // takes auguments frm the command line
 FILE* fp;                                // file pointer
 char cd[50][100];                        // stores all the commands in the strings of array
 char d_cd[50][100];                      // duplicate of cd array
 char c_cd[50][100];
 char b_cd[50][100];
 int c = 0;                               // this will store the number of commands in all the files
 char * line = NULL;
 size_t len = 0;
 ssize_t reads;
 if(argc<2){                             // to check if atleast one file is passed while executing
  printf("please give atleast one file as input\n");
  exit(0);
 }
 
 for(int i =1;i<argc;i++){
    fp = fopen(argv[i],"r");             // opens each file which is passed in the command line
    if(fp == NULL){                      // checks if the file exist or not
      printf("%s dosen't exist\n",argv[i]);
      break;
      }
      while ((reads = getline(&line, &len, fp)) != -1) {  // prints all the contan in the files;
                                                          // printf("Retrieved line of length %zu:\n", read);
                                                           //  printf("%s", line);
        strcpy(cd[c],line);                               // created three duplicate array which contains of the commands with arrguments
        strcpy(d_cd[c],line);
        strcpy(c_cd[c],line);
        strcpy(b_cd[c],line);
        
        c++;
    }
      fclose(fp);                                        //closes the files
 }
 
 
 
 char* arg[64];              // stores the command like ex - arg[0] will be ls and arg[1] will be -al. similarlly for other command as well
 for(int i = 0;i<c;i++){     // this for loop to iterate all the command in order to execute them
    int length;              
    int j = 0;
   	 
       char *token = strtok(cd[i]," ");  // breaking the string when ever space is encontered and storing it in arg
       
       while(token != NULL){     //seperating all the strings in a command based on spaces to use in execvp
        arg[j] = token;
        token = strtok(NULL," ");  
        length = strlen(arg[j]);
        if(arg[j][length-1] == '\n')    // to remove \n charactor at the end of the string
        arg[j][length-1] = 0;
        j++;
       } 
       char* u = arg[0];
        insert(u);                     // inserting the command into the linked list
       arg[j] = NULL;
        printf("%s",arg[1]);    
   
  pid_t pid = fork();       // created parent and child processor
  if(pid < 0){               // check case 
   printf("fork failed\n");
  }
  else if(pid == 0){       // child process        
     
    execvp(arg[0],arg);                // executing the command
  }
  
  else{
    wait(NULL);
    printf("----------next command ----------------------\n\n");
  }
 
 }
  
    
  printf("welcome to the user interactive mode\n");
  while(1){
  printf("\nplease enter you command (only capitals EX - EXEC ls)\n");
  
  
  char u_c[64];                      // this charater array will take the input from the user
  scanf ("%[^\n]%*c", u_c);          
   char* div[2];                    // to store each string in a command by the user
   char *token = strtok(u_c," ");  // breaking the string when ever space is encontered and storing it in arg
   int j = 0;
     while(token != NULL){
        div[j] = token;
        token = strtok(NULL," ");    
        j++;
      }
      
       if( strcmp("HISTORY",div[0]) == 0 &&  strcmp("BRIEF",div[1]) == 0){
  	 printf("----------History Brief------------\n");
         print_list();                           // printing the linked list when the user command is History brief
       }
       
       
       else if( strcmp("HISTORY",div[0]) == 0 &&  strcmp("FULL",div[1]) == 0){
  	 printf("----------History FULL------------\n");
         for(int i = 0;i<c;i++){
           printf("%d. %s\n",i+1,b_cd[i]);
         
         }
       }
       
       
     
      else if(strcmp("EXEC",div[0]) == 0){       // checking id the first word of the user is EXEC or not
        int b = atoi(div[1]);                    // so if the string after exec is string then b will be 0 if it is number then b will be integer 
         if(b == 0){                               // this case when the second word is a command after EXEC
           printf("----------executing %s------------\n",div[1]);
           char* arg[64];
           temp = head;
           while(temp !=NULL){                 // this loop checks if the command is in the history or not
           if(strcmp(temp->str,div[1]) == 0){
             printf("yes it is there in the history\n");
             break;
           }
           
           else if(temp->next == NULL){
             if(strcmp(temp->str,div[1]) == 0){
             printf("yes it is there in the history\n");
             break;
             }
             else{
              printf("it is not in the history breif\n");
             }
           }
            temp = temp->next;
          }
          for(int i = 0;i<c;i++){     // this for loop to get the full command and execute it
           int length;          
   	   int k = 0;
           char *token = strtok(d_cd[i]," ");  // breaking the string when ever space is encontered and storing it in arg
       
          while(token != NULL){
           arg[k] = token;
           token = strtok(NULL," ");
           length = strlen(arg[k]);
          if(arg[k][length-1] == '\n')         // to remove \n charactor at the end of the string
           arg[k][length-1] = 0;
           k++;
          }
         arg[k] = NULL; 
          if(strcmp(arg[0],div[1]) == 0){
           pid_t pid = fork();                // created parent and child processor
            if(pid < 0){                       // check case 
             printf("fork failed\n");
            }
            else if(pid == 0){                   // child process        
             execvp(arg[0],arg);                // executing the command
            }
  
            else{
             wait(NULL);
            // printf("----------next command ----------------------\n\n");
          
             }
          break;
           }
         
          }
         }
       
         else if(b != 0){                            // this case if the string after EXEC is integer
          int length;          
   	  int k = 0;
         char *token = strtok(c_cd[b-1]," ");        // breaking the string when ever space is encontered and storing it in arg
       
          while(token != NULL){
          arg[k] = token;
          token = strtok(NULL," ");
          length = strlen(arg[k]);
          if(arg[k][length-1] == '\n')               // to remove \n charactor at the end of the string
          arg[k][length-1] = 0;
          k++;
         }
         arg[k] = NULL; 
      
      
         temp = head;
         while(temp !=NULL){                    // this loop checks if the command is in the history or not
         if(b>c){
            printf("it is not in the history breif\n");
            break;
         }
          if(strcmp(temp->str,arg[0]) == 0){
             printf("yes it is there in the history\n");
             break;
          }
           
           else if(temp->next == NULL){
             if(strcmp(temp->str,arg[0]) == 0){
             printf("yes it is there in the history\n");
             break;
             }
             else{
             printf("it is not in the history breif\n");
             }
           }
           temp = temp->next;
         }   
      
          pid_t pid = fork();                  // created parent and child processor
          if(pid < 0){                         // check case 
            printf("fork failed\n");
           }
         else if(pid == 0){                   // child process        
           execvp(arg[0],arg);                // executing the command
           }
  
         else{
           wait(NULL);
          // printf("----------next command ----------------------\n\n");
         
           } 
       
      } 
     }
     
     else if(strcmp(div[0],"STOP") == 0){
       break;
       exit(0);
     
     }
     
     else{
      printf("not valid user input\n");
      }
     
     }
      
    
 
 
return 0;
}
