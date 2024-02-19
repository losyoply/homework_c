#include<stdio.h>
int main()
{

    int a[5];
    char point;
    scanf("%d%c%d %d%c%d%c%d", &a[0], &point, &a[1], &a[2], &point, &a[3], &point, &a[4]);
    int b[5];
    scanf("%d%c%d %d%c%d%c%d", &b[0], &point, &b[1], &b[2], &point, &b[3], &point, &b[4]);
    int ans1, ans2;
    int asec, amin, ahr;
    for(int i = 0; i<5;i++)
    {
        if(a[i]>b[i])
        {
            break;
        }
        else if(a[i] <b[i])
        {
            int temp[5];
            for(int h = 0; h<5;h++)
            {
                temp[h] = a[h];
                a[h] = b[h];
                b[h] = temp[h];

            }
            break;
        }

    }
    if(a[4]>=b[4])
    {
        asec = a[4]- b[4];
    }
    else
    {
        asec = a[4]- b[4]+60;
       a[3] = a[3] -1;
    }
    if(a[3]>=b[3])
    {
        amin = a[3]-b[3];
    }
    else
    {
        amin =  a[3]-b[3]+60;
        a[2] = a[2] -1;
    }
    if(a[2]>=b[2])
    {
        ahr = a[2] - b[2];
    }
    else
    {
        ahr = a[2]-b[2]+24;
        a[1] = a[1]-1;
    }
    if(a[1]>=b[1])
    {
        ans2 = a[1] - b[1];
    }
    else
    {
        ans2 = a[1] - b[1]+30;
        a[0] = a[0] -1;
    }
    ans1 = a[0] -b[0];
    printf("%d %d\n", ans1, ans2);

    printf("%02d:%02d:%02d\n", ahr, amin, asec);
    return 0;
}
