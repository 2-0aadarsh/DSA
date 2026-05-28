#include<bits/stdc++.h>
using namespace std;

bool checkTargetSubsequence(vector<int> &arr, int target, int index, int currentSum, vector<int> &current, vector<vector<int>> &ans){

    // base case
    if(index == arr.size()){
        if(currentSum == target) {
            ans.push_back(current);
            return true;
        }
        return false;
    }

    if(checkTargetSubsequence(arr, target, index+1, currentSum, current, ans)) {
        return true;
    }

    current.push_back(arr[index]);
    if(checkTargetSubsequence(arr, target, index+1, currentSum+arr[index], current, ans)){
        current.pop_back();
        return true;
    }
    
    current.pop_back();
    return false;
}

int main(){
    vector<int> arr = {1,2,3};
    int target = 3;
    vector<vector<int>> ans;
    vector<int> current;
    
    checkTargetSubsequence(arr, target, 0, 0, current, ans);
    for(int x : current) {
        cout<<x<<" ";
    } cout<<endl;

    for(int x : ans[0]) {
        cout << x << " ";
    } cout<<endl;

    return 0;
}