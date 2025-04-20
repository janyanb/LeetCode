class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // if(gas.size() == 1 && gas[0] >= cost[0] ) return 0;

        // int i = 0, j = 0;
        // int start = -1, tgas = 0;
        // while(i < gas.size()){
        //     if(start == -1){
        //         if(gas[i] > cost[i]){
        //         start = i;
        //         } else {
        //             i++;
        //         }
        //     } else {
        //         tgas += gas[i];
        //         tgas -= cost[i];
        //         if (tgas >= 0) {
        //             i++;
        //             i = i%gas.size();
        //         } else {
        //             i = start + 1;
        //             start = -1;
        //             tgas = 0;                    
        //         }
        //         if(i == start) return start;  
        //     }            
        // }
        // return -1;

        int start = 0, TGas = 0, TCost = 0, tgas = 0;
        for(int i =0; i < gas.size(); i++){
            TGas += gas[i];
            TCost += cost[i];
           tgas += gas[i] - cost[i];

            if(tgas < 0){
                start = i + 1;               //works because TGas >= TCost;
                tgas = 0;                
            }
        }
        return TGas>= TCost ? start: -1;
    }
};