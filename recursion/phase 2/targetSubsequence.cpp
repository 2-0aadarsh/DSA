#include<bits/stdc++.h>
using namespace std;

void findTargetSubsequence(vector<int> &arr, int index, vector<int> &current, vector<vector<int>> &ans, int currentSum, int target){

    if(index == arr.size()) {
        // int sum = 0; 
        // for(int i=0; i<current.size(); i++) {
        //     sum += current[i]; 
        // }
        if(currentSum == target) {
            ans.push_back(current);
        }
        return;
    }

    // 1. Either we will not take the current value of the array as the part of the subsequence
    findTargetSubsequence(arr, index+1, current, ans, currentSum, target);
    
    // 2. Or we will take the current value of the array as the part of the subsequence
    current.push_back(arr[index]);
    findTargetSubsequence(arr, index+1, current, ans, currentSum+arr[index], target);

    current.pop_back();
}

int main(){

    vector<int> arr = {1,2,1,4,5};
    int target = 2;

    vector<vector<int>> ans;
    vector<int> current;
    int currentSum = 0;

    cout<<"size of ans before target is "<<ans.size()<<endl;
    findTargetSubsequence(arr, 0, current, ans, currentSum, target);

    cout<<"size of ans after target is "<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}