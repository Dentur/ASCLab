%{
//#include "myparser.h"
#include "lang_parser.tab.h"

int curCMD = 0;
int startCMD = -1;
%}

/*
///////////////////////////////////////////////////////////////////////////
// declarations section
*/
%s LOOP
%option yylineno

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
"{"						{ curCMD++; return BEGIN_BLOCK;}
"}"						{ 
							if(startCMD >= 0){
								curCMD--;
								if(curCMD == startCMD){
									startCMD = -1;
									BEGIN 0;
								}
							}
							return END_BLOCK;}
"("						{ return LEFTB;}
")"						{ return RIGHTB;}
"true"					{ return TRUE;}
"false"					{ return FALSE;}
"=="					{ return EQ;}
"!="					{ return NE;}
"<"						{ return LT;}
"<="					{ return LE;}
">"						{ return GT;}
">="					{ return GE;}
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
"while"					{ 
							BEGIN LOOP;
							return WHILE;
						}
"if"					{ return IF;}
"else"					{ return ELSE;}
"print"					{ return PRINT;}
<LOOP>"break"			{ return BREAK;}
"//"[^~]* 				{ 
						yylval.str = malloc( yyleng+1);
						strcpy( yylval.str, yytext);
						return COMMENT; }
"i_"[a-zA-Z][a-zA-Z0-9_]*		{
						yylval.str = malloc( yyleng+1);
						strcpy( yylval.str, yytext);
						return INT_IDENTIFIER;
						}
"d_"[a-zA-Z][a-zA-Z0-9_]*		{
						yylval.str = malloc( yyleng+1);
						strcpy( yylval.str, yytext);
						return DIR_IDENTIFIER;
						}
"w_"[a-zA-Z][a-zA-Z0-9_]*		{
						yylval.str = malloc( yyleng+1);
						strcpy( yylval.str, yytext);
						return WALL_IDENTIFIER;
						}
"b_"[a-zA-Z][a-zA-Z0-9_]*		{
						yylval.str = malloc( yyleng+1);
						strcpy( yylval.str, yytext);
						return BOOL_IDENTIFIER;
						}
[0-9][0-9]*				{
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
  fprintf (stderr, "Line %d: %s at %s\n",yylineno, s, yytext);
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