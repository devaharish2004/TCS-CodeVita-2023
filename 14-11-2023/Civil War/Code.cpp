#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>v; 
        for (int i = 0; i < N; i++) 
        { 
            int a;
            cin >> a;
            v.push_back(a);
        }    
        
        int A = 0;
        int B = 0;
        
        sort(v.begin(),v.end(), [](int a, int b) {
            return abs(a) > abs(b) || (abs(a) == abs(b) && a > b);
        });   

        bool chance = true;    
        for (int i = 0; i < N; i++) {
            if (chance) {
                A += v[i];
            }
            else {
                B += v[i];
            }
            chance = !chance;
        }    
        int ans = abs(A - B);
        cout << ans << endl;
    } 
   return 0;
}