#include "controller.h"
#include "operations\opAddRect.h"


//Constructor
controller::controller()
{
	pGraph = new Graph;
	pGUI = new GUI;	//Create GUI object
}

//==================================================================================//
//								operations-Related Functions							//
//==================================================================================//
operationType controller::GetUseroperation() const
{
	//Ask the input to get the operation from the user.
	return pGUI->GetUseroperation();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an operation and executes it
operation* controller::createOperation(operationType OpType)
{
	operation* pOp = nullptr;
	
	//According to operation Type, create the corresponding operation object
	switch (OpType)
	{
		case DRAW_RECT:
			pOp = new opAddRect(this);
			break;

		case DRAW_LINE:
			pOp = new opAddLine(this);

			break;
		case  DRAW_TRI :
			pOp = new opAddTriangle(this);
			break;
		case  DRAW_SQUARE:
			pOp = new opAddSquare(this);

			break;
		case  DRAW_CIRC:
			pOp = new opAddCircle(this);
			break;
		case ROTATE :
			pOp = new opRotate(this);

			break;
		//case DRAW_POLY:
		//	pOp = new opAddpoly(this);
		//	break;
		case DRAW_OVAL:
			pOp = new opAddOVAL(this);
			break;
		case  CHNG_generalPENCOLOR:
			pOp = new opChangeColor(this);
			break;
		case  CHNG_generalFILLCOLOR:
				pOp = new opChangefillColor(this);
				break; 
		case  SELECT:
			pOp = new opselect(this);
			break;
		case  SAVE : 
			pOp = new opSave(this);
			break;
		case LOAD :
			pOp = new opLoad(this);
			break;
		case  DEL:
			pOp = new DelShape(this);
			break;
		case  COPY:
			pOp = new opCopyShape(this);
			break;

		case  STICK_IMAGE:
			pOp = new opStickImage(this);
			break;
		case EXIT:
			pOp = new opExit(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no operation
			break;
	}

	return pOp;
	
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all shapes on the user interface
void controller::UpdateInterface() const
{	
	pGraph->Draw(pGUI);
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the UI
GUI *controller::GetUI() const
{	return pGUI; }
//////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the Graph
Graph* controller::getGraph() const
{
	return pGraph;
}






//void controller::getGraph







//Destructor
controller::~controller()
{
	delete pGUI;
	delete pGraph;
	
}



//==================================================================================//
//							Run function											//
//==================================================================================//
void controller::Run()
{
	operationType OpType;
	do
	{
		//1. Ask the GUI to read the required operation from the user
		OpType = GetUseroperation();

		//2. Create an operation coresspondingly
		operation* pOpr = createOperation(OpType);
		 
		//3. Execute the created operation
		if (pOpr)
		{
			pOpr->Execute();//Execute
			delete pOpr;	//operation is not needed any more ==> delete it
			pOpr = nullptr;
		}

		//Update the interface
		UpdateInterface();

	} while (OpType != EXIT);

}
bool operator==(color c1, color c2)
{

	if (c1.ucBlue == c2.ucBlue &&
		c1.ucGreen == c2.ucGreen &&
		c1.ucRed == c2.ucRed)
		return true;

	else return false;

}