#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string words;
    unsigned int vowels = 0;
    unsigned int consonants = 0;
    unsigned int others = 0;

    cout << "Enter words (q to quit):" << endl;
    while (cin >> words, words != "q")
    {
        if (isalpha(words[0]))
        {
            switch (tolower(words[0]))
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                {
                    ++vowels;
                    break;
                }
                default:
                {
                    ++consonants;
                    break;
                }
            }
        }
        else
        {
            ++others;
        }
    }
    cout << vowels << " words beginning with vowels" << endl;
    cout << consonants << " words beginning with consonants" << endl;
    cout << others << " others" << endl;

    return 0;
}
