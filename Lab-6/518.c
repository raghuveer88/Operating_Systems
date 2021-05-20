#include <stdio.h>
 
#include <pthread.h>
 
#include <assert.h>
 
#include <stdlib.h>

#include<string.h>

#include<sys/syscall.h>
#include<unistd.h>


typedef struct __myarg_t {
 int a;
 char *b;	
 } myarg_t;

 
 
 
typedef struct __myret_t 
{
 
int x;
 
char *y;

} myret_t;



typedef struct __mycon_t 
{
 
char *c;
 
char *d;

} mycon_t;


void * mythrea(void * arg) {
 myarg_t * m = (myarg_t * ) arg;
 printf("%d %s\n", m->a, m->b);
 return NULL;
 }



 
int task0(){
 pthread_t p;

  myarg_t args;
  args.a = 10;
  args.b = "hello world";

  pthread_create(&p, NULL, mythrea, &args);
 // sleep(3);   for 2 point uncomment
  pthread_join(p,NULL);

return 1;
 }


void * mythread(void * arg) {

myarg_t * m = (myarg_t * ) arg;


//int print_index=0;



/*for(print_index=0; print_index<m->a; print_index++)
{

 
printf("Printing %d th character %c\n", print_index, *(m->b+print_index));


}*/


myret_t * r = malloc(sizeof(myret_t));

 
r->x = 1;
 
r->y = m->b;
pid_t tid;
tid = syscall(SYS_gettid);
printf("%u ",tid);
return (void * ) r;
 
}


void * myconcate(void * arg) {
mycon_t * m = (mycon_t * ) arg;
strcat(m->c," ");
strcat(m->c,m->d);
pid_t tid;
tid = syscall(SYS_gettid);
printf("%u ",tid);
return m->c;
}



int task2(int argc, char * argv[]){
 pthread_t p;
myret_t * m;
myret_t * n;

//pid_t tid;

myarg_t args;


args.a= strlen(argv[1]);

args.b=(char *)malloc(strlen(argv[1]));

strcpy(args.b,  argv[1]);


pthread_create(&p, NULL, mythread, &args);


pthread_join(p, (void ** ) &m);


printf("returned %s\n", m->y);

//-----------------------------
pthread_t q;
args.a= strlen(argv[2]);
//tid = syscall(SYS_gettid);
args.b=(char *)malloc(strlen(argv[2]));

strcpy(args.b,  argv[2]);


pthread_create(&q, NULL, mythread, &args);


pthread_join(q, (void ** ) &n);


printf("returned %s\n",n->y);

//-----------------------------------------
mycon_t c_args;
pthread_t r;

char *full = (char*)malloc(100*sizeof(char));
c_args.c = m->y;
c_args.d = n->y;
pthread_create(&r,NULL,myconcate,&c_args);

pthread_join(r, (void ** )&full);

printf("returned %s\n",full);


return 0;






}






int main(int argc, char * argv[]){
printf("1.task0\n2.task2\n");
 printf("enter the input\n");
 int input;
 scanf("%d",&input);
 printf("-------------------------\n");
 
 switch(input){
    case 1: {
      task0();
      break;
    }
    
    case 2: {
     task2(argc,argv);
     break;
    
    }
    
    default : {
     printf("invalid input\n");
     break;
    }
 
 
 
 }
 





}
