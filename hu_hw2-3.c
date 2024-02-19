#include <stdio.h>
main()
{
	int n,a[100][100]={0},i,j,x,y,c=1;
	x=0,y=0;
	scanf("%d",&n);
	n = n*2;
	a[x][y]=c;
	while (c<n*n)
	{
		while (y+1<n&&!a[x][y+1])
		 a[x][++y]=++c;
		while (x+1<n&&!a[x+1][y])
		a[++x][y]=++c;
		while (y-1>=0&&!a[x][y-1])
		a[x][--y]=++c;
		while (x-1>0&&!a[x-1][y])
		a[--x][y]=++c;
	}
	for (i=0;i<n;i++)
	{
	for (j=0;j<n;j++)
	{
	printf("%d",a[i][j]);
		if(j!=n-1)
		{
			printf(" ");
		}
	}
	printf("\n");
	}

}
