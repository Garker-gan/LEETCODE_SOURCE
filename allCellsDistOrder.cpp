/* 
    1030. 距离顺序排列矩阵单元格 暴力排序】
    Lamada表达式：[capture list] (params list) mutable exception-> return type { function body }
    隐式捕获[=]和[&]
    Garker-gan
    2020-11-17
 */
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>>ans;
        // 将所有点压入向量中
        for(int i = 0;i < R;i++)
        {
            for(int j = 0;j < C;j++)
            {
                ans.push_back({i,j});
            }
        }
        // 对所有点按曼哈顿距离进行排序
        sort(ans.begin(),ans.end(),[=](vector<int>& u,vector<int>& v){
            return abs(u[0]-r0) + abs(u[1]-c0) < abs(v[0]-r0) + abs(v[1]-c0);
        });
        return ans;
    }
};