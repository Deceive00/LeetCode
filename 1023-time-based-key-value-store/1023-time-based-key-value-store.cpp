class TimeMap {
    
public:
    unordered_map<string, vector<pair<string,int>>> data;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(data.find(key) != data.end()){
            vector<pair<string,int>>& arr = data[key];

            int left = 0, right = arr.size() - 1;
            while(left <= right){
                int mid = left + (right - left) / 2;
                if(arr[mid].second == timestamp){
                    return arr[mid].first;
                }
                else if(arr[mid].second > timestamp){
                    right = mid - 1;
                } else if(arr[mid].second < timestamp){
                    left = mid + 1;
                }
            }
            // for(int i = 0 ; i < arr.size() ; i++){
            //     cout << arr[i].first << " " << arr[i].second << endl;
            // }
            // cout << right << endl;
            if (right >= 0) {
                return arr[right].first;
            } else {
                return "";
            }
        }

        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */