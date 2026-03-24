#include<bits/stdc++.h>

using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> vis, vector<vector<int>> &maze){
    if( (x >= 0 && x < n) && (y >= 0 && y < n) && vis[x][y] == 0 && maze[x][y] == 1 ){
        return true;
    }
    return false;
}

void solve(vector<vector<int>> &maze, int n, vector<string> &ans, vector<vector<int>> vis, int x, int y, string path){

    if( x == n - 1 && y == n - 1){
        ans.push_back(path);
        return;
    }

    vis[x][y] = 1;

    // 4 movements

    // down
    int new_x = x + 1;
    int new_y = y;
    if(isSafe(new_x, new_y, n, vis, maze)){
        path.push_back('D');
        solve(maze, n, ans, vis, new_x, new_y, path);
        path.pop_back();
    }
    // left
    new_x = x;
    new_y = y - 1;
    if(isSafe(new_x, new_y, n, vis, maze)){
        path.push_back('L');
        solve(maze, n, ans, vis, new_x, new_y, path);
        path.pop_back();
    }
    // up
    new_x = x - 1;
    new_y = y;
    if(isSafe(new_x, new_y, n, vis, maze)){
        path.push_back('U');
        solve(maze, n, ans, vis, new_x, new_y, path);
        path.pop_back();
    }
    // right
    new_x = x;
    new_y = y + 1;
    if(isSafe(new_x, new_y, n, vis, maze)){
        path.push_back('R');
        solve(maze, n, ans, vis, new_x, new_y, path);
        path.pop_back();
    }
    vis[x][y] = 0; 

}

vector<string> findPath(vector<vector<int>> &maze, int n){

    vector<string> ans;
    int x = 0;
    int y = 0;

    vector<vector<int>> vis = maze;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            vis[i][j] = 0;
        }
    }
    
    string path = "";

    solve(maze, n, ans, vis, x, y, path);
    sort(ans.begin(), ans.end());
    return ans;

}

int main(){

    vector<vector<int>> maze = {{1,1,0,1},{0,1,1,0},{1,0,1,0},{0,0,1,1}};
    int n = 4;

    vector<string> path = findPath(maze, n);

    for(int i = 0; i < path.size(); i++){
        cout << path[i];
    }
    
}