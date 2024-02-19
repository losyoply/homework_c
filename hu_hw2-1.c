#include<stdio.h>

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n+1][m+1];
	for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int q;
	scanf("%d",&q);
	for(int t=0;t<q;t++)
    {
		int u,d,l,r;
		scanf("%d %d %d %d",&u,&d,&l,&r);
		int ans = 0;
		 /* do something */
		 for(int x=u; x<=d;x++)
         {
             for(int y=l ; y<=r; y++)
             {
                 if(ans<a[x][y])
                 {
                     ans = a[x][y];
                 }
             }
         }

		printf("%d\n",ans);	// output the answer immedialety
    }
    return 0;
}
