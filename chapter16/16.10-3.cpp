#include <iostream>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    srand(time(0));
    char play;
    string temp;
    ifstream infile;
    vector<string> wordlist;

    infile.open("wordlist.txt");
    if (!infile.is_open()) //检测是否成功打开文件;
    {
        cout << "Can't open file wordlist.txt" << endl;
        cout << "Program terminating." << endl;
        exit(EXIT_FAILURE);
    }
    while (infile >> temp) //从文件中读取直至EOF;
    {
        wordlist.push_back(temp);
    }

    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    play = tolower(play);
    while (play == 'y')
    {
        string target = wordlist[rand() % wordlist.size()];
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;
        cout << "Guess my secret word. It has " << length;
        cout << " letters, and you guess\n";
        cout << "one letter at a time. You get " << guesses;
        cout << " wrong guesses.\n";
        cout << "Your word: " << attempt << endl;
        while (guesses > 0 && attempt != target)
        {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;
            if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos)
            {
                cout << "You already guessed that. Try again.\n";
                continue;
            }
            int loc = target.find(letter);
            if (loc == string::npos)
            {
                cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter;
            }
            else
            {
                cout << "Good guess!\n";
                attempt[loc] = letter;
                loc = target.find(letter, loc + 1);
                while (loc != string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }
            cout << "Your word: " << attempt << endl;
            if (attempt != target)
            {
                if (badchars.length() > 0)
                {
                    cout << "Bad choices: " << badchars << endl;
                }
                cout << guesses << " bad guesses left\n";
            }
        }
        if (guesses > 0)
        {
            cout << "That's right!\n";
        }
        else
        {
            cout << "Sorry, the word is " << target << ".\n";
        }
        cout << "Will you play another? <y/n> ";
        cin >> play;
        play = tolower(play);
    }
    infile.close();
    cout << "Bye\n";

    return 0;
}
