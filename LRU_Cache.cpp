#include <string>
#include <iostream>
#include <list> 
#include <unordered_map>

namespace logging
{
    using  namespace std; 
class LRUCache {
public:
    LRUCache(int capacity) 
    {
        _capacity = capacity;
    }
    
    int get(int key) 
    {
        if(_list.empty())
        {
            return -1;
        }

        auto it = _map.find(key);
        if(it == _map.end())
        {
            return -1;
        }

    }
    
    void put(int key, int value) 
    {

    }

private:
    std::list<std::pair<int,int>> _list;
    std::unordered_map<int,std::list<std::pair<int,int>>::iterator> _map;
    int _capacity;
};
}
    int main(void)
    {
        std::list<int> my_list {5,10,15,20,25,30};
        auto it = my_list.begin();
        advance(it,2);
        my_list.insert(it,100);
        it = my_list.end();
        my_list.erase(it);
        my_list.reverse();

        // for(auto it = my_list.begin(); it != my_list.end(); it++)
        // {
        //     std::cout << "#" my_list.???() <<"\t";
        // }

        for (auto val : my_list) 
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }




