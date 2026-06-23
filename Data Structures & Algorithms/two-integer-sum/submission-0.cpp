class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> twoSumMap;

        for (int i = 0; i < nums.size(); i ++){
            // check other value needed in list
            if (twoSumMap.contains(target - nums[i])){
                return std::vector <int> {twoSumMap[(target-nums[i])], i};
            }
            // didn't find value add this value to list
            twoSumMap[nums[i]] = i;
        }

        return std::vector <int> {0,0};
        /*
        put all numbers in an unordered map with position in list as value
        for each number check if other number needed exists
        */
    }
};
