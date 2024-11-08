#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> checkMoves(int dx, int dy) {
    return {
        {dx,dy},       
        {dy,-dx},      
        {-dy,dx},       
        {-dx,-dy}       
    };
}
bool isValid(int x, int y, int A, int B, const vector<vector<int>>& grid) {
    return (x>=0&&x<A&&y>=0&&y<B&&grid[x][y]==0);
}
int findMOves(const vector<vector<int>>& grid, int A, int B,int sourceX, int sourceY, int destX, int destY, int moveX, int moveY) {
    queue<pair<int, int>> q;
    q.push({sourceX, sourceY});

    vector<vector<bool>> visited(A,vector<bool>(B, false));
    visited[sourceX][sourceY]=true;
    int steps = 0;

    while (!q.empty()){
        int size = q.size();
        while (size--){
            auto [x,y]=q.front();
            q.pop();

            if (x == destX && y == destY) {
                return steps;
            }

            for (auto [dx,dy] : checkMoves(moveX, moveY)) {
                int newX=x+dx;
                int newY=y+dy;

                if (isValid(newX, newY, A, B, grid) && !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }
        steps++;
    }
    return -1;
}

int main() {
    int A,B;
    cin >>A>>B;

    vector<vector<int>> grid(A, vector<int>(B));
    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < B; ++j) {
            cin >> grid[i][j];
        }
    }

    int sourceX, sourceY, destX, destY;
    cin >> sourceX >> sourceY >> destX >> destY;

    int moveX, moveY;
    cin >> moveX >> moveY;

    int res=findMOves(grid, A, B, sourceX, sourceY, destX, destY, moveX, moveY);
    cout<<res<<endl;

    return 0;
}
