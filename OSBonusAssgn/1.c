#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
sem_t forks[5];
void* philo(void * num) {
	int phil = *(int *)num;
	sem_wait(&forks[phil]);
	sem_wait(&forks[(phil+1)%5]);
	printf("Philosopher %d is tired of thinking and has started eating with forks %d and %d\n", phil, phil, (phil+1)%5);
	sleep(1);
	printf("Philosopher %d has finished eating and has started thinking\n", phil);
	sem_post(&forks[(phil+1)%5]);
	sem_post(&forks[phil]);
}
int main() {
	int a[5];
	pthread_t thread[5];
	for(;;) {
		for(int i = 0; i < 5; i++)
			sem_init(&forks[i], 0, 1);
		for(int i = 0; i < 5; i++){
			a[i]=i;
			pthread_create(&thread[i], NULL, philo, (void *)&a[i]);
		}
		for(int i = 0; i < 5; i++)
			pthread_join(thread[i], NULL);
		for(int i = 0; i < 5; i++)
			sem_destroy(&forks[i]);
	}
	return 0;
}