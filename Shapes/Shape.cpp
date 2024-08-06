#include "shape.h"

shape::shape(GfxInfo shapeGfxInfo)
{
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
}



bool shape::IsSelected() const
{
	return ShpGfxInfo.isSelected;
}

void shape::ChngDrawClr(color Dclr)
{
	ShpGfxInfo.DrawClr = Dclr;
}

void shape::ChngFillClr(color Fclr)
{
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr;
}

void shape::SetSelected(bool s)
{


	ShpGfxInfo.isSelected = s;
	//ShpGfxInfo.isFilled = s;
	//ShpGfxInfo.FillClr = s;

}

//void shape::display_selected_info(bool IsSelected())const
//{
//	if(ShpGfxInfo.isSelected){ 
//
//}
string shape::ColorToString(color anycolor)
{
    if (anycolor == BLACK) return "BLACK";
    else if (anycolor == WHITE) return "WHITE";
    else if (anycolor == BLUE) return "BLUE";
    else if (anycolor == RED) return "RED";
    else if (anycolor == YELLOW) return "YELLOW";
    else if (anycolor == GREEN) return "GREEN";
    else if (anycolor == GREY || anycolor == GRAY) return "GREY";
    else if (anycolor == LIGHTGOLDENRODYELLOW) return "LIGHTGOLDENRODYELLOW";
    else if (anycolor == LIGHTGREY || anycolor == LIGHTGRAY) return "LIGHTGREY";
    else if (anycolor == DARKGREY || anycolor == DARKGRAY) return "DARKGREY";
    else if (anycolor == PURPLE) return "PURPLE";
    else if (anycolor == ORANGE) return "ORANGE";
    else if (anycolor == PINK) return "PINK";
    else if (anycolor == MAGENTA) return "MAGENTA";
    else if (anycolor == CYAN) return "CYAN";
    else if (anycolor == ORANGERED) return "ORANGERED";
    else if (anycolor == BROWN) return "BROWN";
    else if (anycolor == GOLD) return "GOLD";
    else if (anycolor == SNOW) return "SNOW";
    else if (anycolor == GHOSTWHITE) return "GHOSTWHITE";
    else if (anycolor == WHITESMOKE) return "WHITESMOKE";
    else if (anycolor == GAINSBORO) return "GAINSBORO";
    else if (anycolor == FLORALWHITE) return "FLORALWHITE";
    else if (anycolor == OLDLACE) return "OLDLACE";
    else if (anycolor == LINEN) return "LINEN";
    else if (anycolor == ANTIQUEWHITE) return "ANTIQUEWHITE";
    else if (anycolor == PAPAYAWHIP) return "PAPAYAWHIP";
    else if (anycolor == BLANCHEDALMOND) return "BLANCHEDALMOND";
    else if (anycolor == BISQUE) return "BISQUE";
    else if (anycolor == PEACHPUFF) return "PEACHPUFF";
    else if (anycolor == NAVAJOWHITE) return "NAVAJOWHITE";
    else if (anycolor == MOCCASIN) return "MOCCASIN";
    else if (anycolor == CORNSILK) return "CORNSILK";
    else if (anycolor == IVORY) return "IVORY";
    else if (anycolor == LEMONCHIFFON) return "LEMONCHIFFON";
    else if (anycolor == SEASHELL) return "SEASHELL";
    else if (anycolor == HONEYDEW) return "HONEYDEW";
    else if (anycolor == MINTCREAM) return "MINTCREAM";
    else if (anycolor == AZURE) return "AZURE";
    else if (anycolor == ALICEBLUE) return "ALICEBLUE";
    else if (anycolor == LAVENDER) return "LAVENDER";
    else if (anycolor == LAVENDERBLUSH) return "LAVENDERBLUSH";
    else if (anycolor == MISTYROSE) return "MISTYROSE";
    else if (anycolor == DARKSLATEGRAY || anycolor == DARKSLATEGREY) return "DARKSLATEGRAY";
    else if (anycolor == DIMGRAY || anycolor == DIMGREY) return "DIMGRAY";
    else if (anycolor == SLATEGRAY || anycolor == SLATEGREY) return "SLATEGRAY";
    else if (anycolor == LIGHTSLATEGRAY || anycolor == LIGHTSLATEGREY) return "LIGHTSLATEGRAY";
    else if (anycolor == MIDNIGHTBLUE) return "MIDNIGHTBLUE";
    else if (anycolor == NAVY || anycolor == NAVYBLUE) return "NAVY";
    else if (anycolor == CORNFLOWERBLUE) return "CORNFLOWERBLUE";
    else if (anycolor == DARKSLATEBLUE) return "DARKSLATEBLUE";
    else if (anycolor == SLATEBLUE) return "SLATEBLUE";
    else if (anycolor == MEDIUMSLATEBLUE) return "MEDIUMSLATEBLUE";
    else if (anycolor == LIGHTSLATEBLUE) return "LIGHTSLATEBLUE";
    else if (anycolor == MEDIUMBLUE) return "MEDIUMBLUE";
    else if (anycolor == ROYALBLUE) return "ROYALBLUE";
    else if (anycolor == DODGERBLUE) return "DODGERBLUE";
    else if (anycolor == DEEPSKYBLUE) return "DEEPSKYBLUE";
    else if (anycolor == SKYBLUE) return "SKYBLUE";
    else if (anycolor == LIGHTSKYBLUE) return "LIGHTSKYBLUE";
    else if (anycolor == STEELBLUE) return "STEELBLUE";
    else if (anycolor == LIGHTSTEELBLUE) return "LIGHTSTEELBLUE";
    else if (anycolor == LIGHTBLUE) return "LIGHTBLUE";
    else if (anycolor == POWDERBLUE) return "POWDERBLUE";
    else if (anycolor == PALETURQUOISE) return "PALETURQUOISE";
    else if (anycolor == DARKTURQUOISE) return "DARKTURQUOISE";
    else if (anycolor == MEDIUMTURQUOISE) return "MEDIUMTURQUOISE";
    else if (anycolor == TURQUOISE) return "TURQUOISE";
    else if (anycolor == LIGHTCYAN) return "LIGHTCYAN";
    else if (anycolor == CADETBLUE) return "CADETBLUE";
    else if (anycolor == MEDIUMAQUAMARINE) return "MEDIUMAQUAMARINE";
    else if (anycolor == AQUAMARINE) return "AQUAMARINE";
    else if (anycolor == DARKGREEN) return "DARKGREEN";
    else if (anycolor == DARKOLIVEGREEN) return "DARKOLIVEGREEN";
    else if (anycolor == DARKSEAGREEN) return "DARKSEAGREEN";
    else if (anycolor == SEAGREEN) return "SEAGREEN";
    else if (anycolor == MEDIUMSEAGREEN) return "MEDIUMSEAGREEN";
    else if (anycolor == LIGHTSEAGREEN) return "LIGHTSEAGREEN";
    else if (anycolor == PALEGREEN) return "PALEGREEN";
    else if (anycolor == SPRINGGREEN) return "SPRINGGREEN";
    else if (anycolor == LAWNGREEN) return "LAWNGREEN";
    else if (anycolor == CHARTREUSE) return "CHARTREUSE";
    else if (anycolor == MEDIUMSPRINGGREEN) return "MEDIUMSPRINGGREEN";
    else if (anycolor == GREENYELLOW) return "GREENYELLOW";
    else if (anycolor == LIMEGREEN) return "LIMEGREEN";
    else if (anycolor == YELLOWGREEN) return "YELLOWGREEN";
    else if (anycolor == FORESTGREEN) return "FORESTGREEN";
    else if (anycolor == OLIVEDRAB) return "OLIVEDRAB";
    else if (anycolor == DARKKHAKI) return "DARKKHAKI";
    else if (anycolor == KHAKI) return "KHAKI";
    else if (anycolor == PALEGOLDENROD) return "PALEGOLDENROD";
    else if (anycolor == LIGHTYELLOW) return "LIGHTYELLOW";
    else if (anycolor == LIGHTGOLDENROD) return "LIGHTGOLDENROD";
    else if (anycolor == GOLDENROD) return "GOLDENROD";
    else if (anycolor == DARKGOLDENROD) return "DARKGOLDENROD";
    else if (anycolor == ROSYBROWN) return "ROSYBROWN";
    else if (anycolor == INDIAN || anycolor == INDIANRED) return "INDIANRED";
    else if (anycolor == SADDLEBROWN) return "SADDLEBROWN";
    else if (anycolor == SIENNA) return "SIENNA";
    else if (anycolor == PERU) return "PERU";
    else if (anycolor == BURLYWOOD) return "BURLYWOOD";
    else if (anycolor == BEIGE) return "BEIGE";
    else if (anycolor == WHEAT) return "WHEAT";
    else if (anycolor == SANDYBROWN) return "SANDYBROWN";
    else if (anycolor == TAN) return "TAN";
    else if (anycolor == CHOCOLATE) return "CHOCOLATE";
    else if (anycolor == FIREBRICK) return "FIREBRICK";
    else if (anycolor == DARKSALMON) return "DARKSALMON";
    else if (anycolor == SALMON) return "SALMON";
    else if (anycolor == LIGHTSALMON) return "LIGHTSALMON";
    else if (anycolor == DARKORANGE) return "DARKORANGE";
    else if (anycolor == CORAL) return "CORAL";
    else if (anycolor == LIGHTCORAL) return "LIGHTCORAL";
    else if (anycolor == TOMATO) return "TOMATO";
    else if (anycolor == HOTPINK) return "HOTPINK";
    else if (anycolor == DEEPPINK) return "DEEPPINK";
    else if (anycolor == LIGHTPINK) return "LIGHTPINK";
    else if (anycolor == PALEVIOLETRED) return "PALEVIOLETRED";
    else if (anycolor == MAROON) return "MAROON";
    else if (anycolor == MEDIUMVIOLETRED) return "MEDIUMVIOLETRED";
    else if (anycolor == VIOLETRED) return "VIOLETRED";
    else if (anycolor == VIOLET) return "VIOLET";
    else if (anycolor == PLUM) return "PLUM";
    /*  else if (anycolor == ORCHID) return "ORCHID";
      else if (anycolor == MEDIUMORCHID) return "MEDIUMORCHID";
      else if (anycolor == DARKORCHID) return "DARKORCHID";
      else if (anycolor == DARKVIOLET) return "DARKVIOLET";
      else if (anycolor == BLUEVIOLET) return "BLUEVIOLET";
      else if (anycolor == MEDIUMPURPLE) return "MEDIUMPURPLE";
      else if (anycolor == THISTLE) return "THISTLE";
      else if (anycolor == DARKBLUE) return "DARKBLUE";
      else if (anycolor == DARKCYAN) return "DARKCYAN";
      else if (anycolor == DARKMAGENTA) return "DARKMAGENTA";
      else if (anycolor == DARKRED) return "DARKRED";
      else if (anycolor == LIGHTGREEN) return "LIGHTGREEN";*/
    return "COLOR";
}



