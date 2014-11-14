//Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

//get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
//set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

//map: key:key, value:iterator of list
//list: entry of (key, value)

class LRUCache{
public:
    struct CacheEntry{
        int key;
        int value;
        CacheEntry(int k, int v):key(k), value(v){}
    };
    LRUCache(int capacity) {
        m_capacity=capacity;
    }
    
    int get(int key) {
        if(m_map.find(key) == m_map.end()){
            return -1;
        }
        MoveToHead(key);
        return m_map[key]->value;
    }
    
    void set(int key, int value) {
        if(m_map.find(key) == m_map.end()){
            CacheEntry newItem(key, value);
            if(m_LRU_cache.size() >= m_capacity){
                m_map.erase(m_LRU_cache.back().key);
                m_LRU_cache.pop_back();
            }
            m_LRU_cache.push_front(newItem);
            m_map[key] = m_LRU_cache.begin();
        }
        m_map[key]->value = value;
        MoveToHead(key);
    }
private:
    unordered_map <int, list<CacheEntry>::iterator> m_map;
    list<CacheEntry> m_LRU_cache;
    int m_capacity;
    void MoveToHead(int key){
        CacheEntry updateEntry = *m_map[key];//key¡®s corresponding entry of list
        m_LRU_cache.erase(m_map[key]);
        m_LRU_cache.push_front(updateEntry);
        m_map[key] = m_LRU_cache.begin();
    }
};