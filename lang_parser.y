%{
//#include "mylexer.h"
#include "lexerHeader.h"
#include "generator.h"
#include <stdio.h>
#include <stdlib.h>
void yyerror(char *s);  
void addToHeap(char* identifier, int type);
int isInHeap(char* identifier);
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section
%union {
	int num;
	char* str;
	struct pt_entry* pt;
}

//UNUSED TOKENS
%token CONCAT
%token FALSE
%token TRUE

//COMMAND TOKENS
%token PRINT
%token MARKER
%token WALL_VAR
%token DIR_VAR
%token BOOL_VAR
%token INT_VAR
%token ASGN
%token FLOOR
%token MDELETE
%token MTOTAL
%token GOALX
%token GOALY
%token POSX
%token POSY
%token GDIR
%token MDIR
%token MVAL
%token SMARK
%token TELEPORT
%token LOAD
%token LOOK
%token MOVE
%token TURN
%token STEP
%token SSTONE
%token WHILE
%token IF
%token ELSE
%token BREAK

//COMMAND HELPER
%token COMMANDEND
%token BEGIN_BLOCK
%token END_BLOCK
%token LEFTB
%token RIGHTB

//DIRECTION TOKEN
%token NORTH
%token EAST
%token SOUTH
%token WEST
%token FORWARD
%token LEFT
%token BACK
%token RIGHT


//WALL TOKEN
%token FREE
%token WALL
%token MARK
%token STONE
%token GOAL

//VALUE TOKEN
%token <str>STRING
%token COMMENT
%token <str>IDENTIFIER
%token <num>DIGIT

//OPERATION TOKEN
%left OR
%left AND
%left NOT
%left EQ NE GT LT GE LE
%left PLUS MINUS

//ENTRY TOKEN
%type <pt>program
%type <pt>loadLab
%type <pt>comments
%type <pt>cmdBlock
%type <pt>cmdSeq
%type <pt>cmd
%type <pt>ret_dir_cmd
%type <pt>ret_int_cmd
%type <pt>ret_wall_cmd
%type <pt>direction
%type <pt>while_cmd
%type <pt>if_cmd
%type <pt>assignment
%type <pt>arith_expr
%type <pt>rel_expr
%type <pt>bool_expr
%type <pt>wall

%start program

// place any declarations here

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)

program: 		comments loadLab cmdBlock
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = PROGRAM;
					$$->op1 = $2;
					$$->op2 = $3;
					createFile();
					generate($$);
					closeFile();
					//TODO GENERATE C-FILE
				}
			  | loadLab cmdBlock
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = PROGRAM;
					$$->op1 = $1;
					$$->op2 = $2;
					createFile();
					generate($$);
					closeFile();
					//TODO GENERATE C-FILE
				};
loadLab: 		LOAD STRING COMMANDEND
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = LOAD_CMD;
					$$->str = $2;
				};
comments: 		COMMENT comments
				{
					
				}
			  | COMMENT
				{
					
				};
cmdBlock: 		BEGIN_BLOCK cmdSeq END_BLOCK
				{
					$$ = $2;
				};
cmdSeq:			cmd cmdSeq
				{
					$1->nxt = $2;
					$$ = $1;
				}
			  | cmd
			    {
					$$ = $1;
			    };
ret_wall_cmd:	LOOK direction
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = LOOK_CMD_RET;
					$$->op1 = $2;
				};
ret_dir_cmd:	GDIR
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = GDIR_CMD_RET;
				}
			  | MDIR direction
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = MDIR_CMD_RET;
					$$->op1 = $2;
				};
ret_int_cmd:	MTOTAL
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = MTOTAL_CMD_RET;
				}
			  | POSX
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = POSX_CMD_RET;
				}
			  | POSY
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = POSY_CMD_RET;
				}
			  | GOALX
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = GOALX_CMD_RET;
				}
			  | GOALY
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = GOALY_CMD_RET;
				}
			  | MVAL direction
			    {
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = MVAL_CMD_RET;
					$$->op1 = $2;
				}
			  | MARKER arith_expr
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = MARKER_CMD_RET;
					$$->op1 = $2;
				};
