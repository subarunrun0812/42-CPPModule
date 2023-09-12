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

void PmergeMe::OutputVec(const std::string& str,std::vector<int> vec)
{
	std::cout << GREEN << str << ":\t" NORMAL;
	std::vector<int>::iterator ite;
	for (std::vector<int>::iterator ite = vec.begin(); ite < vec.end(); *ite++)
		std::cout << *ite << " ";
	std::cout << std::endl;
}

void PmergeMe::PrepareVec(std::vector<std::pair<int, int> >& pairs,
	std::vector<int>& smallVec, std::vector<int>& largeVec)
{
		if (_vec.begin() + 1 == _vec.end())
		{
			largeVec.push_back(_vec[0]);
			return;
		}
	for (std::vector<int>::iterator ite = _vec.begin();
		ite < _vec.end(); ite += 2)
	{
		int firstValue = *ite;
		int secondValue = -1;
		if (ite + 1 < _vec.end())
			secondValue = *(ite + 1);
		if (firstValue > secondValue)
			std::swap(firstValue, secondValue);

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

int PmergeMe::BinarySearchVector(const std::vector<int>& vec, int target)
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
	std::vector<int>::iterator ite = std::find(smallVec.begin(), smallVec.end(), -1);
	if (ite != smallVec.end())
		smallVec.erase(ite);
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (largeVec[0] == pairs[i].second && pairs[i].first != -1)
		{
			largeVec.insert(largeVec.begin(), pairs[i].first);
			std::vector<int>::iterator ite = std::find(smallVec.begin(),smallVec.end(), pairs[i].first);
			if (ite != smallVec.end())
				smallVec.erase(ite);
			break;
		}
	}
	for (size_t i = 0; i < smallVec.size(); i++)
	{
		int position = BinarySearchVector(largeVec, smallVec[i]);
		largeVec.insert(largeVec.begin() + position, smallVec[i]);
	}
	return (largeVec);
}

void PmergeMe::MergeInsertionSort_Vector()
{
	OutputVec("Before",this->_vec);
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> smallVec;
	std::vector<int> largeVec;
	PrepareVec(pairs, smallVec, largeVec);
	InsertionSortVec(largeVec, largeVec.size());
	this->_vec = MergeSmallVecAndLargeVec(smallVec, largeVec,pairs);
	OutputVec("After",this->_vec);
}


/*
 ======== List ========
*/

void PmergeMe::OutputList(const std::string& str,std::list<int> list)
{
    std::cout << GREEN << str << ":\t" NORMAL;
    for (std::list<int>::iterator ite = list.begin(); ite != list.end(); ++ite)
        std::cout << *ite << " ";
    std::cout << std::endl;
}

void PmergeMe::PrepareList(std::list<std::pair<int, int> >& pairs,
    std::list<int>& smallList, std::list<int>& largeList)
{
    for (std::list<int>::iterator ite = _list.begin();
        ite != _list.end(); ++ite)
    {
        int firstValue = *ite;
        if (++ite == _list.end()) {
            pairs.push_back(std::make_pair(firstValue, -1));
            smallList.push_back(firstValue);
            return;
        }
        int secondValue = *ite;

        if (firstValue > secondValue)
            std::swap(firstValue, secondValue);

        pairs.push_back(std::make_pair(firstValue, secondValue));
        smallList.push_back(firstValue);
        largeList.push_back(secondValue);
    }
}




void PmergeMe::InsertionSortList(std::list<int>& lst, std::list<int>::iterator it)
{
    if (it == lst.begin())
		return;

    std::list<int>::iterator prev_it = it;
    --prev_it;
    InsertionSortList(lst, prev_it);

    while (it != lst.begin() && *prev_it > *it)
    {
        std::iter_swap(prev_it, it);
        --it;
        if (it != lst.begin())
			--prev_it;
    }
}

std::list<int>::iterator PmergeMe::BinarySearchList(std::list<int>& lst, int target)
{
    std::list<int>::iterator left = lst.begin();
    std::list<int>::iterator right = lst.end();

    int count = 0;
    for (std::list<int>::iterator it = left; it != right; ++it)
        count++;

    while (count > 0)
    {
        std::list<int>::iterator middle = left;
		 for (int i = 0; i < count / 2; ++i)
            ++middle;

        if (*middle == target)
            return middle;

        if (*middle < target)
        {
            left = middle;
            ++left;
            count -= (count / 2) + 1;
        }
        else
            count /= 2;
    }

    return left;
}

std::list<int> PmergeMe::MergeSmallListAndLargeList(std::list<int>& smallList, std::list<int>& largeList,
    std::list<std::pair<int, int> >& pairs)
{
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        if (largeList.front() == it->second)
        {
            largeList.push_front(it->first);
            std::list<int>::iterator ite = std::find(smallList.begin(),smallList.end(), it->first);
			if (ite != smallList.end())
				smallList.erase(ite);
            break;
        }
    }
    for (std::list<int>::iterator it = smallList.begin(); it != smallList.end(); ++it)
    {
        std::list<int>::iterator pos = BinarySearchList(largeList, *it);
        largeList.insert(pos, *it);
    }
    return largeList;
}

void PmergeMe::MergeInsertionSort_List()
{
    OutputList("Before",this->_list);
    std::list<std::pair<int, int> > pairs;
    std::list<int> smallList;
    std::list<int> largeList;
    PrepareList(pairs, smallList, largeList);
    std::list<int>::iterator end = largeList.end();
	--end;
	InsertionSortList(largeList, end);
    this->_list = MergeSmallListAndLargeList(smallList, largeList, pairs);
    OutputList("After",this->_list);
}
