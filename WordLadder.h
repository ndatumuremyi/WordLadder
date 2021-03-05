#include <iostream>
#include<fstream>
#include<vector>
#include<random>
#include<string>
#include<queue>
#include<stack>
#include<set>

//peace-zeros

using namespace std;
bool isWordExist(string, set<string>&);
class WordLadder {
private:
	queue<vector<string>> AllLadders;
	string secondWord;
	string firstWord;
	set<string> words;
	set<string> usedWord;
	vector<string> choosenLadder;

	//other valiables used in program
	vector<string> prevLadder;

public:
	set<string> generateAllValidWords(string);
	vector<string> getLadder();
	void getLadderH();

	WordLadder(string first, string second, set<string>& words) {
		this->words = words;
		this->secondWord = second;
		this->firstWord = first;

		usedWord.insert(first);
	}

};
vector<string> WordLadder::getLadder() {
	vector<string> ladder;
	ladder.push_back(firstWord);
	

	AllLadders.push(ladder);
	getLadderH();
	
	return this->choosenLadder;
}
void WordLadder::getLadderH() {
	
	prevLadder = AllLadders.front();
	AllLadders.pop();

	
	string wordToOpareateOn = prevLadder.back();

	set<string> allValidWords = generateAllValidWords(wordToOpareateOn);
	for (auto word : allValidWords) {
		vector<string> newLadder(prevLadder);
		

		newLadder.push_back(word);
		if (word == secondWord) {
			this->choosenLadder = newLadder;
			return;
		}
		
		AllLadders.push(newLadder);

	}

	if (AllLadders.empty()) {
		return;
	}
	
	else {
		getLadderH();
	}
}
set<string> WordLadder::generateAllValidWords(string word) {
	set<string> possibleWords;

	for (int i = 0; i < word.size(); i++) {
		
		string wordToOparateOn = word;
		
		for (char ch = 'a'; ch <= 'z'; ++ch) {
			//this create string from char, in order to be able to replace it in wordtoOparateOn
			string formString(1, ch);
			wordToOparateOn.replace(i, 1, formString);
			if (usedWord.find(wordToOparateOn) == usedWord.end())
			{
				if (isWordExist(wordToOparateOn, words)) {

					possibleWords.insert(wordToOparateOn);
					this->usedWord.insert(wordToOparateOn);
				}
			}


		}
	}
	return possibleWords;
}
