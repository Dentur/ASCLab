#include "Labyrinth.h"


Labyrinth::Labyrinth() {
   view = NORTH;
   x = -1;
   y = -1;
   goalX = -1;
   goalY = -1;
}


Labyrinth::~Labyrinth() {
   free(_lab);
}

void Labyrinth::load(string File) {
   string line = "";
   int row = 0;
   ifstream _file(File);
   _file >> labWidth >> labHeight;
   /*
   while (getline(_file, line)) {
      row++;
      if (labWidth < line.length()) {
         labWidth = line.length();
      }
   }
   _file.clear();
   labHeight = row;
   row = 0;
   _file.seekg(0, ios::beg);
   */
   _lab = (char*)calloc(labHeight*labWidth + 1, 1);
   while (getline(_file, line)) {
      int i = 0;
      for (; i < line.length(); i++) {
         if (line[i] == '\t') {
            line[i] = ' ';
         }
         _lab[row++] = line[i];
         
         if (x < 0) {
            if (line[i] == 's' || line[i] == 'S') {
               x = i;
               y = row / labWidth;
            }
         }
         if (goalX < 0) {
            if (line[i] == 'g' || line[i] == 'G') {
               goalX = i;
               goalY = row / labWidth;
            }
         }
      }
      while (row%labWidth != 0) {
         _lab[row++] = ' ';
      }
   }
   _lab[row] = 0;
   _file.clear();
   _file.close();
   log(File);
}

Direction Labyrinth::getRealDirection(Direction dir) {
   if (dir < 4) {
      return dir;
   }
   else if (dir == 5) {
      return (Direction)((view + 3) % 4);
   }
   else if (dir == 6) {
      return (Direction)((view + 2) % 4);
   }
   else if (dir == 7) {
      return Direction((view + 1) % 4);
   }
   else if (dir == FLOOR) {
      return FLOOR;
   }
   return view;
}

char Labyrinth::setChar(Direction dir, char c) {
   if (dir >= 4) {
      dir = getRealDirection(dir);
   }
   char* _wall;
   if (dir == NORTH) {
      if (y == 0) {
         //TODO Log Error
         return c;
      }
      _wall = &_lab[(y - 1)*labWidth + x];
   }
   else if (dir == EAST) {
      if (x == labWidth - 1) {
         //TODO Log Error
         return c;
      }
      _wall = &_lab[y*labWidth + x + 1];
   }
   else if (dir == SOUTH) {
      if (y == labHeight - 1) {
         //TODO Log Error
         return c;
      }
      _wall = &_lab[(y + 1)*labWidth + x];
   }
   else if (dir == WEST) {
      if (x == 0) {
         //TODO Log Error
         return c;
      }
      _wall = &_lab[y*labWidth + x - 1];
   }
   else {
      _wall = &_lab[y*labWidth + x];
   }
   char ret = _wall[0];
   switch (_wall[0]) {
   case ' ':
      _wall[0] = c;
      break;
   case '=':
      _wall[0] = c;
      break;
   case 'm':
      _wall[0] = c;
      break;
   case 'S':
      _wall[0] = c;
      break;
   default:
      return c;
   }
   return ret;
}

WallTypes Labyrinth::getWallType(Direction dir) {
   if (dir >= 4) {
      dir = getRealDirection(dir);
   }
   char _wall = ' ';
   if (dir == NORTH) {
      if (y == 0) {
         //TODO Log Error
         return Wall;
      }
      _wall = _lab[(y - 1)*labWidth + x];
   }
   else if (dir == EAST) {
      if (x == labWidth - 1) {
         //TODO Log Error
         return Wall;
      }
      _wall = _lab[y*labWidth + x + 1];
   }
   else if (dir == SOUTH) {
      if (y == labHeight - 1) {
         //TODO Log Error
         return Wall;
      }
      _wall = _lab[(y + 1)*labWidth + x];
   }
   else if (dir == WEST) {
      if (x == 0) {
         //TODO Log Error
         return Wall;
      }
      _wall = _lab[y*labWidth + x - 1];
   }
   else if (dir == FLOOR) {
      _wall = _lab[y*labWidth + x];
   }
   switch (_wall) {
      case '#':
         return Wall;
      case ' ':
         return Free;
      case '=':
         return Stone;
      case 'm':
         return Marker;
      case 'G':
         return Goal;
      case 'g':
         return Goal;
      case 'S':
         return Free;
      default:
         return Wall;
   }
}

void Labyrinth::moveDirection(Direction dir) {
   if (dir >= 4) {
      dir = getRealDirection(dir);
   }
   if (getWallType(dir) == Wall) {
      //TODO Log Error
      return;
   }
   if (dir == NORTH) {
      y--;
   }
   else if (dir == EAST) {
      x++;
   }
   else if (dir == SOUTH) {
      y++;
   }
   else if (dir == WEST) {
      x--;
   }
}

