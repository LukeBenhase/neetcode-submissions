class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> table; // max size of 26 so technicaly its o(n)
        static string allLetters = "QWERTYUIOPASDFGHJKLZXCVBNM";
        int longest = 0;
        int l = 0;
        int kUsed = 0;
        int maxUsed = 0;
        for (int r = 0; r < s.length(); r ++){
            // add the new value to the map
            table[s[r]] += 1;

            //check if total length of char in table - largest amount of 1 char is > k
            maxUsed = 0;
            kUsed = 0;
            for (char c : allLetters){
                // count all letters used
                if (maxUsed < table[c]){
                    kUsed +=maxUsed;
                    maxUsed = table[c];
                }
                else {
                    kUsed += table[c];
                }
            }
            while (kUsed > k) {
                // we have to use less k letters
                // if it is move l closer to r until its not true
                table[s[l]] -= 1;
                // re calculate
                maxUsed = 0;
                kUsed = 0;
                for (char c : allLetters){
                    // count all letters used
                    if (maxUsed < table[c]){
                        kUsed +=maxUsed;
                        maxUsed = table[c];
                    }
                    else {
                        kUsed += table[c];
                    }
                }
                l++;
            }
            // Is this longest?
            if (longest < r-l+1)
                longest = r-l+1;

        }
        return longest;
    }
};
