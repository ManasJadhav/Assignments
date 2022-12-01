#include <bits/stdc++.h>
using namespace std;

int main()
{

    map<string, pair<string, string>> opcode;

    opcode["STOP"] = {"IS", "00"};
    opcode["ADD"] = {"IS", "01"};
    opcode["SUB"] = {"IS", "02"};
    opcode["MULT"] = {"IS", "03"};
    opcode["MOVER"] = {"IS", "04"};
    opcode["MOVEM"] = {"IS", "05"};
    opcode["COMP"] = {"IS", "06"};
    opcode["BC"] = {"IS", "07"};
    opcode["DIV"] = {"IS", "08"};
    opcode["READ"] = {"IS", "09"};
    opcode["PRINT"] = {"IS", "10"};
    opcode["START"] = {"AD", "01"};
    opcode["END"] = {"AD", "02"};
    opcode["ORIGIN"] = {"AD", "03"};
    opcode["EQU"] = {"AD", "04"};
    opcode["LTORG"] = {"AD", "05"};
    opcode["DC"] = {"DL", "01"}; // define constant // while defining literal
    opcode["DS"] = {"DL", "02"}; // define statement // while defining symbols

    opcode["AREG"] = {"1", ""};
    opcode["BREG"] = {"2", ""};
    opcode["CREG"] = {"3", ""};
    opcode["DREG"] = {"4", ""};

    opcode["LT"] = {"1", ""};
    opcode["LE"] = {"2", ""};
    opcode["EQ"] = {"3", ""};
    opcode["GT"] = {"4", ""};
    opcode["GE"] = {"5", ""};
    opcode["ANY"] = {"6", ""};

    map<string, pair<int, string>> symbolTable;
    vector<pair<string, int>> literableTable;

    vector<string> poolTable;
    int litIndex = 0;
    int lc = -1;

    ifstream fin;

    fin.open("source2.txt");

    ofstream fout;

    fout.open("answer.txt");

    string line;
    string word;

    while (getline(fin, line))
    {
        stringstream st(line);
        st >> word;
        string label = "";

        if (opcode.count(word) == 0)
        {
            if (symbolTable.count(word) == 0)
            {
                symbolTable[word] = {lc, to_string(symbolTable.size() + 1)};
            }
            else
            {
                symbolTable[word].first = lc;
            }

            label = word;
            st >> word;
        }

        string operation = word;

        if (operation == "START")
        {
            fout << "    ";
            fout << "(" << opcode[word].first << " , " << opcode[word].second;
            fout << ") ";
            st >> word;
            fout << "(c , " << word << ")";
            lc = stoi(word);
        }
        else if (operation == "END")
        {
            fout << "    ";
            fout << "(" << opcode[word].first;

            if (opcode[word].second != "")
            {
                fout << " , " << opcode[word].second;
            }
            fout << ") ";

            fout << endl;

            poolTable.push_back("#" + to_string(litIndex + 1));

            for (; litIndex < literableTable.size(); litIndex++)
            {

                fout << lc << " ";

                fout << "(" << opcode["DC"].first;
                if (opcode[word].second != "")
                {
                    fout << " , " << opcode["DC"].second;
                }
                fout << ") ";

                literableTable[litIndex].second = lc;

                string literal = literableTable[litIndex].first;
                string num = literal.substr(2, literal.length() - 3);

                fout << "(c , " << num << ")";
                lc++;
            }
        }
        else if (operation == "LTORG")
        {

            fout << "    ";
            fout << "(" << opcode[word].first << " , " << opcode[word].second << ") ";

            fout << "\n";

            poolTable.push_back("#" + to_string(litIndex + 1));

            for (; litIndex < literableTable.size(); litIndex++)
            {

                fout << lc << " ";
                fout << "(" << opcode["DC"].first << " , " << opcode["DC"].second << ") ";

                literableTable[litIndex].second = lc;

                string temp = literableTable[litIndex].first;
                temp = temp.substr(2, temp.size() - 3);

                fout << "(c , " << temp << ") ";
                fout << "\n";
                lc++;
            }
        }
        else if (operation == "EQU")
        {
            fout << "    ";
            fout << "No IC Generated";

            st >> word;
            int plusOrMinusIndex = 0;
            for (int i = 0; i < word.length(); i++)
            {
                if (word[i] == '+' || word[i] == '-')
                {
                    plusOrMinusIndex = i;
                    break;
                }
            }

            char plusOrMinus = '0';
            string afterSign;
            string beforeSign;
            if (plusOrMinusIndex != 0)
            {
                plusOrMinus = word[plusOrMinusIndex];
                afterSign = word.substr(plusOrMinusIndex + 1);
                beforeSign = word.substr(0, plusOrMinusIndex);
            }
            else
            {
                beforeSign = word.substr(0, word.length());
            }

            symbolTable[label].first = symbolTable[beforeSign].first;

            if (plusOrMinus == '+')
            {
                symbolTable[label].first += stoi(afterSign);
            }
            else if (plusOrMinus == '-')
            {
                symbolTable[label].first -= stoi(afterSign);
            }
        }
        else if (operation == "ORIGIN")
        {
            fout << "    ";
            fout << "(" << opcode[word].first << " , " << opcode[word].second << ")     ";

            st >> word;

            int plusOrMinusIndex = 0;
            for (int i = 0; i < word.length(); i++)
            {
                if (word[i] == '+' || word[i] == '-')
                {
                    plusOrMinusIndex = i;
                    break;
                }
            }

            string afterSign, beforeSign;
            char plusOrMinus = '0';
            if (plusOrMinusIndex != 0)
            {
                plusOrMinus = word[plusOrMinusIndex];
                afterSign = word.substr(plusOrMinusIndex + 1);
                beforeSign = word.substr(0, plusOrMinusIndex);
            }
            else
            {
                beforeSign = word.substr(0, word.length());
            }

            lc = symbolTable[beforeSign].first;
            fout << "(s , " << symbolTable[beforeSign].second << ")";
            if (plusOrMinus == '+')
            {
                fout << "+" << afterSign;
                lc += stoi(afterSign);
            }
            else if (plusOrMinus == '-')
            {
                fout << "-" << afterSign;
                lc -= stoi(afterSign);
            }
        }
        else
        {
            fout << lc << " ";

            fout << "(" << opcode[word].first;
            fout << " , " << opcode[word].second;
            fout << ") ";

            while (st >> word)
            {

                if (operation == "DC")
                {
                    word = word.substr(1, word.size() - 2);
                    fout << "(c , " << word << ") ";
                    // symbolTable[label].first = lc; // done earilierin first if, doubttt
                }
                else if (operation == "DS")
                {

                    fout << "(c , " << word << ") ";
                    // symbolTable[label].first = lc;

                    // lc += stoi(word) - 1;
                }
                else if (word[0] == '=')
                {
                    literableTable.push_back({word, lc});
                    fout << "(L , " << literableTable.size() << ") ";
                }
                else if (opcode.count(word) > 0)
                {
                    fout << "(" << opcode[word].first << ") ";
                }
                else
                {
                    if (symbolTable.count(word) == 0)
                    {
                        symbolTable[word] = {lc, to_string(symbolTable.size() + 1)};
                    };
                    fout << "(s , " << symbolTable[word].second << ") ";
                }
            }
            lc++;
        }
        fout << "\n";
    }

    fin.close();
    fout.close();

    ofstream sout;
    sout.open("Symbol.txt");

    for (auto i : symbolTable)
    {
        sout << i.second.second << " " << i.first << " " << i.second.first << "\n";
    }
    sout.close();

    ofstream lout;
    lout.open("literal.txt");

    for (auto i : literableTable)
    {
        lout << i.first << " " << i.second << "\n";
    }

    lout.close();

    ofstream pout;
    pout.open("pool_table.txt");

    for (auto i : poolTable)
    {
        pout << i;
        pout << endl;
    }

    pout.close();

    return 0;
};