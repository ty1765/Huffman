#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include <queue>
#include "huffman.cpp"

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
		//counts freq of chars
		while(inFile >> noskipws >> c){
			arr[int(c)]++;
		}

		inFile.close();
		//creates a priority queue 
		priority_queue<TreePtr, vector<TreePtr>, CompareFrequency> pq;
		TreePtr NullPtr = NULL;
		for(int i = 0; i < 256; i++){
			if(arr[i] != 0){
				TreePtr NewTree = newTree(NullPtr, NullPtr, i, arr[i]);
				pq.push(NewTree);
			}
		}
		
		TreePtr ptr, ptr2;
		//creates final tree
		while(pq.size() != 1){
			ptr = pq.top();
			pq.pop();
			ptr2 = pq.top();
			pq.pop();
			TreePtr NewTree = newTree(ptr, ptr2);
			pq.push(NewTree);
		}
		//cout << pq.top()->info.frequency << endl;

		TreePtr Final = pq.top();
		pq.pop();
		
		PostOrder(Final);
	/*
		size_t pos = file.find(".");
		string oFile = file.substr(0, pos) + ".tree";
		ofstream outFile;
		outFile.open(oFile.c_str());
		outFile <*/
	}
		//size_t pos = file.find(".");
		//string oFile = file.substr(0, pos) + ".hzip";
		//ofstream outFile;
		//outFile.open(oFile.c_str());
	
	else{
		cerr << "Invalid Number of Arguments!" << endl;
	}
    
    return 0;
}