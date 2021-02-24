#include "AStar.h"
#include "Util.h"

AStar::AStar() : SearchPathBase()
{
}

void AStar::Run()
{
	bool bFind = false;
	Point* tempPoint = nullptr;
	param* current = GetNodeByPoint(begin);
	current->g = 0;
	openList.push(current);
	while (openList.size() > 0)
	{
		current = openList.top();
		openList.pop();
		param* tempNode = nullptr;
		for (int i = 0; i < NEIGHBOUR; ++i)
		{
			tempPoint = current->pos->Neighbour(i);
			tempNode = GetNodeByPoint(tempPoint);
			if (tempNode != nullptr)
			{
				if (came_from[tempNode] == nullptr)
				{					
					if (i < 4)
					{
						tempNode->g = current->g + 10;
					}
					else
					{
						tempNode->g = current->g + 14;
					}
					tempNode->f = tempNode->g + tempNode->h;
					openList.push(tempNode);
					came_from[tempNode] = current;
				}
				//ÕÒµ½ÖÕµã£¬ÍË³ö
				if (tempNode->pos->CheckEqual(end))
				{
					bFind = true;
					break;
				}
			}
		}
		if (bFind)
		{
			break;
		}
	}
	if (bFind)
	{
		std::list<param*> tempResult;
		while (current != nullptr && current != GetNodeByPoint(begin))
		{
			result_path.push_front(current->pos);
			current = came_from[GetNodeByPoint(current->pos)];
		}
	}	
}

