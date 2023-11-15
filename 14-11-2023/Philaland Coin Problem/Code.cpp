// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    //Philaland Coin
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << int(log2(n) + 1) << endl;
    }

    return 0;
}