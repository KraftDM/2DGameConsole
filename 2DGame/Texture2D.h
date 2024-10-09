#pragma once
#include <iostream>
#include <fstream>


struct CMPHeader {
    uint16_t file_type{ 0x4D43 };          // File type always CM which is 0x4D43
    uint32_t file_size{ 0 };               // Size of the file (in bytes)
    uint32_t width{ 0 };
    uint32_t height{ 0 };
};

class Texture2D
{
public:
	uint32_t width{ 0 };
	uint32_t height{ 0 };
    uint8_t* data;

    Texture2D(const char* fname) {
        read(fname);
    }
    Texture2D(uint32_t w, uint32_t h) : width(w), height(h) {
        data = new uint8_t[w * h];
        Clear(15);
    }
    ~Texture2D() {
        delete(data);
    }

    void TextureDraw(Texture2D* srcText, int32_t x = 0, int32_t y = 0);
    void Clear(uint8_t col = 0) {
        std::fill(data, data + width * height, col);
    };

private:
    void read(const char* fname) {
        CMPHeader file_header;
        std::ifstream inp{ fname, std::ios_base::binary };
        if (inp) {
            inp.read((char*)&file_header, sizeof(file_header));
            if (file_header.file_type != 0x4D43) {
                throw std::runtime_error("Error! Unrecognized file format.");
            }
            inp.seekg((uint32_t)16, inp.beg);
            width = file_header.width;
            height = file_header.height;
            data = new uint8_t[width * height];
            inp.read((char*)data, width * height);
        }
        else {
            throw std::runtime_error("Unable to open the input image file.");
        }
    }
};

