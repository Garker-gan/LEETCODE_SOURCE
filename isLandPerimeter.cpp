/* 
    463: 岛屿周长；4*岛屿数-2*交界边数
    Garker-gan
    2020-10-30
 */

//先计算总的岛屿数量，在计算相邻岛屿的边的数量，最后4*岛屿数-2*相邻边数
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int sum = 0;        //岛屿数
        int cover = 0;    //相邻边数
        for(int i = 0;i < grid.size();i++)
        {
            for(int j = 0; j < grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    sum++;
                    //上面是否相邻
                    if(i-1 >= 0&&grid[i-1][j] == 1)
                        cover++;
                    if(j-1>=0&&grid[i][j-1]==1)  cover++;
                    //左边是否相邻，下面和右面不需要，避免重复
                    
                }
            }
        }
        return sum*4-cover*2;
    }
};