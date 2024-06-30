class Solution {
private:
    int oddeve, eveodd, odd, eve;
    int n, par;

public:
    int maximumLength(vector<int>& nums) {
        n = nums.size();
        
        oddeve = 0; par = 1;
        for(int i = 0; i < n; i++) {
            if((nums[i] & 1) && (par & 1)) {
                ++oddeve;
                par = !par;
            }
            else if(!(nums[i] & 1) && !(par & 1)) {
                ++oddeve;
                par = !par;
            }
        }
        
        eveodd = 0; par = 0;
        for(int i = 0; i < n; i++) {
            if((nums[i] & 1) && (par & 1)) {
                ++eveodd;
                par = !par;
            }
            else if(!(nums[i] & 1) && !(par & 1)) {
                ++eveodd;
                par = !par;
            }
        }
        
        odd = 0; eve = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] & 1) ++odd;
            else ++eve;
        }
        
        return std::max({oddeve, eveodd, odd, eve});
    }
};
