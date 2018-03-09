/*
 * Copyright (c) 2014.  lin_jie_long@126.com, Sat 17 Oct 2015 04:50:25 PM CST,  All rights reserved.
 */
/*
 * File Name:  mutex_recursive.c
 * Author:     Vanqusier(lin_jie_long@126.com)
 * EMail:      lin_jie_long@126.com
 */

#include <pthread.h>  
#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
pthread_mutex_t mutex;   
pthread_mutexattr_t attr;  

static int num = 0;

int func1()
{
    pthread_mutex_lock(&mutex);       
    num ++;
	printf("Enter func1: num = %d\n", num);
	pthread_mutex_unlock(&mutex);         
	
	printf("Exit func1: num = %d\n", num);
	return 0;
} 

int func2()
{
    pthread_mutex_lock(&mutex);       
    num ++;
	printf("Enter func2: num = %d\n", num);
    pthread_mutex_unlock(&mutex);         
	
	printf("Exit func2: num = %d\n", num);
	return 0;
}
 
void* func(void* arg){  
	int i;
	char *str = (char*)arg;

    printf("Enter Func, %s\n", str);
	for(i = 0; i < 5; i++) {
		func1();
		func2();
	}
	return NULL;  
}  
int main(){  
    int ret;  
    if(( ret = pthread_mutexattr_init(&attr)) != 0){  
        fprintf(stderr, "create mutex attribute error. msg:%s", strerror(ret));  
        exit(1);  
    }  
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);  
    pthread_mutex_init(&mutex, &attr);    
    pthread_t p1, p2;   
    char str1[8], str2[8];   
    sprintf(str1, "abcdefg");  
    sprintf(str2, "1234567");  
    if((ret = pthread_create(&p1, NULL, func, str1)) != 0){  
        fprintf(stderr, "create thread error. msg:%s", strerror(ret));  
        exit(1);  
    }
#if 1  
    if((ret = pthread_create(&p2, NULL, func, str2)) != 0){  
        fprintf(stderr, "create thread error. msg:%s", strerror(ret));  
        exit(1);  
    }
#endif  
    pthread_join(p1, NULL);  
    pthread_join(p2, NULL);  
}     
