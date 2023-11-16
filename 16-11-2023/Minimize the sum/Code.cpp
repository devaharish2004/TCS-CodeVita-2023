// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int n,k;
    cin >> n >> k;
    //using priority queue (max heap)
    priority_queue<int>pq;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        pq.push(a);
    }
    while(k--)
    {
        int maxi = pq.top();
        if(maxi == 0) break;
        pq.pop();
        pq.push(maxi/2);
    }
    int sum = 0;
    while(!pq.empty())
    {
        sum += pq.top();
        pq.pop();
    }
    cout << sum << endl;

    return 0;
}