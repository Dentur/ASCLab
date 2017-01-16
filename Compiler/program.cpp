#include "Labyrinth.h"
using namespace std;

int main() {
try {
remove("error.txt");
Labyrinth lab = Labyrinth();
lab.load("C:/Users/Tim/Desktop/FH/ASC/lab.txt");
lab.setMarker(FLOOR, FORWARD, 0);
while ( lab.getXPos() != lab.getGoalXPos() || lab.getYPos() != lab.getGoalYPos()) { 
int index;
index=0;
int minIndex;
int minVal;
minIndex=-1;
minVal=99999;
while ( index < lab.getMarkerTotalCount()) { 
int curVal;
curVal=lab.getMarkerValue(index);
if (curVal < minVal && curVal != -1) {
minVal=curVal;
minIndex=index;
}
index=index + 1;
}
if (minIndex == -1) {
lab.print("Error: Goal cannot be reached (1)");
break;
}
lab.teleport(minIndex);
if (lab.look(NORTH) == Free) {
lab.setMarker(NORTH, SOUTH, minVal + 1);
}
if (lab.look(NORTH) == Marker) {
if (lab.getMarkerValue(NORTH) >= 0) {
if (minVal + 1 < lab.getMarkerValue(NORTH)) {
lab.setMarker(NORTH, SOUTH, minVal + 1);
}
}
}
if (lab.look(EAST) == Free) {
lab.setMarker(EAST, WEST, minVal + 1);
}
if (lab.look(EAST) == Marker) {
if (lab.getMarkerValue(EAST) >= 0) {
if (minVal + 1 < lab.getMarkerValue(EAST)) {
lab.setMarker(EAST, WEST, minVal + 1);
}
}
}
if (lab.look(SOUTH) == Free) {
lab.setMarker(SOUTH, NORTH, minVal + 1);
}
if (lab.look(SOUTH) == Marker) {
if (lab.getMarkerValue(SOUTH) >= 0) {
if (minVal + 1 < lab.getMarkerValue(SOUTH)) {
lab.setMarker(SOUTH, NORTH, minVal + 1);
}
}
}
if (lab.look(WEST) == Free) {
lab.setMarker(WEST, EAST, minVal + 1);
}
if (lab.look(WEST) == Marker) {
if (lab.getMarkerValue(WEST) >= 0) {
if (minVal + 1 < lab.getMarkerValue(WEST)) {
lab.setMarker(WEST, EAST, minVal + 1);
}
}
}
Direction mDir;
mDir=lab.getMarkerDirection(FLOOR);
lab.deleteMarker(FLOOR);
lab.setMarker(FLOOR, mDir, -1);
}
if (lab.getXPos() == lab.getGoalXPos() && lab.getYPos() == lab.getGoalYPos()) {
lab.print("Ziel gefunden");
}
} catch (const std::exception ex) {
FILE* _errorFile = fopen("error.txt", "w");
fprintf(_errorFile, ex.what());
fclose(_errorFile);
} 
}
