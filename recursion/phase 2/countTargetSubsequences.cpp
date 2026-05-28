#include<bits/stdc++.h>
using namespace std;

int countTargetSubsequences(vector<int> &arr, int target, int index, int currentSum, vector<int> &current, vector<vector<int>> &ans){

    // base case
    if(arr.size() == index) {
        if(currentSum == target) {
            ans.push_back(current);
            return 1;
        }
        return 0;
    }

    int skip = countTargetSubsequences(arr, target, index+1, currentSum, current, ans);

    current.push_back(arr[index]);
    int take = countTargetSubsequences(arr, target, index+1, currentSum+arr[index], current, ans);
    current.pop_back();

    return skip + take;

}

int main(){
    vector<int> arr = {1,2,3};
    int target = 3;
    vector<vector<int>> ans;
    vector<int> current;
    
    int count = countTargetSubsequences(arr, target, 0, 0, current, ans);
    cout << "Number of subsequences with target sum: " << count << endl;
        for(int i=0; i<ans.size(); i++) {
            for(int j=0; j<ans[i].size(); j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    return 0;
}