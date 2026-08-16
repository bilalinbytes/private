class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        vector<int> ans;
        for(int i =1;i<=nums.size();i++){
            if(s.count(i)==0){
                ans.push_back(i);
            }
        }
        return ans;

    }
};