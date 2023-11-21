#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    string s1 = to_string(a);
    int m = INT_MAX;
    sort(s1.begin(),s1.end());

    do
    {
        int el = stoi(s1);
        if(el > b && el < m)
        {
            m = el;
        }
    } while(next_permutation(s1.begin(),s1.end()));

    cout << m << endl;
}