#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        vector<int>ans;
       for(auto &i: nums)
       {
           m[i]++;
       }
       priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>v;
        for(auto &i: m)
        {
            v.push({i.second,i.first});
            if(v.size()>k)
            {
                v.pop();
            }
        }
        while(!v.empty())
        {
            ans.push_back(v.top()[1]);
            v.pop();
        }
        return ans;
    }
};