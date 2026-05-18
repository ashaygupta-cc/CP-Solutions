class Router {
public:
    deque<vector<int>>check;
    unordered_set<string>seen;
    unordered_map<int, vector<int>> counts;
    int memoryLimit;

    Router(int memoryLimit){
        this->memoryLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp){
        string key = to_string(source) + "_" + to_string(destination) + "_" + to_string(timestamp);
        if(seen.count(key)) return false;
        check.push_back({source,destination,timestamp});
        seen.insert(key);
        auto &vec = counts[destination];
        vec.insert(lower_bound(vec.begin(), vec.end(), timestamp), timestamp);
        if((int)check.size() > memoryLimit){
            auto old = check.front();
            string oldKey = to_string(old[0]) + "_" + to_string(old[1]) + "_" + to_string(old[2]);
            seen.erase(oldKey);
            auto &lst = counts[old[1]];
            auto it = lower_bound(lst.begin(), lst.end(), old[2]);
            if(it != lst.end() && *it == old[2]) lst.erase(it);
            check.pop_front();
        }
        return true;
    }
    
    vector<int> forwardPacket(){
        if(check.empty()) return {};
        auto pkt = check.front();
        vector<int>res = pkt;
        string oldKey = to_string(pkt[0]) + "_" + to_string(pkt[1]) + "_" + to_string(pkt[2]);
        seen.erase(oldKey);
        auto &lst = counts[pkt[1]];
        auto it = lower_bound(lst.begin(), lst.end(), pkt[2]);
        if(it != lst.end() && *it == pkt[2]) lst.erase(it);
        check.pop_front();
        return res;
    }
    
    int getCount(int destination, int startTime, int endTime){
        auto it = counts.find(destination);
        if(it == counts.end() || it->second.empty()) return 0;
        vector<int>& list = it->second;
        int left = lower_bound(list.begin(), list.end(), startTime) - list.begin();
        int right = upper_bound(list.begin(), list.end(), endTime) - list.begin();
        return right - left;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
