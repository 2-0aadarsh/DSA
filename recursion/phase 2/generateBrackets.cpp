#include<bits/stdc++.h>
using namespace std;

class Solution {
public :
    void generateBrackets(int &n, string &current, vector<string>& ans){
        if(current.length() == 2*n) {
            ans.push_back(current);
            return;
        }

        // we will add open  brackets
        current.push_back('(');
        generateBrackets(n, current, ans);
        current.pop_back();

        // we will add close brackets
        current.push_back(')');
        generateBrackets(n, current, ans);
        current.pop_back();

    }    

    void generateValidBrackets(int &n, int open, int close, string&current, vector<string>&ans){

        if(close > open){
            return;
        }
        if(open == n && close == n) {
            ans.push_back(current);
            return;
        }
        if(open<n) {
            current.push_back('(');
            generateValidBrackets(n, open+1, close, current, ans);
            current.pop_back();
        }

        if(close<open){
            current.push_back(')');
            generateValidBrackets(n, open, close+1, current, ans);
            current.pop_back();
        }

    }

};

int main(){
    int n = 3;
    string current = "";
    vector<string> ans;

    Solution obj;
    obj.generateValidBrackets(n, 0, 0, current, ans);
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }

    
    return 0;
}