#include "opAddRect.h"
#include "..\shapes\Rect.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"
#include <cstdlib>

opAddRect::opAddRect(controller * pCont):operation(pCont)
{}
opAddRect::~opAddRect()
{} 

//Execute the operation
void opAddRect::Execute() 
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Rectangle: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all rectangle parameters
	GfxInfo RectGfxInfo;
	
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pUI->getCrntDrawColor();
	RectGfxInfo.FillClr = pUI->getCrntFillColor();
	RectGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	RectGfxInfo.isFilled = false;	//default is not filled
	RectGfxInfo.isSelected = false;	//defualt is not selected


	//Create a rectangle with the above parameters
	Rect *R=new Rect(P1, P2, RectGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(R);

}/*
void opAddRect::PrintInfo (shape* Getshape)
{
	GfxInfo RectGfxInfo;
	
		
	GUI* pUI = pControl->GetUI();
	
	pUI->PrintMessage();
}*/

opAddTriangle::opAddTriangle(controller* pCont) : operation(pCont)
{}

opAddTriangle::~opAddTriangle()
{}

void opAddTriangle::Execute()
{
	Point P1, P2, P3;
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Triangle: Click at first corner");
	pUI->GetPointClicked(P1.x, P1.y);

	pUI->PrintMessage("Click second corner");
	pUI->GetPointClicked(P2.x, P2.y);

	pUI->PrintMessage("Click third corner");
	pUI->GetPointClicked(P3.x, P3.y);
	pUI->ClearStatusBar();

	GfxInfo TriGfxInfo;
	TriGfxInfo.DrawClr = pUI->getCrntDrawColor();
	TriGfxInfo.FillClr = pUI->getCrntFillColor();
	TriGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	TriGfxInfo.isFilled = true; // Default is not filled
	TriGfxInfo.isSelected = false; // Default is not selected

	Triangle* T = new Triangle(P1, P2, P3, TriGfxInfo);
	Graph* pGr = pControl->getGraph();
	pGr->Addshape(T);
}


opAddLine::opAddLine(controller* pCont) : operation(pCont)
{}

opAddLine::~opAddLine()
{}

void opAddLine::Execute()
{
	Point P1, P2;
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Line: Click at the starting point");
	pUI->GetPointClicked(P1.x, P1.y);

	pUI->PrintMessage("Click at the ending point");
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	GfxInfo LineGfxInfo;
	LineGfxInfo.DrawClr = pUI->getCrntDrawColor();
	LineGfxInfo.FillClr = pUI->getCrntFillColor(); // For a line, fill color might not be used
	LineGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	LineGfxInfo.isFilled = false; // Default is not filled
	LineGfxInfo.isSelected = false; // Default is not selected
	
	Line* L = new Line(P1, P2, LineGfxInfo);
	Graph* pGr = pControl->getGraph();
	pGr->Addshape(L);
}




opAddSquare::opAddSquare(controller* pCont) :operation(pCont)
{}
opAddSquare::~opAddSquare()
{}

//Execute the operation
void opAddSquare::Execute()
{
	Point P1, P2,P3;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Square: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2


	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();
	
	//Preapre all rectangle parameters
	GfxInfo RectGfxInfo;

	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pUI->getCrntDrawColor();
	RectGfxInfo.FillClr = pUI->getCrntFillColor();
	RectGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	RectGfxInfo.isFilled = true;	//default is not filled
	RectGfxInfo.isSelected = false;	//defualt is not selected


	P3.x = P1.x + (P2.x - P1.x);
	P3.y = P1.y + (P2.x - P1.x);
	//Create a rectangle with the above parameters
	//P1 = P2;
	Square* R = new Square(P1, P3, RectGfxInfo);

	//void PrintInfo(shape * Graph)override;
	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(R);
	

}








opAddCircle::opAddCircle(controller* pCont) :operation(pCont)
{}
opAddCircle::~opAddCircle()
{}

