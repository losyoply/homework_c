#include<iostream>
#include<set>
#include<string>
using namespace std;

int main()
{
    int T;
    cin>>T;
    string s;
    set<int> myset;
    while(T--)
    {
        cin>>s;
        if(s=="print"&&myset.begin() != myset.end())
        {
            for(set<int>::iterator i = myset.begin();i!=myset.end();i++)
            {
                if(i!=myset.begin()) cout<<" ";
                cout<<*i;
            }
            cout<<endl;
        }
        if(s=="insert")
        {
            int num;
            cin>>num;
            myset.insert(num);
        }
        if(s=="min"&&myset.begin() != myset.end())
        {
            cout<<*myset.begin()<<endl;
        }
        if(s=="range_erase")
        {
            int l, r;
            cin>>l>>r;
            myset.erase(myset.lower_bound(l), myset.upper_bound(r));
        }
    }
}
