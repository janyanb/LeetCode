class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int volume = 0;

        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    volume += leftMax - height[left];
                left++;
            } else {
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    volume += rightMax - height[right];
                right--;
            }
        }

        return volume;
    }
};
