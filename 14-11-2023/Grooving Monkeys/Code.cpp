// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int findCount(int arr[], int index, int count, int start)
{
    count++;
    if(arr[index]-1 == start)
    {
        return count;
    }
    return findCount(arr,arr[index]-1,count,start);
}

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b,a%b);
}

int main() {
    //Grooving monkeys
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        //code
        vector<int>v;
        for(int i = 0; i < n; i++)
        {
            int count = 0;
            int finalCount = findCount(arr,i,count,i);
            v.push_back(finalCount);
        }
        //lcm
        int ans = v[0];
        for(int i = 1; i < n; i++)
        {
            ans = (ans*v[i])/gcd(v[i],ans);
        }
        cout << ans << endl;
    }

    return 0;
}