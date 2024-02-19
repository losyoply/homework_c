#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
    }
    int times;
    scanf("%d", &times);
    for(int i=0;i<times;i++)
    {
        int p,b;
        scanf("%d %d", &p,&b);
        int QOQ=0;
        int QOQf=0;
        int temp;
        for(int x=p;x<=b;x++)
        {
            QOQ=0;
            for(int h=p;h<=b;h++)
            {
                if(a[x] == a[h])
                {
                    QOQ=QOQ+1;
                }

            }
            if(QOQf<QOQ)
            {
                temp = a[x];
                QOQf = QOQ;
            }
            else if(QOQf == QOQ)
            {
                if(temp>a[x])
                {
                    temp = a[x];
                }
            }
        }
        printf("%d\n", temp);
    }

    return 0;
}
