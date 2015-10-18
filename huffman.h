#ifndef HUFFMAN_H
#define HUFFMAN_H 

#include <queue>

struct huffman {
    int frequency;
    char c; //Character represented in file
};
class compareHuffman {
public:
    bool operator()(huffman& t1, huffman& t2);   
};

#endif
