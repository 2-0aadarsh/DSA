#include<bits/stdc++.h>
using namespace std;

class solution {
public:
    void getSubseq(vector<int>& arr, int index, int length, vector<int>& current, vector<vector<int>>& ans){
        if(index == arr.size()) {
            if(current.size() == length) {
                ans.push_back(current);
                return;
            }
            return;
        }

        // either we will skip the current character
        getSubseq(arr, index+1, length, current, ans);
        
        // either we will take the current character
        current.push_back(arr[index]);
        getSubseq(arr, index+1, length, current, ans);

        current.pop_back();
    }
};

int main(){
    vector<int> arr = {1,2,3};
    int length = 2;
    vector<vector<int>> ans;
    vector<int> current;

    solution obj;
    obj.getSubseq(arr, 0, length, current, ans);

    // printing the answer
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}