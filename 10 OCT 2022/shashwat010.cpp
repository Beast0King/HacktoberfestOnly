class Solution {
  public:  
    void dfs(vector<vector<char>> &grid, int i, int j, int m, int n) {
        if(i>=0 && i<m && j>=0 && j<n && grid[i][j] == '1') {
            grid[i][j] = 0;
            dfs(grid, i-1, j, m, n);
            dfs(grid, i+1, j, m, n);
            dfs(grid, i, j-1, m, n);
            dfs(grid, i, j+1, m, n);
        }
        else
            return;
    }
    
    int numIslands(vector<vector<char>> grid) {
        if(grid.size() == 0)            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return ans;
    }
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<int> res;
        vector<vector<char>> surface(n,vector<char>(m,'0'));
        
        for(int i=0;i<operators.size();i++){
            surface[operators[i][0]][operators[i][1]]='1';
            int temp = numIslands(surface);
            res.push_back(temp);
        }        
        return res;
    }
};