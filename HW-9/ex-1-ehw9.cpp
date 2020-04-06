#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

unsigned gen_random_index(const unsigned size);
void generate_exclamation_mark(char symbol);
void pick_a_random_word(const char *words[], const unsigned size);
void generate_a_whole_sentence(const char *exclamation[],
	const char *subject[],
	const char *action[],
	char symbol,
	const unsigned size);
int main()
{
	srand(time(0));
	const unsigned MAX_SIZE = 8;
	unsigned n;
	cout << "Kolko skandalni zaglaviya iskate da prochetete? ";
	cin >> n;

	char symbol = '!';

	const char *exclamation[MAX_SIZE] = { "Bedstvie", "Iznenada", "Skandalno", "Shokirashto","Potres", "Paranoya","Katastrofalno", "Panika" };
	const char *subject[MAX_SIZE] = { "Kote", "Tir", "Mylniq","Ptica", "Dyrvo","Bager", "Stol", "Kartina" };
	const char *action[MAX_SIZE] = { "udari", "blysna", "schupi", "smaza","izqde", "otkradna","izqde", "otrqza" };

	for (unsigned i = 0; i < n; i++)
	{
		generate_a_whole_sentence(exclamation, subject, action, symbol, MAX_SIZE);
		cout << endl;
	}


	return 0;
}

unsigned gen_random_index(const unsigned size)
{
	return rand() % size;
}

void generate_exclamation_mark(char symbol)
{
	unsigned n = rand() % 7 + 3;

	while (n > 0)
	{
		cout << symbol;
		n--;
	}
	cout << " ";
}

void pick_a_random_word(const char *words[], const unsigned size)
{
	unsigned index = gen_random_index(size);
	cout << words[index] << " ";
}

void generate_a_whole_sentence(const char *exclamation[],
	const char *subject[],
	const char *action[],
	char symbol,
	const unsigned size)
{
	pick_a_random_word(exclamation, size);
	generate_exclamation_mark(symbol);
	pick_a_random_word(subject, size);
	pick_a_random_word(action, size);
	pick_a_random_word(subject, size - 2);
	cout << ".";
}