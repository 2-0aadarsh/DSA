#include<bits/stdc++.h>
using namespace std;

bool isVowel(char &ch) {
    ch = tolower(ch);
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        return true;
    } else {
        return false;
    }
}

int countVowels(string &str, int index, int &count) {
    if(str[index] == '\0') return count;

    char ch = str[index];
    if(isVowel(ch)) {
        count++;
    } 
    countVowels(str, index+1, count);
}

int main(){
    string str = "abecidA";
    int count = 0;
    int index = 0;
    // cout<<countVowels(str, index, count);
    cout<<char(int('A'+'r'-'a'));
    return 0;
}