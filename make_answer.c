#include <stdio.h>

void	print_ans(char arr[4][5])
{
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			//write(1, &arr[i][j], 1);
			printf("%c", arr[i][j]);
			if (j < 3)
				printf(" ");
			j++;
		}
		//write(1, "\n", 1);
		printf("\n");
		i++;
	}
	arr[0][4] = '5';
}

int	check_num(int i, int j, char x, char arr[4][5])
{
	
   int	idx;

	idx = 0;
	while (idx < 4)
	{
		if (x == arr[i][idx])
			return (0);
		if (x == arr[idx][j])
			return (0);
		idx++;
	}
	return (1);
}

void	make_board(int i, int j, char arr[4][5], char test[4][4])
{
	char	x;

	if (arr[0][4] == '5')
		return ;
	else
	{
		if (i == 4) //정답이 맞는지 확인하는 추가적인 기능 필요
		{
			print_ans(arr);
			return ;
		}
		x = '0';
		while (++x < '5')
		{
			if (check_num(i, j, x, arr) == 1)
			{	
				arr[i][j] = x;
				if (j + 1 == 4)
					make_board(i + 1, 0, arr, test);
				else
					make_board(i, j + 1, arr, test);
				arr[i][j] = '0';
			}
		}
	}
}