//Execute the operation
void opAddCircle::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Circle : Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x,P2.y);
	pUI->ClearStatusBar();

	//Preapre all rectangle parameters
	GfxInfo RectGfxInfo;

	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pUI->getCrntDrawColor();
	RectGfxInfo.FillClr = pUI->getCrntFillColor();
	RectGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	RectGfxInfo.isFilled = false;	//default is not filled
	RectGfxInfo.isSelected = false;	//defualt is not selected


	//Create a rectangle with the above parameters
	//P1 = P2;
	Circle* R = new Circle(P1, P2, RectGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle t
	// 
	// o the list of shapes
	pGr->Addshape(R);

}

opChangeColor::opChangeColor(controller* pCont) :operation(pCont)
{}
opChangeColor::~opChangeColor()
{}

//Execute the operation
void opChangeColor::Execute()
{
	GUI* pUI = pControl->GetUI();
	color x=pUI->getColorFromPalette();
	pUI->setDrawColor(x);
	Graph* pGr = pControl->getGraph();

}

opChangefillColor::opChangefillColor(controller* pCont) :operation(pCont)
{}
opChangefillColor::~opChangefillColor()
{}


void opChangefillColor::Execute()
{
	GUI* pUI = pControl->GetUI();
	color x = pUI->getColorFromPalette();
	pUI->setFillolor(x);
	Graph* pGr = pControl->getGraph();

}
opselect::opselect(controller* pCont) :operation(pCont)
{

}
opselect::~opselect() {}

void opselect::Execute() {

	Point p;
	GUI* pUI = pControl->GetUI();

	pUI->GetPointClicked(p.x, p.y);
	Graph* pGr = pControl->getGraph();

	pGr->Getshape(p);
}



opSave::opSave(controller* pCont) : operation(pCont) {}

opSave::~opSave() {}

void opSave::Execute() {
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Saving shapes to file. Please enter the file name:");
	string fileName = pUI->GetSrting() + ".txt";
	pUI->ClearStatusBar();

	Graph* pGraph = pControl->getGraph();
	ofstream outFile(fileName);
	if (outFile.is_open()) {
		pGraph->save(outFile);
		outFile.close();
		pUI->PrintMessage("Shapes saved successfully to " + fileName);
	}
	else {
		pUI->PrintMessage("Error: Could not open file " + fileName);
	}

}
opLoad::opLoad(controller* pCont) : operation(pCont) {}

opLoad::~opLoad() {}

void opLoad::Execute() {
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Loading shapes from file. Please enter the file name:");
	string fileName = pUI->GetSrting() + ".txt";
	pUI->ClearStatusBar();

	Graph* pGraph = pControl->getGraph();
	ifstream inFile(fileName);
	if (inFile.is_open()) {
		pGraph->load(inFile);
		inFile.close();
		pUI->PrintMessage("Shapes loaded successfully from " + fileName);
	}
	else {
		pUI->PrintMessage("Error: Could not open file " + fileName);
	}
}


//opAddpoly::opAddpoly(controller* pCont) :operation(pCont)
//{
//}
//
//opAddpoly::~opAddpoly()
//{
//}
//
//void opAddpoly::Execute()
//{
//	GUI* pUI = pControl->GetUI();
//	//Get data from user to draw 
//	int vertices_num;
//	pUI->ClearStatusBar();
//	pUI->PrintMessage("Add new  polygon --> Please enter number of vertices : ");
//	vertices_num = stoi(pUI->GetSrting());
//	pUI->ClearStatusBar();
//	Point p, center;
//	pUI->PrintMessage(" Click at first point ");
//	pUI->GetPointClicked(p.x, p.y);
//	pUI->ClearStatusBar();
//	string msg = "First point is at (" + to_string(p.x) + ", " + to_string(p.y) + " )";
//	msg += " ... Click at center";
//	pUI->PrintMessage(msg);
//	pUI->GetPointClicked(center.x, center.y);
//	pUI->ClearStatusBar();
//	msg = "Center point is at (" + to_string(center.x) + ", " + to_string(center.y) + " )";
//	pUI->PrintMessage(msg);
//	//set all Irrpoly propertise 
//	GfxInfo PolyGfxInfo;
//	PolyGfxInfo.BorderWdth = pUI->getCrntPenWidth();
//	PolyGfxInfo.DrawClr = pUI->getCrntDrawColor();
//	PolyGfxInfo.FillClr = pUI->getCrntFillColor();
//	PolyGfxInfo.isFilled = false; // detault isn't filled 
//	PolyGfxInfo.isSelected = false; // detault isn't selected 
//	// Create  a new Irrpoly with this parameters and properties
//	Poly* polygon = new Poly(p, center, vertices_num, PolyGfxInfo);
//	//Get a pointer to the graph
//	Graph* pGr = pControl->getGraph();
//	//Add the Line to the list of shapes
//	pGr->Addshape(polygon);
//}

