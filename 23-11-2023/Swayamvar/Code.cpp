#include <iostream>
#include <map>
#include <vector>
using  namespace std;

int main()
{
    int n;
    cin >> n;
    vector<char>brides(n),grooms(n);
    map<char,int> mp;
    for(int i = 0; i < n; i++)
    {
        cin >> brides[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> grooms[i];
        mp[grooms[i]]++;
    }
    int index = -1;
    for(int i = 0; i < n; i++)
    {
        if(mp[brides[i]] == 0)
        {
            index = i;
            break;
        }
        else
        {
            mp[brides[i]]--;
        }
    }
    if(index == -1) cout << 0 << endl;
    else cout << n-index << endl;
}