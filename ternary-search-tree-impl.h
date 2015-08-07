#ifndef TERNARY_SEARCH_TREE_IMPL_H
#define TERNARY_SEARCH_TREE_IMPL_H

#include <iostream>
#include <string.h>

class Node;

class TernarySearchTreeImpl
{
  public:
  	TernarySearchTreeImpl();
  	~TernarySearchTreeImpl();

  	void insert(std::string& str);
  	bool search(std::string& str);
	  void remove(std::string& str);
    void display();
    void pattern(std::string& str);
    void searchPrefix(std::string& str);
	  int getWordCount(); 
  private:
  	void insertWord(Node **root, char *str);
  	bool searchWord(char *str);
  	bool removeWord(Node **root, std::string& str, int index);
    void displayTst(Node *root, std::string& str, int index);
    void patternSearch(Node *root, const char *str);
    Node* searchPrefixInTree(Node *root, const char *str, std::string& prefix, int& index);

    Node *m_node;
  	int m_wordCount;
};

class Node
{
  public:
  	Node(char c);
  	~Node();

  	void setChar(char c);
  	char getChar();
  	void setEnd(bool value);
  	bool getEnd();
  	bool isLeafNode();

  	Node *left, *center, *right;
  private:
  	char m_character;
  	bool m_endOfString;
};

#endif