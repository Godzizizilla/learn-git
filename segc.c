#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigsegv_handler(int signum) {
    fprintf(stderr, "Caught segmentation fault!\n");
    exit(1);
}

int main() {
		signal(SIGSEGV, sigsegv_handler);

		int *p = NULL;
		puts("before invalid access");
		*p = 0;
		puts("after invalid access");
		exit(EXIT_SUCCESS);
}
