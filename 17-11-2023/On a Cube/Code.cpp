#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include <iomanip>
#define PI 3.14
using namespace std;

double distance(int x1, int y1, int z1, int x2, int y2, int z2)
{
    double d = 0;
    if(z2 == z1 && (x1 == x2 || y1 == y2) && z2 != 0)
    {
        if(x1 != x2)
        {
            d = (2*PI*abs(x1-x2))/6.0;
        }
        else
        {
            d = (2*PI*abs(y1-y2))/6.0;
        }
    }
    else
    {
        d = (int)(sqrt(pow(abs(x1-x2),2) + pow(abs(y1-y2),2)) + abs(z1-z2));
    }
    return d;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin,s);
    stringstream X(s);
    string t;
    vector<int>v;
    while(getline(X,t,','))
    {
        v.push_back(stoi(t));
    }
    int x = v[0];
    int y = v[1];
    int z = v[2];
    double ans = 0;
    for(int i = 3; i < n*3; i+=3)
    {
        ans += distance(x,y,z,v[i],v[i+1],v[i+2]);
        x = v[i];
        y = v[i+1];
        z = v[i+2];
    }

    cout << fixed << setprecision(2) << ans << endl;


}