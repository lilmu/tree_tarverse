/* Binary Tree Traversal - Preorder, Inorder, Postorder */
#include<iostream>
#include<iomanip>
#include<fstream>
#include "tree.h"       // design the tree class by yourself
#include <queue>
using namespace std;
void init();
//Tree<char> bt;
//Tree<Token> bt2;
string infix, input;
int debug=0;

int main() {
	/* construct a binary search tree
	   according to the input chars 

	             M
			   /   \
			  B     Q
			 / \     \
			A   C     Z
                     /
					X
				   /
				  W	  
	*/
	Tree<char> bt;
	char input[30] = "MBQZACXW";
	cout << "Key in the original chars :\n";
	cin >> input;
	init();
	for (int i = 0; i < 8; i++) bt.Insert(input[i]);
		cout <<left << setw(15) <<"original input chars:" << input << endl;
		cout<<left<<setw(15)<<"Preorder: ";    bt.Preorder();
		cout<<left<<setw(15)<<"Inorder: ";	   bt.Inorder();
		cout<<left<<setw(15)<<"Postorder:";    bt.Postorder();
		cout<<left<<setw(15)<<"Levelorder:";   bt.Levelorder();	
	return 0;
}

void init() {  // read the infix from the file infix.txt
	ifstream inFile("traversal.txt", ios::in); // input file
	if (!inFile) { cerr << "Cannot open input file" << endl; exit(1); }
	inFile >> debug;	inFile.clear();  inFile.ignore(100, '\n');
	inFile >> input;    inFile.clear();  inFile.ignore(100, '\n');
	inFile >> infix;	inFile.clear();  inFile.ignore(100, '\n');
};