// 2. Count vowels/consonants
#include<bits/stdc++.h>
using namespace std;

bool isVowel(char *ch) {
    if(!*ch || *ch == ' ') return false;

    const string vowels = "aeiouAEIOU";
    for(int i=0; i<vowels.length(); i++) {
        if(vowels[i] == *ch) return true;
    }
    return false;
}

int countVowels(string &str) {
    if(str.length() == 0) return 0;

    int count = 0;
    for(int i=0; i<str.length(); i++) {
        if(isVowel(&str[i])) count++;
    }
    return count;
}

int consonants(string &str) {
    if(str.length() == 0) return 0;

    int count = 0;
    for(int i=0; i<str.length(); i++) {
        if(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z') {
            if(!isVowel(&str[i]) && str[i] != ' ') count++;
        }
    }
    return count;
}


int main(){
    // string s = "Hello there, this is Aadarsh";
    // cout<<"Number of vowels in string "<<s<<" is "<<countVowels(s)<<endl;
    // cout<<"Number of consonants in string "<<s<<" is "<<consonants(s)<<endl;

    string s = "A";
    char ch = tolower(s[0]);
    cout<<ch<<endl;

    // string s = "";
    // int ascii = (int)s[0];
    // cout<<"ASCII value of "<<s<<" is "<<ascii<<endl;

    return 0;
}