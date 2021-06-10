int  test(char *str)
{
	static int i = -1;
	i++;
	while (str[i])
	{
		if (str[i] == 'l')
			return (i);
		i++;
	}
	return (0);
}

int main ()
{
	static char str [] = "hola lo llamo";
	printf("%d\n", test(str));
	//printf("%d\n", test(str));
	//printf("%d\n", test(str));
	//printf("%d\n", test(str));
}