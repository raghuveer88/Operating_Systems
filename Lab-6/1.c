#include<stdio.h>
#include <pthread.h>
#include<unistd.h>

 typedef struct __myarg_t {
 int a;
 char *b;	
 } myarg_t;

 void * mythread(void * arg) {
 myarg_t * m = (myarg_t * ) arg;
 printf("%d %s\n", m->a, m->b);
 return NULL;
 }

int main(int argc, char * argv[]) {
pthread_t p;

myarg_t args;
args.a = 10;
args.b = "hello world";

pthread_create(&p, NULL, mythread, &args);
sleep(3);
//pthread_join(p,NULL);

return 1;
 }
