#include<bits/stdc++.h>
using namespace std;

class Solutions {
public : 
    void generateBinaryString(int &n, string &current, vector<string>& ans) {
        if(current.size() == n) {
            ans.push_back(current);
            return;
        }

        // either we take 0
        current.push_back('0');
        generateBinaryString(n, current, ans);
        current.pop_back();

        // or we consider 1
        current.push_back('1');
        generateBinaryString(n, current, ans);
        current.pop_back();
    }

    void noConsecutive1s(int &n, string &current, vector<string> &ans) {
        if(current.size() == n) {
            ans.push_back(current);
            return;
        }

        // either we take 0
        current.push_back('0');
        noConsecutive1s(n, current, ans);
        current.pop_back();       
        
        // or we take 1
        if(current.size() == 0 || current.back() != '1') {
            current.push_back('1');
            noConsecutive1s(n, current, ans);
            current.pop_back();
        }

    }

};


int main(){
    int n = 3;
    string current = "";
    vector<string> ans;

    Solutions obj;
    // obj.generateBinaryString(n, current, ans);
    obj.noConsecutive1s(n, current, ans);

    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }cout<<endl;

    return 0;
}