#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main ()
{
	int fd;
	char *line;
	int ret;

	line = malloc(sizeof(char) * 100);
	fd = open("yo", O_RDONLY);
	ret = get_next_line(fd, &line);
	printf("%s\n", line);

}