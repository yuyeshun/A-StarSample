#pragma once
#include "SearchPathBase.h"

class AStar : public SearchPathBase
{
public:
	AStar();

public:
	virtual void Run() override;
};