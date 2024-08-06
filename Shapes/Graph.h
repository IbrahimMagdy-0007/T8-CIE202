#pragma once
#include "Shape.h"
#include <fstream>
#include <iostream>

using namespace std;

//forward decl
class GUI;

//A class that is responsible on everything related to shapes
class Graph
{
	enum { maxShapeCount = 1000 };
private:
	shape* shapesList[maxShapeCount]; //a container to hold all shapes							   
	int shapeCount;			// Actual number of shapes stored in the list
	shape* selectedShape;	//pointer to the currently selected shape
	shape* CreateShape(const string& shapeType);
	bool unsavedChanges; 


public:
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	shape* GetSelected() const;

	void SetUnsavedChanges(bool value);
	bool HasUnsavedChanges() const;

	void save(ofstream& outfile);	//Save all shapes to a file
	void load(ifstream& inputfile);	//Load all shapes from a file
	shape* Getshape(Point P) const;
	shape* DelShape(Point P);
	shape* GetSelected2();
	void StickImage(shape* s);
	shape* copyShape(Point p);
};
