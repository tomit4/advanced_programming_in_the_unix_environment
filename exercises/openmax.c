/* #include "apue.h" */
#include <limits.h>
#include <sys/resource.h>

#include <errno.h>  /* for definition of errno */
#include <stdarg.h> /* ISO C variable aruments */
#include <stdio.h>
#include <stdlib.h> /* for convenience */
#include <string.h> /* for convenience */
#include <unistd.h> /* for convenience */

void err_sys(const char *, ...) __attribute__((noreturn));
static void err_doit(int errnoflag, int error, const char *fmt, va_list ap);

#define MAXLINE 4096 /* max line length */

#define OPEN_MAX_GUESS 256

long open_max(void)
{
	long openmax;
	struct rlimit rl;

	if ((openmax = sysconf(_SC_OPEN_MAX)) < 0 || openmax == LONG_MAX) {
		if (getrlimit(RLIMIT_NOFILE, &rl) < 0)
			err_sys("can't get file limit");
		if (rl.rlim_max == RLIM_INFINITY)
			openmax = OPEN_MAX_GUESS;
		else
			openmax = rl.rlim_max;
	}
	return (openmax);
}

void err_sys(const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	err_doit(1, errno, fmt, ap);
	va_end(ap);
	exit(1);
}

static void err_doit(int errnoflag, int error, const char *fmt, va_list ap)
{
	char buf[MAXLINE];

	vsnprintf(buf, MAXLINE - 1, fmt, ap);
	if (errnoflag)
		snprintf(buf + strlen(buf), MAXLINE - strlen(buf) - 1, ": %s",
			 strerror(error));
	strcat(buf, "\n");
	fflush(stdout); /* in case stdout and stderr are the same */
	fputs(buf, stderr);
	fflush(NULL); /* flushes all stdio output streams */
}
