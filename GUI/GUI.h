#pragma once



#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

#include <string>
using namespace std;

struct Point	//To be used for shapes points
{
	int x, y;
};

struct GfxInfo	//Graphical info common for all shapes (you may add more members)
{
	color DrawClr;	//Draw color of the shape
	color FillClr;	//Fill color of the shape
	bool isFilled;	//shape Filled or not
	int BorderWdth;	//Width of shape borders
	bool isSelected;	//true if the shape is selected.
};




class GUI
{
	enum MenuIcon //The icons of the menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_RECT,		//Recangle icon in menu
		ICON_TRI,		//Triangle icon in menu
		ICON_line,
		ICON_square,
		ICON_circle,
		ICON_oval,
		ICON_ploy,
		ICON_select,
		//ICON_colorPal,
		ICON_penColor,
		ICON_GeneralFillColor,
		//ICON_borderColor,
		//ICON_fillColor,
		ICON_delete,
		ICON_Save,
		ICON_load,
		ICON_resize,
		ICON_rotate,
		ICON_copy,
		ICON_cut,
		ICON_paste,
		ICON_stick,
		//TODO: Add more icons names here

		ICON_EXIT,		//Exit icon

		DRAW_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};



	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuIconWidth;		//Width of each icon in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor ;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed



	window* pWind;

public:

	GUI();

	// Input Functions  ---------------------------
	void GetPointClicked(int& x, int& y) const;//Get coordinate where user clicks
	
		//void GetPointClicked_circle(int& radius,int& y2 ) const;//Get coordinate where user clicks


	string GetSrting() const;	 //Returns a string entered by the user

	operationType GetUseroperation() const; //Read the user click and map to an operation

	// Output Functions  ---------------------------
	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar();	//creates Draw mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void setDrawColor(color Draw_Color);//set drawcolor
	void setFillolor(color Draw_Color);
	color getColorFromPalette();
	color getDrawColor();

	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- shapes Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const;  //Draw a rectangle
	void DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo) const;
	void DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo) const;
	void Draw_square(Point P1, Point P2, GfxInfo squareGfxInfo) const;//Draw a Square
	void Draw_Circle(Point P1, Point P2, GfxInfo circleGfxInfo) const;  //Draw a circle
	void Draw_Oval(Point P1, Point P2, GfxInfo OVALGfxInfo)const;
	//void DrawPoly(int* x, int* y, int vertices_num, GfxInfo PolyGfxInfo) const;

	
	///Make similar functions for drawing all other shapes.

	void PrintMessage(string msg) const;	//Print a message on Status bar


	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width


	~GUI();
};

