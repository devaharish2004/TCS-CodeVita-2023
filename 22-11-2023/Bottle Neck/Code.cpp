#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int,int>mp;
    for(int i= 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    int m = INT_MIN;
    for(auto it : mp)
    {
        if(it.second > m)
        {
            m = it.second;
        }
    }
    cout << m << endl;
    

}