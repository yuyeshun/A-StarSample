#include <iostream>
#include <fstream>
#include <exception>

#include "DisplayApp.h"
#include "Util.h"
#include "AStar.h"

DisplayApp::DisplayApp()
	:
	begin(nullptr),
	end(nullptr),
	table(nullptr),
	list(nullptr)	
{
}

void DisplayApp::Init(Point* begin, Point* end)
{
	this->begin = begin;
	this->end = end;
	AllocateMemory();
	initMap();
	initList();
}

void DisplayApp::RunAStar()
{
	AStar* aStar = new AStar();
	aStar->Init(table, list, begin, end);
	aStar->Run();
	aStar->OutPut();
}

void DisplayApp::AllocateMemory()
{
	table = new int* [HEIGHT];
	for (int i = 0; i < HEIGHT; ++i)
	{
		table[i] = new int[WIDTH];		
	}

	list = new param * [HEIGHT];
	for (int i = 0; i < HEIGHT; ++i)
	{
		list[i] = new param[WIDTH];
	}
}

void DisplayApp::initMap()
{
	std::ifstream mapfile("Map.txt");
	if (mapfile)
	{
		char data;
		for (int i = 0; i < HEIGHT; ++i)
		{
			for (int j = 0; j < WIDTH; ++j)
			{
				mapfile >> data;
				if (data == 'x')
				{
					table[i][j] = -1;
				}
				else if(data == '-')
				{
					table[i][j] = 0;					
				}				
				else
				{
					table[i][j] = data;
				}
			}
		}
		mapfile.close();
	}	
	else
	{
		std::cout << "can not open Map.txt" << std::endl;
		_ASSERT(false);
	}

	std::cout << "----------------↓Map↓----------------" << std::endl;
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			if (table[i][j] == -1)
			{
				std::cout << "x ";
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
		std::cout << std::endl;
	}
	std::cout << "----------------↑Map↑----------------\n" << std::endl;
}

void DisplayApp::initList()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{			
			list[i][j].h = 10 * (abs(i - end->x) + abs(j - end->y));
			list[i][j].g = 0x7ffffff;
			list[i][j].pos = new Point(i, j);
		}
	}
	//起始点到自己的距离是0
	list[begin->x][begin->y].g = 0;
}
