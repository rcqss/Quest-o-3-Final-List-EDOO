#include "genome_analyzer.h"
#include <iostream>
using namespace std;

int main() {
    const string inputFilename = "sequences.fasta.txt";
    const string outputFilename = "genome_analysis_output.txt";
    //const string inputFilename = "sequences.rafael.txt";
    //const string outputFilename = "genome_analysis_output_rafael.txt";

    try {
        processGenome(inputFilename, outputFilename);
        cout << "Genome analysis complete. Results saved to " 
             << outputFilename << endl;
        cout << "First and last lines were ignored in the analysis." << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
