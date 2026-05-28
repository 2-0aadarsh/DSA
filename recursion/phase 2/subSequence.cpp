#include <iostream>
#include <vector>
using namespace std;

void generateSubSequence(string &str, int index, string current, vector<string> &ans){

    if(index == str.size()) {
        ans.push_back(current);
        return;
    }

    // we not have to include the current character of the string as a subsequence
    generateSubSequence(str, index+1, current, ans);

    // we have to include the current character of the string as a subsequence
    current += str[index];
    generateSubSequence(str, index+1, current, ans);

}

int main() {
    string str = "hey";
    vector<string> ans;
    generateSubSequence(str, 0, "", ans);

    for(const string& s : ans) {
        cout << s << " \n";
    }
    cout << endl;

    return 0;
}