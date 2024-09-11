class Solution {
public:
    string decToBinary(int n)
    {   
        string binary = "";
        for (int i = 31; i >= 0; i--) {
            int k = n >> i;
            if (k & 1)
                binary += "1";
            else
                binary += "0";
        }

        return binary;
    }
    int minBitFlips(int start, int goal) {
        int count = 0;
        string startBinary = decToBinary(start);
        string goalBinary = decToBinary(goal);
        bool starting = false;
        for(int i = 0 ; i <= 31 ; i++){
            if((startBinary[i] == '1' || goalBinary[i] == '0') && !starting)   starting = true;
            if(starting){
                count += ((startBinary[i] - '0') ^ (goalBinary[i] - '0'));
            }
        }
        return count;
    }
};