#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getEvenSubseq(vector<int>&arr, int index, vector<int>&current, int currentSum, vector<vector<int>>&ans) {
        // base case
        if(index == arr.size()) {
            // check if current sum of the subseq array is even or not
            if(!(currentSum&1)) {
                ans.push_back(current);
            }
            return;
        }
        // now we will either skip the current element
        getEvenSubseq(arr,index+1,current, currentSum, ans);
        
        // or  we will either take the current element
        current.push_back(arr[index]);
        getEvenSubseq(arr,index+1,current, currentSum+arr[index], ans);

        current.pop_back();
    }

};


int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans;
    vector<int> current;

    Solution obj;
    obj.getEvenSubseq(arr, 0, current, 0, ans);
    // for(int i=0; i<ans.size(); i++) {
    //     for(int j=0; j<ans[i].size(); j++) {
    //         cout<<ans[i][j]<<" ";
    //     } cout<<endl;
    // }

    // printing the answer
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}