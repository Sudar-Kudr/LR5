#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <vector>
#include <set>

using namespace std;
int main()
{
    //1
    std::unordered_multimap<int, std::string> multimap;
    multimap.insert({10, "Hello"});
    multimap.insert({10, "People's"});
    multimap.insert({7, "Robot's"});
    multimap.insert({10, "World"});
    multimap.insert({-4, "Элемент равный -4"});
    multimap.insert({0, "Нулевое значение"});
    cout << "Вставка\n";
    for(std::pair<int, std::string> p : multimap)
        cout << p.first << " " << p.second << endl;
    
    multimap.erase(7); //Удаление
    cout << "\nУдаление\n";
    for(std::pair<int, std::string> p : multimap)
        cout << p.first << " " << p.second << endl;
    
    //2
    std::map<int, string> map;
    for(std::pair<int, std::string> p : multimap)
        map.insert(p);
    
    copy(multimap.begin(), multimap.end(), inserter(map, map.begin()));
    cout << "\nКопирование в map\n";
    for(std::pair<int, std::string> p : map){
        cout << p.first << " " << p.second << endl;
    }
    
    cout << "\nЗадание 2\nПоложительных: ";
    long res = count_if(map.begin(), map.end(), [](pair<int, string> n){return n.first > 0;});
    cout << res << endl;
    
    vector<int> keys;
    transform(map.begin(), map.end(), back_inserter(keys), [](pair<int, string> n){return n.first;});
    cout << "Вектор:\n";
    for(int key : keys)
        cout << key << " ";
    cout << "\n\n";
    
    //3
    cout << "Поиск элемента\n";
    auto res2 = find(keys.begin(), keys.end(), -4);
    if(res2 == keys.end()){
        cout << "нет элемента\n";
    }
    else
        cout << *res2 << endl;
    
    cout << "Замена 0\n";
    replace_if(keys.begin(), keys.end(), [](int veckey){return veckey == 0;}, 6);
    for(int key : keys)
        cout << key << " ";
    cout << "\n\n";
    
    sort(keys.begin(), keys.end(), [](int a, int b){return a > b;});
    cout << "Cортировка\n";
    for(int key : keys)
        cout << key << " ";
    cout << "\n\n";
    
    set<int> s;
    copy(keys.begin(), keys.end(), inserter(s, s.begin()));
    cout << "Set\n";
    for(int key : s)
        cout << key << " ";
    cout << endl;
    
    return 0;
}
