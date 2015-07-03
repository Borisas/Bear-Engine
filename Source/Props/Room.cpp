#include "Room.h"

Room::Room(int w, int h){
    room = new Tile*[h];
    for(unsigned int i = 0; i < w; i++){
	room[i] = new Tile[w];
    }
    width = w;
    height = h;
}
Room::~Room(){
   for(unsigned int i = 0; i < height; i++){
	delete[] room[i];
   }
   delete[] room;
}
Room* Room::create(int w, int h){
    auto r = new Room(w,h);
    r->loadTileSet(0);
    return r;
}
void Room::draw(){
    for(unsigned int i = 0; i < width; i++){
	for(unsigned int j = 0; j < height; j++){
	   room[i][j].img->draw(); 
	}
    }
}
void Room::loadTileSet(unsigned int tid){
    for(unsigned int i = 0; i < width; i++){
	for(unsigned int j = 0; j < height; j++){
	    room[i][j].img = Sprite::create("");
	    room[i][j].imageID = tid;
	}
    }
}
