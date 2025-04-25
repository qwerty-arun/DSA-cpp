#include "linearProbing.cpp"
int main() {
    HashTable ht(10);

    ht.put(1, "One");
    ht.put(11, "Eleven");
    ht.put(21, "Twenty-One");

    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 11: " << ht.get(11) << endl;
    cout << "Get key 21: " << ht.get(21) << endl;

    ht.remove(11);
    cout << "After removing 11: " << ht.get(11) << endl;

    return 0;
}
