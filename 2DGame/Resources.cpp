#include "Resources.h"

using namespace std;


vector<Texture2D*> Resources::textures = {};
vector<SpriteAtlas> Resources::atlases = {};
vector<Sprite> Resources::sprites = {};

char** loadImage(const char* path, int width, int height)	
{
    char** data = new char*[height];
	ifstream in(path);	
    if (in.is_open())
    {
        int y=0;
        string s;
        while (getline(in, s) && y<height)
        {
            data[y] = new char[width];
            copy(s.begin(), s.end(), data[y]);
            y++;
        }
    } else 
        cout << "NO" << endl;
    in.close();		
    return data;
}


Texture2D* Resources::LoadTexture2D(const char* path) {
    Texture2D* a = new Texture2D(path);
    textures.push_back(a);
    return a;
}

bool Resources::LoadAtlas(const char* path) {
    Texture2D* a = LoadTexture2D(path);
    // TO DO: сделать гибки в будущем
    Grid g(16, 16); 
    SpriteAtlas atlas(0, a, g); // TO DO: добавить инициализацию всех атласов из json файла
    atlases.push_back(atlas);
    return true;
}

bool Resources::LoadSprites(const char* path) {
    //Sprite s0(0, 0);
    //Sprite s1(1, 0);
    //sprites.push_back(s0);
    //sprites.push_back(s1);
    return true;
}


/*
void Resources::AddPalette(string id, SpritePackage* pl)
{
    packagesLoaded[id] = pl;
}

SpritePackage* Resources::GetPackageById(const string id) {
    if (packagesLoaded.find(id) != packagesLoaded.end())
        return packagesLoaded[id];
    else
        return nullptr;
}

Sprite* Resources::GetSpriteById(short id) 
{
    for (auto pck : packagesLoaded) {
        if (pck.second->IsSpriteInPackage(id)) {
            return pck.second->GetSpriteById(id);
        }
    }
    return nullptr;
}

bool Resources::LoadPackages ()
{
    SpritePackage* pl = new SpritePackage("Assets/Sprites/tileset_1.txt", Size{ 24, 24 }, Size{ 8, 8 });
    //AddPalette("castle", pl);
    Sprite* s = new Sprite(0, "stone", "castle", Vector2Short{0, 0});
    pl->AddSprite(s);

    SpritePackage* pl2 = new SpritePackage("Assets/Sprites/player_sprite.txt", Size{ 24, 24 }, Size{ 1, 1 });
    //AddPalette("player", pl2);
    Sprite* s2 = new Sprite(16, "dima", "player", Vector2Short{ 0, 0 }, true);
    pl2->AddSprite(s2);

    return 0;
}
*/