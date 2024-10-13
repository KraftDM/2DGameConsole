#include "Render.h"
#include "Camera.h"
#include "Character.h"
#include "Game.h"
#include "PickableObject.h"

#include "RenderTiles.h"

#include "Windows.h"
#include "WinCon.h"
#include <vector>
#include <stdio.h>

#include "resource.h"

using namespace std;

int main(int argvc, char const *argv[])
{
	setlocale(LC_CTYPE, ".866");

	Game game {};
	
	/*
	HRSRC myResource = ::FindResource(NULL, MAKEINTRESOURCE(IDR_CMP2), L"CMP");
	HGLOBAL myResourceData = ::LoadResource(NULL, myResource);
	void* pMyBinaryData = ::LockResource(myResourceData);

	byte* data = (byte*)pMyBinaryData;
	cout << endl;
	*/

	Render::get_instance();

	Texture2D* cmp = Resources::atlases[0].texture;


	Player player{};
	game.player = &player;
	Camera cam{ 320, 256 };
	cam.transform.SetParent(player.transform);
	

	PickableObject heart{};
	heart.TransportTo(30, 30);

	Tilemap map{Vector2Int(30, 30)};

	for (int y = 0; y < 30; y++) {
		for (int x = 0; x < 30; x++) {
			Sprite* s = new Sprite(y*x%4, &Resources::atlases[0]);
			map.SetTileSprite(s, Vector2Int(x, y));
		}
	}


	int step = 1;
	bool isRun = true;
	while (isRun) {

		game.Run();

		//cam.Clear();

		Render::ConsoleClear();
		cam.Clear();
		cam.RenderTileMap(map);
		cam.DrawObjAtPos(player);
		cam.DrawObjAtPos(heart);
		Render::ConsoleDraw(cam.GetRender(), 0, 0);
		Render::ConsoleOutput();

		/*
		if (Inputs::isPresed(87)) {
			cam.position.y -= step;
		}
		if (Inputs::isPresed(83)) {
			cam.position.y += step;
		}
		if (Inputs::isPresed(65)) {
			cam.position.x -= step;
		}
		if (Inputs::isPresed(68)) {
			cam.position.x += step;
		}*/


		if (Inputs::isClick(VK_ESCAPE)) {
			isRun = false;
		}
	}

	//SetConsoleTextAttribute(hCons, 15);

    return 0;
}
