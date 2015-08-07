#include "ternary-search-tree-impl.h"
#include "log.h"

TernarySearchTreeImpl::TernarySearchTreeImpl()
    : m_node(0)
	, m_wordCount(0)
{}

TernarySearchTreeImpl::~TernarySearchTreeImpl()
{
	// delete m_node;
}

void TernarySearchTreeImpl::insert(std::string& str)
{
	if (str.empty()) {
		return;
	}
	insertWord(&m_node, const_cast<char*> (str.c_str()));
	m_wordCount++;
}

bool TernarySearchTreeImpl::search(std::string& str)
{
	if (str.empty() && !getWordCount()) {
		return false;
	}
	return searchWord(const_cast<char*> (str.c_str()));
}

void TernarySearchTreeImpl::remove(std::string& str)
{
	if (str.empty() && !getWordCount()) {
		return;
	}
	removeWord(&m_node, str, 0);
}

void TernarySearchTreeImpl::display()
{
	if (!m_wordCount) {
		LOG("Tree is empty");
		return;
	}

	std::string str;
	displayTst(m_node, str, 0);
}

void TernarySearchTreeImpl::pattern(std::string& str)
{
	if (!m_wordCount) {
		LOG("Tree is empty");
		return;
	}

	patternSearch(m_node, str.c_str());
}

void TernarySearchTreeImpl::searchPrefix(std::string& str)
{
	std::string prefix;
	int index = 0;
	if (str.empty()) {
		return;
	}
	Node *root = searchPrefixInTree(m_node, str.c_str(), prefix, index);
	if (!root) {
		std::cout << "No matching words with the prefix -> " << str << std::endl;
	}
	displayTst(root, prefix, index);
}

int TernarySearchTreeImpl::getWordCount()
{
	return m_wordCount;
}

void TernarySearchTreeImpl::insertWord(Node **root, char *str)
{
	if (!*root) {
		*root = new Node(*str);
	}

    if ((*root)->getChar() > *str) {
        insertWord(&( (*root)->left ), str);
    } else if ((*root)->getChar() < *str) {
        insertWord(&( (*root)->right ), str);
	} else {
		if (*(str+1))
			insertWord(&( (*root)->center ), (str+1));
		else
			(*root)->setEnd(true);
	}
}

bool TernarySearchTreeImpl::searchWord(char *str)
{
	int index = 0;
	Node *root = m_node;
	while (root) {
		if (root->getChar() == str[index]) {
			if ((str[index+1]) == NULL && root->getEnd()) {
				return true;
			}
			root = root->center;
			index++;
		} else if (str[index] < root->getChar()) {
			root = root->left;
		} else {
			root = root->right;
		}
	}
	return false;
}

bool TernarySearchTreeImpl::removeWord(Node **root, std::string& str, int index)
{
	if (*root == NULL) {
		return false;
	}

	if (index == str.length()-1) {
		// Reduce the word count here
		m_wordCount--;
		if ((*root)->isLeafNode()) {
			delete *root;
            *root = NULL;
			return true;
		} else {
			(*root)->setEnd(false);
			return false;
		}
	} else {
		if (str[index] < (*root)->getChar()) {
            return removeWord(&( (*root)->left), str, index);
		} else if (str[index] > (*root)->getChar()) {
			return removeWord(&( (*root)->right), str, index);
		} else {
            if (removeWord(&( (*root)->center ), str, index+1)) {
                if ((*root)->isLeafNode() && !(*root)->getEnd()) {
					delete *root;
					*root = NULL;
					return true;
				}
				return false;
			}
		}
	}
	return false;
}

void TernarySearchTreeImpl::displayTst(Node *root, std::string& str, int index)
{
	if (!root) {
		return;
	}

    if (root->left) {
        displayTst(root->left, str, index);
    }

	str.insert(index, 1, root->getChar()) ;
	if (root->getEnd()) {
		LOG(str.substr(0, index+1));
    }

	if (root->center) {
		displayTst(root->center, str, index+1);
	}

    if (root->right) {
		displayTst(root->right, str, index);
	}
}

void TernarySearchTreeImpl::patternSearch(Node *root, const char *str)
{
	// Needs to be implemented
	if (!str || !root) {
		return;
	}

	if (*str == '.' || *str < root->getChar()) {
		patternSearch(root->left, str);
	}

}

Node* TernarySearchTreeImpl::searchPrefixInTree(Node *root, const char *str, std::string& prefix, int& index)
{
	if (!root) {
		return NULL;
	}

	if (*str == root->getChar()) {
		if (!*(str+1)) {
            prefix.insert(index, 1, root->getChar());
            index++;
			return root;
		} else {
			prefix.insert(index, 1, root->getChar());
			index++;

			Node *current = searchPrefixInTree(root->center, str+1, prefix, index);
            return current ? current->center : root->center;
		}
	} else if (*str < root->getChar()) {
		searchPrefixInTree(root->left, str, prefix, index);
	} else {
		searchPrefixInTree(root->right, str, prefix, index);
	}
}

Node::Node(char c)
	: left(0)
    , center(0)
    , right(0)
	, m_character(c)
	, m_endOfString(false)
{}

Node::~Node()
{}

void Node::setChar(char c)
{
	m_character = c;
}

char Node::getChar()
{
	return m_character;
}

void Node::setEnd(bool value)
{
	m_endOfString = value;
}

bool Node::getEnd()
{
	return m_endOfString;
}

bool Node::isLeafNode()
{
    return ((left == NULL) && (right == NULL) && (center == NULL));
}
