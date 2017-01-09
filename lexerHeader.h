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
#define USE_VARIABLE 	1008
#define LOOK_CMD_RET 	1009
#define IF_CMD 			1010
#define SETSTONE_CMD 	1011
#define BREAK_CMD 		1012
#define SETMARK_CMD 	1013
#define GDIR_CMD 		1014
#define GDIR_CMD_RET 	1015
#define MTOTAL_CMD	 	1016
#define MTOTAL_CMD_RET 	1017
#define POSX_CMD	 	1018
#define POSX_CMD_RET 	1019
#define POSY_CMD	 	1020
#define POSY_CMD_RET 	1021
#define GOALX_CMD	 	1022
#define GOALX_CMD_RET 	1023
#define GOALY_CMD	 	1024
#define GOALY_CMD_RET 	1025
#define MVAL_CMD	 	1026
#define MVAL_CMD_RET 	1027
#define MDELETE_CMD 	1028
#define MDIR_CMD 		1029
#define MDIR_CMD_RET 	1030
#define TELEPORT_CMD 	1031
#define MARKER_CMD 		1032
#define MARKER_CMD_RET 	1033

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
#define NEW_ASSIGN 		1114
#define ASSIGN 			1115
#endif