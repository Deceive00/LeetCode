class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // N, E, S, W
        int direction = 0;
        int max = -1000000;
        int x = 0, y = 0;
        set<pair<int, int>> obstacle;
        for(vector<int> obs : obstacles){
            obstacle.insert({obs[0], obs[1]});
        }

        for(int c : commands){
            if(c == -1){
                direction++;
                direction = direction > 3 ? 0 : direction; 
            } else if(c == -2){
                direction--;
                direction = direction < 0 ? 3 : direction; 
            } else {
                int currX = x, currY = y;
                for(int i = 0 ; i < c ; i++){
                    switch(direction){
                        case 0:
                            currY++;
                            break;
                        case 1:
                            currX++;
                            break;
                        case 2:
                            currY--;
                            break;
                        case 3:
                            currX--;
                            break;
                    }
                    if(obstacle.count({currX, currY})) break;
                    x = currX;
                    y = currY;
                }
                int total = x*x + y*y;
                if(max < total){
                    max = total;
                }
            }
        }


        return max;
    }
};