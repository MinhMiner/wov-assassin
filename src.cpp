#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    cout << "Cong cu ho tro tim kiem danh sach\t- By Minh Ga Mo\n";
    // Input
    start: string soChuCai; 
    printf("Nhap so chu cai: ");
    getline(cin, soChuCai);
    if (soChuCai == "0") return 0;
    vector<int> input;

    int temp;
    do
    {
        temp = stoi(soChuCai.substr(0,2));
        soChuCai.erase(0,2);
        input.push_back(temp);
    } while (soChuCai.find(' ') >= 0 and soChuCai.find(' ') < soChuCai.length());

    if (!soChuCai.empty())
    {
        temp = stoi(soChuCai.substr(0,1));
        input.push_back(temp);
    }
    
    string soTu = to_string(input.size()) + "_word.txt";
    ifstream fin(soTu);
    string tempStr;

    vector<vector<string>> database;
    int i1 = 0;
    while (!fin.eof()) {
        database.push_back(vector<string> {});
        for (int i = 0; i < stoi(soTu); i++)
        {
            fin >> tempStr;
            database[i1].push_back(tempStr);
        }
        i1++;
    }
    fin.close();

    // Search
    for (int i = 0; i < database.size(); i++)
    {
        for (int j = 0; j < stoi(soTu); j++)
        {
            if (input[j] != database[i][j].length())
            {
                goto skip;
            }      
        }
        for (int j = 0; j < stoi(soTu); j++)
        {
            cout << database[i][j] << ' ';   
        }
        cout << '\n';
        skip: continue;
    }
    
    goto start;
    return 0;
}
