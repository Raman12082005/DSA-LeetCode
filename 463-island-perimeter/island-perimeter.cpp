class Solution {
public:
    void helper(int& perimeter, int i, int j, vector<vector<int>>& grid){
        // base case
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == 0){
            perimeter++;
            return;
        }
        // if already reached
        if(grid[i][j] == -1) return;

        grid[i][j] = -1;

        helper(perimeter, i+1, j, grid);
        helper(perimeter, i-1, j, grid);
        helper(perimeter, i, j+1, grid);
        helper(perimeter, i, j-1, grid);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    helper(perimeter, i, j, grid);
                    return perimeter;
                }
            }
        }
        return 0;
    }
};