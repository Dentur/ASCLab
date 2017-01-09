#include "Labyrinth.h"


Labyrinth::Labyrinth() {
   view = NORTH;
   x = -1;
   y = -1;
}


Labyrinth::~Labyrinth() {
   free(_lab);
}

void Labyrinth::load(string File) {
   string line = "";
   int row = 0;
   ifstream _file(File);

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
   else /*if (dir == WEST)*/ {
      if (x == 0) {
         //TODO Log Error
         return c;
      }
      _wall = &_lab[y*labWidth + x - 1];
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
   switch (_wall) {
      case '#':
         return Wall;
      case ' ':
         return Free;
      case '=':
         return Stone;
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
void Labyrinth::print() {
   for (int i = 0; i < labHeight; i++) {
      for (int j = 0; j < labWidth; j++) {
         cout << _lab[i*labWidth + j];
      }
      cout << endl;
   }
}

void Labyrinth::move(Direction dir) {
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
   moveDirection(dir);
   //TODO Log to File
   string str = "step ";
   str += (char)(getRealDirection(dir) + 48);
   log(str);
}

void Labyrinth::turn(Direction dir) {
   view = getRealDirection(dir);
   string str = "turn ";
   str += (char)(view + 48);
   log(str);
   //TODO Log to File
}

void Labyrinth::setStone(Direction dir) {
   char temp = setChar(dir, '=');
   string str = "sstone ";
   str += (char)(getRealDirection(dir) + 48);
   log(str);
}
void Labyrinth::deleteMarker(Direction dir) {
   char old = setChar(dir, ' ');
   if (old == 'm') {
      //TODO delete Marker from List
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

void Labyrinth::log(string text) {
   ofstream log_file("log_file.txt", ios_base::out | ios_base::app);
   log_file << text << endl;
}



Direction Labyrinth::getViewDirection() {
   return view;
}