/*
** LRU Cache **
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, 
it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

/*
The key point is how to track the least recently used cache position and erase/insert/find efficiently in O(1)
find - hashmap
erase/insert - list

Time complexity: O(1)
Space Complexity: O(n)
*/
class LRUCache {
private:
    int size;
    list<int> lru;                              // MRU ... LRU
    unordered_map<int, list<int>::iterator> mp; // key -> iterator points the position in the list
    unordered_map<int, int> kv;                 // key -> value

public:
    LRUCache(int capacity) : size(capacity) {}
    
    int get(int key) {
        if (kv.count(key) == 0) return -1;
        updateLRU(key);
        return kv[key];
    }
    
    void put(int key, int value) {
        if (kv.size() == size && kv.count(key) == 0) evict();
        updateLRU(key);
        kv[key] = value;
    }

    void updateLRU(int key) {
        if (kv.count(key)) lru.erase(mp[key]);
        lru.push_front(key);
        mp[key] = lru.begin();
    }
    
    void evict() {
        mp.erase(lru.back());
        kv.erase(lru.back());
        lru.pop_back();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */