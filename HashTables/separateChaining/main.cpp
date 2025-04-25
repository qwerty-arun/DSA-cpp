#include "separateChaining.hpp"
#include <string>

int main() {
    HashTableSeparateChaining<std::string, int> map;

    map.put("apple", 1);
    map.put("banana", 2);
    map.put("orange", 3);
    map.put("apple", 10);  // Update value

    std::cout << "Get 'apple': " << map.get("apple") << "\n";
    std::cout << "Contains 'banana': " << map.containsKey("banana") << "\n";

    map.print();

    map.remove("banana");
    std::cout << "After removing 'banana':\n";
    map.print();

    std::cout << "All keys:\n";
    for (const auto& key : map.keys()) std::cout << key << " ";
    std::cout << "\n";

    std::cout << "All values:\n";
    for (const auto& val : map.values()) std::cout << val << " ";
    std::cout << "\n";

    return 0;
}
