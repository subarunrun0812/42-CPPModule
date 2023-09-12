#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}
PmergeMe::~PmergeMe()
{
}
PmergeMe::PmergeMe(const PmergeMe& pmergeme)
{
	this->_vec = pmergeme._vec;
	this->_list = pmergeme._list;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& pmergeme)
{
	this->_vec = pmergeme._vec;
	this->_list = pmergeme._list;
	return (*this);
}

void PmergeMe::AssingToContainer(int argc, const char** argv)
{
	long num;
	for (int i = 1; i < argc; i++)
	{
		for (size_t j = 0; j < strlen(argv[i]); j++)
		{
			if (argv[i][j] < '0' || '9' < argv[i][j])
				throw ErrorParametor();
		}

		//TODO:stoiはc++98より後に出た関数
		num = std::stoi(argv[i]);
		if (num < 0 || INT_MAX < num)
			throw ErrorParametor();
		this->_vec.push_back(static_cast<int>(num));
		this->_list.push_back(static_cast<int>(num));
	}
}

/*
 ======== Vector ========
*/

void PmergeMe::MakePairsVec(std::vector<std::pair<int, int> >& pairs)
{
	for (std::vector<int>::iterator ite = _vec.begin();
		ite < _vec.end(); ite += 2)
	{
		// sizeが偶数だった場合
		if (ite + 1 < _vec.end())
		{
			pairs.push_back(std::make_pair(*ite, *(ite + 1)));
		}
		else
		{
			pairs.push_back(std::make_pair(*ite, -1));
		}
	}

#ifdef DEBUG
	for (size_t i = 0; i < pairs.size(); i++)
	{
		std::cout << "(" << pairs[i].first << ","
			<< pairs[i].second << ")" << std::endl;
	}
#endif
}

void PmergeMe::SortPairVec(std::vector<std::pair<int, int> >& pairs)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first > pairs[i].second)
		{
			int tmp = pairs[i].first;
			pairs[i].first = pairs[i].second;
			pairs[i].second = tmp;
		}
	}
#ifdef DEBUG
	std::cout << LINE "pairをソート" LINE << std::endl;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		std::cout << "(" << pairs[i].first << ","
			<< pairs[i].second << ")" << std::endl;
	}
#endif
}

