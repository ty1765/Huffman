#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include "huffman.h"

using namespace std;

int main(int argc, char *argv[])
{
	if(argc == 2){
		string file = argv[1];
		ifstream inFile;

		inFile.open(file.c_str());

		if(inFile.fail()){
			cerr << "Failure opening file!" << endl;
			exit(1);
		}
	}
	else{
		cerr << "Invalid Number of Arguments!" << endl;
	}
    
    return 0;
}