#include "Rect.h"
#include <corecrt_math_defines.h>

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}
Triangle::Triangle(Point P1, Point P2, Point P3, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
    Corner1 = P1;
    Corner2 = P2;
    Corner3 = P3;
}

Triangle::~Triangle()
{}

void Triangle::Draw(GUI* pUI) const
{
    // Call GUI::DrawTriangle to draw a triangle on the screen
    pUI->DrawTriangle(Corner1, Corner2, Corner3, ShpGfxInfo);
}
Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
    Start = P1;
    End = P2;
}

Line::~Line()
{}

void Line::Draw(GUI* pUI) const
{
    // Call GUI::DrawLine to draw a line on the screen
    pUI->DrawLine(Start, End, ShpGfxInfo);
}





Square::Square(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{

    length = P1;
 
    width = P2;
    //width = length;
    //P2 = P1;

}
Square::~Square()
{}

void Square::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(length, width, ShpGfxInfo);
}
//

Circle::Circle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{

	coordinate = P1;
	radius = P2;

}

Circle::~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->Draw_Circle(coordinate, radius, ShpGfxInfo);
}
bool Rect::checkInside(Point P)
{
    if (P.x >= Corner1.x && P.x <= Corner2.x && P.y >= Corner1.y && P.y <= Corner2.y) { return true; }

    else {
        return false;
    }
}
double TriangleArea(Point A, Point B, Point C) {
    return abs((A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0);
}

bool Triangle::checkInside(Point P) {
    // Calculate the area of the triangle
    double A = TriangleArea(Corner1, Corner2, Corner3);

    // Calculate the areas of the triangles formed with the point P
    double A1 = TriangleArea(P, Corner1, Corner2);
    double A2 = TriangleArea(P, Corner2, Corner3);
    double A3 = TriangleArea(P, Corner3, Corner1);

    // Check if the sum of the areas is equal to the area of the triangle
    return (A == A1 + A2 + A3);
}
bool Line::checkInside(Point P)
{
    if (P.x >= Start.x && P.x <= End.x && P.y >= Start.y && P.y <= End.y) { return true; }

    else {
        return false;
    }
}



bool Square::checkInside(Point P)
{
    if (P.x >= length.x && P.x <= width.x && P.y >= length.y && P.y <= width.y) { return true; }
    else {
        return false;
    }
}
bool Circle::checkInside(Point P)
{
    if (sqrt(pow(P.x - coordinate.x, 2)) <= sqrt(pow(radius.x - coordinate.x, 2)) && sqrt(pow(P.y - coordinate.y, 2)) <= sqrt(pow(P.y - radius.y, 2))) { return true; }

    else {
        return false;
    }
}
void Rect::Save(ofstream& outFile)  {
    outFile << "RECT " << shapeID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";
    outFile << ColorToString(ShpGfxInfo.DrawClr) << " " << ColorToString(ShpGfxInfo.FillClr) << " " << ShpGfxInfo.BorderWdth << " ";
    outFile << ShpGfxInfo.isFilled << " " << ShpGfxInfo.isSelected << endl;
}

void Rect::Load(ifstream& inFile) {
    string drawColor, fillColor;
    inFile >> shapeID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
    inFile >> drawColor >> fillColor >> ShpGfxInfo.BorderWdth;
    inFile >> ShpGfxInfo.isFilled >> ShpGfxInfo.isSelected;
    ShpGfxInfo.DrawClr = StringToColor(drawColor);
    ShpGfxInfo.FillClr = StringToColor(fillColor);
}
void Triangle::Save(ofstream& outFile) {
    outFile << "TRIANGLE " << shapeID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << Corner3.x << " " << Corner3.y << " ";
    outFile << ColorToString(ShpGfxInfo.DrawClr) << " " << ColorToString(ShpGfxInfo.FillClr) << " " << ShpGfxInfo.BorderWdth << " ";
    outFile << ShpGfxInfo.isFilled << " " << ShpGfxInfo.isSelected << endl;
}

void Triangle::Load(ifstream& inFile) {
    string drawColor, fillColor;
    inFile >> shapeID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y;
    inFile >> drawColor >> fillColor >> ShpGfxInfo.BorderWdth;
    inFile >> ShpGfxInfo.isFilled >> ShpGfxInfo.isSelected;
    ShpGfxInfo.DrawClr = StringToColor(drawColor);
    ShpGfxInfo.FillClr = StringToColor(fillColor);
}

void Line::Save(ofstream& outFile) {
    outFile << "LINE " << shapeID << " " << Start.x << " " << Start.y << " " << End.x << " " << End.y << " ";
    outFile << ColorToString(ShpGfxInfo.DrawClr) << " " << ColorToString(ShpGfxInfo.FillClr) << " " << ShpGfxInfo.BorderWdth << " ";
    outFile << ShpGfxInfo.isFilled << " " << ShpGfxInfo.isSelected << endl;
}

void Line::Load(ifstream& inFile) {
    string drawColor, fillColor;
    inFile >> shapeID >> Start.x >> Start.y >> End.x >> End.y;
    inFile >> drawColor >> fillColor >> ShpGfxInfo.BorderWdth;
    inFile >> ShpGfxInfo.isFilled >> ShpGfxInfo.isSelected;
    ShpGfxInfo.DrawClr = StringToColor(drawColor);
    ShpGfxInfo.FillClr = StringToColor(fillColor);
}

void Square::Save(ofstream& outFile) {
    outFile << "SQUARE " << shapeID << " " << length.x << " " << length.y << " " << width.x << " " << width.y << " ";
    outFile << ColorToString(ShpGfxInfo.DrawClr) << " " << ColorToString(ShpGfxInfo.FillClr) << " " << ShpGfxInfo.BorderWdth << " ";
    outFile << ShpGfxInfo.isFilled << " " << ShpGfxInfo.isSelected << endl;
}

void Square::Load(ifstream& inFile) {
    string drawColor, fillColor;
    inFile >> shapeID >> length.x >> length.y >> width.x >> width.y;
    inFile >> drawColor >> fillColor >> ShpGfxInfo.BorderWdth;
    inFile >> ShpGfxInfo.isFilled >> ShpGfxInfo.isSelected;
    ShpGfxInfo.DrawClr = StringToColor(drawColor);
    ShpGfxInfo.FillClr = StringToColor(fillColor);
}
void Circle::Save(ofstream& outFile)  {
    outFile << "CIRCLE " << shapeID << " " << coordinate.x << " " << coordinate.y << " " << radius.x << " " << radius.y << " ";
    outFile << ColorToString(ShpGfxInfo.DrawClr) << " " << ColorToString(ShpGfxInfo.FillClr) << " " << ShpGfxInfo.BorderWdth << " ";
    outFile << ShpGfxInfo.isFilled << " " << ShpGfxInfo.isSelected << endl;
}

void Circle::Load(ifstream& inFile) {
    string drawColor, fillColor;
    inFile >> shapeID >> coordinate.x >> coordinate.y >> radius.x >> radius.y;
    inFile >> drawColor >> fillColor >> ShpGfxInfo.BorderWdth;
    inFile >> ShpGfxInfo.isFilled >> ShpGfxInfo.isSelected;
    ShpGfxInfo.DrawClr = StringToColor(drawColor);
    ShpGfxInfo.FillClr = StringToColor(fillColor);
}

//Poly::Poly(Point p1, Point center, int vertices_num, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
//{
//    p = p1;
//    this->center = center;
//    this->vertices_num = vertices_num;
//    x = new int[vertices_num];
//    y = new int[vertices_num];
//}



//Poly::~Poly()
//
//{
//    delete[] x;
//    delete[] y;
//}
//
//void Poly::Draw(GUI* pUI) const
//{
//    double distance = sqrt(pow(p.x - center.x, 2) + pow(p.y - center.y, 2));
//
//    for (int i = 0; i < vertices_num; i++) {
//        double p_x = center.x + distance * cos(i * 2 * M_PI / vertices_num);
//        double p_y = center.y + distance * sin(i * 2 * M_PI / vertices_num);
//        x[i] = p_x;
//        y[i] = p_y;
//    }
//    pUI->DrawPoly(x, y, vertices_num, ShpGfxInfo);
//}
Oval::Oval(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
    p = P1;
    w = P2;
}

Oval::~Oval()
{}

void Oval::Draw(GUI* pUI) const
{
    //Call Output::DrawRect to draw a rectangle on the screen	
    pUI->Draw_Oval(p, w, ShpGfxInfo);
}

bool Oval::checkInside(Point P)
{


    Point c, a;
    c.x = (p.x + w.x) / 2;
    c.y = (p.y + w.y) / 2;
    a.x = (w.x - p.x) / 2;
    a.y = (w.y - p.y) / 2;

    //((x - h) ^ 2) / a ^ 2 + ((y - k) ^ 2) / b ^ 2 <= 1
    if (pow(P.x - c.x, 2) / pow(a.x, 2) + pow(P.y - c.y, 2) / pow(a.y, 2) <= 1) { return true; }


    return false;

}


//bool Poly::checkInside(Point P)
//{
//    int i, j;
//    bool result = false;
//    for (i = 0, j = vertices_num - 1; i < vertices_num; j = i++) {
//        if ((y[i] > P.y) != (y[j] > P.y) &&
//            (P.x < (x[j] - x[i]) * (P.y - y[i]) / (y[j] - y[i]) + x[i])) {
//            result = !result;
//        }
//    }
//    return result;
//}

void Oval::Save(ofstream& outFile) {
    outFile << "OVAL " << shapeID << " " << p.x << " " << p.y << " " << w.x << " " << w.y << " ";
    outFile << ColorToString(ShpGfxInfo.DrawClr) << " " << ColorToString(ShpGfxInfo.FillClr) << " " << ShpGfxInfo.BorderWdth << " ";
    outFile << ShpGfxInfo.isFilled << " " << ShpGfxInfo.isSelected << endl;
}

void Oval::Load(ifstream& inFile) {
    string drawColor, fillColor;
    inFile >> shapeID >> p.x >> p.y >> w.x >> w.y;
    inFile >> drawColor >> fillColor >> ShpGfxInfo.BorderWdth;
    inFile >> ShpGfxInfo.isFilled >> ShpGfxInfo.isSelected;
    ShpGfxInfo.DrawClr = StringToColor(drawColor);
    ShpGfxInfo.FillClr = StringToColor(fillColor);
}

//void Poly::Save(ofstream& outFile) {
//    outFile << "POLY " << shapeID << " " << p.x << " " << p.y << " " << center.x << " " << center.y << " " << vertices_num << " ";
//    outFile << ColorToString(ShpGfxInfo.DrawClr) << " " << ColorToString(ShpGfxInfo.FillClr) << " " << ShpGfxInfo.BorderWdth << " ";
//    outFile << ShpGfxInfo.isFilled << " " << ShpGfxInfo.isSelected << endl;
//}
//
//void Poly::Load(ifstream& inFile) {
//    string drawColor, fillColor;
//    inFile >> shapeID >> p.x >> p.y >> center.x >> center.y >> vertices_num;
//    inFile >> drawColor >> fillColor >> ShpGfxInfo.BorderWdth;
//    inFile >> ShpGfxInfo.isFilled >> ShpGfxInfo.isSelected;
//    ShpGfxInfo.DrawClr = StringToColor(drawColor);
//    ShpGfxInfo.FillClr = StringToColor(fillColor);
//
//    delete[] x;
//    delete[] y;
//    x = new int[vertices_num];
//    y = new int[vertices_num];
//}
void RotatePoint(Point& p, const Point& center) {
    int x = p.x - center.x;
    int y = p.y - center.y;
    p.x = center.x - y;
    p.y = center.y + x;
}
void Rect::Rotate() {
    Point center;
    center.x = (Corner1.x + Corner2.x) / 2;
    center.y = (Corner1.y + Corner2.y) / 2;

    RotatePoint(Corner1, center);
    RotatePoint(Corner2, center);
}

void Rect::Resize(double b)
{
}

void Triangle::Rotate() {
    Point center;
    center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
    center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;

    RotatePoint(Corner1, center);
    RotatePoint(Corner2, center);
    RotatePoint(Corner3, center);
}

void Triangle::Resize(double b)
{
}

void Line::Rotate() {
    Point center;
    center.x = (Start.x + End.x) / 2;
    center.y = (Start.y + End.y) / 2;

    RotatePoint(Start, center);
    RotatePoint(End, center);
}

void Line::Resize(double b)
{
}




void Square::Rotate() {
    Point center;
    center.x = (length.x + width.x) / 2;
    center.y = (length.y + width.y) / 2;

    RotatePoint(length, center);
    RotatePoint(width, center);
}

void Square::Resize(double b)
{
}

void Oval::Rotate() {
    Point center;
    center.x = (p.x + w.x) / 2;
    center.y = (p.y + w.y) / 2;

    RotatePoint(p, center);
    RotatePoint(w, center);
}

void Oval::Resize(double b)
{
}


void Circle::Rotate() {

}

void Circle::Resize(double b)
{
}

