#include<bits/stdc++.h>
using namespace std;

unsigned long int a[100001]={}; // card data
int b[100001]={}; // how much
int main()
{
    ios::sync_with_stdio(0);
    int N;
    cin>>N;
    unsigned long int carddata;
    //int cardnum;
    int flag = 0;
    for(int i = 0;i<N;i++)
    {
        flag = 0;
        cin>>carddata;
        for(int j = 0;j<i;j++)
        {
            if(a[j]== carddata) //©â¹L
            {
                b[j]++;
                flag = 1;
            }
        }

        if(flag==0) //¨S©â¹L
        {
            a[i]=carddata;
            b[i]=1;
        }
        ///////////////`////////////
        unsigned long int ans;

        int maxnum = -1;
        for(int z = 0;z<=i;z++)
        {
            if(b[z]>maxnum)
            {
                ans = a[z];
                maxnum = b[z];
            }
            else if(b[z] == maxnum)
            {
                if(a[z]>ans)
                {
                    ans = a[z];
                }
            }
        }
        cout<<ans<<endl;
    }

}
