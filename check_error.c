int	check_err(char *str)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (str[i] < '1' && str[i] > '4')
				return (0);
			cnt++;
			i++;
		}
		
		if (cnt > 16)
			return (0);
	}
	return (1);
}
