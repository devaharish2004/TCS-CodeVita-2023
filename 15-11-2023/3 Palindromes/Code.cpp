#include<bits/stdc++.h>
using namespace std;

bool ispal(string s)
{
    if(s.length() == 1) return true;
    string s1 = s;
    reverse(s1.begin(),s1.end());
    return (s1 == s);
}

int main()
{
    string s,s1,s2,s3;
    cin >> s;
    int l = s.length();
    for(int i = 1; i < l-1; i++)
    {
        s1 = s.substr(0,i);
        if(ispal(s1))
        {
            for(int j = 1; j < l-i; j++)
            {
                s2 = s.substr(i,j);
                s3 = s.substr(i+j, l-i-j);
                if(ispal(s2) && ispal(s3))
                {
                    cout << s1 << endl << s2 << endl <<s3;
                    return 0;
                }
            }
        }
    }
    
    cout << "Impossible";
    return 0;
}