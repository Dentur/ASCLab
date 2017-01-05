%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: Montag, 2. Januar 2017
****************************************************************************/

#include "mylexer.h"
#include "lexerHeader.h"
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section
%union {
	int num;
	char* str;
	bool bol;
	struct pt_entry* pt;
}

// attribute type
%include {
#ifndef YYSTYPE
#define YYSTYPE int
#endif
}
%token COMMANDEND
%token COMMENT
%token LOAD
%token NORTH
%token SOUTH
%token EAST
%token WEST
%token LEFT
%token RIGHT
%token FORWARD
%token BACK
%token BEGIN
%token END
%token MOVE
%token TURN
%token STEP
%token <str>STRING

%type <pt>program
%type <pt>loadLab
%type <pt>comments
%type <pt>cmdBlock
%type <pt>cmdSeq
%type <pt>cmd
%type <pt>direction
%type <pt>while_block
%type <pt>if_block
%type <pt>assignment
%type <pt>arith_expr
%type <pt>rel_expr
%type <pt>bool_expr
%type <pt>direction
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
					//TODO GENERATE C-FILE
				};
loadLab: 		LOAD STRING COMMANDEND
				{
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = LOAD;
					$$->str = $2;
				};
comments: 		COMMENT comments
				{
					//Do Nothing
				}
			  | COMMENT
				{
					//Do Nothing
				}
			  | ;
cmdBlock: 		BEGIN cmdSeq END
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
			  | RIGHT
			    {
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = DIRECTION;
					$$->num = 6;
			    }
			  | BACK
			    {
					$$ = (PT_ENTRY*) calloc(1, sizeof(PT_ENTRY));
					$$->type = DIRECTION;
					$$->num = 7;
			    };
%%

/////////////////////////////////////////////////////////////////////////////
// programs section

int main(void)
{
	return yyparse();
}

