#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static unsigned int retry = 0;

void nope(int sig_num) {
	printf("\nGo AWAY\n");

	if (retry > 3) {
		printf("\nFine!\n");
		exit(0);
	}

	retry++;
}

int main() {
	printf("Going to eat your memories!\n");
	/* signal(SIGTERM, nope); */

	while(1) {
		malloc(200 * sizeof(int));
		usleep(2);
	}

	return 0;
}
