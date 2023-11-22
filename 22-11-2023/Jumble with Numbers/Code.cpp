#include <iostream>
#include <vector>
using namespace std;

int calc(int x)
{
    return (x*(x+1))/2;
}
int main()
{
    int a,b,x;
    cin >> a >> b >> x;
    int i = 1;
    while(calc(i) < a)
    {
        i += 2;
    }
    vector<int>ans;
    while(calc(i) <= b)
    {
        ans.push_back(calc(i));
        i += 2;
    }
    if(x > ans.size())
    {
        cout << "No number present at this index" << endl;
    }
    else
    {
        cout << ans[x-1] << endl; 
    } 
}