#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &str, int start, int end) {
    if(str.length() == 0) return false;   // assuming the empty string is not a palindrome
    if(start>=end) return true;

    if(str[start] != str[end]) {
        return false;
    }
    return isPalindrome(str, start+1, end-1);
}

int main(){
    string str = "madam";
    cout<<isPalindrome(str, 0, str.length()-1);
    return 0;
}