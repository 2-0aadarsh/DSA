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

    void countPermutation(vector<int>&arr, vector<bool>& isVisited, vector<int>&current, int&count) {
        if(current.size() == arr.size()) {
            count++;
            return;
        }
        for(int i=0; i<arr.size(); i++) {
            if(!isVisited[i]) {
                isVisited[i] = true;
                current.push_back(arr[i]);
                
                countPermutation(arr, isVisited, current, count);
                
                isVisited[i] = false;
                current.pop_back();
            }
        }
    }
    
    int countPermutation(vector<int>&arr, vector<bool>& isVisited, vector<int>&current) {
        if(current.size() == arr.size()) {
            return 1;
        }
        int count = 0;
        for(int i=0; i<arr.size(); i++) {
            if(!isVisited[i]) {
                isVisited[i] = true;
                current.push_back(arr[i]);
                
                count += countPermutation(arr, isVisited, current);
                
                isVisited[i] = false;
                current.pop_back();
            }
        }
        return count;
    }

    void permutationOfLastElementEven(vector<int>&arr, vector<bool>&isVisited, vector<int>&current, vector<vector<int>>&ans){   
        if(current.size() == arr.size()) {
            if(!(current[current.size()-1]&1)) {
                ans.push_back(current);
            }
            return;
        }
        for(int i=0; i<arr.size(); i++) {
            if(!isVisited[i]) {
                isVisited[i] = true;
                current.push_back(arr[i]);

                permutationOfLastElementEven(arr,isVisited, current, ans);

                isVisited[i] = false;
                current.pop_back();
            }
        }
    }

    void evenSumPermutation(vector<int>&arr, vector<bool>&isVisited, vector<int>&current, vector<vector<int>>&ans, int currentSum) {
        if(current.size() == arr.size()) {
            if(!(currentSum&1)) {
                ans.push_back(current);
            }
            return;
        }

        for(int i=0; i<arr.size(); i++) {
            if(!(isVisited[i])) {
                isVisited[i] = true;
                current.push_back(arr[i]);

                evenSumPermutation(arr, isVisited, current, ans, currentSum+arr[i]);

                isVisited[i] = false;
                current.pop_back();
            }
        }
    }



    void adjacentUnequalPermutation(vector<int>&arr, vector<bool>&isVisited, vector<int>&current, vector<vector<int>>&ans) {
        if(current.size() == arr.size()) {
            ans.push_back(current);
            return;
        }


        for(int i=0; i<arr.size(); i++) {
            if(!isVisited[i] && (current.size() ==0 || current.back() != arr[i])) {
                isVisited[i] = true;
                current.push_back(arr[i]);

                // make the function call for the next index
                adjacentUnequalPermutation(arr, isVisited, current, ans);

                // backtrack
                isVisited[i] = false;
                current.pop_back();
            }
        }
    }

    void removeDuplicatePermutation(vector<int>&arr, vector<bool>&isVisited, vector<int>&current, vector<vector<int>>&ans) {
        // sort the array first
        sort(arr.begin(), arr.end());

        // then skip the duplicate elements in the for loop
        if(current.size() == arr.size()) {
            ans.push_back(current);
            return;
        }

        for(int i=0; i<arr.size(); i++) {
            if(i>0 && arr[i] == arr[i-1] && !isVisited[i-1]) {
                continue;
            }
            if(!isVisited[i]) {
                isVisited[i] = true;
                current.push_back(arr[i]);

                // make the function call for the next index
                removeDuplicatePermutation(arr, isVisited, current, ans);

                // backtrack
                isVisited[i] = false;
                current.pop_back();
            }
        }
    
    }


};

int main(){
    // vector<int> arr = {1,2,3};
    // vector<int> arr = {1,1,2};
    vector<int> arr = {1,1,2,4};
    vector<vector<int>> ans;
    vector<int> current;
    vector<bool> isVisited(arr.size(), false);

    Solution obj;
    // obj.Permutations(arr, current, ans);
    // obj.Permutations2(arr, 0, ans);

    // for(int i=0; i<ans.size(); i++) {
    //     for(int j=0; j<ans[i].size(); j++) {
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // int count = 0;
    // obj.countPermutation(arr, isVisited, current, count);
    // cout<<count<<endl;

    // cout<<obj.countPermutation(arr, isVisited, current)<<endl;
    
    
    // obj.permutationOfLastElementEven(arr,isVisited, current, ans);
    // obj.evenSumPermutation(arr,isVisited, current, ans, 0);
    // obj.adjacentUnequalPermutation(arr,isVisited, current, ans);
    obj.removeDuplicatePermutation(arr, isVisited, current, ans);
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    

    return 0;
}