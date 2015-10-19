#ifndef HUFFMAN_H
#define HUFFMAN_H 

struct huffman {
    long long int frequency;
    char c; //Character represented in file
};

// use a priotity queue with pointers to huffman and add the frequencyuencys together and make
// char @ for interior nodes and make frquencies of the head the totals. 

struct TreeNodeType;
typedef TreeNodeType* TreePtr;

struct TreeNodeType
{
  huffman info;
  TreePtr left;
  TreePtr right;
};

TreePtr newTree (TreePtr& left, TreePtr& right, char, long long int);

void InOrder(TreePtr);	
void PreOrder(TreePtr);
void PostOrder(TreePtr);
void deleteTree(TreePtr);


#endif
