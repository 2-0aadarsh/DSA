#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void Permutations(vector<int>&arr, vector<int>&current, vector<vector<int>>&ans){
        if(current.size() == arr.size()) {
            ans.push_back(current);
            return;
        }

        for(int i = 0; i<arr.size(); i++) {
            // check if the current element is already present in the current array or not
            if(find(current.begin(), current.end(), arr[i]) != current.end()) {
                continue;
            }
            current.push_back(arr[i]);
            Permutations(arr, current, ans);
            current.pop_back();
        }
    }

    void Permutations2(vector<int>&arr, int index, vector<vector<int>>&ans) {
        if(index == arr.size()) {
            ans.push_back(arr);
            return;
        }

        for(int i=index; i<arr.size(); i++) {
            swap(arr[index], arr[i]);
            Permutations2(arr, index+1, ans);
            swap(arr[index], arr[i]);
        }
    }

    void Permutation3(vector<int>&arr, vector<bool>&isVisited, vector<int>&current, vector<vector<int>>&ans){

        if(current.size() == arr.size()) {
            ans.push_back(current);
            return;
        }
        for(int i=0; i<arr.size(); i++) {
            if(!isVisited[i]) {
                isVisited[i] = true;
                current.push_back(arr[i]);

                // make the function call for the next index
                Permutation3(arr, isVisited, current, ans);
                
                // backtrack
                isVisited[i] = false;
                current.pop_back();
            }
        }
    }
};

int main(){
    vector<int> arr = {1,2,3};

    vector<vector<int>> ans;
    vector<int> current;

    Solution obj;
    // obj.Permutations(arr, current, ans);
    obj.Permutations2(arr, 0, ans);

    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}