cmd:			TURN direction COMMANDEND
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = TURN_CMD;
					$$->op1 = $2;
				}
			  | COMMENT
				{
					//
				}
			  | MOVE direction COMMANDEND
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = MOVE_CMD;
					$$->op1 = $2;
				}
			  | STEP direction COMMANDEND
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = STEP_CMD;
					$$->op1 = $2;
				}
			  | SSTONE direction COMMANDEND
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = SETSTONE_CMD;
					$$->op1 = $2;
				}
			  | SMARK direction direction arith_expr COMMANDEND
			    {
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = SETMARK_CMD;
					$$->op1 = $2;
					$$->op2 = $3;
					$$->op3 = $4;
				}
			  | TELEPORT arith_expr COMMANDEND
			    {
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = TELEPORT_CMD;
					$$->op1 = $2;
				}
			  | PRINT STRING COMMANDEND
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = PRINT_CMD;
					$$->str = $2;
				}
			  | while_cmd
			    {
					$$ = $1;
				}
			  | if_cmd
				{
					$$ = $1;
				}
			  | ret_wall_cmd COMMANDEND
				{
					$1->type = LOOK_CMD;
					$$ = $1;
				}
			  | ret_dir_cmd COMMANDEND
				{
					$1->type = GDIR_CMD;
					$$ = $1;
				}
			  | ret_int_cmd COMMANDEND
				{
					switch($1->type){
						case MTOTAL_CMD_RET:
							$1->type = MTOTAL_CMD;
							break;
						case POSX_CMD_RET:
							$1->type = POSX_CMD;
							break;
						case POSY_CMD_RET:
							$1->type = POSY_CMD;
							break;
						case GOALX_CMD_RET:
							$1->type = GOALX_CMD;
							break;
						case GOALY_CMD_RET:
							$1->type = GOALY_CMD;
							break;
						case MVAL_CMD_RET:
							$1->type = MVAL_CMD;
							break;
						case MARKER_CMD_RET:
							$1->type = MARKER_CMD;
							break;
					}
					$$ = $1;
				}
			  | MDELETE direction COMMANDEND
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = MDELETE_CMD;
					$$->op1 = $2;
				}
			  | BREAK COMMANDEND
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = BREAK_CMD;
				}
			  | assignment
			    {
					$$ = $1;
				};
