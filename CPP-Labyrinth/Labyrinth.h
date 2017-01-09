#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

enum Direction{
  NORTH,
  EAST,
  SOUTH,
  WEST,
  FORWARD,
  LEFT,
  BACK,
  RIGHT,
  FLOOR
};

enum WallTypes {
   Free,
   Wall,
   Marker,
   Stone,
   Goal,
};

struct _Marker {
   Direction dir;
   int value;
   int x;
   int y;
   _Marker *next;
};

class Labyrinth
{
public:
  Labyrinth();
  ~Labyrinth();
  void load(string File);
  void move(Direction dir);
  void step(Direction dir);
  void turn(Direction dir);
  void setStone(Direction dir);
  void deleteMarker(Direction dir);
  WallTypes look(Direction dir);
  Direction getViewDirection();
  int getXPos();
  int getYPos();
  void print();
private:
  Direction view;
  char* _lab;
  int labWidth;
  int labHeight;
  int x;
  int y;
  vector<_Marker> marks;
  Direction getRealDirection(Direction dir);
  void moveDirection(Direction dir);
  WallTypes getWallType(Direction dir);
  void log(string text);
  char setChar(Direction dir, char c);
  //Funktionen die noch implementiert werden müssen
  void removeMarkerFromVector(int index);
  int getMarkerIndexByCoords(int x, int y);
  int getXPos(Direction dir);
  int getYPos(Direction dir);
};

