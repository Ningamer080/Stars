#include "UI.h"


UI::UI()
{
	
}

void UI::InitUI() {
	UButton button = canvas.createButton(77);
}

UCanvas& UI::getCanvas() {
	return canvas;
}

void UI::setCanvas(UCanvas canvas_) {
	canvas = canvas_;
}