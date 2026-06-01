#include<bits/stdc++.h>
using namespace std;

class solution {
public :
    int countSuboddseq(vector<int>& arr, int index, int currentSum) {
        // base case
        if(arr.size() == index) {
            if(currentSum&1) {
                return 1;
            }
            return 0;
        }

        // either we skip the current element
        int skip = countSuboddseq(arr, index+1, currentSum);

        // or we take the current element
        int take = countSuboddseq(arr, index+1, currentSum+arr[index]);
        return skip+take;
    }

};

int main(){
    vector<int> arr = {1,2,3};
    solution obj;
    cout<<obj.countSuboddseq(arr, 0, 0);

    return 0;
}