// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int lcm(vector<int>v)
{
    int ans = v[0];
    for(int i = 1; i < v.size(); i++)
    {
        ans = (ans*v[i])/gcd(ans,v[i]);
    }
    return ans;
}

int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b,a%b);
}

bool isprime(int n)
{
    if(n == 2) return true;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0)
        {
            return false;
        }
    }
    return true;
}

int main() {
    // Write C++ code here
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>v;
        int mini = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            v.push_back(a);
            mini = min(mini,a);
        }
        auto index = find(v.begin(),v.end(),mini);
        v.erase(index);
        int ans = lcm(v);
        if(isprime(ans + mini))
        {
            cout << ans + mini << endl;
        }
        else
        {
            cout << "None" << endl;
        }
        
    }

    return 0;
}