int* Labyrinth::getCoords(Direction dir) {
   dir = getRealDirection(dir);
   int coord[2];
   coord[0] = x;
   coord[1] = y;
   switch (dir) {
   case NORTH:
      if (y == 0) {
         return coord;
      }
      coord[1]--;
      break;
   case EAST:
      if (x == (labWidth - 1)) {
         return coord;
      }
      coord[0]++;
      break;
   case SOUTH:
      if (y == (labHeight - 1)) {
         return coord;
      }
      coord[1]++;
      break;
   case WEST:
      if (x == 0) {
         return coord;
      }
      coord[0]--;
      break;
   }
   return coord;
}

void Labyrinth::print() {
   for (int i = 0; i < labHeight; i++) {
      for (int j = 0; j < labWidth; j++) {
         cout << _lab[i*labWidth + j];
      }
      cout << endl;
   }
}

void Labyrinth::move(Direction dir) {
   if (dir == FLOOR) {
      return;
   }
   view = getRealDirection(dir);
   moveDirection(view);
   //TODO Log to File
   string str = "move ";
   str += (char)(view + 48);
   log(str);
}
WallTypes Labyrinth::look(Direction dir) {
   string str = "look ";
   str += (char)(getRealDirection(dir) + 48);
   log(str);
   return getWallType(dir);
}
void Labyrinth::step(Direction dir) {
   if (dir == FLOOR) {
      return;
   }

   moveDirection(dir);
   //TODO Log to File
   string str = "step ";
   str += (char)(getRealDirection(dir) + 48);
   log(str);
}

void Labyrinth::turn(Direction dir) {
   if (dir == FLOOR) {
      return;
   }
   view = getRealDirection(dir);
   string str = "turn ";
   str += (char)(view + 48);
   log(str);
   //TODO Log to File
}

void Labyrinth::removeMarkerFromVector(int index) {
   marks.erase(marks.begin() + index);
}

void Labyrinth::addMarker(Direction dir, int x, int y, int val) {
   _Marker m = _Marker();
   m.dir = dir;
   m.x = x;
   m.y = y;
   m.value = val;
   marks.push_back(m);
}

void Labyrinth::teleport(int index) {
   if (index >= marks.size() || index < 0) {
      return;
   }
   string str = "teleport ";
   str += to_string(x);
   str += " ";
   str += to_string(y);
   log(str);
   x = marks[index].x;
   y = marks[index].y;
}
int Labyrinth::getMarkerValue(int index) {
   if (index >= marks.size() || index < 0) {
      return NULL;
   }
   return marks[index].value;
}
int Labyrinth::getMarkerValue(Direction dir) {
   int* coords = getCoords(dir);
   return marks[getMarkerIndexByCoords(coords[0], coords[1])].value;
}
int Labyrinth::getMarkerTotalCount() {
   return marks.size();
}
Direction Labyrinth::getMarkerDirection(Direction dir) {
   int* coords = getCoords(dir);
   return marks[getMarkerIndexByCoords(coords[0], coords[1])].dir;
}


void Labyrinth::setStone(Direction dir) {
   char old = setChar(dir, '=');
   if (old == 'm') {
      int* coords = getCoords(dir);
      removeMarkerFromVector(getMarkerIndexByCoords(coords[0], coords[1]));
   }
   string str = "sstone ";
   str += (char)(getRealDirection(dir) + 48);
   log(str);
}

int Labyrinth::getMarkerIndexByCoords(int x, int y) {
   for (int i = 0; i < marks.size(); i++) {
      if (marks[i].x == x && marks[i].y == y) {
         return i;
      }
   }
   return NULL;
}

void Labyrinth::setMarker(Direction placeDir, Direction dir, int value) {
   char old = setChar(placeDir, 'm');
   int* coords = getCoords(placeDir);
   dir = getRealDirection(dir);
   string str = "dmarker ";
   if (old != 'm') {
      addMarker(dir, coords[0], coords[1], value);
   } else {
	  int index = getMarkerIndexByCoords(coords[0], coords[1]);
	  marks[index].value = value;
	  marks[index].dir = dir;
	  str += (char)(getRealDirection(dir) + 48);
	  log(str);
   }
   str = "smarker ";
   str += (char)(getRealDirection(placeDir) + 48);
   str += ' ';
   str += (char)(getRealDirection(dir) + 48);
   str += ' ';
   str += to_string(value);
   log(str);
}
void Labyrinth::deleteMarker(Direction dir) {
   char old = setChar(dir, ' ');
   if (old == 'm') {
      int* coords = getCoords(dir);
      removeMarkerFromVector(getMarkerIndexByCoords(coords[0], coords[1]));
   }
   string str = "dmarker ";
   str += (char)(getRealDirection(dir) + 48);
   log(str);
}
int Labyrinth::getXPos() {
   return x;
}
int Labyrinth::getYPos() {
   return y;
}

int Labyrinth::getGoalXPos() {
   return goalX;
}
int Labyrinth::getGoalYPos() {
   return goalY;
}

void Labyrinth::log(string text) {
   ofstream log_file("log_file.txt", ios_base::out | ios_base::app);
   log_file << text << endl;
}



Direction Labyrinth::getViewDirection() {
   return view;
}