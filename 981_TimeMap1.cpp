// https://leetcode.com/problems/time-based-key-value-store/

// 1st solution. Not as memory efficient as 2nd solution, but simpler code by replacing binary search with use of upper_bound() map function.
// Also not as time efficient on set(), since a bracket insert is log(n) where n is number of time-value entries for a given key
class TimeMap {
public:
    TimeMap() {
        tm = {};
    }
    
    void set(string key, string value, int timestamp) {
        tm[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (tm.count(key) == 0) return "";
        auto it = tm[key].upper_bound(timestamp);
        if (it == tm[key].begin()) {    // if the very first key is greater than timestamp
            return "";      // then we know there are no timestamp_prevs less than timestamp
        }
        // otherwise, the previous iterator points to map entry with timestamp_prev <= timestamp
        return prev(it)->second; 
    }
private:
    unordered_map<string, map<int, string>> tm;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
