#include <stdio.h>
#include <pthread.h>

int shared_resource = 0;
// pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

void *increment(void *arg) {
	int i;
	for (i = 0; i < 100000; i++) {
		// pthread_mutex_lock(&mutex);
		shared_resource++;
		// pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

void *decrement(void *arg) {
	int i;
	for (i = 0; i < 100000; i++) {
		// pthread_mutex_lock(&mutex);
		shared_resource--;
		// pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

// rm -rf a.out && gcc race_condition.c && ./a.out
int main() {
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, increment, NULL);
	pthread_create(&thread2, NULL, decrement, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("Shared Resource: %d\n", shared_resource);
	return 0;
}
