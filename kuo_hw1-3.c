#include<stdio.h>
#include<stdlib.h>

int line2[5000][100];
int count[5000];

int main()
{
    int numnodes;
    int a, b;

    int delen;
    scanf("%d", &numnodes);
    for(int i = 0;i<numnodes-1;i++)
    {
        scanf("%d %d", &a, &b);
        count[a]++;
        count[b]++;
        line2[a][count[a]] = b;
        line2[b][count[b]] = a;
    }
    for(int x = 0;x<numnodes-2;x++)
    {
        for(int i = 1;i<=numnodes;i++)
        {
            if(count[i]==1)
            {
                delen = i;
                count[i]--;
                break;
            }
        }
        if(x!=numnodes-3) printf("%d ", line2[delen][1] );
        else  printf("%d \n", line2[delen][1] );
        for(int i = 1;i<=count[line2[delen][1]];i++)
        {
            if(line2[line2[delen][1]][i]==delen)
            {
                for(int y = i;y<count[line2[delen][1]];y++)
                {
                    line2[line2[delen][1]][y] = line2[line2[delen][1]][y+1];////////////////////
                }
                count[line2[delen][1]]--;
                break;
            }
        }

    }
    return 0;
}
