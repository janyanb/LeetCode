class Solution {
public:
    bool isPalindrome(string s) {
        // Initialize two pointers
        int left = 0;
        int right = s.size() - 1;

        // Use two-pointer technique to check for palindrome
        while (left < right) {
            // Move the left pointer to the next alphanumeric character
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            // Move the right pointer to the previous alphanumeric character
            while (left < right && !isalnum(s[right])) {
                right--;
            }

            // Compare the characters (case-insensitive)
            if (tolower(s[left]) != tolower(s[right])) {
                return false; // Not a palindrome
            }

            // Move both pointers towards the center
            left++;
            right--;
        }

        return true; // It's a palindrome
    }
};