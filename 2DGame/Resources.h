#pragma once

#include "Sprite.h"

#include <iostream>
#include <map>
#include<fstream>
#include <string>
#include <vector>

using namespace std;

class Resources
{
    public:
        static vector<Texture2D*> textures;
        static vector<SpriteAtlas> atlases;
        static vector<Sprite> sprites;

    public:
    //static bool rLoadImage(const char* path, Image* out);
    static Texture2D* LoadTexture2D(const char* path);
    static bool LoadAtlas(const char* path);
    static bool LoadSprites(const char* path);
   
private:

    Resources(const Resources&) = delete;
    ~Resources() { }
};
