#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char map[101][101];
int m=0, n=0, X;
int mark[101][101] = { 0 }; 
int x1[8] = { 0,1,1,1,0,-1,-1,-1 };
int y1[8] = { -1,0,1,-1,1,-1,0,1 };

void search(int x, int y, int N)
{
	if (x < 0 || y < 0 || x >= m || y >= n)
	{
		return;
	}
	if (mark[x][y] > 0 || map[x][y] != '@')
	{
		return;
	}
	mark[x][y] = N;
	for (int i = 0; i < 8; i++)
	{
		search(x + x1[i], y + y1[i], N);
	}
}
int main()
{
	while (scanf("%d%d", &m, &n) && m != 0)
	{
		X = 0;
		memset(mark, 0, sizeof(mark));

		for (int i = 0; i < m; i++)
		{
			scanf("%s", map[i]);
		}
		
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (mark[i][j] == 0 && map[i][j] == '@')
				{
					
					search(i, j, ++X);
				}
			}
		}

		printf("%d\n", X);
		n = 0;

	}
}

