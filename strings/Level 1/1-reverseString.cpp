// 1. Reverse String

#include <iostream>
using namespace std;

string reverseString(const string &s){
    if(s.empty()) return "";
    // string res = "";
    // for(int i=s.length()-1; i>=0; i--) {
    //     res +=s[i];
    // }
    // cout<<"Reversed "<< s <<" string is "<<res<<endl;
    
    string res = s;
    int start =0; int end=s.length()-1;
    
    while(start<end){
        swap(res[start++], res[end--]);
    }
    cout<<"Reversed "<< s <<" string is "<<res<<endl;
    return res; 
}

int main() {
    const string s1 = "Aadarsh is a good boy";
    // cout << s1 << endl;
    reverseString(s1);
    return 0;
}