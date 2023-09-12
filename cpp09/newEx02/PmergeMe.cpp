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

int PmergeMe::stringToInt(const std::string& str)
{
	std::istringstream iss(str);
	int num;
	if (!(iss >> num))
	{
		std::cout << "\"" << str << "\"";
		throw ErrorConversion();
	}
	return num;
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

		num = stringToInt(argv[i]);
		if (num < 0 || INT_MAX < num)
			throw ErrorParametor();
		this->_vec.push_back(static_cast<int>(num));
		this->_list.push_back(static_cast<int>(num));
	}
}

/*
 ======== Vector ========
*/

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

void PmergeMe::PrepareVec(std::vector<std::pair<int, int> >& pairs,
	std::vector<int>& smallVec, std::vector<int>& largeVec)
{
	for (std::vector<int>::iterator ite = _vec.begin();
		ite < _vec.end(); ite += 2)
	{
		int firstValue = *ite;
		int secondValue = -1;
		if (ite + 1 < _vec.end())
			secondValue = *(ite + 1);
		if (firstValue > secondValue)
		{
			std::swap(firstValue, secondValue);
		}

		pairs.push_back(std::make_pair(firstValue, secondValue));

		if (firstValue != -1)
			smallVec.push_back(firstValue);
		largeVec.push_back(secondValue);
	}
}

// 再起的にソートする
void PmergeMe::InsertionSortVec(std::vector<int>& vec, int num)
{
	if (num <= 1)
		return;

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

int PmergeMe::binary_search(const std::vector<int>& vec, int target)
{
	int left = 0;
	int right = vec.size() - 1;

	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (vec[middle] == target)
			return middle;
		if (vec[middle] < target)
			left = middle + 1;
		else
			right = middle - 1;
	}
	return (left);
}

std::vector<int> PmergeMe::MergeSmallVecAndLargeVec(std::vector<int>& smallVec, std::vector<int>& largeVec\
,std::vector<std::pair<int, int> >& pairs)
{
	// largeVecの初めの要素とペアとなった要素をresultVecをlargeVecに挿入
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (largeVec[0] == pairs[i].second)
		{
			//TODO: paris[i].firstの要素を一番先頭に挿入する
			largeVec.insert(largeVec.begin(), pairs[i].first);
			std::vector<int>::iterator ite = std::find(smallVec.begin(),
												smallVec.end(), pairs[i].first);
			if (ite != smallVec.end())
				smallVec.erase(ite);
			break;
		}
	}
	// バイナリサーチを使って、smallVecの要素をlargeVecに挿入していく
	for (size_t i = 0; i < smallVec.size(); i++)
	{
		int position = binary_search(largeVec, smallVec[i]);
		largeVec.insert(largeVec.begin() + position, smallVec[i]);
	}

	return (largeVec);
}
void PmergeMe::MergeInsertionSort_Vector()
{
	OutputVec("Before");
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> smallVec;
	std::vector<int> largeVec;
	// 各ペアの小さい数と大きい数を大小によって2つのリストに代入
	PrepareVec(pairs, smallVec, largeVec);
	InsertionSortVec(largeVec, largeVec.size());
	this->_vec = MergeSmallVecAndLargeVec(smallVec, largeVec,pairs);
	OutputVec("After");
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