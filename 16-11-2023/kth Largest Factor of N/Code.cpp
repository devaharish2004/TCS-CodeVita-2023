// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    //kth largest factor of N
    int n,k;
    cin >> n >> k;
    int count = 0;
    for(int i = n; i >= 1;i--)
    {
        if(n%i == 0)
        {
            count++;
        }
        if(count == k)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    

    return 0;
}