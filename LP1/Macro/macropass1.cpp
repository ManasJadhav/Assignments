#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("source2.txt");

    ofstream fout;
    fout.open("output.txt");

    ofstream mntout;
    mntout.open("mnttab.txt");

    ofstream mdtout;
    mdtout.open("mdttab.txt");

    ofstream pntout;
    pntout.open("pnttab.txt");

    ofstream kptout;
    kptout.open("kpdttab.txt");

    vector<array<string, 5>> mnt;
    vector<pair<string, string>> kpdtab;

    map<string, int> pntab;

    string line, word;
    int p = 1;
    bool started = false;
    bool macroStart = false;

    while (getline(fin, line))
    {
        stringstream st(line);

        st >> word;

        if (started)
        {
            if (word != "END")
            {
                fout << word << " ";
                while (st >> word)
                {
                    fout << word << " ";
                }
                fout << "\n";
            }
            continue;
        }

        if (word == "MACRO")
        {
            macroStart = true;
            continue;
        }

        if (macroStart)
        {
            array<string, 5> a;
            mnt.push_back(a);

            int i = mnt.size() - 1;
            mnt[i][0] = word;
            mnt[i][3] = to_string(p);

            int pp = 0, kp = 0;

            pntout << "-----Pntab  for " << word << " is -----\n";

            while (st >> word)
            {
                if (word[word.length() - 1] == ',')
                {
                    word = word.substr(1, word.length() - 2);
                }
                else
                {
                    word = word.substr(1, word.length() - 1);
                }

                int equalIndex = -1;

                for (int j = 0; j < word.length(); j++)
                {
                    if (word[j] == '=')
                    {
                        equalIndex = j;
                        break;
                    }
                }

                if (equalIndex == -1)
                {
                    pp++;
                    pntab[word] = pntab.size() + 1;
                    pntout << pntab[word] << " . " << word << "\n";
                }
                else
                {
                    kp++;
                    string beforeEqual = word.substr(0, equalIndex);
                    string afterEqual = word.substr(equalIndex + 1);

                    kpdtab.push_back({beforeEqual, afterEqual});
                    pntab[beforeEqual] = pntab.size() + 1;

                    pntout << pntab[beforeEqual] << " . " << beforeEqual << "\n";
                }
            }
            mnt[i][1] = to_string(pp);
            mnt[i][2] = to_string(kp);

            if (kp != 0)
            {
                mnt[i][4] = to_string(kpdtab.size() - kp + 1);
            }
            else
            {
                mnt[i][4] = "-";
            }

            macroStart = false;
            continue;
        }

        if (word == "MEND")
        {
            mdtout << "MEND"
                   << "\n";
            pntab.clear();
        }
        else if (word == "START")
        {
            started = true;
        }
        else
        {
            mdtout << word << " ";
            while (st >> word)
            {
                if (word[0] == '&')
                {
                    if (word[word.length() - 1] == ',')
                    {
                        word = word.substr(1, word.length() - 2);
                    }
                    else
                    {
                        word = word.substr(1, word.length() - 1);
                    }

                    mdtout << "(p , " << pntab[word] << ") ";
                }
                else
                {
                    if (word[word.length() - 1] == ',')
                    {
                        word = word.substr(0, word.length() - 1);
                    }
                    else
                    {
                        word = word.substr(0, word.length());
                    }

                    mdtout << word << " ";
                }
            }
            mdtout << "\n";
        }
        p++;
    }
    fin.close();

    for (auto i : mnt)
    {
        for (auto j : i)
        {
            mntout << j << " ";
        }
        mntout << "\n";
    }

    mntout.close();

    for (auto i : kpdtab)
    {
        kptout << i.first << " " << i.second << "\n";
    }

    kptout.close();
    pntout.close();
    mdtout.close();
}