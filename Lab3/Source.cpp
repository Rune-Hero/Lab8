#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

class Word
{
public:
	string ukrainian;
	string english;

	Word(string ukr,string eng) : ukrainian(ukr), english(eng) {}
	

	bool operator<(Word other) {
		return ukrainian < other.ukrainian;
	}

	bool operator>=(Word other) {
		return ukrainian >= other.ukrainian;
	}
	
};

class DICTIONARY
{
private:
	vector<Word> words;
public:

	DICTIONARY operator+(Word word)
	{
		words.push_back(word);
		return *this;
	}

	DICTIONARY operator-(Word word) {
		words.erase(remove_if(words.begin(), words.end(),
			[&](Word w) { return w.ukrainian == word.ukrainian && w.english == word.english; }),
			words.end());
		return *this;
	}

	Word operator[](string ukrWord) {
		for (auto word : words) {
			if (word.ukrainian == ukrWord) {
				return word;
			}
		}
	}
	string find(string ukrWord) {
		try {
			if (words.empty()) {
				throw runtime_error("Словник порожній\n"); 
			}

			for (const auto& word : words) {
				if (word.ukrainian == ukrWord) {
					return word.english;  
				}
			}

			return "Переклад не знайдено"; 
		}
		catch (const exception& e) {
			cerr << e.what(); 
			return ""; 
		}
	}

	void print()
	{
		for (auto word : words)
		{
			cout << word.ukrainian << " - " << word.english << endl;
		}

	}
};
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	DICTIONARY MyDictionary;

	MyDictionary + Word("привіт", "hello");
	MyDictionary + Word("собака", "dog");
	MyDictionary + Word("птиця", "bird");

	cout << "Словник:\n";
	MyDictionary.print();

	cout << "Словник після видалення слова 'птиця':\n";
	MyDictionary - Word("птиця", "bird");
	MyDictionary.print();

	//string translation = MyDictionary.find("привіт");
	Word translation = MyDictionary["привіт"];


	cout << "\nПереклад слова 'привіт' - " << translation.english << endl;

	translation = MyDictionary.find("egegd");
	cout << "Переклад слова 'egegd' - " << translation.ukrainian << endl;

	return 0;
}