#ifndef PT_ENTRY

#define PT_ENTRY struct pt_entry

PT_ENTRY
{
	int type;
	PT_ENTRY *nxt;
	PT_ENTRY *op1;
	PT_ENTRY *op2;
	PT_ENTRY *op3;
	PT_ENTRY *op4;
	int num;
	double fnum;
	char *str;
	int boolval;
	char* identifier;
};

#define PROGRAM 		1000
#define LOAD_CMD 		1001
#define MOVE_CMD 		1002
#define TURN_CMD 		1003
#define STEP_CMD 		1004
#define LOOK_CMD 		1005
#define WHILE_CMD 		1006
#define VAL_DIGIT 		1007
#define ID_VARIABLE 	1008
#define LOOK_CMD_RET 	1009
#define IF_CMD 			1010
#define SETSTONE_CMD 	1011
#define BREAK_CMD 		1012

#define OP_EQ			1100
#define OP_NE			1101
#define OP_LT			1102
#define OP_LE			1103
#define OP_GT			1104
#define OP_GE			1105
#define OP_NOT			1106
#define OP_AND			1107
#define OP_OR			1108
#define OP_UMINUS		1109
#define OP_PLUS			1110
#define OP_MINUS		1111
#define DIRECTION 		1112
#define WALL_TYPE 		1113

/*
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
*/
#endif