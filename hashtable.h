#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <utility>

class HashTable {
public:
    HashTable();
    ~HashTable();
    void insert(const std::string& key);
    std::vector<std::pair<std::string, int>> getAllEntries();

private:
    struct Node {
        std::string key;
        int count;
        Node* next;
        Node(std::string k);
    };

    static const int TABLE_SIZE = 10007;
    std::vector<Node*> table;

    size_t hashFunction(const std::string& key);
};

#endif // HASHTABLE_H