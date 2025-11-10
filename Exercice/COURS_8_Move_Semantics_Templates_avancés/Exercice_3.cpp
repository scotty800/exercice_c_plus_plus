#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    unordered_map<string, int> map1 = {
        {"scott", 20}, {"alice", 25}, {"bob", 30}, {"david", 15}, {"eva", 16}
    };

    auto maxPerson = *max_element(
        map1.begin(),
        map1.end(),
        [](const auto &a, const auto &b) {
            return a.second < b.second;
        }
    );

    cout << "Peronne la plus âgée:"
        << maxPerson.first << ", " << maxPerson.second << " ans\n";

    cout << "Ages > 18 :\n";

    for_each(map1.begin(), map1.end(), [](const auto &p) {
        if (p.second > 18)
            cout << p.first << ": " << p.second << endl;
    });

    return 0;
    
}