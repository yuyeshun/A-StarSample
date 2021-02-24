#pragma once
#include <map>
#include <list>
#include <queue>

using namespace std;

struct param;

struct cmp
{
	bool operator() (param* a, param* b);	
};

class SearchPathBase
{
public:
	SearchPathBase();

public:
	virtual void Init(int** table, struct param** list, struct Point* begin, struct Point* end);
	virtual void Run() = 0;
	virtual void OutPut();

public:
	struct param* GetNodeByPoint(struct Point* point);
protected:
	struct Point* begin;
	struct Point* end;
	int** table;
	struct param** list;	
	//使用优先队列，判断 F=G+H 的最小值进行排序
	std::priority_queue<param*, vector<param*>, cmp> openList;
	map<param*, param*> came_from;

	std::list<Point*> result_path;
};