cls
flex lang_scan.lex
bison -d lang_parser.y
copy lang_parser.tab.c "CPP-Files"
copy lang_parser.tab.h "CPP-Files"
copy lex.yy.c "CPP-Files"
copy generator.h "CPP-Files"
copy generator.cpp "CPP-Files"
copy lexerHeader.h "CPP-Files"