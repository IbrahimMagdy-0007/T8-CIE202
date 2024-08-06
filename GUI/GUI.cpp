#include "GUI.h"
#include <stdexcept>
#include <sstream>
#include <iostream>

GUI::GUI()
{

	width = 1400;
	height = 700;
	wx = 5;
	wy = 5;

	
	StatusBarHeight = 50;
	ToolBarHeight = 50;
	MenuIconWidth = 60;
	DrawColor = DARKGREEN;	//default Drawing color
	FillColor = YELLOW;	//default Filling color
	MsgColor = BLUE;		//Messages color
	BkGrndColor = WHITE;	//Background color
	HighlightColor = DARKGRAY;	//This color should NOT be used to draw shapes. use it for highlight only
	StatusBarColor = LIGHTGRAY;
	PenWidth = 3;	//default width of the shapes frames


	//Create the output window
	pWind = CreateWind(width, height, wx, wy);
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - PAINT ^ ^ PLAY - - - - - - - - - -");

	CreateDrawToolBar();
	CreateStatusBar();
}




//======================================================================================//
//								Input Functions										//
//======================================================================================//
void GUI::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

//void GUI::GetPointClicked(int& x,int& y) const
//{
//	pWind->WaitMouseClick(x,y);	//Wait for mouse click
//}


string GUI::GetSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if( Label.size() > 0)	
				Label.resize(Label.size() - 1);
			else
				Key = '\0';		
		else
			Label += Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired operation
operationType GUI::GetUseroperation() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);    //Get the coordinates of the user click

	if (y >= 0 && y < ToolBarHeight)
	{
		int ClickedIconOrder = (x / MenuIconWidth);

		switch (ClickedIconOrder)
		{
		case ICON_RECT:
			PrintMessage("Rectangle tool selected");
			return DRAW_RECT;
		case ICON_TRI:
			PrintMessage("Triangle tool selected");
			return DRAW_TRI;
		case ICON_line:
			PrintMessage("Line tool selected");
			return DRAW_LINE;
		case ICON_square:
			PrintMessage("Square tool selected");
			return DRAW_SQUARE;
		case ICON_circle:
			PrintMessage("Circle tool selected");
			return DRAW_CIRC;
		case ICON_oval:
			PrintMessage("Oval tool selected");
			return DRAW_OVAL;
		case ICON_ploy:
			PrintMessage("Polygon tool selected");
			return DRAW_POLY;
		case ICON_select:
			PrintMessage("Select tool selected");
			return SELECT;
		//case ICON_colorPal:
			//PrintMessage("Color Palette tool selected");
			//return CHOSE_COLOR;
		case ICON_penColor:
			PrintMessage(" choose draw color");
			return CHNG_generalPENCOLOR;
		case ICON_GeneralFillColor:
			PrintMessage("chose fill color");
			return CHNG_generalFILLCOLOR;
		//case ICON_borderColor:
			//PrintMessage(" SINGLE Border Color tool selected");
			//return CHNG_PENCOLOR;
		//c/ase ICON_fillColor:
			//PrintMessage("SINGLE Fill Color tool selected");
			//return CHNG_FILLCOLOR;
		case ICON_delete:
			PrintMessage("Delete tool selected");
			return DEL;
		case ICON_Save:
			PrintMessage("Save tool selected");
			return SAVE;
		case ICON_load:
			PrintMessage("Load tool selected");
			return LOAD;
		case ICON_resize:
			PrintMessage("Resize tool selected");
			return RESIZE;
		case ICON_rotate:
			PrintMessage("Rotate tool selected");
			return ROTATE;
		case ICON_copy:
			PrintMessage("Copy tool selected");
			return COPY;
		case ICON_cut:
			PrintMessage("Cut tool selected");
			return CUT;
		case ICON_paste:
			PrintMessage("Paste tool selected");
			return PASTE;
		case ICON_stick:
			PrintMessage("Stick tool selected");
			return STICK_IMAGE;
		case ICON_EXIT:
			PrintMessage("Exiting application");
			return EXIT;
		default:
			PrintMessage("No tool selected");
			return EMPTY;
		}
	}
	//[2] User clicks on the drawing area
	if (y >= ToolBarHeight && y < height - StatusBarHeight)
	{
		return DRAWING_AREA;
	}

	//[3] User clicks on the status bar
	return STATUS;
	

}
////////////////////////////////////////////////////



//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////
void GUI::CreateDrawToolBar() 
{

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu icon
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuIcon
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_RECT] = "images\\MenuIcons\\Menu_Rect.jpg";
	MenuIconImages[ICON_TRI] = "images\\MenuIcons\\Menu_Tri.jpg";
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\Menu_Exit.jpg";
	MenuIconImages[ICON_line] = "images\\MenuIcons\\Line.jpg";
	MenuIconImages[ICON_square] = "images\\MenuIcons\\square.jpg";
	MenuIconImages[ICON_circle] = "images\\MenuIcons\\Circle.jpg";
	MenuIconImages[ICON_oval] = "images\\MenuIcons\\oval.jpg";
	MenuIconImages[ICON_ploy] = "images\\MenuIcons\\poly.jpg";
	MenuIconImages[ICON_select] = "images\\MenuIcons\\select.jpg";
	//MenuIconImages[ICON_colorPal] = "images\\MenuIcons\\colorPal.jpg";
	MenuIconImages[ICON_penColor] = "images\\MenuIcons\\PenColor.jpg";
	MenuIconImages[ICON_GeneralFillColor] = "images\\MenuIcons\\Menu_GeneralFillColor.jpg";
	//MenuIconImages[ICON_borderColor] = "images\\MenuIcons\\border.jpg";
	//MenuIconImages[ICON_fillColor] = "images\\MenuIcons\\Menu_FillColor.jpg";
	MenuIconImages[ICON_delete] = "images\\MenuIcons\\delete.jpg";
	MenuIconImages[ICON_Save] = "images\\MenuIcons\\save.jpg";
	MenuIconImages[ICON_load] = "images\\MenuIcons\\upload.jpg";
	MenuIconImages[ICON_resize] = "images\\MenuIcons\\resize.jpg";
	MenuIconImages[ICON_rotate] = "images\\MenuIcons\\rotate.jpg";
	MenuIconImages[ICON_copy] = "images\\MenuIcons\\copy.jpg";
	MenuIconImages[ICON_cut] = "images\\MenuIcons\\cut.jpg";
	MenuIconImages[ICON_paste] = "images\\MenuIcons\\paste.jpg";
	MenuIconImages[ICON_stick] = "images\\MenuIcons\\stick.jpg";
	//TODO: Prepare images for each menu icon and add it to the list

	//Draw menu icon one image at a time
	for (int i = 0; i < DRAW_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////



void GUI::ClearDrawArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, height - (int)(0.75 * StatusBarHeight), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////


void GUI::setDrawColor(color Draw_Color) {

	DrawColor = Draw_Color;
}
void GUI::setFillolor(color Draw_Color) {

	FillColor = Draw_Color;
}




color GUI::getColorFromPalette()
{
	int x, y;
	window* NewWind = CreateWind(400, 300, 400, 70);
	NewWind->DrawImage("images\\MenuIcons\\basic-color-palette.jpg", 0, 0, 500, 300);
	NewWind->ChangeTitle("color Palette");
	NewWind->WaitMouseClick(x, y);
	color N = NewWind->GetColor(x, y);
	delete NewWind;

	// Print the RGB values of the selected color
	std::ostringstream oss;
	cout << "Selected Color - R: " << N.ucRed << ", G: " << N.ucGreen << ", B: " << N.ucBlue;
	PrintMessage(oss.str());

	return N;	
}

color GUI::getDrawColor() {


	return DrawColor;
}



////////////////////////////////////////////////
color GUI::getCrntDrawColor() const	//get current drwawing color
{
	return DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{
	return FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int GUI::getCrntPenWidth() const		//get current pen width
{
	return PenWidth;
}

//======================================================================================//
//								shapes Drawing Functions								//
//======================================================================================//

void GUI::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
//	pWind->DrawEllipse()
}
void GUI::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo) const
{
	color DrawingClr;
	if (LineGfxInfo.isSelected)
		DrawingClr = HighlightColor;
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, LineGfxInfo.BorderWdth);
	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y);
}
void GUI::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo) const
{
	color DrawingClr;
	if (TriGfxInfo.isSelected)
		DrawingClr = HighlightColor;
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, TriGfxInfo.BorderWdth);

	if (TriGfxInfo.isFilled)
	{
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
	{
		pWind->SetBrush(BkGrndColor);
	}

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y); // Draw the triangle
}

