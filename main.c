#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/errno.h>
#include <string.h>
#include <stdlib.h> // exit();

#ifndef NUM_THREADS
# define NUM_THREADS 5
#endif

void	print_error(char *str, int status)
{
	printf("%s\n", str);
	if (status != 0)
		exit(status);
}

void	*sample_fuction(void *arg)
{
	printf("GIRDIK Philo ID: %ld\n", (long)arg);
	while (1)
	{
		printf("philo ID: %ld\n", (long)arg);
		usleep(1000000);
	}
}

// rm -rf a.out && gcc main.c && ./a.out
int	main()
{
	int			i;
	int			ret_thread;
	pthread_t	ths[NUM_THREADS]; // 2

	// pthread_create(&ths[0], NULL, sample_fuction, "Disaridan veridigmiz mal.\n");
	// pthread_create(&ths[1], NULL, sample_fuction2, "2'yi verdik disaridan.\n");

	i = 0;
	while (i < NUM_THREADS)
	{
		ret_thread = pthread_create(&ths[i], NULL, sample_fuction, (void *)(intptr_t)i);
		if (ret_thread != 0)
			print_error(strerror(errno), errno);
		i++;
	}

	write(1, "kaka\n", 6);
	while (1);
	return (0);
}