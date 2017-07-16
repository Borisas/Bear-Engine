#include "Util.h"


char BearEngine::Util::KeycodeToChar(Uint32 kc, bool shift) {
	switch(kc){

		case 4:		return shift ? 'A' : 'a';
		case 5:		return shift ? 'B' : 'b';
		case 6:		return shift ? 'C' : 'c';
		case 7:		return shift ? 'D' : 'd';
		case 8:		return shift ? 'E' : 'e';
		case 9:		return shift ? 'F' : 'f';
		case 10:	return shift ? 'G' : 'g';
		case 11:	return shift ? 'H' : 'h';
		case 12:	return shift ? 'I' : 'i';
		case 13:	return shift ? 'J' : 'j';
		case 14:	return shift ? 'K' : 'k';
		case 15:	return shift ? 'L' : 'l';
		case 16:	return shift ? 'M' : 'm';
		case 17:	return shift ? 'N' : 'n';
		case 18:	return shift ? 'O' : 'o';
		case 19:	return shift ? 'P' : 'p';
		case 20:	return shift ? 'Q' : 'q';
		case 21:	return shift ? 'R' : 'r';
		case 22:	return shift ? 'S' : 's';
		case 23:	return shift ? 'T' : 't';
		case 24:	return shift ? 'U' : 'u';
		case 25:	return shift ? 'V' : 'v';
		case 26:	return shift ? 'W' : 'w';
		case 27:	return shift ? 'X' : 'x';
		case 28:	return shift ? 'Y' : 'y';
		case 29:	return shift ? 'Z' : 'z';
		case 30:	return shift ? '!' : '1';
		case 31:	return shift ? '@' : '2';
		case 32:	return shift ? '#' : '3';
		case 33:	return shift ? '$' : '4';
		case 34:	return shift ? '%' : '5';
		case 35:	return shift ? '^' : '6';
		case 36:	return shift ? '&' : '7';
		case 37:	return shift ? '*' : '8';
		case 38:	return shift ? '(' : '9';
		case 39:	return shift ? ')' : '0';
		case 40:	return '\n';
		case 43:	return '\t';
		case 44:	return ' ';
		case 45:	return shift ? '_' : '_';
		case 46:	return shift ? '+' : '=';
		case 47:	return shift ? '{' : '[';
		case 48:	return shift ? '}' : ']';
		case 49:	return shift ? '|' : '\\';
		case 51:	return shift ? ':' : ';';
		case 52:	return shift ? '\"': '\'';
		case 53:	return shift ? '~' : '`';
		case 54:	return shift ? '<' : ',';
		case 55:	return shift ? '>' : '.';
		case 56: 	return shift ? '?' : '/';
		case 84:	return '/';
		case 85:	return '*';
		case 86:	return '-';
		case 87:	return '+';
		case 88:	return '\n';
		case 89:	return '1';
		case 90:	return '2';
		case 91:	return '3';
		case 92:	return '4';
		case 93:	return '5';
		case 94:	return '6';
		case 95:	return '7';
		case 96:	return '8';
		case 97:	return '9';
		case 98:	return '0';
		case 99:	return '.';

		default:	return 0;
	}
}