%{
//#include "myparser.h"
#include "lang_parser.tab.h"
%}

/*
///////////////////////////////////////////////////////////////////////////
// declarations section
*/
%option yylineno

/*
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
"NORTH"					{ return NORTH;}
"SOUTH"					{ return SOUTH;}
"EAST"					{ return EAST;}
"WEST"					{ return WEST;}
"LEFT"					{ return LEFT;}
"RIGHT"					{ return RIGHT;}
"BACK"					{ return BACK;}
"FORWARD"				{ return FORWARD;}
"THIS"					{ return FLOOR;}
"FREE"					{ return FREE;}
"WALL"					{ return WALL;}
"GOAL"					{ return GOAL;}
"MARK"					{ return MARK;}
"STONE"					{ return STONE;}
";"						{ return COMMANDEND;}
"{"						{ return BEGIN_BLOCK;}
"}"						{ return END_BLOCK;}
"("						{ return LEFTB;}
")"						{ return RIGHTB;}
SINGLE_COMMENT			{ return COMMENT;}
"true"					{ return TRUE;}
"false"					{ return FALSE;}
"=="					{ return EQ;}
"!="					{ return NE;}
LESS					{ return LT;}
LESSTHAN				{ return LE;}
GREATER					{ return GT;}
GREATERTHAN				{ return GE;}
"="						{ return ASGN;}
"+"						{ return PLUS;}
"-"						{ return MINUS;}
\.						{ return CONCAT;}
"AND"					{ return AND;}
"OR"					{ return OR;}
"NOT"					{ return NOT;}
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
"break"					{ return BREAK;}

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
[ \t]+				; //Ignoriere Whitespace
\n			;
.					{
						printf("Unexpected token: %c\n", *yytext);
					}
%%
//extern FILE *yyin;
//extern FILE *yyout;

void yyerror (char const *s)
{
  fprintf (stderr, "Line %d: %s at %s",yylineno, s, yytext);
}

yywrap() {
	fclose( yyin);
 	exit(1);
}

/*void printtoken(int toke){
	switch(token){
		case LOAD:
			printf("LOAD\n");
			break;
		case STRING:
			printf("STRING\n");
			break;
	}
}

int main( int argc, char *argv[]) {
	int token;
 	yyout = stdout;
 	yyin = fopen( "C:\\Users\\Tim\\Desktop\\FH\\ASC\\Project\\Testfiles\\testProg.txt", "r");
 	while( (token = yylex()) > 0)
 		printtoken( token);
	return 0;
}*/