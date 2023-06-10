#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void	input_arr(char *argv, char test[4][4])
{
	int	i;
	int	row;
	int	col;

	i = 0;
	row = 0;
	col = 0;
	while (argv[i])
	{
		if (i % 2 == 0)
		{
			test[row][col] = argv[i];
			col ++;
			if (col == 4)
			{
				col = 0;
				row++;
			}
		}
		i++;
	}
}

int	main()
{
	int		i;
	int		j;
	size_t	len = 0;	//입력 받을 때 사용
	char	arr[4][5];	//입력 받은 값 4x4 테이블 형태로 저장, 마지막 열은 에러체크 및 예외처리로 사용
	char	test[4][4];	//skyscrapers puzzle의 답을 맞추기 위해 이 배열에 숫자를 하나씩 채워가며 정답 생성
	char	*argv = NULL;	//문자 입력 받을 떄 사용

	//안내 문구
	printf("Insert in the order of top, bottom, left, right.\n");	
	printf("(top and bottom values are left to right, left and right values are top to bottom)\n");
	printf("ex: 1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4\n");
	printf("values given in question: ");
	getline(&argv, &len, stdin);
	printf("\n");
	if (strlen(argv) != 32)
	{
		printf("Error: Pleaase enter correct values\n");
		return (0);
	}
	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 5)
		{
			arr[i][j++] = '0';
		}
		i++;
	}
	input_arr(argv, test);
}

