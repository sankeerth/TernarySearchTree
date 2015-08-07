#ifndef TERNARY_SEARCH_TREE_H
#define TERNARY_SEARCH_TREE_H

#include <iostream>
#include <string.h>

class TernarySearchTreeImpl;

class TernarySearchTree
{
  public:
	static TernarySearchTree* create()
	{
		return new TernarySearchTree();
	}
	~TernarySearchTree();
	void insert(std::string str);
	bool search(std::string str);
	void remove(std::string str);
	void display();
	void pattern(std::string str);
	void searchPrefix(std::string str);
	int getWordCount();
  private:
  	TernarySearchTree();
    TernarySearchTreeImpl *m_impl;
};

#endif