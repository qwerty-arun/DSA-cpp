#include <iostream>
#include <string>
#include <vector>
using namespace std;


void getAns(vector<vector<int>> &maze, int r, int c, vector<string>& ans, string path, vector<vector<bool>> vis)
{
    int n = maze.size();

    if(r<0 || c<0 || r>=n || c>=n )
    {
        return;
    }

    if(maze[r][c]==0 || vis[r][c])
    {
        return;
    }

    if(r==n-1 &&  c==n-1)
    {
        ans.push_back(path);
        return;
    }

    vis[r][c]=true;

    getAns(maze, r+1, c, ans, path + "D", vis);
    getAns(maze, r-1, c, ans, path + "U", vis);
    getAns(maze, r, c-1, ans, path + "L", vis);
    getAns(maze, r, c+1, ans, path + "R", vis);

    vis[r][c]=false;
}

vector<string> findPath(vector<vector<int>> maze)
{
    int n = maze.size();
    vector<string> ans;
    string path = "";
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    getAns(maze, 0,0, ans, path, vis);

    return ans;
}
int main()
{
    int n = 4;
    vector<vector<int>> maze = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> ans = findPath(maze);
    for(int i =0;i<ans.size();i++)
    {
        cout<<ans[i]<<"\n";
    }
}

