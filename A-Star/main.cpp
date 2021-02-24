#include <iostream>
#include <cmath>
using namespace std;

#include "Util.h"
#include "DisplayApp.h"

int main()
{ 	 		
	DisplayApp* app = new DisplayApp();
	app->Init();
	app->RunAStar();		

	system("pause");
    return 0;
}
