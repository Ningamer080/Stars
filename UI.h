#ifndef UI_H
#define UI_HC
#include "UCanvas.h"

class UI
{
public:
	UI();
	void InitUI();

	UCanvas& getCanvas();
	void setCanvas(UCanvas);
private:
	UCanvas canvas;
};
#endif