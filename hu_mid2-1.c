#include<stdio.h>
#define MAX 2050
int prin = 0;
    int ans[MAX][10] = {};
    char s[12] ;
    int N;
    int xpos;
int main()
{

    scanf("%d", &N);
    for(int i = 0; i<N;i++)
    {
        scanf("%s", s);
        int h = 0;
        for(int x = 0;x<10;x++)
        {
            if(s[x]=='x')
            {
                xpos = x;
            }
        }

        for(int x = 0; x<10; x++)
        {
            if(x == xpos)
            {
                x++;
            }
            h = h<<1;
            if(s[x] == '1') h = h +1; else h = h+0;
        }
        ans[h][xpos]++;
    }
    for(int i = 0; i<MAX; i++)
    {
        for(int j = 0; j<10; j++)
        {
            if(ans[i][j]) prin++;

        }
    }
    printf("%d\n", prin);
return 0;

}
