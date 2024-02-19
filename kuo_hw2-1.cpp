#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int ans = 0;
    for(int i = 0;i<s.length();i++)
    {
        int i2 = i+1, i3 = i+2;
        if(i2<s.length()&&s[i]==s[i2]&&s[i]!='X'&&s[i2]!='X') ans++, s[i2]='X';
        if(i3<s.length()&&s[i]==s[i3]&&s[i]!='X'&&s[i3]!='X') ans++, s[i3] = 'X';
    }
    cout<<ans<<endl;
}
