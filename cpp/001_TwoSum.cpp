//
//  main.cpp
//  001TwoSum
//
//  Created by bengxy on 9/10/15.
//  Copyright (c) 2015 leetcode. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        vector<int> nn;
        nn=nums;
        
        sort(nums.begin(), nums.end());
        for(auto iter = nums.begin();iter!=nums.end();iter++){
            cout<<*iter<<" ";
        }
        cout<<endl;
        int lid = 0;
        int gid = (int)nums.size()-1;
        
        
        while( lid!= gid){
            if(nums[lid] + nums[gid] > target)
                gid--;
            else if(nums[lid] + nums[gid] < target)
                lid++;
            else
                break;
            
        }
        
        cout<<nums[gid]<<" "<<nums[lid]<<endl;
        
        
        int l, g;
        l = g = 0;
        int i=0;
        if( nums[gid] == nums[lid] ){
            bool mark = false;
            for(i=0;i<nn.size();i++){
                if(nn[i] == nums[lid]){
                    if( mark){
                        g = i;
                        break;
                    }
                    else {
                        l = i;
                        mark = true;
                    }
                }
            }
        }
        else{
            for(i=0;i<nn.size();i++){
                if(nn[i] == nums[lid])
                    l = i;
                if(nn[i] == nums[gid])
                    g = i;
            }
        }
        
    
        
        
        res.push_back( (l<g?l:g)  +1 );
        res.push_back( (l<g?g:l) +1 );
        cout<<(l<g?l:g)  +1 <<" "<<(l<g?g:l) +1<<endl;
        
        return res;
    }
    
};

int main(void) {
    vector<int> test;
    for(int i=0;i<3;i++){
        int j;
        cin>>j;
        test.push_back(j);
    }
    
    
    Solution a;
    a.twoSum(test, 6);
    return 0;
}
