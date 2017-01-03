%{
/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: Montag, 2. Januar 2017
****************************************************************************/

//#include "myparser.h"
#include "lexerHeader.h"
%}

/*
///////////////////////////////////////////////////////////////////////////
// declarations section
//--Syntaxmakierungen--
*/
SINGLE_COMMENT //[^\n]*\n

/*
//--Vergleichs_Operationen--
*/
LESSTHAN <=
LESS <
GREATERTHAN >=
GREATER >
EQUAL ==
NOTEQUAL !=

/*
// place any declarations here
*/

%%
RELATIV_DIRECTION_CONST  { return RELATIVE_DIRECTION;}
ABSOLUTE_DIRECTION_CONST { return ABSOLUTE_DIRECTION;}
DIRECTION_CONST			{ return DIRECTION;}
FLOOR_CONST				{ return FLOOR;}
ALL_DIRECTIONS_CONST    { return ALL_DIRECTIONS;}
WALLS_CONST				{ return WALLS;}
";"						{ return COMMANDEND;}
"{"						{ return BEGIN;}
"}"						{ return END;}
"("						{ return LEFTB;}
")"						{ return RIGHTB;}
SINGLE_COMMENT			{ return COMMENT;}
"true"					{ return TRUE;}
"false"					{ return FALSE;}
EQUAL					{ return EQ;}
NOTEQUAL				{ return NE;}
LESS					{ return LT;}
LESSTHAN				{ return LE;}
GREATER					{ return GT;}
GREATERTHAN				{ return GE;}
"="						{ return ASGN;}
"+"						{ return PLUS;}
"-"						{ return MINUS;}
\.						{ return CONCAT;}
"und"					{ return AND;}
"oder"					{ return OR;}
"nicht"					{ return NOT;}
"int"					{ return INT_VAR;}
"bool"					{ return BOOL_VAR;}
"direction"				{ return DIR_VAR;}
"wall"					{ return WALL_VAR;}
"turn"					{ return TURN;}
"move"					{ return MOVE;}
"step"					{ return STEP;}
"teleport"				{ return TELEPORT;}
"look"					{ return LOOK;}
"load"					{ return LOAD;}
"set_marker"			{ return SMARK;}
"set_stone"				{ return SSTONE;}
"marker_value"			{ return MVAL;}
"marker_direction"		{ return MDIR;}
"get_direction"			{ return GDIR;}
"position_x"			{ return POSX;}
"position_y"			{ return POSY;}
"goal_x"				{ return GOALX;}
"goal_y"				{ return GOALY;}
"get_marker_count"		{ return MTOTAL;}
"get_marker"			{ return MARKER;}
"delete_marker"			{ return MDELETE;}
"while"					{ return WHILE;}
"if"					{ return IF;}
"else"					{ return ELSE;}
"print"					{ return PRINT;}

[a-zA-Z_][a-zA-Z0-9_]*	{
						yylval.str = malloc( yyleng+1);
						strcpy( yylval.str, yytext);
						return IDENTIFIER;
						}
[1-9][0-9]*				{
						yylval.num = (int) atoi(yytext);
						return DIGIT;
						}

\"[^"]*\"				{
						yylval.str = malloc( yyleng-1);
						strncpy(yylval.str,yytext+1,yyleng-2);
						*(yylval.str+yyleng-2) = 0; // EOS
						return STRING;
						}
%%
/////////////////////////////////////////////////////////////////////////////
// programs section

extern FILE *yyin;
extern FILE *yyout;

yywrap() {
	fclose( yyin);
 	exit(1);
}

void printtoken(int token){
	switch( token)
	{
		case RELATIVE_DIRECTION:
			printf("RELATIVE_DIRECTION\n"); break;
		case ABSOLUTE_DIRECTION:
			printf("ABSOLUTE_DIRECTION\n"); break;
		case DIRECTION:
			printf("DIRECTION\n"); break;
		case FLOOR:
			printf("FLOOR\n"); break;
		case ALL_DIRECTIONS:
			printf("ALL_DIRECTIONS\n"); break;
		case WALLS:
			printf("WALLS\n"); break;
		case COMMANDEND:
			printf("COMMANDEND\n"); break;
		case BEGIN:
			printf("BEGIN\n"); break;
		case END:
			printf("END\n"); break;
		case LEFTB:
			printf("LEFTB\n"); break;
		case RIGHTB:
			printf("RIGHTB\n"); break;
		case COMMENT:
			printf("COMMENT\n"); break;
		case TRUE:
			printf("TRUE\n"); break;
		case FALSE:
			printf("FALSE\n"); break;
		case EQ:
			printf("EQ\n"); break;
		case NE:
			printf("NE\n"); break;
		case LT:
			printf("LT\n"); break;
		case LE:
			printf("LE\n"); break;
		case GT:
			printf("GT\n"); break;
		case GE:
			printf("GE\n"); break;
		case ASGN:
			printf("ASGN\n"); break;
		case PLUS:
			printf("PLUS\n"); break;
		case MINUS:
			printf("MINUS\n"); break;
		case CONCAT:
			printf("CONCAT\n"); break;
		case AND:
			printf("AND\n"); break;
		case OR:
			printf("OR\n"); break;
		case NOT:
			printf("NOT\n"); break;
		case INT_VAR:
			printf("INT_VAR\n"); break;
		case BOOL_VAR:
			printf("BOOL_VAR\n"); break;
		case DIR_VAR:
			printf("DIR_VAR\n"); break;
		case WALL_VAR:
			printf("WALL_VAR\n"); break;
		case TURN:
			printf("TURN\n"); break;
		case MOVE:
			printf("MOVE\n"); break;
		case STEP:
			printf("STEP\n"); break;
		case TELEPORT:
			printf("TELEPORT\n"); break;
		case LOOK:
			printf("LOOK\n"); break;
		case LOAD:
			printf("LOAD\n"); break;
		case SMARK:
			printf("SMARK\n"); break;
		case SSTONE:
			printf("SSTONE\n"); break;
		case MVAL:
			printf("MVAL\n"); break;
		case MDIR:
			printf("MDIR\n"); break;
		case GDIR:
			printf("GDIR\n"); break;
		case POSX:
			printf("POSX\n"); break;
		case POSY:
			printf("POSY\n"); break;
		case GOALX:
			printf("GOALX\n"); break;
		case GOALY:
			printf("GOALY\n"); break;
		case MTOTAL:
			printf("MTOTAL\n"); break;
		case MARKER:
			printf("MARKER\n"); break;
		case MDELETE:
			printf("MDELETE\n"); break;
		case WHILE:
			printf("WHILE\n"); break;
		case IF:
			printf("IF\n"); break;
		case ELSE:
			printf("ELSE\n"); break;
		case PRINT:
			printf("PRINT\n"); break;
		case IDENTIFIER:
			printf("IDENTIFIER (%s)\n", yylval.str); break;
		case STRING:
			printf("STRING (%s)\n", yylval.str); break;
		case DIGIT:
			printf("DIGIT (%g)\n", yylval.num); break;
		default:
			printf("Unknown Token: (%g)", token); break;
	}
}

void main( int argc, char *argv[]) {
	int token;
	yyout = stdout;
	yyin = fopen( "C:\\Users\\Tim\\Desktop\\FH\\ASC\\Project_Alt\\Input.txt", "r");
	while( (token = yylex()) > 0)
		printtoken( token);
}