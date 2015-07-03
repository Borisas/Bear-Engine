#ifndef _ROOM_H_
#define _ROOM_H_

#include "../engine/BEngineCore.h"

struct Tile{
    Sprite* img;
    int imageID;
};

class Room{
public:
    Room(int, int);
    ~Room();
    static Room* create(int w, int h);

    void loadTileSet(unsigned int);
    void draw();

private:
    Tile ** room;
    int width = 0;
    int height = 0;
};

#endif
