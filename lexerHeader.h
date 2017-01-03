typedef union
{
	double num;
	char *str;
} YYSTYPE;

extern YYSTYPE yylval;

#define RELATIVE_DIRECTION 200
#define ABSOLUTE_DIRECTION 201
#define DIRECTION 202
#define FLOOR 203
#define ALL_DIRECTIONS 204
#define WALLS 205
#define COMMANDEND 206
#define BEGIN 207
#define END 208
#define LEFTB 209
#define RIGHTB 210
#define COMMENT 211
#define TRUE 212
#define FALSE 213
#define EQ 214
#define NE 215
#define LT 216
#define LE 217
#define GT 218
#define GE 219
#define ASGN 220
#define PLUS 221
#define MINUS 222
#define CONCAT 223
#define AND 224
#define OR 225
#define NOT 226
#define INT_VAR 227
#define BOOL_VAR 228
#define DIR_VAR 229
#define WALL_VAR 230
#define TURN 231
#define MOVE 232
#define STEP 233
#define TELEPORT 234
#define LOOK 235
#define LOAD 236
#define SMARK 237
#define SSTONE 238
#define MVAL 239
#define MDIR 240
#define GDIR 241
#define POSX 242
#define POSY 243
#define GOALX 244
#define GOALY 245
#define MTOTAL 246
#define MARKER 247
#define MDELETE 248
#define WHILE 249
#define IF 250
#define ELSE 251
#define PRINT 252
#define IDENTIFIER 253
#define DIGIT 254
#define STRING 255