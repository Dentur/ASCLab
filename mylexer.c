/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 1 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* mylexer.c
* C source file generated from mylexer.l.
* 
* Date: 01/02/17
* Time: 16:35:43
* 
* ALex Version: 2.07
****************************************************************************/

#include <yylex.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTLEXER

#line 1 ".\\mylexer.l"

/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: Montag, 2. Januar 2017
****************************************************************************/

//#include "myparser.h"
#include "lexerHeader.h"

#line 52 "mylexer.c"
/* repeated because of possible precompiled header */
#include <yylex.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTLEXER

#include ".\mylexer.h"

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/* yytext */
static char YYNEAR yysatext[(YYTEXT_SIZE) + 1];		/* extra char for \0 */
char YYFAR *YYNEAR YYDCDECL yystext = yysatext;
char YYFAR *YYNEAR YYDCDECL yytext = yysatext;
int YYNEAR YYDCDECL yystext_size = (YYTEXT_SIZE);
int YYNEAR YYDCDECL yytext_size = (YYTEXT_SIZE);
int YYNEAR YYDCDECL yytext_max = (YYTEXT_MAX);

/* yystatebuf */
#if (YYTEXT_SIZE) != 0
static int YYNEAR yysastatebuf[(YYTEXT_SIZE)];
int YYFAR *YYNEAR YYDCDECL yysstatebuf = yysastatebuf;
int YYFAR *YYNEAR YYDCDECL yystatebuf = yysastatebuf;
#else
int YYFAR *YYNEAR YYDCDECL yysstatebuf = NULL;
int YYFAR *YYNEAR YYDCDECL yystatebuf = NULL;
#endif

/* yyunputbuf */
#if (YYUNPUT_SIZE) != 0
static int YYNEAR yysaunputbuf[(YYUNPUT_SIZE)];
int YYFAR *YYNEAR YYDCDECL yysunputbufptr = yysaunputbuf;
int YYFAR *YYNEAR YYDCDECL yyunputbufptr = yysaunputbuf;
#else
int YYFAR *YYNEAR YYDCDECL yysunputbufptr = NULL;
int YYFAR *YYNEAR YYDCDECL yyunputbufptr = NULL;
#endif
int YYNEAR YYDCDECL yysunput_size = (YYUNPUT_SIZE);
int YYNEAR YYDCDECL yyunput_size = (YYUNPUT_SIZE);
int YYNEAR YYDCDECL yyunput_max = (YYUNPUT_MAX);

/* backwards compatability with lex */
#ifdef input
#ifdef YYPROTOTYPE
int YYCDECL yyinput(void)
#else
int YYCDECL yyinput()
#endif
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
#ifdef YYPROTOTYPE
void YYCDECL yyoutput(int ch)
#else
void YYCDECL yyoutput(ch)
int ch;
#endif
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
#ifdef YYPROTOTYPE
void YYCDECL yyunput(int ch)
#else
void YYCDECL yyunput(ch)
int ch;
#endif
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		/* <warning: unreachable code> off */
#endif
#endif

