#include<iostream>
#include"function.h"
#define MOD 880301
special_power::special_power(int n){ //special_power::special_power(int n){this->n = n;}
    this->n = n;
}
int special_power::fpow(int x){ //int special_power::fpow(int x){return fpow(x, MOD);}
    return fpow(x, MOD);
}
int special_power::fpow(int x, int m){ //int special_power::fpow(int x, int m){long long num = 1; for(int i = 0;i<n;i++){num = (x*num)%m;}return num;} **************
    long long num = 1;
    for(int i = 0; i < n; i++){
        num = (x * num) % m;
    }
    return num;
}
int special_power::fpow(){ //int special_pow::fpow(){return fpow(2);
    return fpow(2);
}
string special_power::fpow(string s){ //string special_pow::fpow(string s){string S="";for(int i = 0;i<s.length();i++){for(int j = 0;j<n;j++) S.push_back(s[i]);return S;}**************
    string S = "";
    for(int i = 0; i < s.length(); i++){
        for(int j = 0; j < n; j++) S.push_back(s[i]);
    }
    return S;
}
string special_power::fpow(string s, int m){ //string special_pow::fpow(string s, int m){int len = s.length()*n; if(len>m) len = m; string S = ""; for(int i = 0;i<s.length();i++){for(int j = 0;j<n&&len;j++,len--)S.push_back(s[i]);
    int len = s.length() * n;
    if(len > m) len = m;
    string S = "";
    for(int i = 0; i < s.length() && len; i++){
        for(int j = 0; j < n && len; j++, len--) S.push_back(s[i]);
    }
    return S;
}
