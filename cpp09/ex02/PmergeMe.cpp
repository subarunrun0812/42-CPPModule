#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}
PmergeMe::~PmergeMe()
{
}
PmergeMe::PmergeMe(const PmergeMe& pmergeme)
{
	(void)pmergeme;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& pmergeme)
{
	(void)pmergeme;
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

		num = std::stoi(argv[i]);
		if (num < 0 || INT_MAX < num)
			throw ErrorParametor();
		this->_vec.push_back(static_cast<int>(num));
		this->_list.push_back(static_cast<int>(num));
	}
	OutputVec("Before");
	// std::cout << "Before:\t";
	// std::list<int>::iterator ite;
	// for (std::list<int>::iterator ite = _list.begin(); ite != _list.end(); *ite++)
	// {
	// 	std::cout << *ite << " ";
	// }
	// std::cout << std::endl;
}


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

void PmergeMe::SortPairVec(std::vector<std::pair<int, int> > pairs)
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

void PmergeMe::AssignToLargeAndSmallVec(std::vector<std::pair<int, int> > pairs, \
	std::vector<int>& smallVec, std::vector<int>& largeVec)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		smallVec.push_back(pairs[i].first);
	}
	for (size_t i = 0; i < pairs.size(); i++)
	{
		//整数列が奇数だった場合、一番最後のpairsのsecondには-1を代入している
		if (pairs[i].second != -1)
		{
			largeVec.push_back(pairs[i].second);
		}
	}
}

void PmergeMe::InsertionSortVec(std::vector<int>& vec)
{
	for (size_t i = 1; i < vec.size(); i++)
	{
		int key = vec[i];
		size_t j = i;
		while ((vec[j - 1] > key) && j > 0)
		{
			vec[j] = vec[j - 1];
			j--;
		}
		vec[j] = key;
	}
}


std::vector<int> PmergeMe::MergeSmallVecAndLargeVec(std::vector<int>& smallVec, std::vector<int>& largeVec)
{
	size_t i = 0;
	size_t j = 0;
	std::vector<int> resultVec;
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
	std::vector<std::pair<int, int> > pairs;
	MakePairsVec(pairs);

	// 各ペアの小さい数と大きい数を大小によって2つのリストに代入
	std::vector<int> smallVec;
	std::vector<int> largeVec;
	AssignToLargeAndSmallVec(pairs, smallVec, largeVec);
	InsertionSortVec(smallVec);
	InsertionSortVec(largeVec);
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
