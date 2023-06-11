
//추가적으로 에러를 검사하는 함수
int	check_err(char *str)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (i % 2 == 0) //배열의 값이 숫자인 index일 때
		{
			if (str[i] < '1' && str[i] > '4')   //입력 받은 숫자의 범위가 올바르지 않을 떄 0반환
				return (0);
			cnt++;
			i++;
		}
		else    //배열에 저장된 값이 공백인 index일 때
		{
			if (str[i] == ' ' || (str[i] > 8 && str[i] < 14))   //white space도 공배으로 설정
				i++;
			else
				return (0);
		}
		if (cnt > 16)   //입력받은 값의 수가 맞지 않으면 0반환
			return (0);
	}
	return (1);
}
