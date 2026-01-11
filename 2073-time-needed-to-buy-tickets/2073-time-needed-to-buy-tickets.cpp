class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int i = 0, n = tickets.size();
        int time = 0;
        while(tickets[k] != 0) {
            if (tickets[i] != 0) {
                tickets[i]--;
                time++;
            }
            i++;
            i %= n;
        }
        return time;
    }
};