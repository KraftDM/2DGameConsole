#include "Render.h"

Render* Render::instance_ptr = nullptr;
Texture2D* Render::render = nullptr;
HANDLE Render::hConsole;
CONSOLE_SCREEN_BUFFER_INFOEX Render::csbi;
COORD Render::coordBufSize;
CHAR_INFO* Render::chiBuffer;
COORD Render::coordBufCoord = { 0, 0 };;
SMALL_RECT Render::srctWriteRect;

WORD* Render::atr = nullptr;


