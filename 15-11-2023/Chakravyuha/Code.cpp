// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
      // Write C++ code here
      int n;
      cin >> n;
      vector<vector<int>>mat(n,vector<int>(n,0));
      
      vector<pair<int,int>>v;
      v.push_back({0,0});
      
      int top = 0, left = 0, bottom = n - 1, right = n - 1;
    
      int count = 1;
      while (top <= bottom && left <= right) 
      {
        
        for (int i = left; i <= right; i++)
        {
           mat[top][i] = count;
           if(count%11 == 0)
           {
               v.push_back({top,i});
           }
           count++;
        }
        
        top++;
    
        
        for (int i = top; i <= bottom; i++)
        {
          mat[i][right] = count;
          if(count%11 == 0)
          {
               v.push_back({i,right});
          }
          count++;  
        }
          
        right--;
        
        if (top <= bottom) 
        {
          for (int i = right; i >= left; i--)
          {
            mat[bottom][i] = count;
            if(count%11 == 0)
            {
               v.push_back({bottom,i});
            }
            count++;  
          }

          bottom--;
        }
    
        
        if (left <= right) 
        {
          for (int i = bottom; i >= top; i--)
          {
            mat[i][left] = count;
            if(count%11 == 0)
            {
               v.push_back({i,left});
            }
            count++;  
          }

          left++;
        }
     }
        
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < v.size(); i++)
    {
        cout << '(' << v[i].first << ',' << v[i].second << ')' << endl;
    }
    
    cout << "Total Power Points : " << v.size() << endl;

    return 0;
}