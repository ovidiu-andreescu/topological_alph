#include <deque>
#include <unordered_map>
#include <fstream>
using namespace std;

ifstream fin("index.in");
ofstream fout("index.out");

class Graph
{
private:
    unordered_map<char, deque<char>> l;
    int nodes;

    unordered_map<char, int> compute_indegree(unordered_map<char, deque<char>> l)
    {
        unordered_map<char, int> indegree;

        for (auto it : l)
        {
            indegree[it.first] = 0;
        }

        for (auto it : l)
            for (auto elem : it.second)
            {
                ++indegree[elem];
                cout << "\nAdded\n";
            }
        return indegree;
    }

public:
    Graph(deque<unordered_map<char, char>> l)
    {
        for (auto it : l)
        {
            for (auto elem : it)
            {
                this->l[elem.first].push_front(elem.second);
                this->l[elem.second];
            }
        }

        nodes = this->l.size();
    }

    void topologicalSort()
    {
        unordered_map<char, int> indegree = compute_indegree(l);

        deque<char> ord;
        deque<char> degree0;

        for (auto it : indegree)
            if (it.second == 0)
                degree0.push_front(it.first);

        while (!degree0.empty())
        {
            char elem = degree0.front();
            degree0.pop_front();
            ord.push_back(elem);

            for (auto it : l[elem])
            {
                --indegree[it];
                if (indegree[it] == 0)
                {
                    degree0.push_front(it);
                }
            }
        }

        if (ord.size() == nodes)
        {
            for (auto it : ord)
                if (it != '\0')
                    fout << it;
        }
        else
            fout << "No topological order!";
    }

    void printGraph()
    {
        for (auto it : l)
        {
            if (it.first != '\0')
            {
                cout << it.first << ": ";
                for (auto elem : it.second)
                    if (elem != '\0')
                        cout << elem << " ";
                cout << "\n";
            }
        }
    }
};