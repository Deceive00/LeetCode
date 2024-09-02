class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int i = 0;
        int n = chalk.size();
        long long int sum = 0;
        if(chalk.size() == 1) return 0;
        for(int c : chalk){
            sum += c;
        }
        k = k % sum;
        while(k > 0){
            k -= chalk[i];
            if(k < 0){
                return i;
            }
            i++;
        }
        return i;
    }
};