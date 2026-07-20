class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        

        //operation
       while(k--){
         int temp = grid[grid.size()-1][grid[0].size()-1];
        int temp2;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){

                temp2=grid[i][j];
                grid[i][j]=temp;
                temp=temp2;

            }
        }
       }
        return grid;
    }
};