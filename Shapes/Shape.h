#pragma once
#include "..\defs.h"
#include "..\GUI\GUI.h"


//Base class for all shapes
class shape
{
protected:
	int ID;		//Each shape has an ID
	GfxInfo ShpGfxInfo;	//shape graphis info
	int shapeID = 2; // Declare shapeID

	/// Add more parameters if needed.

public:
	shape(GfxInfo shapeGfxInfo);
	virtual ~shape() {}
	void SetSelected(bool s);	//select/unselect the shape
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(GUI* pUI) const = 0;		//Draw the shape

	void ChngDrawClr(color Dclr);	//changes the shape's drawing color
	void ChngFillClr(color Fclr);	//changes the shape's filling color

	virtual bool checkInside(Point P) = 0;
	virtual void Save(ofstream& outFile)  = 0;
	virtual void Load(ifstream& inFile) = 0;
	string ColorToString(color anycolor);
	color StringToColor(const string& colorStr);




	//////////////////////////void display_selected_info(bool IsSelected())const;


	///The following functions should be supported by the shape class
	///It should be overridden by each inherited shape

	///Decide the parameters that you should pass to each function	


	virtual void Rotate() = 0;	//Rotate the shape
	virtual void Resize(double b) = 0;	//Resize the shape
	//virtual void Move() = 0;		//Move the shape

	//virtual void Save(ofstream &OutFile) = 0;	//Save the shape parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the shape parameters to the file

	//virtual void PrintInfo(shape* Getshape) = 0;	//print all shape info on the status bar
};