color shape::StringToColor(const string& colorStr)
{
    if (colorStr == "BLACK") return BLACK;
    else if (colorStr == "WHITE") return WHITE;
    else if (colorStr == "BLUE") return BLUE;
    else if (colorStr == "RED") return RED;
    else if (colorStr == "YELLOW") return YELLOW;
    else if (colorStr == "GREEN") return GREEN;
    else if (colorStr == "GREY" || colorStr == "GRAY") return GREY;
    else if (colorStr == "LIGHTGOLDENRODYELLOW") return LIGHTGOLDENRODYELLOW;
    else if (colorStr == "LIGHTGREY" || colorStr == "LIGHTGRAY") return LIGHTGREY;
    else if (colorStr == "DARKGREY" || colorStr == "DARKGRAY") return DARKGREY;
    else if (colorStr == "PURPLE") return PURPLE;
    else if (colorStr == "ORANGE") return ORANGE;
    else if (colorStr == "PINK") return PINK;
    else if (colorStr == "MAGENTA") return MAGENTA;
    else if (colorStr == "CYAN") return CYAN;
    else if (colorStr == "ORANGERED") return ORANGERED;
    else if (colorStr == "BROWN") return BROWN;
    else if (colorStr == "GOLD") return GOLD;
    else if (colorStr == "SNOW") return SNOW;
    else if (colorStr == "GHOSTWHITE") return GHOSTWHITE;
    else if (colorStr == "WHITESMOKE") return WHITESMOKE;
    else if (colorStr == "GAINSBORO") return GAINSBORO;
    else if (colorStr == "FLORALWHITE") return FLORALWHITE;
    else if (colorStr == "OLDLACE") return OLDLACE;
    else if (colorStr == "LINEN") return LINEN;
    else if (colorStr == "ANTIQUEWHITE") return ANTIQUEWHITE;
    else if (colorStr == "PAPAYAWHIP") return PAPAYAWHIP;
    else if (colorStr == "BLANCHEDALMOND") return BLANCHEDALMOND;
    else if (colorStr == "BISQUE") return BISQUE;
    else if (colorStr == "PEACHPUFF") return PEACHPUFF;
    else if (colorStr == "NAVAJOWHITE") return NAVAJOWHITE;
    else if (colorStr == "MOCCASIN") return MOCCASIN;
    else if (colorStr == "CORNSILK") return CORNSILK;
    else if (colorStr == "IVORY") return IVORY;
    else if (colorStr == "LEMONCHIFFON") return LEMONCHIFFON;
    else if (colorStr == "SEASHELL") return SEASHELL;
    else if (colorStr == "HONEYDEW") return HONEYDEW;
    else if (colorStr == "MINTCREAM") return MINTCREAM;
    else if (colorStr == "AZURE") return AZURE;
    else if (colorStr == "ALICEBLUE") return ALICEBLUE;
    else if (colorStr == "LAVENDER") return LAVENDER;
    else if (colorStr == "LAVENDERBLUSH") return LAVENDERBLUSH;
    else if (colorStr == "MISTYROSE") return MISTYROSE;
    else if (colorStr == "DARKSLATEGRAY" || colorStr == "DARKSLATEGREY") return DARKSLATEGRAY;
    else if (colorStr == "DIMGRAY" || colorStr == "DIMGREY") return DIMGRAY;
    else if (colorStr == "SLATEGRAY" || colorStr == "SLATEGREY") return SLATEGRAY;
    else if (colorStr == "LIGHTSLATEGRAY" || colorStr == "LIGHTSLATEGREY") return LIGHTSLATEGRAY;
    else if (colorStr == "MIDNIGHTBLUE") return MIDNIGHTBLUE;
    else if (colorStr == "NAVY" || colorStr == "NAVYBLUE") return NAVY;
    else if (colorStr == "CORNFLOWERBLUE") return CORNFLOWERBLUE;
    else if (colorStr == "DARKSLATEBLUE") return DARKSLATEBLUE;
    else if (colorStr == "SLATEBLUE") return SLATEBLUE;
    else if (colorStr == "MEDIUMSLATEBLUE") return MEDIUMSLATEBLUE;
    else if (colorStr == "LIGHTSLATEBLUE") return LIGHTSLATEBLUE;
    else if (colorStr == "MEDIUMBLUE") return MEDIUMBLUE;
    else if (colorStr == "ROYALBLUE") return ROYALBLUE;
    else if (colorStr == "DODGERBLUE") return DODGERBLUE;
    else if (colorStr == "DEEPSKYBLUE") return DEEPSKYBLUE;
    else if (colorStr == "SKYBLUE") return SKYBLUE;
    else if (colorStr == "LIGHTSKYBLUE") return LIGHTSKYBLUE;
    else if (colorStr == "STEELBLUE") return STEELBLUE;
    else if (colorStr == "LIGHTSTEELBLUE") return LIGHTSTEELBLUE;
    else if (colorStr == "LIGHTBLUE") return LIGHTBLUE;
    else if (colorStr == "POWDERBLUE") return POWDERBLUE;
    else if (colorStr == "PALETURQUOISE") return PALETURQUOISE;
    else if (colorStr == "DARKTURQUOISE") return DARKTURQUOISE;
    else if (colorStr == "MEDIUMTURQUOISE") return MEDIUMTURQUOISE;
    else if (colorStr == "TURQUOISE") return TURQUOISE;
    else if (colorStr == "LIGHTCYAN") return LIGHTCYAN;
    else if (colorStr == "CADETBLUE") return CADETBLUE;
    else if (colorStr == "MEDIUMAQUAMARINE") return MEDIUMAQUAMARINE;
    else if (colorStr == "AQUAMARINE") return AQUAMARINE;
    else if (colorStr == "DARKGREEN") return DARKGREEN;
    else if (colorStr == "DARKOLIVEGREEN") return DARKOLIVEGREEN;
    else if (colorStr == "DARKSEAGREEN") return DARKSEAGREEN;
    else if (colorStr == "SEAGREEN") return SEAGREEN;
    else if (colorStr == "MEDIUMSEAGREEN") return MEDIUMSEAGREEN;
    else if (colorStr == "LIGHTSEAGREEN") return LIGHTSEAGREEN;
    else if (colorStr == "PALEGREEN") return PALEGREEN;
    else if (colorStr == "SPRINGGREEN") return SPRINGGREEN;
    else if (colorStr == "LAWNGREEN") return LAWNGREEN;
    else if (colorStr == "CHARTREUSE") return CHARTREUSE;
    else if (colorStr == "MEDIUMSPRINGGREEN") return MEDIUMSPRINGGREEN;
    else if (colorStr == "GREENYELLOW") return GREENYELLOW;
    else if (colorStr == "LIMEGREEN") return LIMEGREEN;
    else if (colorStr == "YELLOWGREEN") return YELLOWGREEN;
    else if (colorStr == "FORESTGREEN") return FORESTGREEN;
    else if (colorStr == "OLIVEDRAB") return OLIVEDRAB;
    else if (colorStr == "DARKKHAKI") return DARKKHAKI;
    else if (colorStr == "KHAKI") return KHAKI;
    else if (colorStr == "PALEGOLDENROD") return PALEGOLDENROD;
    else if (colorStr == "LIGHTYELLOW") return LIGHTYELLOW;
    else if (colorStr == "LIGHTGOLDENROD") return LIGHTGOLDENROD;
    else if (colorStr == "GOLDENROD") return GOLDENROD;
    else if (colorStr == "DARKGOLDENROD") return DARKGOLDENROD;
    else if (colorStr == "ROSYBROWN") return ROSYBROWN;
    else if (colorStr == "INDIAN" || colorStr == "INDIANRED") return INDIANRED;
    else if (colorStr == "SADDLEBROWN") return SADDLEBROWN;
    else if (colorStr == "SIENNA") return SIENNA;
    else if (colorStr == "PERU") return PERU;
    else if (colorStr == "BURLYWOOD") return BURLYWOOD;
    else if (colorStr == "BEIGE") return BEIGE;
    else if (colorStr == "WHEAT") return WHEAT;
    else if (colorStr == "SANDYBROWN") return SANDYBROWN;
    else if (colorStr == "TAN") return TAN;
    else if (colorStr == "CHOCOLATE") return CHOCOLATE;
    else if (colorStr == "FIREBRICK") return FIREBRICK;
    else if (colorStr == "BROWN") return BROWN;
    else if (colorStr == "DARKSALMON") return DARKSALMON;
    else if (colorStr == "SALMON") return SALMON;
    else if (colorStr == "LIGHTSALMON") return LIGHTSALMON;
    else if (colorStr == "DARKORANGE") return DARKORANGE;
    else if (colorStr == "CORAL") return CORAL;
    else if (colorStr == "LIGHTCORAL") return LIGHTCORAL;
    else if (colorStr == "TOMATO") return TOMATO;
    else if (colorStr == "HOTPINK") return HOTPINK;
    else if (colorStr == "DEEPPINK") return DEEPPINK;
    else if (colorStr == "LIGHTPINK") return LIGHTPINK;
    else if (colorStr == "PALEVIOLETRED") return PALEVIOLETRED;
    else if (colorStr == "MAROON") return MAROON;
    else if (colorStr == "MEDIUMVIOLETRED") return MEDIUMVIOLETRED;
    else if (colorStr == "VIOLETRED") return VIOLETRED;
    else if (colorStr == "VIOLET") return VIOLET;
    // else if (colorStr == "PLUM") return PLUM;
  /*   else if (colorStr == "ORCHID") return ORCHID;
     else if (colorStr == "MEDIUMORCHID") return MEDIUMORCHID;
     else if (colorStr == "DARKORCHID") return DARKORCHID;
     else if (colorStr == "DARKVIOLET") return DARKVIOLET;
     else if (colorStr == "BLUEVIOLET") return BLUEVIOLET;
     else if (colorStr == "MEDIUMPURPLE") return MEDIUMPURPLE;
     else if (colorStr == "THISTLE") return THISTLE;
     else if (colorStr == "DARKBLUE") return DARKBLUE;
     else if (colorStr == "DARKCYAN") return DARKCYAN;
     else if (colorStr == "DARKMAGENTA") return DARKMAGENTA;
     else if (colorStr == "DARKRED") return DARKRED;
     else if (colorStr == "LIGHTGREEN") return LIGHTGREEN;*/
    return BLACK; // Default color
}
