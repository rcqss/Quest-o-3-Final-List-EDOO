#include "genome_analyzer.h"
#include "hashtable.h"
#include <fstream>
#include <vector>
using namespace std;

void processGenome(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    HashTable hashTable;

    if (!inFile.is_open()) {
        throw runtime_error("Error opening input file!");
    }

    // Read all lines into a vector first
    vector<string> lines;
    string line;
    while (getline(inFile, line)) {
        lines.push_back(line);
    }

    // Process lines (ignoring first and last)
    for (size_t i = 1; i < lines.size() - 1; ++i) {
        const string& currentLine = lines[i];
        if (currentLine.empty() || currentLine.size() < 6) continue;

        for (size_t j = 0; j <= currentLine.size() - 6; j += 6) {
            string block = currentLine.substr(j, 6);
            hashTable.insert(block);
        }
    }

    // Write results
    auto entries = hashTable.getAllEntries();
    for (const auto& entry : entries) {
        outFile << entry.first << "\t" << entry.second << "\n";
    }

    inFile.close();
    outFile.close();
}