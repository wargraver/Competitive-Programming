class LRUCache {
public:
    struct Element
    {
        std::list<Element*>::iterator pos;
        unsigned key = 0;
        int value = -1;
    };

    LRUCache(int capacity) : capacity(capacity) {

    }
    
    int get(int key) {
         auto& e = map[key];
         if (e.value == -1)
             return -1;
        lst.erase(e.pos);
        lst.push_front(&e);
        e.pos = lst.begin();
        return e.value;
        
    }
    
    void put(int key, int value) {
        auto& e = map[key];
        if (e.value == -1)
        {
            e.key = key;
            e.value = value;
            lst.push_front(&e);
            e.pos = lst.begin();
            if (lst.size() > capacity)
            {
                Element* l = lst.back();
                l->value = -1;
                lst.pop_back();
            }
        }
        else
        {
            e.value = value;
            lst.erase(e.pos);
            lst.push_front(&e);
            e.pos = lst.begin();
        }
    }
private:
     unsigned capacity;
     std::list<Element*>        lst;
     std::array<Element, 3001> map;
     
};
