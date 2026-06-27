class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> uniqueNums;
        int longestSequence = 0;

        // 1
        for (int i : nums){
            if (!uniqueNums.contains(i)){
                uniqueNums.insert(i);
            }
        }

        // 2
        for (int i : uniqueNums){
            // check left
            if (uniqueNums.contains(i-1)){
                continue; // go to next element becuase there is a longer sequence
            }
            int j = 1;
            while( uniqueNums.contains(i+j)){
                j++;
            }
            if (j > longestSequence){
                longestSequence = j;
            }
        }


        return longestSequence;

        /*
        1. take all numbers and put unique numbers into a set
        2. loop through set checking if number is smallest in sequence
        aka no number is one smaller than it. 
        if it is the smallest count how long the sequence is and change largestSequence if larger
        */
    }
};
