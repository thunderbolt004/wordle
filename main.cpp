#include <algorithm>
#include <climits>
#include <cstdlib>
#include <string>
#include <vector>
#include <random>
#include "colors.cpp"
#include "words.h"

void generateWord(std::vector<std::string>& arr, std::string& val){
	val = arr[rand()%arr.size()];	
}

int main(){
	system("clear");
	int len, chances;
	std::cout<<"Enter length of wordle, between 4 & 7: ";
	std::cin>>len;
	if (len < 4 || len > 7) {
		main();
	}
	chances = len > 5 ? len+2 : len+1;
	system("clear");
	srand(time(0));
	std::vector<std::string>* ptr;
	std::string word, guess;
	switch (len) {
		case 4: ptr = &four; break;
		case 5: ptr = &five; break;
		case 6: ptr = &six; break;
		case 7: ptr = &seven; break;
	}
	generateWord(*ptr, word);
	for (int i = 1; i <= chances; ++i) {
		std::cin>>guess;
		if(guess.size() != len){
			std::cout<<"Enter "<<len<<" length word.\n";
			--i;
			continue;
		}
		if (!binary_search(ptr->begin(), ptr->end(), guess)){
			std::cout<<"word not in dictionary!\n";
			--i;
			continue;
		}
		std::cout<<"\033[A"; //ANSI escape to move cursor one line up, B for down 
		for (int j = 0; j < guess.size(); ++j) {
			if(char(tolower(guess[j])) == word[j]){
				color('g');
			}
			else{
				color('w');
				for (char ch : word) {
					if (char(tolower(guess[j])) == ch) {
						color('y');
						break;
					}
				}
			}
			std::cout<<char(toupper(guess[j]));
		}
		std::cout<<std::endl;
		color('z');
		if (guess == word){
			std::cout<<"Well Done. Solved in "<<i<<" moves.\n";
			std::cout<<"Press x to end game, y to restart.\n";
			char ch;
			std::cin>>ch;
			if(ch=='x') break;
			else main();
		}
	}
	std::cout<<std::endl<<"Correct Word: "<<word<<std::endl;
	return 0;
}
