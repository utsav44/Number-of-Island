int direction[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
  bool is_possible(int x,int y,int m,int n)
  {
    return (x>=0&&x<m&&y>=0&&y<n);
  }
    void dfs(int x,int y,vector<vector<char>>&grid,int m,int n,bool &flag)
    {
      grid[x][y]='0';
      flag=true;
       // cout<<x<<" "<<y<<endl;
      for(int i=0;i<4;i++)
      {
        int dx=x+direction[i][0];
        int dy=y+direction[i][1];
        if(is_possible(dx,dy,m,n)&&grid[dx][dy]=='1')
        {
          
          // cout<<dx<<" "<<dy<<endl;
          dfs(dx,dy,grid,m,n,flag);
        }
      }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
         int n=grid[0].size();
      int ans=0;
      for(int i=0;i<m;i++)
      {
        for(int j=0;j<n;j++)
        {
             if(grid[i][j]=='1')
           {
            bool flag=false;
            dfs(i,j,grid,m,n,flag);
            if(flag)ans++;  
                // cout<<i<<" "<<j<<" "<<flag<<" "<<ans<<endl;
           }
        }
      }
      return ans;
    }
