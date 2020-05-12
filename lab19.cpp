#include <iostream>
#include <string>
using namespace std;

template <class K, class V>
struct Map
{
   K keys[100];
   V values[100];
   int size;
};

template <class K, class V>
void Initialize(Map<K,V>& map)
{
   map.size = 0;
}


template <class K, class V>
void Put(Map<K,V>& map , const K& key, const V& value)
{
   if(map.size < 100 && !Contains(map, key))
   {
       map.keys[map.size] = key;
       map.values[map.size] = value;
       map.size++;
   }
}

template <class K, class V>
V& Get(Map<K,V>& map, const K& key)
{
   for(int i = 0; i < map.size; i++){
       if(map.keys[i] == key)
           return map.values[i];
   }
   throw "Key Does Not Exists";
}


template <class K, class V>
bool Contains(Map<K,V>& map, const K& key)
{
   for(int i = 0; i < map.size; i++){
       if(map.keys[i] == key)
           return true;
   }
   return false;
}


template <class K, class V>
void Remove(Map<K,V>& map, const K& key)
{
   int index = -1;
   for(int i = 0; i < map.size; i++){
       if(map.keys[i] == key){
           index = i;
           break;
       }
   }
  
   if(index != -1){
       
       map.keys[index] = map.keys[map.size-1];
       map.values[index] = map.values[map.size-1];
       map.size--;
   }
}

int main()
{
   Map<string, int> items;
   string shirt = "shirt", socks = "socks", chips = "chips"; 
   Initialize(items);
   Put(items,shirt, 79);
   Put(items,socks, 5);
   Put(items,chips, 3);
   cout << "items[shirt] = " << Get(items, shirt) << endl;
   cout << "items[socks] = " << Get(items, socks) << endl;
   cout << "items[chips] = " << Get(items, chips) << endl;
   if(Contains(items,socks))
       cout << "items contains socks" << endl;
   else
       cout << "item does not contain socks" <<endl;
   cout << "Removing shirt from items" << endl;
   Remove(items, shirt);
   if(Contains(items,shirt))
       cout << "items contains shirt" << endl;
   else
       cout << "item does not contain shirt" <<endl;
  
   cout << "Updating items[chips] = 5" << endl;
   Get(items, chips) = 5;
   cout << "items[chips] = " << Get(items, chips) << endl;
   return 0;
}