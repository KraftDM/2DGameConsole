#pragma once

#include "Resources.h"
#include "GameObject.h"

#include <windows.h>
#include <vector>


struct color {
	uint8_t r{ 0 };
	uint8_t g{ 0 };
	uint8_t b{ 0 };

	color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {}
};

class Render
{
	static Render* instance_ptr;
	static Texture2D* render;

	static HANDLE hConsole;
	static CONSOLE_SCREEN_BUFFER_INFOEX csbi;
	static COORD coordBufSize;
	static CHAR_INFO* chiBuffer;
	static COORD coordBufCoord;
	static SMALL_RECT srctWriteRect;

	static WORD* atr;

	Render() { 

		system("color F0");

		char colortablet[16 * 3];
		std::ifstream inp{ "color_tablet.ACT", std::ios_base::binary };
		if (inp) {
			inp.read((char*)&colortablet, 16 * 3);
		}
		inp.close();

		// ”Ѕ–ј“№ ќЌќ “”“ Ќ≈Ќ”∆Ќќ
		std::vector<color> colors{};
		for (int i = 0; i < 16; i++) {
			colors.push_back(color(colortablet[i * 3], colortablet[i * 3 + 1], colortablet[i * 3 + 2])); 
		}

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hConsole != INVALID_HANDLE_VALUE) {
			CONSOLE_FONT_INFOEX cfi;
			cfi.cbSize = sizeof(cfi);
			cfi.nFont = 1;
			cfi.dwFontSize.X = 3;     // Width of each character in the font 
			cfi.dwFontSize.Y = 3;     // Height 
			cfi.FontFamily = FF_DONTCARE;
			cfi.FontWeight = FW_NORMAL;
			wcscpy_s(cfi.FaceName, L"SquarePix3"); // Choose your font 
			SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
		}
		
		Resources::LoadSprites("path_to_sprite_file");
		Resources::LoadAtlas("test_cmp.cmp");

		Texture2D* cmp = Resources::atlases[0].texture;

		for (int i = 0; i < 16; i++)
			csbi.ColorTable[i] = RGB(colors[i].r, colors[i].g, colors[i].b);
		SetConsoleScreenBufferInfoEx(hConsole, &csbi);


		// TO DO: инициализировать в другом месте 
		coordBufSize.X = 320;
		coordBufSize.Y = 256;
		render = new Texture2D(coordBufSize.X, coordBufSize.Y);
		system("mode con cols=320 lines=256"); // сделать программно


		//TEST
		atr = new WORD[coordBufSize.X * coordBufSize.Y];

		chiBuffer = new CHAR_INFO[coordBufSize.X * coordBufSize.Y];
		srctWriteRect.Top = 0;
		srctWriteRect.Left = 0;
		srctWriteRect.Bottom = coordBufSize.Y - 1;
		srctWriteRect.Right = coordBufSize.X - 1;
		
		
		for (int i = 0; i < coordBufSize.X * coordBufSize.Y; i++) {
			chiBuffer[i].Char.UnicodeChar = ' ';
			chiBuffer[i].Attributes = (WORD)0 << 4;
		}

		ConsoleOutput();
	}

public:
	static Render* get_instance()
	{
		if (instance_ptr == nullptr) {
			instance_ptr = new Render();
		}

		return instance_ptr;
	}

	static void ConsoleOutput() {
		for (int i = 0; i < coordBufSize.X * coordBufSize.Y; i++) {
			atr[i] = (WORD)render->data[i] << 4;
			//chiBuffer[i].Attributes = (WORD)render->data[i] << 4;
		}

		DWORD cWritten;
		WriteConsoleOutputAttribute(
			hConsole,          // дескриптор экранного буфера
			atr,           // цвет дл€ заполнени€
			coordBufSize.X* coordBufSize.Y,            // число заполн€емых €чеек
			COORD {0, 0},            // перва€ €чейка дл€ записи
			&cWritten);       // фактическое число записей

		/*
		WriteConsoleOutput(
			hConsole, 	// экранный буфер, в который будем записывать
			chiBuffer,        	// буфер, из которого копируем
			coordBufSize,     	// размер колонки/строки chiBuffer
			coordBufCoord,    	// верхн€€ лева€ €чейка источника в chiBuffer
			&srctWriteRect);
		*/
	}

	static void ConsoleClear() {
		for (int i = 0; i < coordBufSize.X * coordBufSize.Y; i++) {
			render->data[i] = 0;
		}
	}

	static void ConsoleDraw(Texture2D* tex, int16_t x, int16_t y) {
		render=tex;
	}

	/*
	static void ConsoleDraw() {
		
		Sprite* ptS = &Resources::sprites[0];
		Sprite* ptS2 = &Resources::sprites[0];
		Grid grid = Resources::atlases[ptS->idAtlas].grid;
		Region reg = grid.GetWorldPosition(ptS->place, ptS->place);
		Texture2D* cmp = Resources::atlases[ptS->idAtlas].texture;

		for (int y = 0; y < coordBufSize.Y; y++) {
			for (int x = 0; x < coordBufSize.X; x++) {
				int i = y * coordBufSize.X + x;
				chiBuffer[i].Char.UnicodeChar = ' ';
				if (x < reg.second.x && x >= reg.first.x && y < reg.second.y && y >= reg.first.y)
					chiBuffer[i].Attributes = (WORD)cmp->data[i] << 4;
				else
					chiBuffer[i].Attributes = (WORD)0 << 4;
			}
		}
		ptS2->place++; 
	}*/


	Render(const Render&) = delete;
	~Render() { instance_ptr = nullptr; }

private:

};

