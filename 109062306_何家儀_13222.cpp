#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<long long> a;
    int N;
    cin>> N;
    long long ele;
    for(int i = 1;i<=N;i++)
    {
        cin>>ele;
        a.push_back(ele);
    }

    long long ans =0;
    vector<long long>::iterator it;
    long long maxnum;
    maxnum = *max_element(a.begin(), a.end());
    for(int i = 1;i<=N;i++)
    {
        for(int j = i;j<=N;j++)
        {
            it = find(a.begin()+i-1, a.begin()+j,maxnum);
            if(it!=a.begin()+j) ans+=maxnum;
            else ans= *max_element(a.begin()+i-1, a.begin()+j) + ans;
        }
    }
    cout<<ans<<endl;
}
