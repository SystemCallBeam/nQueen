#include<bits/stdc++.h>
using namespace std;

//#define n 4
#define met vector<vector<int>>
met result;
int n = 4;

bool isOnGrid(met grid, int row, int col);

bool isFound(met grid, int col){
    //Base Case
    //All queens are placed
    if (col == n)
    {
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    temp.push_back(j);
                }
            }
        }
        result.push_back(temp);
        return true;
    }
    //recursive case
    bool isfound = false;
    for (int row = 0; row < n; row++)
    {
        if (isOnGrid(grid, row, col))
        {
            grid[row][col] = 1;
            
            isfound = isFound(grid, col+1);

            grid[row][col] = 0;
        }
    }

    return isFound;
}

bool isOnGrid(met grid, int row, int col){
    int i, j;
    //Row Checking
    for (int i = 0; i < col; i++)
    {
        if (grid[row][i])
        {
            return false;
        }
    }
    for (int i = row, j=col; i >=0&&j>=0 ;i--, j--)
    {
        if (grid[i][j])
        {
            return false;
        }
    }
    for (int i = row, j=col; i < n&&j>=0; i++,j--)
    {
        if (grid[row][i])
        {
            return false;
        }
    }
    return true;
}

met solve(int n){
    result.clear();
    met grid(n, vector<int>(n, 0));
    
    if (isFound(grid, 0) == false)
    {
        return {};
    }

    return result;
}

void printMat(met mat){
    
    for (auto row: mat){
        for (auto col: row){
            cout << col << " ";
        }
        cout << endl;
    }
}

int main(){
    met mat = solve(n);
    printMat(Mat);
    return 0;
}