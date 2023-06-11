#include <stdio.h>

extern int	check_all(char arr[4][5], char test[4][4]);

//정답 출력하는 함수
void	print_ans(char arr[4][5])
{
	int			i;
	int			j;

	i = 0;
	while (i < 4)	//반복문 사용하여 정답 출력
	{
		j = 0;
		while (j < 4)
		{
			printf("%c", arr[i][j]);
			if (j < 3)
				printf(" ");	//값들 사이에 공백
			j++;
        }
		printf("\n");	//puzzle이 4x4형태이므로 사이에 줄바꿈 출력
		i++;
	}
	arr[0][4] = '5';
}
//정답을 만들고 있는 배열에서 같은 행과 열에 중복되는 값이 있는지 확인
int	check_num(int i, int j, char x, char arr[4][5])
{
	
   int	idx;

	idx = 0;
	//같은 행과 열에 중복되는 값이 있으면 0반환
	while (idx < 4)
	{
		if (x == arr[i][idx])
			return (0);
		if (x == arr[idx][j])
			return (0);
		idx++;
	}
	//중복되는 값이 없이 정답 후보가 되는 값이면 1반환
	return (1);
}

void	make_board(int i, int j, char arr[4][5], char test[4][4])
{
	char	x;

	if (arr[0][4] == '5')	//값이 올바르지 않을 때 종료
		return ;
	else
	{
		if (i == 4 && check_all(arr, test) == 1) //값이 모든 조건을 만족할 때
		{
			print_ans(arr);	//정답 출력후 종료
			return ;
		}
		x = '0';	//초기값에 0저장후 늘려나가며 비교
		while (++x < '5')
		{
			if (check_num(i, j, x, arr) == 1)	//값이 정답 후보일 때
			{	
				arr[i][j] = x;
				//재귀함수를 사용하여 초기값 x를 증가해나가며 값을 맞춰 나감.
				if (j + 1 == 4)
					make_board(i + 1, 0, arr, test);	
				else
					make_board(i, j + 1, arr, test);
				arr[i][j] = '0';
			}
		}
	}
}