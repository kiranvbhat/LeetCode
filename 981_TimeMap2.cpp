// https://leetcode.com/problems/time-based-key-value-store/

// My 2nd Solution to the TimeMap class. More memory efficient with use of vector instead of map.
class TimeMap {
public:
    void set(const string& key, string value, int timestamp) 
    {
        // more efficient than push_back because pair is not constructed beforehand
        tm[key].emplace_back(timestamp, std::move(value));  // std::move allows more efficient transfer of resources from value
    }
    
    // returns true if index is that of the greatest timestamp_prev (tsp) less than or equal to timestamp
    bool greatestTSLE(const string& key, int index, int timestamp) {
        int numTimestamps = tm[key].size();
        if (index == numTimestamps - 1) {       // edge case: last index in vector<pair<int, string>>
            return (tm[key][index].first <= timestamp);
        }
        return (tm[key][index].first <= timestamp) && (tm[key][index + 1].first > timestamp);
    }
    
    // finds the timestamp_prev such that it is the greatest number <= timestamp.
    string get(const string& key, int timestamp) {
        if (tm.count(key) == 0) return "";
        
        // binary search for greatest timestamp_prev that is less than or equal to timestamp
        int l = 0;
        int r = tm[key].size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (greatestTSLE(key, m, timestamp)) return tm[key][m].second;
            if (tm[key][m].first <= timestamp) l = m + 1;
            else r = m - 1;
        }
        return "";
    }
private:
    unordered_map<string, vector<pair<int, string>>> tm;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
