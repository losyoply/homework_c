#include<stdio.h>

int main()
{
    int row, col;
    scanf("%d %d", &row, &col);
    int mat[150][150]={};
    int temp;
    for(int x = 0; x<row; x++)
    {
        for(int y = 0; y<col; y++)
        {
            scanf("%d", &mat[x][y]);
        }
    }
    int tmparr[150][150]={};
    int time;
    scanf("%d", &time);
    time = time%4;
    while(time)
    {
        temp = row;
        row = col;
        col = temp;

        for(int x = 0;x<row;x++)
        {
            for(int y = 0; y<col;y++)
            {
                tmparr[x][y] = mat[col-1-y][x];
            }
        }

        for(int x = 0; x<row;x++)
        {
            for(int y = 0; y<col; y++)
            {
                mat[x][y] = tmparr[x][y];
            }
        }
        time = time-1;
    }

    for(int x = 0; x<row; x++)
    {
        for(int y = 0;y<col; y ++)
        {
            if(y == col-1)
            {
                printf("%d\n", mat[x][y]);

            }
            else
            {
                printf("%d ", mat[x][y]);
            }
        }
    }
    return 0;
}
