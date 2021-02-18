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
	cout << endl << "welcome \n enter two english word to provide ladder \n";



	set<string> words;
	ifstream get;//reading the file
	//get.open("file1.txt");//openning the file
	get.open("EnglishWords 1.dat");
	if (!get)//checking if the file exists
	{

		cout << "loss of allocation \n";
		return 0;
	}
	words = getWords(get);//called functions
	bool indexOfFirst = false, indexOfSecond = false;
	do {


		do {
			while (!indexOfFirst) {
				cout << "enter first word :";
				cin >> firstWord;

				indexOfFirst = isWordExist(firstWord, words);
				if (!indexOfFirst) {
					cout << "\n no such word exist, you can try again \n";
				}

			}
			while (!indexOfSecond) {

				cout << "enter second word :";
				cin >> secondWord;
				indexOfSecond = isWordExist(secondWord, words);

				if (!indexOfSecond) {
					cout << " \n no such word exist , you can try again \n ";
				}


			}
			if (firstWord.size() != secondWord.size()) {
				cout << "\n file size must equal try again \n";
				indexOfFirst = indexOfSecond = false;
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
			indexOfFirst = indexOfSecond = false;
		}
	} while (tryAgain == 'y');




	//cout << "first word is " << indexOfFirst << " and second word is " << indexOfSecond;



}
bool isWordExist(string word, set<string>& words) {
	set<string>::iterator it = words.find(word);


	if (it == words.end()) {
		return false;
	}
	else {
		return true;
	}
}