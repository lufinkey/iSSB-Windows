
#include "Keys.h"

namespace GameEngine
{
	String Keys::GetKeyText(int keyNum)
	{
		switch (keyNum)
		{
			case A: return "a";
			case B: return "b";
			case C: return "c";
			case D: return "d";
			case E: return "e";
			case F: return "f";
			case G: return "g";
			case H: return "h";
			case I: return "i";
			case J: return "j";
			case K: return "k";
			case L: return "l";
			case M: return "m";
			case N: return "n";
			case O: return "o";
			case P: return "p";
			case Q: return "q";
			case R: return "r";
			case S: return "s";
			case T: return "t";
			case U: return "u";
			case V: return "v";
			case W: return "w";
			case X: return "x";
			case Y: return "y";
			case Z: return "z";
			case NUM_0: return "0";
			case NUM_1: return "1";
			case NUM_2: return "2";
			case NUM_3: return "3";
			case NUM_4: return "4";
			case NUM_5: return "5";
			case NUM_6: return "6";
			case NUM_7: return "7";
			case NUM_8: return "8";
			case NUM_9: return "9";
			case ESCAPE: return "esc";
			case CTRL_LEFT: return "ctrl";
			case SHIFT_LEFT: return "shift";
			case ALT_LEFT: return "alt";
			case WINDOWS_LEFT: return "windows";
			case CTRL_RIGHT: return "ctrl";
			case SHIFT_RIGHT: return "shift";
			case ALT_RIGHT: return "alt";
			case WINDOWS_RIGHT: return "windows";
			case CONTEXT_MENU: return "context";
			case OPENBRACKET: return "[";
			case CLOSEBRACKET: return "]";
			case SEMICOLON: return ";";
			case COMMA: return ",";
			case PERIOD: return ".";
			case QUOTE: return "\"";
			case FORWARDSLASH: return "/";
			case BACKSLASH: return "\\";
			case TILDE: return "~";
			case EQUALS: return "=";
			case DASH: return "-";
			case SPACE: return "space";
			case ENTER: return "enter";
			case BACKSPACE: return "backspace";
			case TAB: return "tab";
			case PAGEUP: return "pg up";
			case PAGEDOWN: return "pg dn";
			case END: return "end";
			case HOME: return "home";
			case INS: return "insert";
			case DEL: return "delete";
			case ADD: return "+";
			case SUBTRACT: return "-";
			case MULTIPLY: return "*";
			case DIVIDE: return "/";
			case LEFTARROW: return "left arrow";
			case RIGHTARROW: return "right arrow";
			case UPARROW: return "up arrow";
			case DOWNARROW: return "down arrow";
			case NUMPAD_0: return "[0]";
			case NUMPAD_1: return "[1]";
			case NUMPAD_2: return "[2]";
			case NUMPAD_3: return "[3]";
			case NUMPAD_4: return "[4]";
			case NUMPAD_5: return "[5]";
			case NUMPAD_6: return "[6]";
			case NUMPAD_7: return "[7]";
			case NUMPAD_8: return "[8]";
			case NUMPAD_9: return "[9]";
			case F1: return "f1";
			case F2: return "f2";
			case F3: return "f3";
			case F4: return "f4";
			case F5: return "f5";
			case F6: return "f6";
			case F7: return "f7";
			case F8: return "f8";
			case F9: return "f9";
			case F10: return "f10";
			case F11: return "f11";
			case F12: return "f12";
			case F13: return "f13";
			case F14: return "f14";
			case F15: return "f15";
			case PAUSE: return "pause";
		}
		return "Unknown Key";
	}
}