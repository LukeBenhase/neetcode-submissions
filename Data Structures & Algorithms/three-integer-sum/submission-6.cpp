#include <algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        if (nums.size() < 3)
            return output;

        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i <= nums.size()-3; i ++){
            // pointer a 
            
            // do sorted two sum with the rest of the list. 
            int j, k, target;
            j = i+1;
            k = nums.size()-1;
            target = 0 - nums[i];
            while (j < k){
                // check to see if it matches the target. 
                int sumjk = nums[j] + nums[k];
                if (sumjk == target){
                    // add the numbers to ouput.
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    output.push_back(temp);
                }
                if (sumjk > target){
                    // move k down
                    k --;
                }
                else {
                    j ++;
                    // Skip any duplicate values for j
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }
                
            }

            // Skip any duplicate values for i. 
            while (nums[i] == nums[i+1] && i < nums.size()-3){
                i ++;
            }
        }
        
        return output;

    }
};
