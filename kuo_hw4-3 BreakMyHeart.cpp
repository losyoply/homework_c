#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
using namespace std;
set<int> my_set;
string s;
int main(){
    int t;
    cin >> t;
    while(t--){
        cin>>s;
        if(s == "print" && my_set.begin() != my_set.end()){
            for(set<int>::iterator i=my_set.begin(); i!=my_set.end(); i++) {
                if(i != my_set.begin())
                    cout << " ";
                cout << *i;
            }
            cout << '\n';
        }
        if(s== "range_erase"){
            int l, r;
            cin >> l >> r;
            my_set.erase(my_set.lower_bound(l), my_set.upper_bound(r));
        }
        if(s== "insert"){
            int now;
            cin >> now;
            my_set.insert(now);
        }
        if(s== "min"&& my_set.begin() != my_set.end()){
            printf("%d\n", *my_set.begin());
        }
    }
}
