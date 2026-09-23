class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        int j = 0;
        do {
            // follow the number to the numbers location
            i = nums[i];
            j = nums[j];
            j = nums[j];
        } while (i != j );
        j = 0;
        while (i != j){
            i = nums[i];
            j = nums[j];
        }
        return i;
        
    }
};
