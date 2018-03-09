#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER; 
pthread_cond_t cond=PTHREAD_COND_INITIALIZER; 
void *thread1(void *); 
void *thread2(void *); 
int i=1; 

int main() 
{ 
    pthread_t t_a; 
    pthread_t t_b; 
    pthread_create(&t_a,NULL,thread1,(void *)NULL); 
    pthread_create(&t_b,NULL,thread2,(void *)NULL); 
    //pthread_join(t_b,NULL); 
    pthread_mutex_destroy(&mutex); 
    pthread_cond_destroy(&cond); 
    exit(0); 
} 
void *thread1(void *junk) 
{ 
    for(i=1;i<=4;i++) 
    { 
        printf("Enter thread1\n"); 
        pthread_mutex_lock(&mutex); 
        if(i%3==0) 
        { 
        	pthread_cond_signal(&cond);
		printf("thread2 is unlocked by thread1\n"); 
        } 
        else 
       		printf("thread1:%d\n",i); 
        
        pthread_mutex_unlock(&mutex); 
        printf("thread1 is unlocked by itself\n"); 
        sleep(1); 
    } 
} 

void *thread2(void *junk) 
{ 
    while(i<4) 
    { 
        printf("Enter thread2\n"); 
        pthread_mutex_lock(&mutex); 
        if(i%3!=0) 
        { 
            pthread_cond_wait(&cond,&mutex); 
            printf("thread2 is waiting for work...\n"); 
        } 
        
        printf("thread2:%d\n",i); 
        pthread_mutex_unlock(&mutex); 
        printf("thread2 is unlocked by itself\n"); 
        sleep(1); 
    } 
} 
