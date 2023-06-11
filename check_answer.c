int	check_up(char arr[4][5], char up[4])
{
	char	max;
	int		i;
	int		cnt;
	int		j;

	i = 0;
	while (i < 4)
	{
		max = arr[0][i];
		cnt = 1;
		j = 0;
		while (j < 3)
		{
			if (max < arr[j + 1][i])
			{
				max = arr[j + 1][i];
				cnt ++;
			}
			j++;
		}
		if (up[i] != '0' + cnt)
			return (0);
		i ++;
	}
	return (1);
}