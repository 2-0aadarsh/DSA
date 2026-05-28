#include<bits/stdc++.h>
using namespace std;

string reverseString(const string &str, int length) {
    if(length == 0) return "";
    string newStr = string(1,str[length-1]) + reverseString(str, length-1);
    return newStr;
}

int main(){
    string str = "hello boi";
    cout<<reverseString(str, str.length());
    // cout<<string(1, 'q');
    return 0;
}