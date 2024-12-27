#include "apue.h"
#include <errno.h>

int main(int argc, char *argv[])
{
	(void)(argc);
	fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
	errno = ENOENT;
	perror(argv[0]);
	exit(0);
}
