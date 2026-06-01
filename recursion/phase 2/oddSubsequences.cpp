#include<bits/stdc++.h>
using namespace std;

class solution {
public : 
    void getOddSubseq(vector<int>& arr, int index, vector<int>& current, int CurrentSum, vector<vector<int>>& ans) {

        if(arr.size() == index) {
            if(CurrentSum & 1) {
                ans.push_back(current);
                return;
            }
            return;
        }

        // either we skip the current character
        getOddSubseq(arr, index+1, current, CurrentSum, ans);
        
        // or we take the current character
        current.push_back(arr[index]);
        getOddSubseq(arr, index+1, current,CurrentSum+arr[index], ans);


        current.pop_back();
    }
};

int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans;
    vector<int> current;

    solution obj;
    obj.getOddSubseq(arr, 0, current, 0, ans);

    // printing the answer
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}