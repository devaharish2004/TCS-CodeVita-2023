#include <bits/stdc++.h>
using namespace std;

double distance(int x, int y)
{
    //distance between (1,1) && (x,y)
    return sqrt(pow(x-1,2) + pow(y-1,2));
}

int main()
{
    int n,m;
    cin >> n >> m;
    int mat[n][m];
    for(int i = 0; i < n ;i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    //code
    vector<pair<double,pair<int,int>>> v;
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(mat[i][j] == 0 || (i == 0 && j == 0)) continue;
            
            int neighbours_count = 0;
            for(int k = -1; k <= 1; k++)
            {
                for(int l = -1; l <= 1; l++)
                {
                    int row = i+k;
                    int col = j+l;
                    if(row >= 0 && row < n && col >= 0 && col < m && mat[row][col] == 1)
                    {
                        neighbours_count++;
                    }
                }
            }
            neighbours_count--;
            
            if(neighbours_count > maxi)
            {
                maxi = neighbours_count;
                v.clear();
                v.push_back({distance(i,j),{i,j}});
            }
        }
    }
    
    sort(v.begin(),v.end());
    cout << v[0].second.first+1 << ":" << v[0].second.second+1 << ":" << maxi << endl;
    
    return 0;
}