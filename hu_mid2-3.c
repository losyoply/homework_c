#include<stdio.h>
#define MAXN 302

int T, N, M;
char maze[MAXN][MAXN];
int been[MAXN][MAXN];
int Y[]={-1, 0, 1, 0}, X[]={0, 1, 0, -1};
int startP[2], portP[26][2], endP[2];
void solve(int y, int x)
{
    been[y][x] = 1; // save if you can arrive
    if(maze[y][x] >= 'a' && maze[y][x] <= 'z') solve(portP[maze[y][x]-'a'][0], portP[maze[y][x]-'a'][1]); //teleport
    else
    {
        for(int d = 0; d<4; d++)
        {
            if(maze[y+Y[d]][x+X[d]] && maze[y+Y[d]][x+X[d]]!='#' && !been[y+Y[d]][x+X[d]]) solve(y+Y[d], x+X[d]);
        }
    }

}

int main()
{
    for(scanf("%d", &T);T--;)
    {
        for(int y = 0; y < MAXN; y++) for(int x = 0; x < MAXN; x++) maze[y][x] = been[y][x] = 0;
        scanf("%d%d", &N, &M);
        for(int y = 1; y <= N; y++) scanf("%s", maze[y]+1);

        for(int y = 1; y<=N ;y++)
        {
            for(int x = 1; x<=M;x++)
            {
                if(maze[y][x] == '$') startP[0] = y, startP[1] = x;
                else if(maze[y][x] == '&') endP[0] = y, endP[1] = x;
                else if(maze[y][x] >= 'A' && maze[y][x] <= 'Z') portP[maze[y][x]-'A'][0] = y, portP[maze[y][x]-'A'][1] = x; ///////////////////
            }
        }

        solve(startP[0], startP[1]);
        if(been[endP[0]][endP[1]]) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
