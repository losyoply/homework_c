#include<iostream>
#include<set>

using namespace std;

int main()
{
    string s;
    multiset<int> q;
    int num;

    while(cin>>s)
    {
        if(s=="PUSH")
        {

            cin>>num;
            q.insert(num);

        }
        else if(s=="POPMIN")
        {
                 if (q.empty()) continue;
            q.erase(q.begin());
        }
        else if(s=="POPMAX")
        {
            if (q.empty()) continue;
             multiset<int>::iterator it = q.end();
            it--;
            q.erase(it);
        }
        else if(s=="MIN")
        {
            if (q.empty())
            {
                cout << "Null\n";
                continue;
            }
            cout<<*q.begin()<<endl;
        }
        else if(s=="MAX")
        {
            if (q.empty())
            {
                cout << "Null\n";
                continue;
            }
            multiset<int>::iterator it = q.end();
            it--;
            cout<< *it<<endl;
        }
        else if(s=="CLEAR")
        {
            q.clear();

        }
    }
}
