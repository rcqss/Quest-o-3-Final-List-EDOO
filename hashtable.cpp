#include "hashtable.h"
using namespace std;

HashTable::Node::Node(string k) : key(k), count(1), next(nullptr) {}

HashTable::HashTable() : table(TABLE_SIZE, nullptr) {}

HashTable::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Node* entry = table[i];
        while (entry != nullptr) {
            Node* prev = entry;
            entry = entry->next;
            delete prev;
        }
    }
}

size_t HashTable::hashFunction(const string& key) {
    const int p = 31;
    const int m = TABLE_SIZE;
    size_t hash_value = 0;
    size_t p_pow = 1;
    
    for (char c : key) {
        hash_value = (hash_value + (c - 'A' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

void HashTable::insert(const string& key) {
    size_t hash_val = hashFunction(key);
    Node* prev = nullptr;
    Node* entry = table[hash_val];

    while (entry != nullptr && entry->key != key) {
        prev = entry;
        entry = entry->next;
    }

    if (entry == nullptr) {
        entry = new Node(key);
        if (prev == nullptr) {
            table[hash_val] = entry;
        } else {
            prev->next = entry;
        }
    } else {
        entry->count++;
    }
}

vector<pair<string, int>> HashTable::getAllEntries() {
    vector<pair<string, int>> entries;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Node* entry = table[i];
        while (entry != nullptr) {
            entries.emplace_back(entry->key, entry->count);
            entry = entry->next;
        }
    }
    return entries;
}