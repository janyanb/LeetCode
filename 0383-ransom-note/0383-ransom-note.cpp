class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magazineCount;
        for(char alpha: magazine){
            magazineCount[alpha]++;
        }

        for(int i =0; i<ransomNote.size(); i++){
            if(magazineCount[ransomNote[i]] > 0){
                magazineCount[ransomNote[i]] --;
            } else {
                return false;
            }
        }
        return true;
    }
};