opAddOVAL::opAddOVAL(controller* pCont) :operation(pCont)
{}
opAddOVAL::~opAddOVAL()
{}

//Execute the operation
void opAddOVAL::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New OVAL : Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2


	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all rectangle parameters
	GfxInfo OvalGfxInfo;

	//get drawing, filling colors and pen width from the interface
	OvalGfxInfo.DrawClr = pUI->getCrntDrawColor();
	OvalGfxInfo.FillClr = pUI->getCrntFillColor();
	OvalGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	OvalGfxInfo.isFilled = true;	//default is not filled
	OvalGfxInfo.isSelected = false;	//defualt is not selected



	Oval* R = new Oval(P1, P2, OvalGfxInfo);

	//void PrintInfo(shape * Graph)override;
	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(R);


}
opRotate::opRotate(controller* pcont) :operation(pcont)
{

}

opRotate::~opRotate()
{
}
void opRotate::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pUI->ClearStatusBar();
	pUI->PrintMessage("Rotate");

	shape* s = pGraph->GetSelected();
	if (s) {
		s->Rotate();
	}
	else {
		pUI->PrintMessage("No shape selected to rotate.");
	}
}



opExit::opExit(controller* pCont) : operation(pCont) {}

opExit::~opExit() {}

void opExit::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();

	// Check for unsaved changes
	if (pGraph->HasUnsavedChanges()) {
		pUI->PrintMessage("unsaved changes. Do you want to save them before exiting? (y/n): ");
		string response;
		response = pUI->GetSrting();
	
		if (response == "y" || response == "Y") {
			opSave saveOperation(pControl);
			saveOperation.Execute();
		}
	}

	// Perform cleanup
	pUI->ClearStatusBar();
	pUI->ClearDrawArea();
	Sleep(100);
	pUI->PrintMessage("Cleaning...");
	Sleep(100);
	pUI->PrintMessage("Exiting the program...");
	Sleep(100);
	exit(0);
}
DelShape::DelShape(controller* pCont) :operation(pCont)
{



}

DelShape::~DelShape() {}

void DelShape::Execute()
{

	Point p;
	GUI* pUI = pControl->GetUI();

	pUI->GetPointClicked(p.x, p.y);
	Graph* pGr = pControl->getGraph();

	pGr->DelShape(p);


}
opCopyShape::opCopyShape(controller* pCont) : operation(pCont)
{}

opCopyShape::~opCopyShape()
{}

void opCopyShape::Execute() {

	Point p;
	GUI* pUI = pControl->GetUI();
	pUI->GetPointClicked(p.x, p.y);
	string msg = "shape is copied";
	pUI->PrintMessage(msg);
	Graph* pGr = pControl->getGraph();
	pGr->copyShape(p);



}
opStickImage::opStickImage(controller* pCont) : operation(pCont)
{}

opStickImage::~opStickImage()
{}

void opStickImage::Execute() {


	GUI* pUI = pControl->GetUI();
	pUI->ClearStatusBar();
	pUI->PrintMessage("select shape to stick image");
	shape* Sh = pControl->getGraph()->GetSelected();
	pControl->getGraph()->StickImage(Sh);

}