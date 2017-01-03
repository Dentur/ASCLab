%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: Montag, 2. Januar 2017
****************************************************************************/

#include "mylexer.h"
%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// attribute type
%include {
#ifndef YYSTYPE
#define YYSTYPE int
#endif
}

// place any declarations here

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)

Grammar
	: /* empty */
	;

%%

/////////////////////////////////////////////////////////////////////////////
// programs section

int main(void)
{
	return yyparse();
}

