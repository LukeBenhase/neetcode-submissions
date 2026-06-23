class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> hashSet = {};
        for (int i = 0; i < nums.size(); i ++){
            if (hashSet.contains(nums[i])){
                return true;
            }
            hashSet.insert(nums[i]);

        }
        return false;
        /*
        loop through all nums
            look if exists
            if it does return true
        return false if loop finishes
        */
    }
};