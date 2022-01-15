#include<stdlib.h>
#include<stdio.h>
#include<sys/time.h>

int f(int n) { return (n < 2) ? n : f(n-1) + f(n-2); }

int main(int argc, char *argv[])
{
	struct timeval start, end;
//	printf("%d\n", f(atoi(argv[1])));

	int i, n;

	n = atoi(argv[1]);

	for (i = 0; i <= n; i++) {
		gettimeofday(&start, NULL);
		f(i);
		gettimeofday(&end, NULL);

		//printf("%ld\n", ((end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec)));
		double elapsed = (end.tv_sec - start.tv_sec) + ((end.tv_usec - start.tv_usec)/1000000.0);
		printf("%lf\n", elapsed);
	}

	return 0;
}
