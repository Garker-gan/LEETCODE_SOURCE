/* 
    406.根据身高重建队列    身高降序，k升序
    Garker-gan
    2020-11-16
 */
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 升高降序，身高相同，按k大小升序
        sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
        });
        vector<vector<int>>ans;
        for(const vector<int>& person : people)
        {
            // 二维向量，按列分配，在这之前插入
            ans.insert(ans.begin()+person[1],person);
        }
        return ans;
    }
};