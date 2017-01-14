#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include "generator.h"
#include <Windows.h>
#include <WinBase.h>

using namespace std;

FILE *cfile;
struct list {
	char* identifier;
	struct list* next; 
};

struct list* myHeap;
char* getDirection(int num) {
	switch(num){
		case 0:
		  return "NORTH";
		  case 1:
		  return "EAST";
		case 2:
		  return "SOUTH";
		case 3:
		  return "WEST";
		case 4:
		  return "FORWARD";
		case 5:
		  return "LEFT";
		case 6:
		  return "BACK";
		case 7:
		  return "RIGHT";
		case 8:
		  return "FLOOR";
	}
}

char* getWall(int num){
	switch(num){
		case 0:
		  return "Free";
		  case 1:
		  return "Wall";
		case 2:
		  return "Marker";
		case 3:
		  return "Stone";
		case 4:
		  return "Goal";
	}
}

void path(char* str) {
   for (int i = 0; str[i]; i++) {
      if (str[i] == '\\') {
         str[i] = '/';
      }
   }
}

void addToHeap(char* identifier)
{
	if(myHeap == NULL) {
		myHeap =  (struct list*)calloc( 1, sizeof(struct list*));
		myHeap->identifier = (char*) malloc(strlen(identifier) + 1);
		strcpy(myHeap->identifier, identifier);
		myHeap->next = 0;
	} else {
		struct list* node = myHeap->next;
		for (; node; node = node->next) {};
		myHeap->identifier = (char*) malloc(strlen(identifier) + 1);
		strcpy(myHeap->identifier, identifier);
		myHeap->next = 0;
	}
}

bool isInHeap(char* identifier)
{
	struct list* node = myHeap;
	for(; node; node = node->next) {
		if (strcmp(identifier,node->identifier) == 0) {
			return true;
		}
	}
	return false;
}

void createFile () {
    cfile = fopen("C:\\Users\\Tim\\Desktop\\FH\\Test\\program.cpp", "w");
}
void createFile (char* path) {
    cfile = fopen(path, "w");
}


int executeBatch() {
   STARTUPINFO si;
   PROCESS_INFORMATION pi;

   ZeroMemory(&si, sizeof(si));
   si.cb = sizeof(si);
   si.wShowWindow = SW_HIDE;
   si.dwFlags |= STARTF_USESHOWWINDOW;
   ZeroMemory(&pi, sizeof(pi));
   if (!CreateProcess(NULL,
      "cmd /C  .\\compileAndExecute.bat",
      NULL,
      NULL,
      FALSE,
      0,
      NULL,
      NULL,
      &si,
      &pi)
      ) {
      return FALSE;
   }
   WaitForSingleObject(pi.hProcess, INFINITE);
   CloseHandle(pi.hProcess);
   CloseHandle(pi.hThread);
   return TRUE;
}

void closeFile() {
   fclose(cfile);
   executeBatch();
}