void GUI::Draw_square(Point P1, Point P2, GfxInfo squGfxInfo) const
{

	//Point P3;

	color DrawingClr;
	if (squGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = squGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, squGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (squGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(squGfxInfo.FillClr);
	}
	else {
		style = FRAME;
	}

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x,P2.y, style);

	//P1 = P2;
	/*double Px ,Py;
	Px = Py;*/
	

	//int center1 = (P1.x + P2.x) / 2;
	//int center2= (P2.y + P2.y) / 2;

	 
		 //P1 = { center1 - halfSize,center2 + halfSize }; // Top left corner
		 //P2 = { center.x + halfSize, center.y + halfSize }; // Top right corner
	
	//const int Size = sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2)) / 2;

	//pWind->DrawPolygon(P1.x, P2.x, Size, style);

	//int px[2] = { P1.x, P2.x };
	//int py[2] = { P1.x, P2.x };
	//pWind->DrawPolygon(px, px, size);
}


void GUI::Draw_Circle(Point P1, Point P2, GfxInfo cirGfxInfo) const
{
	color DrawingClr;
	if (cirGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = cirGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, cirGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (cirGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(cirGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawCircle(P1.x, P1.y, sqrt(pow(P2.x - P1.x, 2) + pow(P2.y - P1.y, 2)), style);
}

//void GUI::DrawPoly(int* x, int* y, int vertices_num, GfxInfo PolyGfxInfo) const
//{
//	color DrawingClr;
//	if (
//		PolyGfxInfo.isSelected)	//shape is selected
//		DrawingClr = HighlightColor; //shape should be drawn highlighted
//	else
//		DrawingClr = PolyGfxInfo.DrawClr;
//
//	pWind->SetPen(DrawingClr, PolyGfxInfo.BorderWdth);	//Set Drawing color & width
//
//	drawstyle style;
//	if (PolyGfxInfo.isFilled)
//	{
//		style = FILLED;
//		pWind->SetBrush(PolyGfxInfo.FillClr);
//	}
//	else
//		style = FRAME;
//
//	pWind->DrawPolygon(x, y, vertices_num, style);
//	ClearStatusBar();
//
//}
void GUI::Draw_Oval(Point P1, Point P2, GfxInfo OVALGfxInfo) const
{
	color DrawingClr;
	if (OVALGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = OVALGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, OVALGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (OVALGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(OVALGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);

	//	pWind->DrawEllipse()
}

















//
//void GUI::Draw_Circle(Point P1, Point P2, GfxInfo cirGfxInfo) const
//{
//	color DrawingClr;
//	if (cirGfxInfo.isSelected)	//shape is selected
//		DrawingClr = HighlightColor; //shape should be drawn highlighted
//	else
//		DrawingClr = cirGfxInfo.DrawClr;
//
//	pWind->SetPen(DrawingClr, cirGfxInfo.BorderWdth);	//Set Drawing color & width
//
//	drawstyle style;
//	if (cirGfxInfo.isFilled)
//	{
//		style = FILLED;
//		pWind->SetBrush(cirGfxInfo.FillClr);
//	}
//	else
//		style = FRAME;
//
//	pWind->DrawCircle(P1.x, P1.y, P2.x, style);
//
//
//}















//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}