void PmergeMe::ShowVector(const std::string& str, std::vector<int>& vec)
{
	std::cout << LINE << str << LINE << std::endl;
	std::vector<int>::iterator ite;
	for (std::vector<int>::iterator ite = vec.begin(); ite < vec.end(); *ite++)
	{
		std::cout << *ite << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::AssignToLargeAndSmallVec(std::vector<std::pair<int, int> >& pairs,
	std::vector<int>& smallVec, std::vector<int>& largeVec)
{
	SortPairVec(pairs);
	for (size_t i = 0; i < pairs.size(); i++)
	{
		smallVec.push_back(pairs[i].first);
	}
	for (size_t i = 0; i < pairs.size(); i++)
	{
		// 整数列が奇数だった場合、一番最後のpairsのsecondには-1を代入している
		if (pairs[i].second != -1)
		{
			largeVec.push_back(pairs[i].second);
		}
	}
}

// 再起的にソートする
void PmergeMe::InsertionSortVec(std::vector<int>& vec, int num)
{
	if (num <= 1)
		return;

	std::cout << "num = " << num << std::endl;
	InsertionSortVec(vec, num - 1);

	int key = vec[num - 1];
	int j = num - 2;

	while (j >= 0 && vec[j] > key)
	{
		vec[j + 1] = vec[j];
		j--;
	}
	vec[j + 1] = key;

}

std::vector<int> PmergeMe::MergeSmallVecAndLargeVec(std::vector<int>& smallVec, std::vector<int>& largeVec)
{
	size_t i = 0;
	size_t j = 0;
	std::vector<int> resultVec;
	//TODO: largeVecの初めの要素とペアとなった要素をresultVecをlargeVecに挿入
	while (i < smallVec.size() && j < largeVec.size())
	{
		if (smallVec[i] < largeVec[j])
		{
			resultVec.push_back(smallVec[i]);
			i++;
		}
		else
		{
			resultVec.push_back(largeVec[j]);
			j++;
		}
	}
	while (i < smallVec.size())
	{
		resultVec.push_back(smallVec[i]);
		i++;
	}
	while (j < largeVec.size())
	{
		resultVec.push_back(largeVec[j]);
		j++;
	}
	return (resultVec);
}
void PmergeMe::MergeInsertionSort_Vector()
{
	OutputVec("Before");
	std::vector<std::pair<int, int> > pairs;
	MakePairsVec(pairs);

	// 各ペアの小さい数と大きい数を大小によって2つのリストに代入
	std::vector<int> smallVec;
	std::vector<int> largeVec;
	AssignToLargeAndSmallVec(pairs, smallVec, largeVec);
	ShowVector("LARGE VECTOR", largeVec);
	InsertionSortVec(largeVec, largeVec.size());
	ShowVector("SORTED LARGE VECTOR", largeVec);
	ShowVector("SMALL VECTOR", smallVec);
	InsertionSortVec(smallVec, smallVec.size());
	ShowVector("SORTED SMALL VECTOR", smallVec);


	this->_vec = MergeSmallVecAndLargeVec(smallVec, largeVec);
	OutputVec("After");
#ifdef DEBUG
	ShowVector("SORTED SMALL VECTOR", smallVec);
	ShowVector("SORTED LARGE VECTOR", largeVec);
	ShowVector("RESULT", this->_vec);
#endif
}

void PmergeMe::OutputVec(const std::string& str)
{
	std::cout << GREEN << str << ":\t" NORMAL;
	std::vector<int>::iterator ite;
	for (std::vector<int>::iterator ite = _vec.begin(); ite < _vec.end(); *ite++)
	{
		std::cout << *ite << " ";
	}
	std::cout << std::endl;
}

/*
 ======== List ========

void PmergeMe::MakePairsList(std::list<std::pair<int, int> >& pairs)
{
	for (std::list<int>::iterator ite = _list.begin();
		ite != _list.end();)
	{
		int first = *ite++;
		int second;
		if (ite != _list.end())
		{
			second = *ite++;
		}
		else
			second = -1;
		pairs.push_back(std::make_pair(first, second));
	}

#ifdef DEBUG
	for (std::list<int>::iterator ite = _list.begin();
		ite != _list.end();)
	{
		std::cout << "(" << pairs[*ite].first << ","
			<< pairs[*ite].second << ")" << std::endl;
	}
#endif
}

void PmergeMe::SortPairList(std::list<std::pair<int, int> >& pairs)
{
	for (std::list<std::pair<int, int> >::iterator ite = pairs.begin(); ite != pairs.end(); ++ite)
	{
		if (ite->first > ite->second)
		{
			int tmp = ite->first;
			ite->first = ite->second;
			ite->second = tmp;
		}
	}

#ifdef DEBUG
	std::cout << LINE "pairをソート" LINE << std::endl;
	for (std::list<std::pair<int, int> >::iterator ite = pairs.begin(); ite != pairs.end(); ++ite)
	{
		std::cout << "(" << ite->first << ","
			<< ite->second << ")" << std::endl;
	}
#endif
}
void PmergeMe::AssignToLargeAndSmallList(std::list<std::pair<int, int> >& pairs,
	std::list<int>& smallList, std::list<int>& largeList)
{
	for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		smallList.push_back(it->first);
		if (it->second != -1)
		{
			largeList.push_back(it->second);
		}
	}
}

void PmergeMe::InsertionSortList(std::list<int>& lst)
{
	if (lst.empty())
		return;

	for (std::list<int>::iterator it = std::next(lst.begin()); it != lst.end(); )
	{
		int key = *it;
		std::list<int>::iterator j = it;
		std::list<int>::iterator prev_j = std::prev(j);

		while (j != lst.begin() && *prev_j > key)
		{
			*j = *prev_j;
			--j;
			if (j != lst.begin())
				prev_j = std::prev(j);
		}

		*j = key;
		it = std::next(it);
	}
}
std::list<int> PmergeMe::MergeSmallListAndLargeList(std::list<int>& smallList, std::list<int>& largeList)
{
	std::list<int> resultList;
	std::list<int>::iterator smallIt = smallList.begin();
	std::list<int>::iterator largeIt = largeList.begin();

	while (smallIt != smallList.end() && largeIt != largeList.end())
	{
		if (*smallIt < *largeIt)
		{
			resultList.push_back(*smallIt);
			++smallIt;
		}
		else
		{
			resultList.push_back(*largeIt);
			++largeIt;
		}
	}

	while (smallIt != smallList.end())
	{
		resultList.push_back(*smallIt);
		++smallIt;
	}
	while (largeIt != largeList.end())
	{
		resultList.push_back(*largeIt);
		++largeIt;
	}

	return resultList;
}

void PmergeMe::OutputList(const std::string& str)
{
	std::cout << GREEN << str << ":\t" NORMAL;
	for (std::list<int>::iterator ite = _list.begin(); ite != _list.end(); ++ite)
	{
		std::cout << *ite << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::MergeInsertionSort_List()
{
	OutputList("Before");
	std::list<std::pair<int, int> > pairs;
	MakePairsList(pairs);
	std::list<int> smallList;
	std::list<int> largeList;
	AssignToLargeAndSmallList(pairs, smallList, largeList);
	InsertionSortList(smallList);
	InsertionSortList(largeList);
	this->_list = MergeSmallListAndLargeList(smallList, largeList);
	OutputList("After");
#ifdef DEBUG
	ShowList("SORTED SMALL LIST", smallList); // ShowVectorもlist版に変更する必要がある
	ShowList("SORTED LARGE LIST", largeList); // ShowVectorもlist版に変更する必要がある
	ShowList("RESULT", this->_list); // ShowVectorもlist版に変更する必要がある
#endif
}
*/