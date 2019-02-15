// Cast.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <iostream>
using namespace std;

class CFather
{
public:
	CFather();
	CFather(double x,double y);
	~CFather();
	virtual double Sum();
public:
	double m_f_x;
	double m_f_y;
};

CFather::CFather()
{
}

CFather::CFather(double x,double y)
{
	m_f_x = x;
	m_f_y = y;
}

CFather::~CFather()
{
}


double CFather::Sum()
{
	double sum = m_f_x + m_f_y;
	return sum;
}


///////////////////////////////////////
class CChild:public CFather
{
public:
	CChild();
	~CChild();
	CChild(double x, double y);

	virtual double Sum();
};

CChild::CChild()
{

}

CChild::CChild(double x,double y)
{
	m_f_x = x;
	m_f_y = y;
}

CChild::~CChild()
{

}

double CChild::Sum()
{
	double sum = 2 * (m_f_x + m_f_y);
	return sum;	
}












/////////////////////////////////
int main()
{
	CFather *father = new CFather(6.0,9.0);

	CFather *parent = new CChild(10.0,20.0);

	CChild *child_01 = dynamic_cast<CChild*>(father);
	if (child_01 != NULL)
	{
		cout << "child_01: " << child_01->Sum() << endl;
	}
	CChild *child_02 = static_cast<CChild*>(father);
	if (child_02 != NULL)
	{
		cout << "child_02: " << child_02->Sum() << endl;
	}


	CChild *child_03 = dynamic_cast<CChild*>(parent);

	if (child_03)
	{
		cout << "child_03: " << child_03->Sum() << endl;
	}

	CChild *child = new CChild(20,40);

	CFather *father_06 = static_cast<CFather*>(child);
	if (father_06 != NULL)
	{
		cout << "father: " << father->Sum() << endl;
	}


	Sleep(20000);
    return 0;
}

