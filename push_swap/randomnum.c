#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int num;
	int cnt;
	int i;
	int *arr;
	int issame;

	if (argc != 2)
	{
		printf("인자에 출력할 개수를 적어주세요. 인자는 1개만 적어야 합니다.\n");
		return (0);
	}
	cnt = atoi(argv[1]);
	arr = malloc(sizeof(int) * cnt);
	if (arr == NULL)
		return (1);
	i = 0;
	while (i < cnt)
	{
		issame = 0;
		num = rand() * rand() % cnt;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] == num)
			{
				issame = 1;
				break ;
			}
		}
		if (issame == 0)
		{
			arr[i] = num;
			i++;
		}
	}
	for(int j = 0; j < cnt; j++)
		printf("%d ", arr[j]);
}
