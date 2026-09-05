class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = 0; // largest pile within
        int min = 1;
        int mid;

        // get the max stack
        for (int pile : piles){
            if (pile > max)
                max = pile;
        }

        // guess and check method based on max bananas
        while (min != max){
            mid = ((max-min)/2)+min;
            // test middle number
            int hours = 0;
            for (int pile : piles){
                hours += (pile / mid);
                int remainder = pile % mid;
                if (remainder > 0)
                    hours ++;
            } 
            if (hours > h){
                // mid is to small
                min = mid +1;
            }
            else{
                max = mid;
            }
        }
        return min;

    }
};
