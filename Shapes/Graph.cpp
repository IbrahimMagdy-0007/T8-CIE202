#include "Graph.h"
#include "../GUI/GUI.h"
#include "Rect.h"
#include <fstream>

//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp) {
    //Add a new shape to the shapes list
    if (shapeCount < maxShapeCount) {
        shapesList[shapeCount++] = pShp;
        SetUnsavedChanges(true);
    }
}

////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const {
    pUI->ClearDrawArea();
    for (int i = 0; i < shapeCount; i++)
        shapesList[i]->Draw(pUI);
}



shape* Graph::Getshape(Point P) const {
    //If a shape is found return a pointer to it.
    //if this point (x,y) does not belong to any shape return NULL

    shape* selectedShape = nullptr;
    ///Add your code here to search for a shape given a point x,y    

    for (int i = 0; i < shapeCount; i++) {
        shapesList[i]->SetSelected(false);
    }
    for (int i = 0; i < shapeCount; i++) {
        if (shapesList[i]->checkInside(P)) {
            selectedShape = shapesList[i];
        }
    }

    if (selectedShape != nullptr) {
        selectedShape->SetSelected(true);
    }

    return nullptr;
}

shape* Graph::GetSelected() const {
    for (int i = 0; i < shapeCount; ++i) {
        if (shapesList[i]->IsSelected()) {
            return shapesList[i];
        }
    }
    return nullptr; // Return nullptr if no shape is selecte
}

Graph::Graph() : shapeCount(0), selectedShape(nullptr), unsavedChanges(false) {}

Graph::~Graph() {
    for (int i = 0; i < shapeCount; ++i) {
        delete shapesList[i];
    }
}

shape* Graph::CreateShape(const string& shapeType) {
    if (shapeType == "RECT") {
        return new Rect(Point(), Point(), GfxInfo());
    }
    else if (shapeType == "TRIANGLE") {
        return new Triangle(Point(), Point(), Point(), GfxInfo());
    }
    else if (shapeType == "LINE") {
        return new Line(Point(), Point(), GfxInfo());
    }
    else if (shapeType == "SQUARE") {
        return new Square(Point(), Point(), GfxInfo());
    }
    else if (shapeType == "CIRCLE") {
        return new Circle(Point(), Point(), GfxInfo());
    }
    else if (shapeType == "OVAL") {
        return new Oval(Point(), Point(), GfxInfo());
    }
    //else if (shapeType == "POLY") {
    //    return new Poly(Point(), Point(), 0, GfxInfo()); 
    return nullptr;
}

void Graph::save(ofstream& outfile) {
    if (outfile.is_open()) {
        outfile << shapeCount << endl;
        for (int i = 0; i < shapeCount; i++) {
            shapesList[i]->Save(outfile);
        }
        SetUnsavedChanges(false);
    }
}

void Graph::load(ifstream& inputfile) {
    if (inputfile.is_open()) {
        int count;
        inputfile >> count;
        shapeCount = 0;
        for (int i = 0; i < count; i++) {
            std::string shapeType;
            inputfile >> shapeType;
            shape* pShp = CreateShape(shapeType);
            if (pShp) {
                pShp->Load(inputfile);
                Addshape(pShp);
            }
        }
        SetUnsavedChanges(false);
    }
}

// Implement other methods as needed...

//==================================================================================//
//						Unsaved Changes Management Functions						//
//==================================================================================//

void Graph::SetUnsavedChanges(bool value) {
    unsavedChanges = value;
}

bool Graph::HasUnsavedChanges() const {
    return unsavedChanges;
}
shape* Graph::DelShape(Point p)
{

    shape* selectedShape = nullptr;
    for (int i = 0; i < shapeCount; i++) {

        if (shapesList[i]->checkInside(p))
        {

            selectedShape = shapesList[i];
            delete selectedShape;

            for (int j = i; j < shapeCount; j++) {

                shapesList[j] = shapesList[j + 1];
                shapeCount--;
            }

        }

    }


    return nullptr;


}
void Graph::StickImage(shape* Sh) {
    for (int i = 0; i < shapeCount; i++) {
        if (shapesList[i]->IsSelected())
            shapesList[i]->~shape();
    }
}

shape* Graph::copyShape(Point P)
{

    shape* selectShape = nullptr;
    for (int i = 0; i <= shapeCount; i++) {
        if (shapesList[i]->checkInside(P)) {
            selectedShape = shapesList[i];

        }

        return selectShape;


    }
}

shape* Graph::GetSelected2() {

    return selectedShape;
}