#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    map<int,int>mp;
    for(int i = 0; i < n; i++)
    {
        mp[s[i]-96]++;
    }
    int f = 1;
    for(auto it : mp)
    {
        if(it.first != it.second)
        {
            f = 0;
            break;
        }
    }
    if(f == 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl; 
    }

}