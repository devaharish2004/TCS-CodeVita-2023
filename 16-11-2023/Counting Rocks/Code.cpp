// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    //Counting rocks
    int n,r;
    cin >> n >> r;
    vector<int>samples(n);
    for(int i =0; i < n; i++)
    {
        cin >> samples[i];
    }
    vector<int>ans;
    for(int i = 0; i < r; i++)
    {
        int low, high;
        cin >> low >> high;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(samples[i] >= low && samples[i] <= high)
            {
                count++;
            }
        }
        ans.push_back(count);
    }
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}