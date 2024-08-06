#pragma once

#include "shape.h"
#include "..\CMUgraphicsLib\colors.h"
#include <iostream>
#include<fstream>

class Rect : public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	Rect(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Rect();
	virtual void Draw(GUI* pUI) const;
	virtual bool checkInside(Point P)override;


	virtual void Save(ofstream& outFile)  override;
	virtual void Load(ifstream& inFile) override;
	void Rotate();
	void Resize(double b);


};
class Triangle : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	Triangle(Point, Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Triangle();
	virtual void Draw(GUI* pUI) const;
	virtual bool checkInside(Point P)override;
	virtual void Save(ofstream& outFile)  override;
	virtual void Load(ifstream& inFile) override;
	void Rotate();
	void Resize(double b);



};
class Line : public shape
{
private:
	Point Start; // Starting point of the line
	Point End;   // Ending point of the line
public:
	Line(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
	virtual bool checkInside(Point P)override;
	virtual void Save(ofstream& outFile)  override;
	virtual void Load(ifstream& inFile) override;
	void Rotate();
	void Resize(double b);


};

class Square : public shape
{
private:
	Point length;
	Point width;
public:
	Square(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Square();
	virtual void Draw(GUI* pUI) const;
	virtual bool checkInside(Point P)override;
	virtual void Save(ofstream& outFile)  override;
	virtual void Load(ifstream& inFile) override;
	void Rotate();
	void Resize(double b);


};




class Circle : public shape
{
private:
	Point coordinate;
	Point radius;

public:
	Circle(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Circle();
	virtual void Draw(GUI* pUI) const;
	virtual bool checkInside(Point P)override;
	virtual void Save(ofstream& outFile)  override;
	virtual void Load(ifstream& inFile) override;
	void Rotate();
	void Resize(double b);

};

class Oval : public shape
{
private:
	Point p;
	Point w;
public:
	Oval(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Oval();
	virtual void Draw(GUI* pUI) const;
	virtual bool checkInside(Point P)override;
	virtual void Save(ofstream& outFile)  override;
	virtual void Load(ifstream& inFile) override;
	void Rotate();
	void Resize(double b);


};
//class Poly : public shape
//{
//private:
//	Point p, center;
//	int  vertices_num;
//	int* x = nullptr;
//	int* y = nullptr;
//	GfxInfo shapeGfxInfo;
//public:
//	Poly(Point, Point, int, GfxInfo shapeGfxInfo);
//	virtual ~Poly();
//	virtual void Draw(GUI* pUI) const;
//	virtual bool checkInside(Point P)override;
//	virtual void Save(ofstream& outFile)  override;
//	virtual void Load(ifstream& inFile) override;
//
//	void Rotate();
//	void Resize(double b);
//
//};