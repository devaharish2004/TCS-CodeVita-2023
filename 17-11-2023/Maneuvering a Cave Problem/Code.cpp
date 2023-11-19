#include <iostream>
using namespace std;

int calc(int n, int m)
{
    if(n == 1 || m == 1)
    {
        return 1;
    }
    else
    {
        return calc(n-1, m) + calc(n, m-1); // returns the no. of paths from the top and the left
    }
    
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        cout << calc(n,m) << endl;
    }
    
}



