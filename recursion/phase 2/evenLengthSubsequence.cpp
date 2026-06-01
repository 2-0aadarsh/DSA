#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    void getEvenLengthSubsequence(vector<int>& arr, int index, vector<int>&current, vector<vector<int>>&ans){
        // base case
        if(index == arr.size()) {
            if(!(current.size()&1)) {
                ans.push_back(current);
            }
            return;
        }

        getEvenLengthSubsequence(arr, index+1, current, ans);

        current.push_back(arr[index]);
        getEvenLengthSubsequence(arr, index+1, current, ans);
        
        current.pop_back();
    }
};


int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans;
    vector<int> current;

    Solution obj;
    obj.getEvenLengthSubsequence(arr, 0, current, ans);
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        } cout<<endl;
    }
    return 0;
}