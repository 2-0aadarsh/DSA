#include<bits/stdc++.h>
using namespace std;

class Solutions {
public : 
    void generateString(int& n, string& current, vector<string>& ans){
        if(current.size() == n) {
            ans.push_back(current);
            return;
        }

        // either we take 'A'
        current.push_back('A');
        generateString(n, current, ans);
        current.pop_back();

        // or we take 'B'
        current.push_back('B');
        generateString(n, current, ans);
        current.pop_back();
    }

    void generateStringsWithoutAAA(int &n, string &current, vector<string>& ans){
        // base case
        if(current.size() == n) {
            ans.push_back(current);
            return;
        }

        // either we take 'A'
        if((current.size() < 2) || (current.substr(current.size()-2) != "AA")) {
            current.push_back('A');
            generateStringsWithoutAAA(n, current, ans);
            current.pop_back();
        }

        // or we take 'B'
        current.push_back('B');
        generateStringsWithoutAAA(n, current, ans);
        current.pop_back();
    }

};

int main(){
    int n = 4;
    string current = "";
    vector<string> ans;

    Solutions obj;
    // obj.generateString(n, current, ans);
    obj.generateStringsWithoutAAA(n, current, ans);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }cout<<endl;


    // string test = "AAA";
    // cout<<test.find("AAA")<<endl;
    // if(test.substr(2) == "bc"){
    //     cout<<"found"<<endl;
    // } else {
    //     cout<<"not found"<<endl;
    // }
    return 0;
}