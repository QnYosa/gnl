#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main ()
{
	int fd;
	char *line;
	int ret;
	int i; 

	i = 0;

	//line = malloc(sizeof(char) * 100);
	fd = open("yo", O_RDONLY);
	while (i < 5)
	{
		ret = get_next_line(fd, &line);
		i++;
		printf("%s\n", line);
		printf("\n");
		free(line);
	}
}