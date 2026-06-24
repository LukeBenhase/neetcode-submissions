class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        
        while (numbers[i] + numbers[j] != target){
            if (numbers[i] + numbers[j] > target){
                j--;
            }
            else{
                i++;
            }
        }

        return vector<int> {i+1, j+1};

        /*
        start a pointer at the start and one at the end and check to see if they add
        up to the target there is a gaurenteed target so if the sum of the pointers
        is bigger than target move top pointer down. if lower move bottom up.
        */
    }
};