#ifdef YYPROTOTYPE
int YYCDECL yylexeraction(int action)
#else
int YYCDECL yylexeraction(action)
int action;
#endif
{
	yyreturnflg = YYTRUE;
	switch (action) {
	case 1:
		{
#line 35 ".\\mylexer.l"
 return RELATIVE_DIRECTION;
#line 173 "mylexer.c"
		}
		break;
	case 2:
		{
#line 36 ".\\mylexer.l"
 return ABSOLUTE_DIRECTION;
#line 180 "mylexer.c"
		}
		break;
	case 3:
		{
#line 37 ".\\mylexer.l"
 return DIRECTION;
#line 187 "mylexer.c"
		}
		break;
	case 4:
		{
#line 38 ".\\mylexer.l"
 return FLOOR;
#line 194 "mylexer.c"
		}
		break;
	case 5:
		{
#line 39 ".\\mylexer.l"
 return ALL_DIRECTIONS;
#line 201 "mylexer.c"
		}
		break;
	case 6:
		{
#line 40 ".\\mylexer.l"
 return WALLS;
#line 208 "mylexer.c"
		}
		break;
	case 7:
		{
#line 41 ".\\mylexer.l"
 return COMMANDEND;
#line 215 "mylexer.c"
		}
		break;
	case 8:
		{
#line 42 ".\\mylexer.l"
 return BEGIN;
#line 222 "mylexer.c"
		}
		break;
	case 9:
		{
#line 43 ".\\mylexer.l"
 return END;
#line 229 "mylexer.c"
		}
		break;
	case 10:
		{
#line 44 ".\\mylexer.l"
 return LEFTB;
#line 236 "mylexer.c"
		}
		break;
	case 11:
		{
#line 45 ".\\mylexer.l"
 return RIGHTB;
#line 243 "mylexer.c"
		}
		break;
	case 12:
		{
#line 46 ".\\mylexer.l"
 return COMMENT;
#line 250 "mylexer.c"
		}
		break;
	case 13:
		{
#line 47 ".\\mylexer.l"
 return TRUE;
#line 257 "mylexer.c"
		}
		break;
	case 14:
		{
#line 48 ".\\mylexer.l"
 return FALSE;
#line 264 "mylexer.c"
		}
		break;
	case 15:
		{
#line 49 ".\\mylexer.l"
 return EQ;
#line 271 "mylexer.c"
		}
		break;
	case 16:
		{
#line 50 ".\\mylexer.l"
 return NE;
#line 278 "mylexer.c"
		}
		break;
	case 17:
		{
#line 51 ".\\mylexer.l"
 return LT;
#line 285 "mylexer.c"
		}
		break;
	case 18:
		{
#line 52 ".\\mylexer.l"
 return LE;
#line 292 "mylexer.c"
		}
		break;
	case 19:
		{
#line 53 ".\\mylexer.l"
 return GT;
#line 299 "mylexer.c"
		}
		break;
	case 20:
		{
#line 54 ".\\mylexer.l"
 return GE;
#line 306 "mylexer.c"
		}
		break;
	case 21:
		{
#line 55 ".\\mylexer.l"
 return ASGN;
#line 313 "mylexer.c"
		}
		break;
	case 22:
		{
#line 56 ".\\mylexer.l"
 return PLUS;
#line 320 "mylexer.c"
		}
		break;
	case 23:
		{
#line 57 ".\\mylexer.l"
 return MINUS;
#line 327 "mylexer.c"
		}
		break;
	case 24:
		{
#line 58 ".\\mylexer.l"
 return CONCAT;
#line 334 "mylexer.c"
		}
		break;
	case 25:
		{
#line 59 ".\\mylexer.l"
 return AND;
#line 341 "mylexer.c"
		}
		break;
	case 26:
		{
#line 60 ".\\mylexer.l"
 return OR;
#line 348 "mylexer.c"
		}
		break;
	case 27:
		{
#line 61 ".\\mylexer.l"
 return NOT;
#line 355 "mylexer.c"
		}
		break;
	case 28:
		{
#line 62 ".\\mylexer.l"
 return INT_VAR;
#line 362 "mylexer.c"
		}
		break;
	case 29:
		{
#line 63 ".\\mylexer.l"
 return BOOL_VAR;
#line 369 "mylexer.c"
		}
		break;
	case 30:
		{
#line 64 ".\\mylexer.l"
 return DIR_VAR;
#line 376 "mylexer.c"
		}
		break;
	case 31:
		{
#line 65 ".\\mylexer.l"
 return WALL_VAR;
#line 383 "mylexer.c"
		}
		break;
	case 32:
		{
#line 66 ".\\mylexer.l"
 return TURN;
#line 390 "mylexer.c"
		}
		break;
	case 33:
		{
#line 67 ".\\mylexer.l"
 return MOVE;
#line 397 "mylexer.c"
		}
		break;
	case 34:
		{
#line 68 ".\\mylexer.l"
 return STEP;
#line 404 "mylexer.c"
		}
		break;
	case 35:
		{
#line 69 ".\\mylexer.l"
 return TELEPORT;
#line 411 "mylexer.c"
		}
		break;
	case 36:
		{
#line 70 ".\\mylexer.l"
 return LOOK;
#line 418 "mylexer.c"
		}
		break;
	case 37:
		{
#line 71 ".\\mylexer.l"
 return LOAD;
#line 425 "mylexer.c"
		}
		break;
	case 38:
		{
#line 72 ".\\mylexer.l"
 return SMARK;
#line 432 "mylexer.c"
		}
		break;
	case 39:
		{
#line 73 ".\\mylexer.l"
 return SSTONE;
#line 439 "mylexer.c"
		}
		break;
	case 40:
		{
#line 74 ".\\mylexer.l"
 return MVAL;
#line 446 "mylexer.c"
		}
		break;
	case 41:
		{
#line 75 ".\\mylexer.l"
 return MDIR;
#line 453 "mylexer.c"
		}
		break;
	case 42:
		{
#line 76 ".\\mylexer.l"
 return GDIR;
#line 460 "mylexer.c"
		}
		break;
	case 43:
		{
#line 77 ".\\mylexer.l"
 return POSX;
#line 467 "mylexer.c"
		}
		break;
	case 44:
		{
#line 78 ".\\mylexer.l"
 return POSY;
#line 474 "mylexer.c"
		}
		break;
	case 45:
		{
#line 79 ".\\mylexer.l"
 return GOALX;
#line 481 "mylexer.c"
		}
		break;
	case 46:
		{
#line 80 ".\\mylexer.l"
 return GOALY;
#line 488 "mylexer.c"
		}
		break;
	case 47:
		{
#line 81 ".\\mylexer.l"
 return MTOTAL;
#line 495 "mylexer.c"
		}
		break;
	case 48:
		{
#line 82 ".\\mylexer.l"
 return MARKER;
#line 502 "mylexer.c"
		}
		break;
	case 49:
		{
#line 83 ".\\mylexer.l"
 return MDELETE;
#line 509 "mylexer.c"
		}
		break;
	case 50:
		{
#line 84 ".\\mylexer.l"
 return WHILE;
#line 516 "mylexer.c"
		}
		break;
	case 51:
		{
#line 85 ".\\mylexer.l"
 return IF;
#line 523 "mylexer.c"
		}
		break;
	case 52:
		{
#line 86 ".\\mylexer.l"
 return ELSE;
#line 530 "mylexer.c"
		}
		break;
	case 53:
		{
#line 87 ".\\mylexer.l"
 return PRINT;
#line 537 "mylexer.c"
		}
		break;
	case 54:
		{
#line 89 ".\\mylexer.l"

						yylval.str = malloc( yyleng+1);
						strcpy( yylval.str, yytext);
						return IDENTIFIER;
						
#line 548 "mylexer.c"
		}
		break;
	case 55:
		{
#line 94 ".\\mylexer.l"

						yylval.num = (int) atoi(yytext);
						return DIGIT;
						
#line 558 "mylexer.c"
		}
		break;
	case 56:
		{
#line 99 ".\\mylexer.l"

						yylval.str = malloc( yyleng-1);
						strncpy(yylval.str,yytext+1,yyleng-2);
						*(yylval.str+yyleng-2) = 0; // EOS
						return STRING;
						
#line 570 "mylexer.c"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = YYFALSE;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		/* <warning: unreachable code> to the old state */
#endif
#endif
YYCONST yymatch_t YYNEARFAR YYBASED_CODE YYDCDECL yymatch[] = {
	0
};

int YYNEAR YYDCDECL yytransitionmax = 410;
YYCONST yytransition_t YYNEARFAR YYBASED_CODE YYDCDECL yytransition[] = {
	{ 0, 0 },
	{ 3, 1 },
	{ 53, 24 },
	{ 259, 243 },
	{ 260, 243 },
	{ 44, 15 },
	{ 54, 24 },
	{ 4, 1 },
	{ 5, 1 },
	{ 223, 204 },
	{ 6, 1 },
	{ 62, 30 },
	{ 7, 1 },
	{ 8, 1 },
	{ 68, 34 },
	{ 0, 1 },
	{ 9, 1 },
	{ 9, 1 },
	{ 9, 1 },
	{ 9, 1 },
	{ 9, 1 },
	{ 9, 1 },
	{ 9, 1 },
	{ 9, 1 },
	{ 9, 1 },
	{ 63, 30 },
	{ 10, 1 },
	{ 224, 204 },
	{ 11, 1 },
	{ 69, 34 },
	{ 41, 12 },
	{ 70, 35 },
	{ 12, 1 },
	{ 158, 127 },
	{ 95, 61 },
	{ 14, 1 },
	{ 15, 1 },
	{ 16, 1 },
	{ 17, 1 },
	{ 74, 37 },
	{ 42, 12 },
	{ 57, 27 },
	{ 159, 127 },
	{ 18, 1 },
	{ 71, 35 },
	{ 19, 1 },
	{ 75, 37 },
	{ 72, 35 },
	{ 96, 61 },
	{ 20, 1 },
	{ 21, 1 },
	{ 58, 27 },
	{ 183, 160 },
	{ 184, 160 },
	{ 22, 1 },
	{ 9, 9 },
	{ 9, 9 },
	{ 9, 9 },
	{ 9, 9 },
	{ 9, 9 },
	{ 9, 9 },
	{ 9, 9 },
	{ 9, 9 },
	{ 9, 9 },
	{ 9, 9 },
	{ 23, 1 },
	{ 59, 28 },
	{ 24, 1 },
	{ 25, 1 },
	{ 26, 1 },
	{ 27, 1 },
	{ 61, 29 },
	{ 28, 1 },
	{ 45, 16 },
	{ 60, 28 },
	{ 29, 1 },
	{ 30, 1 },
	{ 31, 1 },
	{ 32, 1 },
	{ 33, 1 },
	{ 64, 31 },
	{ 165, 137 },
	{ 34, 1 },
	{ 35, 1 },
	{ 36, 1 },
	{ 66, 33 },
	{ 37, 1 },
	{ 166, 137 },
	{ 67, 33 },
	{ 65, 32 },
	{ 38, 1 },
	{ 46, 17 },
	{ 39, 1 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 47, 18 },
	{ 48, 19 },
	{ 73, 36 },
	{ 49, 20 },
	{ 76, 41 },
	{ 77, 42 },
	{ 78, 43 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 79, 44 },
	{ 80, 45 },
	{ 81, 46 },
	{ 82, 47 },
	{ 13, 330 },
	{ 83, 48 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 13, 330 },
	{ 84, 49 },
	{ 85, 50 },
	{ 86, 51 },
	{ 87, 52 },
	{ 88, 53 },
	{ 89, 54 },
	{ 90, 55 },
	{ 91, 56 },
	{ 92, 57 },
	{ 93, 58 },
	{ 94, 60 },
	{ 50, 21 },
	{ 97, 62 },
	{ 98, 63 },
	{ 99, 64 },
	{ 100, 65 },
	{ 101, 66 },
	{ 102, 67 },
	{ 103, 68 },
	{ 104, 69 },
	{ 105, 70 },
	{ 106, 71 },
	{ 107, 72 },
	{ 108, 73 },
	{ 109, 74 },
	{ 110, 75 },
	{ 111, 76 },
	{ 112, 77 },
	{ 113, 78 },
	{ 114, 79 },
	{ 115, 80 },
	{ 116, 81 },
	{ 117, 82 },
	{ 118, 83 },
	{ 119, 84 },
	{ 120, 85 },
	{ 121, 86 },
	{ 122, 87 },
	{ 123, 88 },
	{ 124, 89 },
	{ 125, 90 },
	{ 126, 91 },
	{ 127, 92 },
	{ 128, 93 },
	{ 129, 95 },
	{ 130, 96 },
	{ 131, 97 },
	{ 132, 98 },
	{ 133, 99 },
	{ 134, 100 },
	{ 135, 101 },
	{ 136, 102 },
	{ 137, 103 },
	{ 138, 104 },
	{ 139, 105 },
	{ 140, 106 },
	{ 141, 107 },
	{ 142, 109 },
	{ 143, 110 },
	{ 144, 111 },
	{ 145, 112 },
	{ 146, 113 },
	{ 147, 114 },
	{ 148, 115 },
	{ 149, 116 },
	{ 150, 117 },
	{ 151, 118 },
	{ 152, 119 },
	{ 153, 120 },
	{ 154, 121 },
	{ 155, 123 },
	{ 156, 124 },
	{ 157, 126 },
	{ 51, 22 },
	{ 160, 128 },
	{ 161, 131 },
	{ 162, 133 },
	{ 163, 135 },
	{ 164, 136 },
	{ 52, 23 },
	{ 167, 139 },
	{ 168, 143 },
	{ 169, 144 },
	{ 170, 145 },
	{ 171, 146 },
	{ 172, 148 },
	{ 173, 149 },
	{ 174, 150 },
	{ 175, 151 },
	{ 176, 152 },
	{ 177, 153 },
	{ 178, 154 },
	{ 179, 155 },
	{ 180, 156 },
	{ 181, 158 },
	{ 182, 159 },
	{ 40, 3 },
	{ 185, 161 },
	{ 186, 163 },
	{ 187, 165 },
	{ 188, 166 },
	{ 189, 167 },
	{ 190, 169 },
	{ 191, 170 },
	{ 192, 171 },
	{ 193, 172 },
	{ 194, 173 },
	{ 195, 174 },
	{ 196, 175 },
	{ 197, 176 },
	{ 198, 177 },
	{ 199, 178 },
	{ 200, 179 },
	{ 201, 180 },
	{ 202, 181 },
	{ 203, 182 },
	{ 204, 185 },
	{ 205, 186 },
	{ 206, 187 },
	{ 207, 188 },
	{ 208, 189 },
	{ 209, 190 },
	{ 210, 191 },
	{ 211, 192 },
	{ 212, 193 },
	{ 213, 194 },
	{ 214, 195 },
	{ 215, 196 },
	{ 216, 197 },
	{ 217, 198 },
	{ 218, 199 },
	{ 219, 200 },
	{ 220, 201 },
	{ 221, 202 },
	{ 222, 203 },
	{ 55, 25 },
	{ 225, 205 },
	{ 226, 206 },
	{ 227, 207 },
	{ 228, 208 },
	{ 229, 209 },
	{ 230, 210 },
	{ 231, 211 },
	{ 232, 212 },
	{ 233, 213 },
	{ 234, 216 },
	{ 235, 217 },
	{ 236, 218 },
	{ 237, 219 },
	{ 238, 220 },
	{ 239, 221 },
	{ 240, 222 },
	{ 241, 223 },
	{ 242, 224 },
	{ 243, 225 },
	{ 244, 226 },
	{ 245, 227 },
	{ 246, 229 },
	{ 247, 230 },
	{ 248, 231 },
	{ 249, 232 },
	{ 250, 233 },
	{ 251, 234 },
	{ 252, 235 },
	{ 253, 236 },
	{ 254, 237 },
	{ 255, 239 },
	{ 256, 240 },
	{ 257, 241 },
	{ 258, 242 },
	{ 56, 26 },
	{ 261, 244 },
	{ 262, 246 },
	{ 263, 247 },
	{ 264, 248 },
	{ 265, 249 },
	{ 266, 250 },
	{ 267, 251 },
	{ 268, 252 },
	{ 269, 253 },
	{ 270, 254 },
	{ 271, 255 },
	{ 272, 256 },
	{ 273, 257 },
	{ 274, 258 },
	{ 275, 262 },
	{ 276, 263 },
	{ 277, 264 },
	{ 278, 267 },
	{ 279, 268 },
	{ 280, 270 },
	{ 281, 271 },
	{ 282, 272 },
	{ 283, 273 },
	{ 284, 274 },
	{ 285, 275 },
	{ 286, 276 },
	{ 287, 277 },
	{ 288, 278 },
	{ 289, 279 },
	{ 290, 280 },
	{ 291, 281 },
	{ 292, 282 },
	{ 293, 283 },
	{ 294, 285 },
	{ 295, 286 },
	{ 296, 287 },
	{ 297, 288 },
	{ 298, 289 },
	{ 299, 292 },
	{ 300, 293 },
	{ 301, 294 },
	{ 302, 295 },
	{ 303, 296 },
	{ 304, 297 },
	{ 305, 299 },
	{ 306, 300 },
	{ 307, 301 },
	{ 308, 302 },
	{ 309, 304 },
	{ 310, 305 },
	{ 311, 306 },
	{ 312, 307 },
	{ 313, 308 },
	{ 314, 309 },
	{ 315, 312 },
	{ 316, 313 },
	{ 317, 314 },
	{ 318, 315 },
	{ 319, 316 },
	{ 320, 317 },
	{ 321, 318 },
	{ 322, 319 },
	{ 323, 320 },
	{ 324, 321 },
	{ 325, 323 },
	{ 326, 324 },
	{ 327, 325 },
	{ 328, 326 },
	{ 329, 327 },
	{ 330, 328 },
	{ 43, 14 }
};

YYCONST yystate_t YYNEARFAR YYBASED_CODE YYDCDECL yystate[] = {
	{ 0, 0, 0 },
	{ 330, -33, 0 },
	{ 1, 0, 0 },
	{ -3, 230, 0 },
	{ 0, 0, 10 },
	{ 0, 0, 11 },
	{ 0, 0, 22 },
	{ 0, 0, 23 },
	{ 0, 0, 24 },
	{ 0, 7, 55 },
	{ 0, 0, 7 },
	{ 0, 0, 21 },
	{ 330, -36, 54 },
	{ 330, 0, 54 },
	{ 330, 336, 54 },
	{ 330, -76, 54 },
	{ 330, -3, 54 },
	{ 330, 9, 54 },
	{ 330, 34, 54 },
	{ 330, 25, 54 },
	{ 330, 37, 54 },
	{ 330, 106, 54 },
	{ 330, 176, 54 },
	{ 330, 136, 54 },
	{ 330, -99, 54 },
	{ 330, 195, 54 },
	{ 330, 241, 54 },
	{ 330, -60, 54 },
	{ 330, -36, 54 },
	{ 330, -40, 54 },
	{ 330, -86, 54 },
	{ 330, -25, 54 },
	{ 330, -11, 54 },
	{ 330, -26, 54 },
	{ 330, -87, 54 },
	{ 330, -70, 54 },
	{ 330, -5, 54 },
	{ 330, -58, 54 },
	{ 0, 0, 8 },
	{ 0, 0, 9 },
	{ 0, 0, 56 },
	{ 330, 24, 54 },
	{ 330, 32, 54 },
	{ 330, 27, 54 },
	{ 330, 51, 54 },
	{ 330, 58, 54 },
	{ 330, 69, 54 },
	{ 330, 56, 54 },
	{ 330, 57, 54 },
	{ 330, 92, 54 },
	{ 330, 91, 54 },
	{ 330, 94, 54 },
	{ 330, 60, 54 },
	{ 330, 64, 54 },
	{ 330, 59, 54 },
	{ 330, 59, 54 },
	{ 330, 67, 54 },
	{ 330, 60, 54 },
	{ 330, 80, 54 },
	{ 330, 0, 51 },
	{ 330, 62, 54 },
	{ 330, -63, 54 },
	{ 330, 66, 54 },
	{ 330, 63, 54 },
	{ 330, 83, 54 },
	{ 330, 82, 54 },
	{ 330, 69, 54 },
	{ 330, 80, 54 },
	{ 330, 70, 54 },
	{ 330, 86, 54 },
	{ 330, 80, 54 },
	{ 330, 72, 54 },
	{ 330, 76, 54 },
	{ 330, 91, 54 },
	{ 330, 84, 54 },
	{ 330, 88, 54 },
	{ 330, 115, 54 },
	{ 330, 100, 54 },
	{ 330, 127, 54 },
	{ 330, 132, 54 },
	{ 330, 119, 54 },
	{ 330, 134, 54 },
	{ 330, 117, 54 },
	{ 330, 132, 54 },
	{ 330, 137, 54 },
	{ 330, 132, 54 },
	{ 330, 128, 54 },
	{ 330, 97, 54 },
	{ 330, 105, 54 },
	{ 330, 106, 54 },
	{ 330, 107, 54 },
	{ 330, 94, 54 },
	{ 330, 115, 54 },
	{ 330, 103, 54 },
	{ 330, 0, 28 },
	{ 330, 112, 54 },
	{ 330, 106, 54 },
	{ 330, 107, 54 },
	{ 330, 114, 54 },
	{ 330, 112, 54 },
	{ 330, 103, 54 },
	{ 330, 113, 54 },
	{ 330, 109, 54 },
	{ 330, 125, 54 },
	{ 330, 109, 54 },
	{ 330, 121, 54 },
	{ 330, 122, 54 },
	{ 330, 114, 54 },
	{ 330, 0, 25 },
	{ 330, 117, 54 },
	{ 330, 118, 54 },
	{ 330, 151, 54 },
	{ 330, 160, 54 },
	{ 330, 162, 54 },
	{ 330, 154, 54 },
	{ 330, 149, 54 },
	{ 330, 148, 54 },
	{ 330, 149, 17 },
	{ 330, 153, 54 },
	{ 330, 151, 54 },
	{ 330, 160, 54 },
	{ 330, 154, 54 },
	{ 330, 0, 29 },
	{ 330, 122, 54 },
	{ 330, 140, 54 },
	{ 330, 0, 52 },
	{ 330, 139, 54 },
	{ 330, -67, 54 },
	{ 330, 147, 54 },
	{ 330, 0, 37 },
	{ 330, 0, 36 },
	{ 330, 142, 54 },
	{ 330, 0, 33 },
	{ 330, 128, 54 },
	{ 330, 0, 26 },
	{ 330, 129, 54 },
	{ 330, 130, 54 },
	{ 330, -28, 54 },
	{ 330, 0, 34 },
	{ 330, 136, 54 },
	{ 330, 0, 13 },
	{ 330, 0, 32 },
	{ 330, 0, 31 },
	{ 330, 148, 54 },
	{ 330, 165, 54 },
	{ 330, 178, 54 },
	{ 330, 168, 54 },
	{ 330, 0, 15 },
	{ 330, 158, 54 },
	{ 330, 185, 54 },
	{ 330, 183, 54 },
	{ 330, 171, 54 },
	{ 330, 184, 54 },
	{ 330, 189, 54 },
	{ 330, 164, 54 },
	{ 330, 159, 54 },
	{ 330, 145, 54 },
	{ 330, 0, 14 },
	{ 330, 157, 54 },
	{ 330, 166, 54 },
	{ 330, -68, 54 },
	{ 330, 151, 54 },
	{ 330, 0, 27 },
	{ 330, 161, 54 },
	{ 330, 0, 53 },
	{ 330, 170, 54 },
	{ 330, 152, 54 },
	{ 330, 158, 54 },
	{ 330, 0, 50 },
	{ 330, 186, 54 },
	{ 330, 189, 54 },
	{ 330, 199, 54 },
	{ 330, 206, 54 },
	{ 330, 192, 54 },
	{ 330, 210, 54 },
	{ 330, 211, 54 },
	{ 330, 191, 54 },
	{ 330, 183, 54 },
	{ 330, 212, 54 },
	{ 330, 185, 54 },
	{ 330, 176, 54 },
	{ 330, 168, 54 },
	{ 330, 169, 54 },
	{ 330, 0, 45 },
	{ 330, 0, 46 },
	{ 330, 189, 54 },
	{ 330, 174, 54 },
	{ 330, 172, 54 },
	{ 330, 176, 54 },
	{ 330, 174, 54 },
	{ 330, 220, 54 },
	{ 330, 221, 54 },
	{ 330, 212, 54 },
	{ 330, 213, 54 },
	{ 330, 209, 19 },
	{ 330, 216, 54 },
	{ 330, 219, 54 },
	{ 330, 201, 54 },
	{ 330, 230, 54 },
	{ 330, 219, 54 },
	{ 330, 190, 54 },
	{ 330, 189, 54 },
	{ 330, 200, 54 },
	{ 330, 195, 54 },
	{ 330, -91, 54 },
	{ 330, 194, 54 },
	{ 330, 198, 54 },
	{ 330, 196, 54 },
	{ 330, 191, 54 },
	{ 330, 213, 54 },
	{ 330, 242, 54 },
	{ 330, 232, 54 },
	{ 330, 233, 54 },
	{ 330, 240, 54 },
	{ 330, 0, 18 },
	{ 330, 0, 16 },
	{ 330, 245, 54 },
	{ 330, 235, 54 },
	{ 330, 237, 54 },
	{ 330, 219, 54 },
	{ 330, 207, 54 },
	{ 330, 219, 54 },
	{ 330, 218, 54 },
	{ 330, 215, 54 },
	{ 330, 224, 54 },
	{ 330, 227, 54 },
	{ 330, 222, 54 },
	{ 330, 223, 54 },
	{ 330, 0, 35 },
	{ 330, 257, 54 },
	{ 330, 242, 54 },
	{ 330, 232, 54 },
	{ 330, 245, 54 },
	{ 330, 264, 54 },
	{ 330, 257, 54 },
	{ 330, 254, 54 },
	{ 330, 249, 54 },
	{ 330, 219, 54 },
	{ 330, 0, 30 },
	{ 330, 218, 54 },
	{ 330, 221, 54 },
	{ 330, 222, 54 },
	{ 330, 229, 54 },
	{ 330, -117, 54 },
	{ 330, 225, 54 },
	{ 330, 0, 39 },
	{ 330, 267, 54 },
	{ 330, 268, 54 },
	{ 330, 275, 54 },
	{ 330, 259, 54 },
	{ 330, 266, 54 },
	{ 330, 263, 54 },
	{ 330, 269, 54 },
	{ 330, 263, 54 },
	{ 330, 241, 54 },
	{ 330, 244, 54 },
	{ 330, 255, 48 },
	{ 330, 250, 54 },
	{ 330, 235, 54 },
	{ 330, 0, 43 },
	{ 330, 0, 44 },
	{ 330, 0, 38 },
	{ 330, 271, 54 },
	{ 330, 275, 54 },
	{ 330, 276, 54 },
	{ 330, 0, 4 },
	{ 330, 0, 20 },
	{ 330, 287, 54 },
	{ 330, 288, 54 },
	{ 330, 0, 6 },
	{ 330, 257, 54 },
	{ 330, 248, 54 },
	{ 330, 261, 54 },
	{ 330, 262, 54 },
	{ 330, 261, 54 },
	{ 330, 294, 54 },
	{ 330, 286, 54 },
	{ 330, 287, 54 },
	{ 330, 299, 54 },
	{ 330, 289, 54 },
	{ 330, 254, 54 },
	{ 330, 259, 54 },
	{ 330, 259, 54 },
	{ 330, 255, 54 },
	{ 330, 0, 40 },
	{ 330, 305, 54 },
	{ 330, 290, 54 },
	{ 330, 291, 54 },
	{ 330, 291, 54 },
	{ 330, 292, 54 },
	{ 330, 0, 49 },
	{ 330, 0, 42 },
	{ 330, 260, 54 },
	{ 330, 273, 54 },
	{ 330, 295, 54 },
	{ 330, 285, 54 },
	{ 330, 297, 54 },
	{ 330, 309, 54 },
	{ 330, 0, 12 },
	{ 330, 273, 54 },
	{ 330, 273, 54 },
	{ 330, 312, 54 },
	{ 330, 319, 54 },
	{ 330, 0, 3 },
	{ 330, 308, 54 },
	{ 330, 272, 54 },
	{ 330, 279, 54 },
	{ 330, 311, 54 },
	{ 330, 312, 54 },
	{ 330, 314, 54 },
	{ 330, 0, 47 },
	{ 330, 0, 41 },
	{ 330, 315, 54 },
	{ 330, 316, 54 },
	{ 330, 300, 54 },
	{ 330, 301, 54 },
	{ 330, 314, 54 },
	{ 330, 331, 54 },
	{ 330, 332, 54 },
	{ 330, 316, 54 },
	{ 330, 322, 54 },
	{ 330, 323, 54 },
	{ 330, 0, 5 },
	{ 330, 325, 54 },
	{ 330, 326, 54 },
	{ 330, 322, 54 },
	{ 330, 323, 54 },
	{ 330, 323, 54 },
	{ 330, 324, 54 },
	{ 330, 0, 1 },
	{ 0, 45, 2 }
};

YYCONST yybackup_t YYNEARFAR YYBASED_CODE YYDCDECL yybackup[] = {
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0
};

#line 105 ".\\mylexer.l"

/////////////////////////////////////////////////////////////////////////////
// programs section

//extern FILE *yyin;
//extern FILE *yyout;

yywrap() {
	fclose( yyin);
 	exit(1);
}
