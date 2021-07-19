#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int mails = 0;
pthread_mutex_t mutex;

void* routine(){
	for (int i=0;i<1000000;i++){
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}

int main(){
	pthread_t p1, p2;
	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&p1, NULL, &routine, NULL) != 0)
		return 1;
	if (pthread_create(&p2, NULL, &routine, NULL) != 0)
		return 2;

	if (pthread_join(p1, NULL) != 0)
		return 3;
	if (pthread_join(p2, NULL) != 0)
		return 4;


	pthread_mutex_destroy(&mutex);
	printf("Number of mails : %d\n", mails); 
	return 0;
}
