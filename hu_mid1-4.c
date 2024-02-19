#include<stdio.h>

int main()
{
    int len;
    scanf("%d", &len);
    char str[111111];
    scanf("%s", str);
    int times;
    scanf("%d", &times);
    int str1[111111];
    int tmp[111111];
    for(int i = 0; i<len; i++)
    {
        str1[i]= str[i] - '0';
    }
    int a, b, sz;
    long long int numA = 0, numB= 0;
    for(int i = 0; i<times; i++)
    {
        numA = 0;numB = 0;
        scanf("%d %d %d", &a, &b, &sz);
        for(int x = a, y = b; x<a+sz;x++, y++)
        {
            numA = numA* 10;
            numA = str1[x] +numA;
            numB = numB*10;
            numB = str1[y]+numB;
            str1[x] = 123;
            str1[y] = 123;
        }
        printf("%lld\n", numA*numB);
        for(int x = 0, y = 0;x<len;x++, y++)
        {
            while(str1[x] ==123)
            {
                x = x+1;
            }
            tmp[y] = str1[x];
        }
        len = len -2*sz;
        for(int x = 0; x<len;x++)
        {
            str1[x] = tmp[x];

        }


    }
    return 0;

}
