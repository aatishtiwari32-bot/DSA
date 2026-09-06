class Solution {
private:

    
    bool isFrequencySame(int freq1[], int freq2[]) {

        for(int i = 0; i < 26; i++) {

            if(freq1[i] != freq2[i]) {
                return false;
            }
        }

        return true;
    }

public:

    bool checkInclusion(string s1, string s2) {

        int n = s1.length();
        int m = s2.length();

        
        if(n > m) {
            return false;
        }


        

        int freq[26] = {0};

        for(int i = 0; i < n; i++) {
            freq[s1[i] - 'a']++;
        }


        

        int windowFreq[26] = {0};

        for(int i = 0; i < n; i++) {
            windowFreq[s2[i] - 'a']++;
        }


       
        if(isFrequencySame(freq, windowFreq)) {
            return true;
        }


        

        int start = 0;
        int end = n-1;

        while(end  < m-1) {

            
            windowFreq[s2[start] - 'a']--;
             start++;

             end++;
             
            
            windowFreq[s2[end] - 'a']++;

            
           
           


            
            if(isFrequencySame(freq, windowFreq)) {
                return true;
            }
        }


        return false;
    }
};