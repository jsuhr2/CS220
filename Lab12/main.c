#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int global_var;

void *worker_function(void *payload){

	printf("In thread %d\n", (int) payload);
	global_var++;
}

#define NUM_THREADS 3

int main(){
	pthread_t threads [NUM_THREADS];
	int i;
	void *payload;
	for(i = 0; i < NUM_THREADS; i++){
		pthread_create(&threads[i], NULL, worker_function, (void *) payload);
		global_var++;
		printf("global_var: %i\n", global_var);
	}

	printf("In main thread\n");


	for(i = 0; i < NUM_THREADS; i++){
		pthread_join(threads[i], NULL);
	}

	void *m = malloc(sizeof(void *));
	
	printf("Inside Main Malloc: %p\n", m);
	
	printf("Exiting main thread\n");
	
	printf("Ooutside Main Malloc: %p\n", m);

	pthread_exit(NULL);
	return(0);
}
