//
// Created by karim on 04/10/19.
//

#ifndef TMES_HASHMAP_H
#define TMES_HASHMAP_H

#include <vector>
#include <forward_list>

namespace pr{
    template <typename K, typename V>
    class HashMap {
        class Entry{
        public:
            const K key;
            V value;
            Entry(const K key, V value):key(key), value(value) {}
        };

        std::vector< std::forward_list< Entry > > buckets;

    public:
        HashMap(size_t taille) : buckets(taille){
            for (int i = 0; i < taille; ++i) {
                buckets.push_back(std::forward_list<Entry>());
            }
        }

        V* get(const K & key){
            size_t h = std::hash<K>()(key);
            h = h % buckets.size();
            for(auto & ent : buckets[h]){
                if(ent.key == key){
                    return &(ent.value);
                }
            }
            return nullptr;
        }

        bool put(const K& key, const V& value){
            V * temp = get(key);
            if(temp == nullptr){
                size_t h = std::hash<K>()(key);
                h = h % buckets.size();
                Entry toAdd(key, value);
                buckets[h].push_front(toAdd);
                return false;
            }else{
                (*temp) = value;
                return true;
            }
        }


        size_t size() const {
            size_t res = 0;
            for (int i = 0; i < buckets.size(); ++i) {
                int t = 0;
                for (auto& b : buckets[i]) {
                    t++;
                }
                res += t;
            }
            return res;
        }


    };

}


#endif //TMES_HASHMAP_H
