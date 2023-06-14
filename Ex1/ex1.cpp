#include <string>
#include <iostream>
#include "graph.h"
using namespace std;

deque<string> readWords()
{
    deque<string> words;
    string x;

    while (fin >> x)
    {
        if (*x.begin() != '.')
        {
            words.push_back(x);
            cout << x << " ";
        }
    }

    return words;
}

deque<unordered_map<char, char>> toLetters(deque<string> words)
{
    deque<unordered_map<char, char>> let;

    if (words.size() == 1)
    {
        let.push_back(unordered_map<char, char>{{*words.front().begin(), NULL}});
        return let;
    }

    for (auto it = words.begin(); it < words.end(); ++it)
    {
        for (int i = 0; i < (*it).size() && i < (*(it + 1)).size(); i++)
        {
            if ((*it)[i] != (*(it + 1))[i])
            {
                let.push_back(unordered_map<char, char>{{(*it)[i], (*(it + 1))[i]}});
                cout << (*it)[i] << (*(it + 1))[i] << " ";
                break;
            }
        }
    }

    return let;
}

int main()
{

    deque<unordered_map<char, char>> let = toLetters(readWords());

    Graph g(let);

    g.printGraph();
    g.topologicalSort();

    fin.close();
    fout.close();
    return 0;
}