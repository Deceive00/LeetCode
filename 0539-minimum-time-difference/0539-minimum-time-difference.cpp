class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> sorted;
        for(string time : timePoints){
            int hours = stoi(time.substr(0, 2));  
            int minutes = stoi(time.substr(3, 2)); 

            int totalTime = hours * 60 + minutes;
            sorted.push_back(totalTime);
        }
        sort(sorted.begin(), sorted.end()); 
        int n = sorted.size();
        if(n <= 1)  return 0;

        int min = 100000;
        for(int s : sorted){
            cout << s <<" ";
        }
        for(int i = 1 ; i < n ;i++){
            int diff = sorted[i] - sorted[i - 1];
            if(min > diff) min = diff;
        }
        int circularDiff = 1440 - sorted[n - 1] + sorted[0];
        if(min > circularDiff) min = circularDiff;
        return min;
    }
};