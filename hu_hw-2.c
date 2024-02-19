#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char in[111] = {0};
    scanf("%s", in);
    int l;
    l = strlen(in);
    for(int i = l-1;i>=0;i--)
    {
        if(in[i] == '2'||in[i] == '3'||in[i] == '4'||in[i] == '5'||in[i] == '7')
        {
            printf("No\n");
            exit(0);
        }
    }
    int a = 0;
    for(int i = l-1;i>=0;i--)
    {
        if(in[i])
        {

            switch(in[i])
            {
                case '0':if(a!=0){ printf("0");}break;
                case '1':printf("1");a = a+1;break;
                case '6':printf("9");a = a+1;break;
                case '8':printf("8");a = a+1;break;
                case '9':printf("6");a = a+1;break;
            }
        }

    }
    printf("\n");
    return 0;
}
