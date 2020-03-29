#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int hungrymovesrecur(int ifish, vector<int> &faqua, int index, int moves)
{

    ///base case

    if (index == faqua.size())
    {

        return moves;
    }

    while (index < faqua.size() && ifish > faqua[index])
    {

        ifish += faqua[index];

        index++;
    }
    // if(index==faqua.size()){

    // return moves;
    // }

    int newifish = ifish + ifish - 1;
    int removal = faqua.size() - 1 - index;
    return min(hungrymovesrecur(newifish, faqua, index, moves + 1), moves + removal + 1);
}

int hungrymoves(vector<int> &faqua, int ifish)
{

    sort(faqua.begin(), faqua.end());
    int sum = ifish;
    int removalneed = faqua.size();
    int moves = 0;
    int best = removalneed;
    int i = 0;

    while (i < faqua.size())
    {

        if (sum > faqua[i])
        {
            sum += faqua[i];

            removalneed -= 1;
            i += 1;
        }
        else
        {

            sum += (sum - 1);
            moves += 1;
        }
        best = min(best, moves + removalneed);
    }

    return best;
}

int main()
{

    string str, temp;
    cin >> str;
    vector<string> tokens;
    vector<string> aqua;
    vector<int> faqua;
    stringstream check(str);
    while (getline(check, temp, '#'))
    {
        tokens.push_back(temp);
    }
    int ifish = stoi(tokens[0]);
    ///cout<<ifish<<endl;
    vector<string> fishnum;
    string fish = tokens[1];
    stringstream check2(fish);
    while (getline(check2, temp, ','))
    {
        fishnum.push_back(temp);
    }
    //vector<int>aquarium;
    for (int i = 0; i < fishnum.size(); i++)
    {

        faqua.push_back(stoi(fishnum[i]));
        //  aquarium.push_back(stoi(fishnum[i]));
        ///cout<<faqua[i]<<endl;
    }
    //aquarium.push_back()

    ///cout<<hungrymoves(faqua,ifish);
    cout << hungrymovesrecur(ifish, faqua, 0, 0);
    return 0;
}