void generate( PT_ENTRY *pentry) {
	switch(pentry->type)
	{
		case PROGRAM :
			fprintf(cfile, "#include \"Labyrinth.h\"\n");
			fprintf(cfile, "using namespace std;\n\n");

			//Main function
			fprintf(cfile, "int main() {\n");
			fprintf(cfile, "Labyrinth lab = Labyrinth();\n");
			generate(pentry->op1);
			for(PT_ENTRY* pt = pentry->op2; pt; pt = pt->nxt)
				generate(pt);
			
			fprintf(cfile, "}\n");
		break;

		case LOAD_CMD:
         path(pentry->str);
         fprintf(cfile, "lab.load(\"%s\");\n", pentry->str);
			break;
	
		case TURN_CMD :
			fprintf(cfile, "lab.turn(%s);\n", getDirection(pentry->op1->num));
			break;

		case MOVE_CMD :
			fprintf(cfile, "lab.move(%s);\n", getDirection(pentry->op1->num));
			break;
		case TELEPORT_CMD:
			fprintf(cfile, "lab.teleport(");
			generate(pentry->op1);
			fprintf(cfile, ");\n");
			break;
		case STEP_CMD :
			fprintf(cfile, "lab.step(%s);\n", getDirection(pentry->op1->num));
			break;
		case LOOK_CMD :
			fprintf(cfile, "lab.look(%s);\n", getDirection(pentry->op1->num));
			break;
		case LOOK_CMD_RET :
			fprintf(cfile, "lab.look(%s)", getDirection(pentry->op1->num));
			break;
		case SETSTONE_CMD :
			fprintf(cfile, "lab.setStone(%s);\n", getDirection(pentry->op1->num));
			break;
		case WHILE_CMD :
			fprintf(cfile, "while ( ");
			generate(pentry->op1);
			fprintf(cfile, ") { \n");
			for(PT_ENTRY* pt = pentry->op2; pt; pt = pt->nxt)
				generate(pt);
			fprintf(cfile, "}\n");
			break;
		case BREAK_CMD:
			fprintf(cfile, "break;\n");
			break;
		case IF_CMD :
			fprintf(cfile, "if (");
			generate(pentry->op1);
			fprintf(cfile, ") {\n");
			for(PT_ENTRY* pt = pentry->op2; pt; pt = pt->nxt)
				generate(pt);
			if(pentry->op3)
			{
			fprintf(cfile, "} else {\n");
				for(PT_ENTRY* pt = pentry->op3; pt; pt = pt->nxt)
					generate(pt);
			}
			fprintf(cfile, "}\n");
			break;
		case PRINT_CMD:
			fprintf(cfile, "printf(\"%s\");\n", pentry->str);
			break;
		case OP_EQ :
			generate(pentry->op1);
			fprintf(cfile, " == ");
			generate(pentry->op2);
			break;

		case OP_NE :
			generate(pentry->op1);
			fprintf(cfile, " != ");
			generate(pentry->op2);
			break;

		case OP_LT :
			generate(pentry->op1);
			fprintf(cfile, " < ");
			generate(pentry->op2);
			break;

		case OP_LE :
			generate(pentry->op1);
			fprintf(cfile, " <= ");
			generate(pentry->op2);
			break;

		case OP_GT :
			generate(pentry->op1);
			fprintf(cfile, " > ");
			generate(pentry->op2);
			break;

		case OP_GE :
			generate(pentry->op1);
			fprintf(cfile, " >= ");
			generate(pentry->op2);
			break;

		case OP_NOT :
			fprintf(cfile, "!");
			generate(pentry->op1);
			break;

		case OP_AND :
			generate(pentry->op1);
			fprintf(cfile, " && ");
			generate(pentry->op2);
			break;

		case OP_OR :
			generate(pentry->op1);
			fprintf(cfile, " || ");
			generate(pentry->op2);
			break;

		case OP_UMINUS :
			fprintf(cfile, "-");
			generate(pentry->op1);
			break;

		case OP_PLUS :
			generate(pentry->op1);
			fprintf(cfile, " + ");
			generate(pentry->op2);
			break;

		case OP_MINUS :
			generate(pentry->op1);
			fprintf(cfile, " - ");
			generate(pentry->op2);
			break;
		case DIRECTION:
			fprintf(cfile, "%s", getDirection(pentry->num));
			break;
		case WALL_TYPE:
			fprintf(cfile, "%s", getWall(pentry->num));
			break;
		case GOALX_CMD:
			fprintf(cfile, "lab.getGoalXPos();\n");
			break;
		case GOALX_CMD_RET:
			fprintf(cfile, "lab.getGoalXPos()");
			break;
		case GOALY_CMD:
			fprintf(cfile, "lab.getGoalYPos();\n");
			break;
		case GOALY_CMD_RET:
			fprintf(cfile, "lab.getGoalYPos()");
			break;
		case POSX_CMD:
			fprintf(cfile, "lab.getXPos();\n");
			break;
		case POSX_CMD_RET:
			fprintf(cfile, "lab.getXPos()");
			break;
		case POSY_CMD:
			fprintf(cfile, "lab.getYPos();\n");
			break;
		case POSY_CMD_RET:
			fprintf(cfile, "lab.getYPos()");
			break;
		case MTOTAL_CMD:
			fprintf(cfile, "lab.getMarkerTotalCount();\n");
			break;
		case MTOTAL_CMD_RET:
			fprintf(cfile, "lab.getMarkerTotalCount()");
			break;
		case GDIR_CMD:
			fprintf(cfile, "lab.getViewDirection();\n");
			break;
		case GDIR_CMD_RET:
			fprintf(cfile, "lab.getViewDirection()");
			break;
		case MVAL_CMD:
			fprintf(cfile, "lab.getMarkerValue(");
			generate(pentry->op1);
			fprintf(cfile, ");\n");
			break;
		case MVAL_CMD_RET:
			fprintf(cfile, "lab.getMarkerValue(");
			generate(pentry->op1);
			fprintf(cfile, ")");
			break;
		case MARKER_CMD:
			fprintf(cfile, "lab.getMarkerValue(");
			generate(pentry->op1);
			fprintf(cfile, ");\n");
			break;
		case MARKER_CMD_RET:
			fprintf(cfile, "lab.getMarkerValue(");
			generate(pentry->op1);
			fprintf(cfile, ")");
			break;
		case MDIR_CMD:
			fprintf(cfile, "lab.getMarkerDirection(");
			generate(pentry->op1);
			fprintf(cfile, ");\n");
			break;
		case MDIR_CMD_RET:
			fprintf(cfile, "lab.getMarkerDirection(");
			generate(pentry->op1);
			fprintf(cfile, ")");
			break;
		case MDELETE_CMD:
			fprintf(cfile, "lab.deleteMarker(");
			generate(pentry->op1);
			fprintf(cfile, ");\n");
			break;
		case SETMARK_CMD:
			fprintf(cfile, "lab.setMarker(");
			generate(pentry->op1);
			fprintf(cfile, ", ");
			generate(pentry->op2);
			fprintf(cfile, ", ");
			generate(pentry->op3);
			fprintf(cfile, ");\n");
			break;
		case NEW_ASSIGN:
			addToHeap(pentry->identifier);
			switch(pentry->num){
				case 0:
					fprintf(cfile, "int %s;\n", pentry->identifier);
					break;
				case 1:
					fprintf(cfile, "Direction %s;\n", pentry->identifier);
					break;
				case 2:
					fprintf(cfile, "WallTypes %s;\n", pentry->identifier);
					break;
				case 3:
					fprintf(cfile, "bool %s;\n", pentry->identifier);
					break;
			}
			break;
			
		case ASSIGN:
			fprintf(cfile, "%s=", pentry->identifier);
			generate(pentry->op1);
			fprintf(cfile, ";\n");
			break;
		
		case VAL_DIGIT:
			fprintf(cfile, "%d", pentry->num);
			break;
			
		case USE_VARIABLE:
			fprintf(cfile, "%s", pentry->identifier);
			break;
	}
}