#include <bits/stdc++.h>
using namespace std;

bool fun(int n) {

    cout << "Checking " << n << endl;

    if(n == 3) {
        cout << "Found 3" << endl;
        return true;
    }

    if(n == 5) {
        return false;
    }

    if(fun(n + 1)) {
        return true;
    }

    cout << "Backtracking from " << n << endl;

    return false;
}

int main() {

    fun(1);

    return 0;
}