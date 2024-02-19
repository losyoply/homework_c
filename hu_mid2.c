#include<stdio.h>
int K;
char tmp;
#define SWAP(a,b) {tmp=a;a=b;b=tmp;}
char A[5][5], B[5][5], startPos[2];
int dy[]={-1,0,1,0}, dx[]={0,1,0,-1};
int available;

int check()
{
    for(int i = 1; i <= 3; i++) for(int j = 1; j <= 3; j++)
        if(A[i][j] != B[i][j]) return 0;
    return 1;
}
void solve(int y, int x, int step)
{
    if(check()) available = 1;
    else if(step)
    {
         for(int d = 0; d < 4; d++)
         {
             if(A[y + dy[d]][x + dx[d]])
             {
                SWAP(A[y][x], A[y + dy[d]][x + dx[d]]);
                solve(y+dy[d], x+dx[d], step-1);
                SWAP(A[y][x], A[y + dy[d]][x + dx[d]]);
             }

         }

    }

}

int main()
{
    int T;
    for(scanf("%d", &T);T--;)
    {
        scanf("%d", &K);
        available = 0;
        for(int i = 0; i < 5; i++) for(int j = 0; j < 5; j++) A[i][j] = B[i][j] = 0;

        for(int i = 1; i <= 3; i++) scanf("%s", A[i]+1);
        for(int i = 1; i <= 3; i++) scanf("%s", B[i]+1);

        for(int i = 1; i <= 3; i++) for(int j = 1; j <= 3; j++) if(A[i][j] == 'x') startPos[0] = i, startPos[1] = j;

        solve(startPos[0], startPos[1], K);
        printf("%s\n", available ? "Yes" : "No");

    }
    return 0;
}
