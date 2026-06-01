#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(vector<int>& arr, int index, int currentSum, int& target) {
        // pruning
        if(currentSum>target){
            return 0;
        }
        
        // base case
        if(arr.size() == index) {
            if(currentSum<=target) {
                return 1;
            }
            return 0;
        }
        
        // Either we skip the current path to the element 
        int skip = solve(arr, index+1, currentSum, target);

        // Or we take the current path to the element 
        int take = solve(arr, index+1, currentSum+arr[index], target); 
        return skip+take;
    }

};


int main(){
    vector<int> arr = {1,2,3};
    int target = 2;

    Solution obj;
    cout<<obj.solve(arr, 0, 0, target);
    return 0;
}