#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void* dormir(void* arg)

{

    //wait
    
    sem_wait(&mutex);
    
    printf("\n Primero..\n");
    
    //critical section
    
    sleep(4);
    
    //signal
    
    printf("\n Segundo..\n");
    
    sem_post(&mutex);
}


int main()

{

	sem_init(&mutex, 0, 1);

	pthread_t t1,t2;

	pthread_create(&t1,NULL,dormir,NULL);

	sleep(2);

	pthread_create(&t2,NULL,dormir,NULL);

	pthread_join(t1,NULL);

	pthread_join(t2,NULL);

	sem_destroy(&mutex);

	return 0;

}