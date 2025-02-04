class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxVolume = 0;

        while (left < right) {
            int length = min(height[left], height[right]);
            int breadth = right - left;
            int volume = length * breadth;

            maxVolume = max(volume, maxVolume);

            if (height[left] < height [right])
                left ++ ;
            else 
                right --;
        }
        return maxVolume ;
        
    }
};