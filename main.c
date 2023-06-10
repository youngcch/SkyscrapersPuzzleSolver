#include <stdio.h>

int	main()
{
	
	size_t	len = 0;	//입력 받을 때 사용
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
}

