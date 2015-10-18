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
		char c;
		int arr[256];
		for(int i = 0; i < 256; i++){
			arr[i] = 0;
		}

		inFile.open(file.c_str());

		if(inFile.fail()){
			cerr << "Failure opening file!" << endl;
			exit(1);
		}

		while(inFile >> c){
			arr[int(c)]++;
		}
		size_t pos = file.find(".");
		string oFile = file.substr(0, pos) + ".hzip";
		ofstream outFile;
		outFile.open(oFile.c_str());
	}
	else{
		cerr << "Invalid Number of Arguments!" << endl;
	}
    
    return 0;
}