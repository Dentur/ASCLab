#include "Labyrinth.h"
using namespace std;

int main() {
try {
remove("error.txt");
Labyrinth lab = Labyrinth();
lab.load("C:/Users/Tim/Desktop/FH/ASC/Project/Programme/pledge_lab.txt");
int i_counter;
i_counter=0;
bool b_holdWall;
b_holdWall=false;
Direction d_startDir;
d_startDir=lab.getViewDirection();
while ( lab.getXPos() != lab.getGoalXPos() || lab.getYPos() != lab.getGoalYPos()) { 
if (i_counter == 0 && d_startDir == lab.getViewDirection()) {
b_holdWall=false;
}
if (b_holdWall) {
if (lab.look(RIGHT) == Wall) {
if (lab.look(FORWARD) == Wall) {
i_counter=i_counter - 1;
lab.turn(LEFT);
} else {
lab.step(FORWARD);
}
} else {
i_counter=i_counter + 1;
lab.move(RIGHT);
}
} else {
if (lab.look(FORWARD) == Wall) {
lab.turn(LEFT);
i_counter=i_counter - 1;
b_holdWall=true;
} else {
lab.move(FORWARD);
}
}
}
lab.print("Found Goal");
} catch (const std::exception ex) {
FILE* _errorFile = fopen("error.txt", "w");
fprintf(_errorFile, ex.what());
fclose(_errorFile);
} 
}
