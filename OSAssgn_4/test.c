#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<linux/kernel.h>
#include<sys/syscall.h>
#include<linux/sched.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<linux/module.h>
#include<semaphore.h>
#include<pthread.h>

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[10];
pthread_mutex_t mutex;

void *producer(void *pno){   
    for(;;) {
        int x = rand();
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        int y = syscall(449, x);
        buffer[in] = x;
        printf("Producer %d inserted value %d at %d\n", *((int *)pno), buffer[in], in);
        sleep(1);
        in = (in+1)%10;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}
void *consumer(void *cno){   
    for(;;) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int x = syscall(450);
        printf("Consumer %d removed value %d from %d\n",*((int *)cno), x, out);
        sleep(1);
        out = (out+1)%10;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}
int main()
{   
    pthread_t pro[10], con[10];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, 10);
    sem_init(&full,0,0);
    int a[10] = {1,2,3,4,5,6,7,8,9,10}; 
    for(int i = 0; i < 10; i++) {
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);
    }
    for(int i = 0; i < 10; i++) {
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);
    }
    for(int i = 0; i < 10; i++) {
        pthread_join(pro[i], NULL);
    }
    for(int i = 0; i < 10; i++) {
        pthread_join(con[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}