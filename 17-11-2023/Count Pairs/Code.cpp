// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    //Count Pairs
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i< n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int start = arr[i]-k;
        int end = arr[i]+k;
        int count = 0;
        for(int j = 0; j < n; j++)
        {
            if(arr[j] == arr[i])
            {
                continue;
            }
            else if(arr[j] >= start && arr[j] <= end)
            {
                count++;
            }
            
            if(count == 1) break;
        }
        if(count != 0)
        {
            ans++;
        }
    }
    
    cout << ans << endl;

    return 0;
}