#include <iostream>
#include <cmath>
using namespace std;

#include "Util.h"
#include "DisplayApp.h"

//初始化地图，坐标（1,4）是起始点，坐标（18,18）是结束点，其他的是墙壁或者障碍
/*					   1 1 1 1 1 1 1 1 1 1
   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
0  - - - - - - - x - - - - - - - - - - - -
1  - - - - 1 - - x - - - - - - - - - - - -
2  - - - - - - - x - - x x x x x x - - - -
3  - - - - - - - x - - - - - - - x - - - -
4  - - - - - - - x - - - - - - - x - - - -
5  - - - x x x x x x x x - - - - x - - - -
6  - - - x - - - - - - - - - - - x - - - -
7  - - - x - - x x x x x x x x x x - - - -
8  - - - x - - x - - - - - - - - - - - - -
9  - - - x - - x - - - - - - - - - - - - -
10 - - - x - - x - - - - - - - - x - - - -
11 - - - x - - x x - - - x x x x x - - - -
12 - - - x - - x - - - - - - - - x - - - -
13 - - - - - - x - - - - - - - - x - - - -
14 - - - - - - x x x x x - - - - x x x x x
15 - - - - - - - - - - x - - - - - - - - -
16 x x x x - - - - - - x x x x - - - - - -
17 - - - - - - - - - - - - - x - - - - - -
18 - - - - - - - - - - - - - x x x x - 2 -
19 - - - - - - - - - - - - - - - - x - - -
*/

int main()
{ 	 	
	Point* begin = new Point(1, 4);
	Point* end = new Point(18, 18);
	DisplayApp* app = new DisplayApp();
	app->Init(begin, end);
	app->RunAStar();		

	system("pause");
    return 0;
}
