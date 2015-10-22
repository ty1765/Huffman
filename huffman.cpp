#include <iostream>
#include <string>
#include <fstream>
#include "huffman.h"

using namespace std;

TreePtr newTree (TreePtr& left, TreePtr& right, char c = '@', int i = -1)
{
    TreePtr Tree = new(TreeNodeType);

    Tree->left = left;
    Tree->right = right;

    if(i != -1) {
        Tree->info.frequency = i;
        Tree->info.c = c;
    }
    else
        Tree->info.frequency = left->info.frequency + right->info.frequency;

    Tree->info.c = c;

    return Tree;
}

void InOrder (TreePtr Ptr)
{
    if (Ptr != NULL)
    {
        InOrder(Ptr->left);
        cout << Ptr->info.frequency << ":" << Ptr->info.c << " ";
        InOrder(Ptr->right);
    }
}

void MakeBinary (TreePtr Ptr, string bits[], string s)
{
    if (Ptr != NULL)
    {
        MakeBinary(Ptr->left, bits, s+='0');
        s = s.substr(0, s.length() - 1);
        if(Ptr->info.c != '@'){
        	bits[int(Ptr->info.c)] = s;
        	s = s.substr(0, s.length() - 1);
        }
        MakeBinary(Ptr->right, bits, s+='1');
        s = s.substr(0, s.length() - 1);
    }
}


void PostOrder (TreePtr Ptr, ofstream& outFile)
{
    if (Ptr != NULL)
    {
        PostOrder(Ptr->left, outFile);
        PostOrder(Ptr->right, outFile);
        cout << Ptr->info.c;
        outFile << Ptr->info.c;
    }
}

void deleteTree(TreePtr root)
{
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
    }
    else
        delete (root);
}

class CompareFrequency {
public:
    bool operator()(TreePtr& t1, TreePtr& t2)
    {
       if (t1->info.frequency >= t2->info.frequency) return true;
       return false;
    }
};