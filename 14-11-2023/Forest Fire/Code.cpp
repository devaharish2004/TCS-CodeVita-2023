// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int n,m;
    cin >> n >> m;
    
    pair<int,int>src;
    cin >> src.first >> src.second;
    
    char arr[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    queue<pair<pair<int,int>,int>> q;
    q.push({{src.first-1,src.second-1},1});
    
    vector<vector<int>> vis(n, vector<int>(m,0));
    vis[src.first][src.second] = 1;
    
    int maxi = INT_MIN;
    //bfs traversal
    while(!q.empty())
    {
        auto it = q.front();
        int row = it.first.first;
        int col = it.first.second;
        int distance = it.second;
        q.pop();
        
        maxi = distance;
        
        //8 directions
        for(int i = -1; i <= 1;  i++)
        {
            for(int j = -1; j <= 1; j++)
            {
                if(i == 0 && j == 0)
                {
                    continue;
                }
                int nrow = row + i;
                int ncol = col + j;
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && arr[nrow][ncol] == 'T' && vis[nrow][ncol] != 1)
                {
                    q.push({{nrow,ncol},distance+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }
    
    cout << maxi << endl;
    
    return 0;
}