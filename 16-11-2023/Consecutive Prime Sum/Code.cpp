// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

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

int next_prime(int prime)
{
    do
    {
        prime++;
    } while(!isprime(prime));
    
    return prime;
}

int main() {
    // Write C++ code here
    //Consecutive prime sum
    int n;
    cin >> n;
    int sum = 2;
    int prime = 2;
    int count = 0;
    vector<int>v; //elements are stored in v
    while(sum <= n)
    {
        prime = next_prime(prime);
        sum += prime;
        if(isprime(sum) && sum <= n)
        {
            v.push_back(sum);
            count++;
        }
    }
    // for(int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << endl;
    // }
    cout << count << endl;
    
    

    return 0;
}