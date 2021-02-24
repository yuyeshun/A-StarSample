#include <iostream>
#include "SearchPathBase.h"
#include "Util.h"

SearchPathBase::SearchPathBase()
	:
	begin(nullptr),
	end(nullptr),
	table(nullptr),
	list(nullptr)
{
}

void SearchPathBase::Init(int** table, param** list, Point* begin, Point* end)
{
	this->table = table;
	this->list = list;
	this->begin = begin;
	this->end = end;
}

void SearchPathBase::OutPut()
{
	if (result_path.size() > 0)
	{
		std::cout << "----------------¡ýResultPath¡ý----------------" << std::endl;
		for (auto it = result_path.begin(); it != result_path.end(); ++it)
		{
			cout << (*it)->ToString() << endl;
		}
		std::cout << "----------------¡üResultPath¡ü----------------\n" << std::endl;

		std::cout << "----------------¡ýResultMap¡ý----------------" << std::endl;
		for (int i = 0; i < HEIGHT; ++i)
		{
			for (int j = 0; j < WIDTH; ++j)
			{
				if (table[i][j] == -1)
				{
					std::cout << "x ";
				}
				else
				{
					bool bEqual = false;
					for (auto it = result_path.begin(); it != result_path.end(); ++it)
					{
						if ((*it)->CheckEqual(i, j))
						{
							bEqual = true;
							break;
						}
					}
					if (bEqual)
					{
						std::cout << "+ ";
					}
					else if (table[i][j] == 0)
					{
						std::cout << "- ";
					}
					else
					{
						std::cout << (char)table[i][j] << " ";
					}
				}
			}
			std::cout << std::endl;
		}
		std::cout << "----------------¡üResultMap¡ü----------------\n" << std::endl;
	}	
	else
	{
		std::cout << "no way to get\n" << std::endl;
	}
}

param* SearchPathBase::GetNodeByPoint(Point* point)
{
	param* ret = nullptr;
	//¼ì²é±ß½ç
	if (point->x >= 0 && point->x < HEIGHT && point->y >= 0 && point->y < WIDTH)
	{
		//¼ì²é×èµ²
		if (table[point->x][point->y] >= 0)
		{
			ret = &list[point->x][point->y];
		}		
	}

	return ret;
}

bool cmp::operator()(param* a, param* b)
{
	return a->f > b->f;
}
