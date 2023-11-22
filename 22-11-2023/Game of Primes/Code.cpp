#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int squareOfDigits(int n)
{
    if(n < 10) return n;
    else
    {
        int val = 0;
        while(n > 0)
        {
            val += (pow(n%10,2));
            n /= 10;
        }
        return squareOfDigits(val);
    }

}


bool check(int n)
{
    if(squareOfDigits(n) == 1)
    {
        return true;
    }
    return false;
}


bool isprime(int n)
{
    if(n == 2) return true;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0) return false;
    }
    return true;
}

int main()
{
    int x,y, n;
    cin >> x >> y >> n;
    if(x < 10)
    {
        x = 10;
    }
    vector<int>ans;
    for(int i = x; i <= y; i++)
    {
        if(check(i) && isprime(i))
        {
            ans.push_back(i);
        }
    }

    if(n > ans.size()-1)
    {
        cout << "No number is present at this index" << endl;
    }
    else
    {
        cout << ans[n-1] << endl;
    }
    
}