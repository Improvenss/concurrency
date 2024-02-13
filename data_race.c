#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// If you are using this don't need to use pthread_mutex_init(&mutex, NULL) function;
// pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

// pthread_mutex_t	mutex;

void *increment(void *arg) {
	int *num_ptr = (int *)arg;
	for (int i = 0; i < 1000; i++) {
		// pthread_mutex_lock(&mutex);
		(*num_ptr)++;
		// pthread_mutex_unlock(&mutex);
		usleep(1000);
	}
	return NULL;
}

// rm -rf a.out && gcc data_race.c && ./a.out
int main() {
	int num = 0;
	pthread_t thread[1000];

	// pthread_mutex_init(&mutex, NULL);
	for (int i = 0; i < 1000; i++) {
		pthread_create(&thread[i], NULL, increment, (void *)&num);
	}

	for (int i = 0; i < 1000; i++) {
		pthread_join(thread[i], NULL);
	}

	printf("Counter: %d\n", num);
	return 0;
}
