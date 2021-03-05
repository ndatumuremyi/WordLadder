// WordLadder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>//including file library
#include<vector> //including vector library
#include<random>//including randomisation
#include<string>//including strings
#include<ctime>//including c string library
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include"WordLadder.h"



using namespace std;









set<string> getWords(ifstream& get)//a funtion that puts the file into a vector and returns the vector
{
	set<string> strings;
	string d;
	while (get >> d) {
		strings.insert(d);
	}
	return strings;
}



int main()
{
	char tryAgain;
	string firstWord, secondWord;
	


	set<string> words;
	ifstream get;

	get.open("EnglishWords 1.dat");
	if (!get)
	{

		cout << "file not found,  \n";
		return 0;
	}
	words = getWords(get);
	bool isFirstWordValid = false, isSecondWordValid = false;
	cout << endl << " \t welcome \n \n \n" << "***********************" << "\n \t enter two english word to provide ladder \n \n \n";

	do {


		do {
			while (!isFirstWordValid) {
				cout << "type first word :";
				cin >> firstWord;

				isFirstWordValid = isWordExist(firstWord, words);
				if (!isFirstWordValid) {
					cout << "\n use existing word only, try again \n";
				}

			}
			while (!isSecondWordValid) {

				cout << "type second word :";
				cin >> secondWord;
				isSecondWordValid = isWordExist(secondWord, words);

				if (!isSecondWordValid) {
					cout << " \n try again with word that do exist, \n ";
				}


			}
			if (firstWord.size() != secondWord.size()) {
				cout << "\n words size must equal, try again,  \n";
				isFirstWordValid = isSecondWordValid = false;
			}
		} while (firstWord.size() != secondWord.size());

		WordLadder wordLadder(firstWord, secondWord, words);
		vector<string> ladder = wordLadder.getLadder();

		if (ladder.empty()) {
			cout << "\n unable to find ladder \n ";
		}
		else {
			
			for (vector<string>::iterator i = ladder.begin(); i < ladder.end(); i++) {
				cout << *i << "->";
			}
		}


		cout << "\n \n do you want to try again ? \'y\' for yes :";
		cin >> tryAgain;
		cin.clear();
		if (tryAgain == 'y') {
			isFirstWordValid = isSecondWordValid = false;
		}
	} while (tryAgain == 'y');



}
bool isWordExist(string word, set<string>& words) {
	
	//find method return iterator of element, else return last iterator that does not point to any element
	if (words.find(word) == words.end()) {
		return false;
	}
	else {
		return true;
	}
}