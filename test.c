#include <stdio.h>
#include <stdlib.h>

char *no_backslash(char *tmp)
{
	int		i;
	char	*new;

	i = 0;
	while (*tmp != '\n')
		tmp++;
	tmp++;
	while (tmp[i])
		i++;
	new = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (tmp[i])
	{
		tmp[i] = new[i];
		i++;
	}
	return (new);
}

int main ()
{
	char tmp [] = "ole\n hola";
	printf("%s", no_backslash(tmp));
}