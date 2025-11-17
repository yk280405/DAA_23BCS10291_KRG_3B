class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        
        int j = 0, n = passengers.size();
        
        for (int bus : buses) {
            int filled = 0;
            while (j < n && passengers[j] <= bus && filled < capacity) {
                j++;
                filled++;
            }
        }

  
        int lastBus = buses.back();
        int filled = 0;
        
      
        j = 0;
        for (int bus : buses) {
            filled = 0;
            while (j < n && passengers[j] <= bus && filled < capacity) {
                j++;
                filled++;
            }
            if (bus == lastBus) break;
        }

        unordered_set<int> used(passengers.begin(), passengers.end());
        int ans;

        if (filled < capacity) {
            ans = lastBus;
        } else {
            ans = passengers[j-1] - 1; 
        }

        while (used.count(ans)) ans--;

        return ans;
    }
};
