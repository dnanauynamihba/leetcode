class Solution {
private:
    int r, b, h1, h2, odd, eve;
    
public:
    int maxHeightOfTriangle(int red, int blu) {
        h1 = 0, h2 = 0;
        
        r = red, b = blu;
        odd = 1, eve = 2;
        while(true) {
            if(r - odd >= 0) {
                r -= odd; odd += 2;
                ++h1;
            }
            else break;
            
            if(b - eve >= 0) {
                b -= eve; eve += 2;
                ++h1;
            }
            else break;
        }
        
        r = red, b = blu;
        odd = 1, eve = 2;
        while(true) {
            if(b - odd >= 0) {
                b -= odd; odd += 2;
                ++h2;
            }
            else break;
            
            if(r - eve >= 0) {
                r -= eve; eve += 2;
                ++h2;
            }
            else break;
        }
        
        return (h1 >= h2)? h1: h2;
    }
};
