class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;

        output.push_back(1); // the first index is 1
        int total = 1;
        for (int i = 0; i < nums.size()-1; i ++){
            total = nums[i] * total;
            output.push_back(total);
        }
        total = 1;
        for (int i = nums.size()-1; i > 0 ; i --){
            total = nums[i] * total;
            output[i-1] = total * output[i-1];
        }

        return output;
        /*
         [ -1, 0, 1, 2, 3] [1, 2, 4,6]
         [ 1, -1, 0, 0, 0] [1, 1, 2,8]
         [ 0,  6, 6, 3, 1] [48,24,6,1]
         [ 0, -6, 0, 0, 0] [48,24,12,8]
         above shows how you can multiply the numbers to the left together and make a
         new list. doing this from the left and the right will create two lists 
         when multiplied together will make a list without the number at that index. 
        */
    }
};
