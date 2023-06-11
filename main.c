#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//외부 파일에서 구현된 함수 사용
extern int	check_err(char *str);
extern void	make_board(int i, int j, char arr[4][5], char test[4][4]);


//입력 받은 값 4x4 테이블 형태로 저장하기 위한 함수
void	input_arr(char *argv, char test[4][4])
{
	int	i;
	int	row;
	int	col;

	i = 0;
	row = 0;
	col = 0;
	while (argv[i])		//입력받은 문자열을 null만날 때까지 반복하여 값을 저장
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
	char	arr[4][5];	//skyscrapers puzzle의 답을 맞추기 위해 이 배열에 숫자를 하나씩 채워가며 정답 생성, 마지막 열은 에러체크 및 예외처리로 사용
	char	test[4][4];	//입력 받은 값 4x4 테이블 형태로 저장
	char	*argv = NULL;	//문자 입력 받을 떄 사용

	//안내 문구
	printf("Insert in the order of top, bottom, left, right.\n");	//입력 순서 및 안내
	printf("(top and bottom values are left to right, left and right values are top to bottom)\n");
	printf("ex: 1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4\n");	//입력 예시
	printf("values given in question: ");
	getline(&argv, &len, stdin);	//값 입력받기
	printf("\n");	//공백 출력
	i = 0;
	j = 0;
	if (check_err(argv) == 0 || strlen(argv) != 32)	//입력 받은 값이 조건에 맞지 않을 떄 에러메세지 출력후 종료
	{
		printf("Error: Pleaase enter correct values\n");
		return (0);
	}
	//정답이 저장될 배열에 0저장
	while (i < 4)
	{
		j = 0;
		while (j < 5)
		{
			arr[i][j++] = '0';
		}
		i++;
	}
	input_arr(argv, test);	//정답을 4x4형태로 배열에 저장
	make_board(0, 0, arr, test);	//정답 생성 함수
	return (0);
}
