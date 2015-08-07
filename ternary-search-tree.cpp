#include "ternary-search-tree.h"
#include "ternary-search-tree-impl.h"

TernarySearchTree::TernarySearchTree()
	: m_impl(new TernarySearchTreeImpl)
{}

TernarySearchTree::~TernarySearchTree()
{
	delete m_impl;
}

void TernarySearchTree::insert(std::string str)
{
	m_impl->insert(str);
}

bool TernarySearchTree::search(std::string str)
{
    return m_impl->search(str);
}

void TernarySearchTree::remove(std::string str)
{
	m_impl->remove(str);
}

void TernarySearchTree::display()
{
	m_impl->display();
}

void TernarySearchTree::pattern(std::string str)
{
	m_impl->pattern(str);
}

void TernarySearchTree::searchPrefix(std::string str)
{
	m_impl->searchPrefix(str);
}

int TernarySearchTree::getWordCount()
{
	return m_impl->getWordCount();
}