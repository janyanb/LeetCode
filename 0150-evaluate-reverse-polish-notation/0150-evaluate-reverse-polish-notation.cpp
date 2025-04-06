class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> currState;

        for(int i =0; i< tokens.size(); i++){
            if(tokens[i] != "*" && tokens[i] != "/" && tokens[i] != "+" && tokens[i] != "-"){
                currState.push(stoi(tokens[i]));
            } else if(tokens[i] == "*"){
                int num1 = (currState.empty())? 1 : currState.top();
                currState.pop();
                int num2 = (currState.empty())? 1 : currState.top();
                currState.pop();

                currState.push(num2*num1);
            } else if(tokens[i] == "/"){
                int num1 = (currState.empty())? 1 : currState.top();
                currState.pop();
                int num2 = (currState.empty())? 1 : currState.top();
                currState.pop();

                currState.push(num2/num1);
            } else if(tokens[i] == "+"){
                int num1 = (currState.empty())? 0 : currState.top();
                currState.pop();
                int num2 = (currState.empty())? 0 : currState.top();
                currState.pop();

                currState.push(num2+num1);
            } else if(tokens[i] == "-"){
                int num1 = (currState.empty())? 0 : currState.top();
                currState.pop();
                int num2 = (currState.empty())? 0 : currState.top();
                currState.pop();

                currState.push(num2-num1);
            }
        }

        return currState.top();
    }
};