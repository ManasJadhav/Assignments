#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream sin;
    sin.open("SYMTAB.txt");

    ifstream lin;
    lin.open("LITTAB.txt");

    ifstream fin;
    fin.open("intermediate.txt");

    ofstream fout;
    fout.open("answer.txt");

    string word;
    string line;

    vector<pair<string, int>> symtab;
    vector<pair<string, int>> littab;

    while (getline(sin, line))
    {

        stringstream st(line);

        st >> word;
        string label = word;

        st >> word;

        symtab.push_back({label, stoi(word)});
    }

    sin.close();

    while (getline(lin, line))
    {

        stringstream st(line);

        st >> word;
        string label = word;

        st >> word;

        littab.push_back({label, stoi(word)});
    }

    lin.close();

    string cls, mnemonics;
    int lc = -1;
    while (getline(fin, line))
    {
        stringstream st(line);

        st >> word;

        cls = word.substr(1, 2);
        mnemonics = word.substr(4, 2);

        if (cls == "AD")
        {
            fout << "    NO MACHINE CODE"
                 << "\n";

            if (mnemonics == "01")
            {
                st >> word;
                lc = stoi(word.substr(3, word.size() - 4));
            }
            else if (mnemonics == "03")
            {
                st >> word;
                int index = stoi(word.substr(3, 2));
                lc = symtab[--index].second;
            }
        }
        else if (cls == "IS")
        {
            fout << lc << " " << mnemonics << " ";
            lc++;

            st >> word;

            if (mnemonics == "00")
            {
                fout << "0 000"
                     << "\n";
                continue;
            }

            if (word[1] != 'L' && word[1] != 'S')
            {
                string temp = word.substr(1, 1);
                fout << temp << " ";
                st >> word;
            }

            if (word[1] != 'L' || word[1] != 'S')
            {
                int index = stoi(word.substr(3, 2));

                if (word[1] == 'L')
                {
                    fout << littab[--index].second << "\n";
                }
                else if (word[1] == 'S')
                {
                    fout << symtab[--index].second << "\n";
                }
            }
        }
        else if (cls == "DL")
        {
            fout << lc << " ";
            lc++;

            if (mnemonics == "01")
            {
                fout << "00 0"
                     << " ";

                st >> word;

                word = word.substr(3, 1);
                fout << "00" << word << "\n";
            }
            else if (mnemonics == "02")
            {
                fout << "NO MACHINE CODE"
                     << "\n";
            }
        }
    }

    fin.close();
    fout.close();

    cout << "Done with the processing \n";
}