assignment:		INT_VAR IDENTIFIER COMMANDEND
				{
					if(isInHeap($2) != -1){
						yyerror("Variable is already declared!");
						return;
					}
					addToHeap($2, 0);
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = NEW_ASSIGN;
					$$->num = 0;
					$$->identifier = $2;
				}
			  | IDENTIFIER ASGN arith_expr COMMANDEND
			    {
					int hType = isInHeap($1);
					if(hType == -1){
						yyerror("Variable is not declared!");
						return;
					} else if(hType != 0){
						yyerror("The desired Variable isn't of type \"int\"!");
						return;
					}
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = ASSIGN;
					$$->identifier = $1;
					$$->num = 0;
					$$->op1 = $3;
				}
			  | IDENTIFIER ASGN ret_int_cmd COMMANDEND
			    {
					int hType = isInHeap($1);
					if(hType == -1){
						yyerror("Variable is not declared!");
						return;
					} else if(hType != 0){
						yyerror("The desired Variable isn't of type \"int\"!");
						return;
					}
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = ASSIGN;
					$$->identifier = $1;
					$$->num = 0;
					$$->op1 = $3;
				}
			  | DIR_VAR IDENTIFIER COMMANDEND
			    {
					if(isInHeap($2) != -1){
						yyerror("Variable is already declared!");
						return;
					}
					addToHeap($2, 1);
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = NEW_ASSIGN;
					$$->num = 1;
					$$->identifier = $2;
				}
			  | IDENTIFIER ASGN direction COMMANDEND
			    {
					int hType = isInHeap($1);
					if(hType == -1){
						yyerror("Variable is not declared!");
						return;
					} else if(hType != 1){
						yyerror("The desired Variable isn't of type \"direction\"!");
						return;
					}
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = ASSIGN;
					$$->identifier = $1;
					$$->num = 1;
					$$->op1 = $3;
				}
			  | IDENTIFIER ASGN ret_dir_cmd COMMANDEND
			    {
					int hType = isInHeap($1);
					if(hType == -1){
						yyerror("Variable is not declared!");
						return;
					} else if(hType != 1){
						yyerror("The desired Variable isn't of type \"direction\"!");
						return;
					}
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = ASSIGN;
					$$->identifier = $1;
					$$->num = 1;
					$$->op1 = $3;
				}
			  | BOOL_VAR IDENTIFIER COMMANDEND
			    {
					if(isInHeap($2) != -1){
						yyerror("Variable is already declared!");
						return;
					}
					addToHeap($2, 2);
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = NEW_ASSIGN;
					$$->num = 2;
					$$->identifier = $2;
				}
			  | IDENTIFIER ASGN bool_expr COMMANDEND
			    {
					int hType = isInHeap($1);
					if(hType == -1){
						yyerror("Variable is not declared!");
						return;
					} else if(hType != 2){
						yyerror("The desired Variable isn't of type \"bool\"!");
						return;
					}
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = ASSIGN;
					$$->identifier = $1;
					$$->num = 2;
					$$->op1 = $3;
				}
			  | WALL_VAR IDENTIFIER COMMANDEND
			    {
					if(isInHeap($2) != -1){
						yyerror("Variable is already declared!");
						return;
					}
					addToHeap($2, 3);
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = NEW_ASSIGN;
					$$->num = 3;
					$$->identifier = $2;
				}
			  | IDENTIFIER ASGN ret_wall_cmd COMMANDEND
			    {
					int hType = isInHeap($1);
					if(hType == -1){
						yyerror("Variable is not declared!");
						return;
					} else if(hType != 3){
						yyerror("The desired Variable isn't of type \"wall\"!");
						return;
					}
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = ASSIGN;
					$$->identifier = $1;
					$$->num = 3;
					$$->op1 = $3;
				}
			  | IDENTIFIER ASGN wall COMMANDEND
			    {
					int hType = isInHeap($1);
					if(hType == -1){
						yyerror("Variable is not declared!");
						return;
					} else if(hType != 3){
						yyerror("The desired Variable isn't of type \"wall\"!");
						return;
					}
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = ASSIGN;
					$$->identifier = $1;
					$$->num = 3;
					$$->op1 = $3;
				};
if_cmd	:		IF bool_expr cmdBlock
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = IF_CMD;
					$$->op1 = $2;
					$$->op2 = $3;	
				}
			|	IF bool_expr cmdBlock ELSE cmdBlock
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = IF_CMD;
					$$->op1 = $2;
					$$->op2 = $3;
					$$->op3 = $5;
				};
while_cmd :		WHILE bool_expr cmdBlock
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = WHILE_CMD;
					$$->op1 = $2;
					$$->op2 = $3;	
				};
arith_expr :	DIGIT
				{
					$$ = (PT_ENTRY *)calloc( 1, sizeof( PT_ENTRY));
					$$->type = VAL_DIGIT;
					$$->num = $1;
				}
			|	IDENTIFIER
				{
					int hType = isInHeap($1);
					if(hType == -1){
						yyerror("Variable is not declared!");
						return;
					} else if(hType != 0){
						yyerror("The desired Variable isn't of type \"int\"!");
						return;
					}
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = USE_VARIABLE;
					$$->identifier = $1;
				}
			|	ret_int_cmd
				{
					$$ = $1;
				}
			|	MINUS arith_expr
				{
					$$ = (PT_ENTRY *)calloc( 1, sizeof( PT_ENTRY));
					$$->type = OP_UMINUS;
					$$->op1 = $2;
				}
			|	LEFTB arith_expr RIGHTB
				{
					$$ = $2;
				}
			|	arith_expr PLUS arith_expr
				{
					$$ = (PT_ENTRY *)calloc( 1, sizeof( PT_ENTRY));
					$$->type = OP_PLUS;
					$$->op1 = $1;
					$$->op2 = $3;
				}
			|	arith_expr MINUS arith_expr
				{
					$$ = (PT_ENTRY *)calloc( 1, sizeof( PT_ENTRY));
					$$->type = OP_MINUS;
					$$->op1 = $1;
					$$->op2 = $3;
				};
