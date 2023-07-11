#include <iostream>

/*Color Codes:
 * r: Red
 * g: Green
 * b: Blue
 * B: Black
 * w: White
 * m: Magenta
 * y: Yellow
 * z: reset*/
void color(char ch){
	switch (ch) {
		case 'r': std::cout<<"\033[1;31m"; break;
		case 'g': std::cout<<"\033[1;32m"; break;
		case 'b': std::cout<<"\033[1;34m"; break;
		case 'B': std::cout<<"\033[1;30m"; break;
		case 'w': std::cout<<"\033[1;37m"; break;
		case 'm': std::cout<<"\033[1;35m"; break;
		case 'y': std::cout<<"\033[1;33m"; break;
		case 'z': std::cout<<"\033[1;0m"; break;
	}
}
