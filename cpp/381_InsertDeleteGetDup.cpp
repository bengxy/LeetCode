class RandomizedCollection {
public:
    /** Initialize your data structure here. */
            vector<int> v;
        unordered_map<int, int> m;
        unordered_map<int, int> counter;
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool check = false;
        if( m.find(val) == m.end())
        {
            check = true;
            m[val] = v.size();
            counter[val] = 1;
            v.push_back(val);
        }
        else
        {
            counter[val]++;
        }
        return check;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool check = false;
        if( m.find(val) != m.end()){
            check = true;
            if( counter[val] == 1){
                //remoev all 
                //int tmp = m[val];
                int last_v = v[v.size()-1];
                v[val] = last_v;
                m[last_v] = m[val];
                
                v.pop_back();
                counter.erase(val)
                m.erase(val);

            }
            else{
                counter[val]--;
            }
        }
        return check;     
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return v[std::rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */