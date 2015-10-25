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


void PostOrder (TreePtr Ptr)
{
    if (Ptr != NULL)
    {
        PostOrder(Ptr->left);
        PostOrder(Ptr->right);
        cout << Ptr->info.c;
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

char bitConvert(string s){
	char c = 0;

	if(s[0] == '1'){
		c += 128;
	}
	if(s[1] == '1'){
		c += 64;
	}
	if(s[2] == '1'){
		c += 32;
	}
	if(s[3] == '1'){
		c += 16;
	}
	if(s[4] == '1'){
		c += 8;
	}
	if(s[5] == '1'){
		c += 4;
	}
	if(s[6] == '1'){
		c += 2;
	}
	if(s[7] == '1'){
		c += 1;
	}
	return c;
}

class CompareFrequency {
public:
    bool operator()(TreePtr& t1, TreePtr& t2)
    {
       if (t1->info.frequency >= t2->info.frequency) return true;
       return false;
    }
};