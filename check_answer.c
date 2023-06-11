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

int	check_down(char arr[4][5], char down[4])
{
	char	max;
	int		i;
	int		cnt;
	int		j;

	i = 0;
	while (i < 4)
	{
		max = arr[3][i];
		cnt = 1;
		j = 3;
		while (j > 0)
		{
			if (max < arr[j - 1][i])
			{
				max = arr[j - 1][i];
				cnt ++;
			}
			j--;
		}
		if (down[i] != '0' + cnt)
			return (0);
		i ++;
	}
	return (1);
}

int	check_left(char arr[4][5], char left[4])
{
	char	max;
	int		i;
	int		cnt;
	int		j;

	i = 0;
	while (i < 4)
	{
		max = arr[i][0];
		cnt = 1;
		j = 0;
		while (j < 3)
		{
			if (max < arr[i][j + 1])
			{
				max = arr[i][j + 1];
				cnt ++;
			}
			j++;
		}
		if (left[i] != '0' + cnt)
			return (0);
		i ++;
	}
	return (1);
}

int	check_right(char arr[4][5], char right[4])
{
	char	max;
	int		i;
	int		cnt;
	int		j;

	i = 0;
	while (i < 4)
	{
		max = arr[i][3];
		cnt = 1;
		j = 3;
		while (j > 0)
		{
			if (max < arr[i][j - 1])
			{
				max = arr[i][j - 1];
				cnt ++;
			}
			j--;
		}
		if (right[i] != '0' + cnt)
			return (0);
		i ++;
	}
	return (1);
}
