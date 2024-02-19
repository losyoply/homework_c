#include<stdio.h>

int main()
{
    int row, col;
    scanf("%d %d", &row, &col);
    int ma[row][col];
    for(int i =0; i<row;i++)
    {
        for(int x = 0; x<col; x++)
        {
            scanf("%d", &ma[i][x]);
        }
    }

    for(int i =0; i<col;i++)
    {
        for(int x = 0; x<row; x++)
        {
            printf("%d", ma[x][i]);
            if(x+1<row)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
