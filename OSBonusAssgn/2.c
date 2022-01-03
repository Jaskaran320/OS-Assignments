#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
sem_t bowl;
void* philo(void * num) {
	int phil = *(int *)num;
	sem_wait(&bowl);
	printf("Philosopher %d is tired of thinking and has started eating with a bowl\n", phil);
	sleep(1);
	printf("Philosopher %d has finished eating and has started thinking\n", phil);
	sem_post(&bowl);
}
int main() {
	int a[5];
	pthread_t thread[5];
	for(;;) {
		sem_init(&bowl, 0, 4);
		for(int i = 0; i < 5; i++){
			a[i] = i;
			pthread_create(&thread[i], NULL, philo, (void *)&a[i]);
		}
		for(int i = 0; i < 5; i++)
			pthread_join(thread[i], NULL);
		sem_destroy(&bowl);
	}
	return 0;
}