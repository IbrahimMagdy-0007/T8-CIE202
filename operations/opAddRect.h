#pragma once

#include "operation.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"

//Add Rectangle operation class
class opAddRect: public operation
{
public:
	opAddRect(controller *pCont);
	virtual ~opAddRect();
	
	//Add rectangle to the controller
	virtual void Execute() ;
	//virtual void PrintInfo(shape* Getshape);

};
class opAddTriangle : public operation
{
public:
	opAddTriangle(controller* pCont);
	virtual ~opAddTriangle();
	virtual void Execute();
};

class opAddLine : public operation
{
public:
	opAddLine(controller* pCont);
	virtual ~opAddLine();
	virtual void Execute();
};

class opAddSquare : public operation
{
public:
	opAddSquare(controller* pCont);
	virtual ~opAddSquare();
	virtual void Execute();
};

class opAddCircle : public operation
{
public:
	opAddCircle(controller* pCont);
	virtual ~opAddCircle();
	virtual void Execute();
};

class opChangeColor : public operation
{
public:
	opChangeColor(controller* pCont);
	virtual ~opChangeColor();

	
	virtual void Execute();
	

};
class opChangefillColor : public operation
{
public:
	opChangefillColor(controller* pCont);
	virtual ~opChangefillColor();


	virtual void Execute();


};
class opselect : public operation
{

public:
	opselect(controller* pCont);
	virtual ~opselect();


	virtual void Execute();



};
class opSave : public operation {
public:
	opSave(controller* pCont);
	virtual ~opSave();
	virtual void Execute();
};
class opLoad : public operation {
public:
	opLoad(controller* pCont);
	virtual ~opLoad();
	virtual void Execute();
};
class opAddOVAL :public operation
{
public:
	opAddOVAL(controller* pCont);
	virtual~opAddOVAL();
	virtual void Execute();



};

//class opAddpoly : public operation
//{
//public:
//	opAddpoly(controller* pCont);
//	virtual ~opAddpoly();
//
//	//Add Irrpoly to the controller
//	virtual void Execute();
//
//
//};
class opRotate :public operation
{
public:
	opRotate(controller* pcont);
	~opRotate();
	virtual void Execute();
	
};


class opExit : public operation {
public:
	opExit(controller* pCont);
	virtual ~opExit();
	virtual void Execute();
};
class DelShape :public operation
{
public:
	DelShape(controller* pCont);
	virtual~DelShape();
	virtual void Execute();
};
class opStickImage : public operation
{
public:
	opStickImage(controller* pCont);
	virtual ~opStickImage();





	virtual void Execute();
};

class opCopyShape : public operation
{
public:
	opCopyShape(controller* pCont);
	virtual ~opCopyShape();





	virtual void Execute();
};