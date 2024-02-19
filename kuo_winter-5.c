#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N,M;
int turn[26];
char name[200005], C1, C2; char sp;
int main()
{
    for(int i = 0; i<26;i++) turn[i] = i;
    scanf("%d %d %s", &N, &M, name);
    scanf("%c", &sp);

     while(M--)
    {
        scanf("%c%c%c%c", &C1,&sp,&C2,&sp);

        for(int i = 0;i<26;i++)
        {
            if(turn[i] == C1-'a') turn[i] = C2-'a';
            else if(turn[i] == C2-'a') turn[i] = C1-'a';
        }
    }
        for(int i = 0;i<N;i++) name[i] = turn[name[i]-'a']+'a';
        puts(name);

}
/* TLE>>>>>>>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N,M;
int turn[26];
char name[200005], C1, C2;
int main()
{
    for(int i = 0; i<26;i++) turn[i] = i;
    scanf("%d %d %s", &N, &M, name);


     while(M--)
    {
        scanf("%s %s", &C1,&C2);

        for(int i = 0;i<N;i++)
        {
            if(name[i] == C1) name[i] = C2;
            else if(name[i] == C2) name[i] = C1;
        }
    }
    printf("%s\n", name);

}
*/
