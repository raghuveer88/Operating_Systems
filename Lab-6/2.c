#include <stdio.h>
 
#include <pthread.h>
 
#include <assert.h>
 
#include <stdlib.h>

#include<string.h>

#include<sys/syscall.h>
#include<unistd.h>
 

typedef struct __myarg_t 
{
 
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

return (void * ) r;
 
}


void * myconcate(void * arg) {
mycon_t * m = (mycon_t * ) arg;
strcat(m->c," ");
strcat(m->c,m->d);

return m->c;
}


 

int  main(int argc, char * argv[]) 
{

//int rc;

pthread_t p;
myret_t * m;
myret_t * n;

pid_t tid;
tid = syscall(SYS_gettid);

myarg_t args;


args.a= strlen(argv[1]);

args.b=(char *)malloc(strlen(argv[1]));

strcpy(args.b,  argv[1]);


pthread_create(&p, NULL, mythread, &args);


pthread_join(p, (void ** ) &m);


printf("returned %d %s\n", tid, m->y);

//-----------------------------
pthread_t q;
args.a= strlen(argv[2]);
tid = syscall(SYS_gettid);
args.b=(char *)malloc(strlen(argv[2]));

strcpy(args.b,  argv[2]);


pthread_create(&q, NULL, mythread, &args);


pthread_join(q, (void ** ) &n);


printf("returned %d %s\n",tid,n->y);

//-----------------------------------------
mycon_t c_args;
pthread_t r;
tid = syscall(SYS_gettid);
char *full = (char*)malloc(100*sizeof(char));
c_args.c = m->y;
c_args.d = n->y;
pthread_create(&r,NULL,myconcate,&c_args);

pthread_join(r, (void ** )&full);

printf("returned %d %s\n",tid,full);


return 0;


}



