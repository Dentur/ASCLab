#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include "generator.h"

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
    cfile = fopen("C:\\Users\\Tim\\Desktop\\program.cpp", "w");
}

void closeFile () {
	fclose(cfile);
}

void generate( PT_ENTRY *pentry) {
	switch(pentry->type)
	{
		case PROGRAM :
			fprintf(cfile, "#include \"Labyrinth.h\"\n");
			fprintf(cfile, "using namespace std;\n\n");

			//Main function
			fprintf(cfile, "int main() {\n");
			fprintf(cfile, "Labyrinth lab();\n");
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
			
		case VAL_DIGIT:
			fprintf(cfile, "%d", pentry->num);
			break;
			
		case ID_VARIABLE :
			fprintf(cfile, "%s", pentry->identifier);
			break;
	}
}