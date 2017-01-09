%{
//#include "mylexer.h"
#include "lexerHeader.h"
#include "generator.h"
#include <stdio.h>
#include <stdlib.h>
void yyerror(char *s);    
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section
%union {
	int num;
	char* str;
	struct pt_entry* pt;
}

//UNUSED TOKENS
%token PRINT
%token MDELETE
%token MARKER
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
%token WALL_VAR
%token DIR_VAR
%token BOOL_VAR
%token INT_VAR
%token CONCAT
%token ASGN
%token FALSE
%token TRUE
%token FLOOR

//COMMAND TOKENS
%token COMMENT
%token LOAD
%token LOOK
%token MOVE
%token TURN
%token STEP
%token SSTONE
%token WHILE
%token IF
%token ELSE
%token IDENTIFIER
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
%token <str>VARIABLE
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
%type <pt>ret_cmd
%type <pt>direction
%type <pt>while_cmd
%type <pt>if_cmd
//%type <pt>assignment
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

program: 		comments loadLab comments cmdBlock comments
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = PROGRAM;
					$$->op1 = $2;
					$$->op2 = $4;
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
				}
			  | comments loadLab cmdBlock
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = PROGRAM;
					$$->op1 = $2;
					$$->op2 = $3;
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
					//Do Nothing
				}
			  | COMMENT
				{
					//Do Nothing
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
ret_cmd:		LOOK direction
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = LOOK_CMD_RET;
					$$->op1 = $2;
				};
cmd:			TURN direction COMMANDEND
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = TURN_CMD;
					$$->op1 = $2;
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
			  | while_cmd
			    {
					$$ = $1;
				}
			  | if_cmd
				{
					$$ = $1;
				}
			  | ret_cmd COMMANDEND
				{
					if($1->type == LOOK_CMD_RET){
						$1->type = LOOK_CMD;
					}
					$$ = $1;
				}
			  | BREAK COMMANDEND
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = BREAK_CMD;
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
			|	VARIABLE
				{
					$$ = (PT_ENTRY *)calloc( 1, sizeof( PT_ENTRY));
					$$->type = ID_VARIABLE;
					$$->identifier = $1;
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
			|   ret_cmd EQ wall
				{
					$$ = (PT_ENTRY *)calloc( 1, sizeof( PT_ENTRY));
					$$->type = OP_EQ;
					$$->op1 = $1;
					$$->op2 = $3;
				}
			|   ret_cmd NE wall
				{
					$$ = (PT_ENTRY *)calloc( 1, sizeof( PT_ENTRY));
					$$->type = OP_NE;
					$$->op1 = $1;
					$$->op2 = $3;
				}
			|	LEFTB bool_expr RIGHTB
				{
					$$ = $2;
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
			    };
%%

/////////////////////////////////////////////////////////////////////////////
// programs section

extern FILE *yyin;
extern FILE *yyout;

int main(int argc, char *argv[])
{
	yyout = stdout;
	if( argc > 1)
		yyin = fopen( argv[2], "r");
	else
		yyin = fopen("C:\\Users\\Tim\\Desktop\\FH\\ASC\\Project\\Testfiles\\testProg.txt", "r");
	yyparse();
}

