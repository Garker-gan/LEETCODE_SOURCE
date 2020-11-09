/* 
    973. 最接近原点的 K 个点 按照距离排序，输出前k个点
    Garker-gan
    2020-11-09
 */

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(),points.end(),[](vector<int>& u,vector<int>& v){
            return u[0] * u[0] + u[1] * u[1] < v[0]*v[0] + v[1]*v[1];
        }
        );
        return {points.begin(),points.begin()+K};
    }
};