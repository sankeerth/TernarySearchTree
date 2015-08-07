#include "ternary-search-tree.h"

int main()
{

	TernarySearchTree *tst = TernarySearchTree::create();
	tst->insert("celebrate");
	tst->insert("candle");
	tst->insert("actor");
	tst->insert("cold");
	tst->insert("forget");
	tst->insert("acid");
	tst->insert("anger");
	tst->insert("acute");

	std::cout << tst->getWordCount() << std::endl;

	std::cout << tst->search("celebrate") << std::endl;
	std::cout << tst->search("cat") << std::endl;
	std::cout << tst->search("actor") << std::endl;
	std::cout << tst->search("big") << std::endl;
	std::cout << tst->search("down") << std::endl;
	std::cout << tst->search("forget") << std::endl;

    tst->display();

    tst->remove("actor");
    tst->remove("forget");
    tst->remove("celebrate");

    std::cout << tst->getWordCount() << std::endl;
    tst->searchPrefix("d");



	return 0;
}
