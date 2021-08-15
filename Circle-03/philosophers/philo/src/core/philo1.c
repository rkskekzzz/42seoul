#include "philo.h"

pthread_mutex_t room;
pthread_mutex_t chopstick[5];

void * philosopher(void *);
void eat(int);
int main()
{
	int i,a[5];
	pthread_t tid[5];

	sem_init(&room,0,4);

	for(i=0;i<5;i++)
		pthread_mutex_init(&chopstick[i],0);

	for(i=0;i<5;i++){
		a[i]=i;
		pthread_create(&tid[i],NULL,philosopher,(void *)&a[i]);
	}
	for(i=0;i<5;i++)
		pthread_join(tid[i],NULL);
}

void * philosopher(void * num)
{
	int phil=*(int *)num;

	pthread_mutex_lock(&room);
	printf("\nPhilosopher %d has entered room",phil);
	pthread_mutex_lock(&chopstick[phil]);
	pthread_mutex_lock(&chopstick[(phil+1)%5]);

	eat(phil);
	sleep(2);
	printf("\nPhilosopher %d has finished eating",phil);

	pthread_mutex_unlock(&chopstick[(phil+1)%5]);
	pthread_mutex_unlock(&chopstick[phil]);
	pthread_mutex_unlock(&room);
}

void eat(int phil)
{
	printf("\nPhilosopher %d is eating",phil);
}
