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
  void setMarker(Direction dir, int value);
  void deleteMarker(Direction dir);
  void teleport(int index);
  WallTypes look(Direction dir);
  Direction getViewDirection();
  int getXPos();
  int getYPos();
  int getGoalXPos();
  int getGoalYPos();
  int getMarkerValue(int index);
  int getMarkerValue(Direction dir);
  int getMarkerTotalCount();
  Direction getMarkerDirection(Direction dir);
  //TODO Fehlende Befehle: 
  void print(char* str);
  //Prints Lab only!
  void print();
private:
  Direction view;
  char* _lab;
  int labWidth;
  int labHeight;
  int x;
  int y;
  int goalX;
  int goalY;
  vector<_Marker> marks;
  Direction getRealDirection(Direction dir);
  void moveDirection(Direction dir);
  WallTypes getWallType(Direction dir);
  void log(string text);
  char setChar(Direction dir, char c);
  int* getCoords(Direction dir);
  void removeMarkerFromVector(int index);
  void addMarker(Direction dir, int x, int y, int val);
  int getMarkerIndexByCoords(int x, int y);
};

