#include<bits/stdc++.h>
using namespace std;

void fun(int n) {

    for(int i=n; i<3; i++) {
        cout << "Before " << i << endl;

        fun(i+1);

        cout << "After " << i << endl;
    }
}

int main(){
    fun(1);
    return 0;
}