rel_expr :		arith_expr EQ arith_expr
				{
					$$ = (PT_ENTRY *)calloc( 1, sizeof( PT_ENTRY));
					$$->type = OP_EQ;
					$$->op1 = $1;
					$$->op2 = $3;
				}
			|	arith_expr NE arith_expr
				{
					$$ = (PT_ENTRY *)calloc( 1, sizeof( PT_ENTRY));
					$$->type = OP_NE;
					$$->op1 = $1;
					$$->op2 = $3;
				}
			|	arith_expr LT arith_expr
				{
					$$ = (PT_ENTRY *)calloc( 1, sizeof( PT_ENTRY));
					$$->type = OP_LT;
					$$->op1 = $1;
					$$->op2 = $3;
				}
			|	arith_expr LE arith_expr
				{
					$$ = (PT_ENTRY *)calloc( 1, sizeof( PT_ENTRY));
					$$->type = OP_LE;
					$$->op1 = $1;
					$$->op2 = $3;
				}
			|	arith_expr GT arith_expr
				{
					$$ = (PT_ENTRY *)calloc( 1, sizeof( PT_ENTRY));
					$$->type = OP_GT;
					$$->op1 = $1;
					$$->op2 = $3;
				}
			|	arith_expr GE arith_expr
				{
					$$ = (PT_ENTRY *)calloc( 1, sizeof( PT_ENTRY));
					$$->type = OP_GE;
					$$->op1 = $1;
					$$->op2 = $3;
				};
bool_expr	:	rel_expr
				{
					$$ = $1;
				}
			|	NOT rel_expr
				{
					$$ = (PT_ENTRY *)calloc( 1, sizeof( PT_ENTRY));
					$$->type = OP_NOT;
					$$->op1 = $2;
				}
			|	bool_expr OR bool_expr
				{
					$$ = (PT_ENTRY *)calloc( 1, sizeof( PT_ENTRY));
					$$->type = OP_OR;
					$$->op1 = $1;
					$$->op2 = $3;
				}
			|	bool_expr AND bool_expr
				{
					$$ = (PT_ENTRY *)calloc( 1, sizeof( PT_ENTRY));
					$$->type = OP_AND;
					$$->op1 = $1;
					$$->op2 = $3;
				}
			
			|   direction EQ direction
				{
					$$ = (PT_ENTRY *)calloc( 1, sizeof( PT_ENTRY));
					$$->type = OP_EQ;
					$$->op1 = $1;
					$$->op2 = $3;
				}
			|   direction NE direction
				{
					$$ = (PT_ENTRY *)calloc( 1, sizeof( PT_ENTRY));
					$$->type = OP_NE;
					$$->op1 = $1;
					$$->op2 = $3;
				}
			|   wall EQ wall
				{
					$$ = (PT_ENTRY *)calloc( 1, sizeof( PT_ENTRY));
					$$->type = OP_EQ;
					$$->op1 = $1;
					$$->op2 = $3;
				}
			|   wall NE wall
				{
					$$ = (PT_ENTRY *)calloc( 1, sizeof( PT_ENTRY));
					$$->type = OP_NE;
					$$->op1 = $1;
					$$->op2 = $3;
				}
			|   ret_wall_cmd EQ wall
				{
					$$ = (PT_ENTRY *)calloc( 1, sizeof( PT_ENTRY));
					$$->type = OP_EQ;
					$$->op1 = $1;
					$$->op2 = $3;
				}
			|   ret_wall_cmd NE wall
				{
					$$ = (PT_ENTRY *)calloc( 1, sizeof( PT_ENTRY));
					$$->type = OP_NE;
					$$->op1 = $1;
					$$->op2 = $3;
				}
			|	LEFTB bool_expr RIGHTB
				{
					$$ = $2;
				}
			| 	IDENTIFIER
				{
					int hType = isInHeap($1);
					if(hType == -1){
						yyerror("Variable is not declared!");
						return;
					} else if(hType != 2){
						yyerror("The desired Variable isn't of type \"bool\"!");
						return;
					}
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = USE_VARIABLE;
					$$->identifier = $1;
				};	
