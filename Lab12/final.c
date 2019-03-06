#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

char *key;

void *print(void *param){
	printf("%s\n", key);
	return NULL;
}

void *scan(void *param){
	scanf("%s", key);
	//printf("%s\n", key);
	return NULL;
}

int main(){
	key = malloc(sizeof(char)*1024);

	pthread_t tid1, tid2;

	pthread_create(&tid1, NULL, scan, NULL);

	pthread_join(tid1, NULL);

	pthread_create(&tid2, NULL, print, NULL);

	pthread_join(tid2, NULL);
	
	free(key);

	return 0;
}
