#ifndef HUFFMAN_H
#define HUFFMAN_H 

struct huffman {
    long long int frequency;
    char c; //Character represented in file
};
 
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