wall:			FREE
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = WALL_TYPE;
					$$->num = 0;
				}
			  | WALL
			    {
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = WALL_TYPE;
					$$->num = 1;
			    }
			  | MARK
			    {
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = WALL_TYPE;
					$$->num = 2;
			    }
			  | STONE
			    {
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = WALL_TYPE;
					$$->num = 3;
			    }
			  | GOAL
			    {
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = WALL_TYPE;
					$$->num = 4;
			    }
			  | IDENTIFIER
				{
					int hType = isInHeap($1);
					if(hType == -1){
						yyerror("Variable is not declared!");
						return;
					} else if(hType != 3){
						yyerror("The desired Variable isn't of type \"wall\"!");
						return;
					}
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = USE_VARIABLE;
					$$->identifier = $1;
				};
direction:		NORTH
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = DIRECTION;
					$$->num = 0;
				}
			  | EAST
			    {
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = DIRECTION;
					$$->num = 1;
			    }
			  | SOUTH
			    {
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = DIRECTION;
					$$->num = 2;
			    }
			  | WEST
			    {
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = DIRECTION;
					$$->num = 3;
			    }
			  | FORWARD
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = DIRECTION;
					$$->num = 4;
				}
			  | LEFT
			    {
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = DIRECTION;
					$$->num = 5;
			    }
			  | BACK
			    {
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = DIRECTION;
					$$->num = 6;
			    }
			  | RIGHT
			    {
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = DIRECTION;
					$$->num = 7;
			    }
			  | FLOOR
			    {
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = DIRECTION;
					$$->num = 8;
				}
			  | IDENTIFIER
				{
					int hType = isInHeap($1);
					if(hType == -1){
						yyerror("Variable is not declared!");
						return;
					} else if(hType != 1){
						yyerror("The desired Variable isn't of type \"direction\"!");
						return;
					}
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = USE_VARIABLE;
					$$->identifier = $1;
				};
%%

/////////////////////////////////////////////////////////////////////////////
// programs section

extern FILE *yyin;
extern FILE *yyout;
struct list {
	char* identifier;
	int type;
	struct list* next; 
};

struct list* myHeap;
void addToHeap(char* identifier, int type)
{
	if(myHeap == NULL) {
		myHeap =  (struct list*)calloc( 1, sizeof(struct list*));
		myHeap->identifier = (char*) malloc(strlen(identifier) + 1);
		strcpy(myHeap->identifier, identifier);
		myHeap->type = type;
		myHeap->next = 0;
	} else {
		struct list* _new = (struct list*)calloc(1, sizeof(struct list*));
		_new->identifier = (char*)malloc(strlen(identifier) + 1);
		strcpy(_new->identifier, identifier);
		_new->type = type;
		_new->next = myHeap;
		myHeap = _new;
	}
}

int isInHeap(char* identifier)
{
	struct list* node = myHeap;
	for(; node; node = node->next) {
		if (strcmp(identifier,node->identifier) == 0) {
			return node->type;
		}
	}
	return -1;
}

int main(int argc, char *argv[])
{
	yyout = stdout;
	if( argc > 1)
		yyin = fopen( argv[1], "r");
	else
		yyin = fopen(stdin, "r");
	yyparse();
}

