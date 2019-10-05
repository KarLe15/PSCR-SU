//
// Created by karim on 04/10/19.
//
#include <iostream>
#include <fstream>
#include <regex>
#include <chrono>
#include "HashMap.h"

using namespace std;
using namespace std::chrono;


void Question1(){
    ifstream input = ifstream("WarAndPeace.txt");

    auto start = steady_clock::now();
    cout << "Parsing War and Peace" << endl;

    size_t nombre_lu = 0;
    // prochain mot lu
    string word;
    // une regex qui reconnait les caractères anormaux (négation des lettres)
    regex re( R"([^a-zA-Z])");
    while (input >> word) {
        // élimine la ponctuation et les caractères spéciaux
        word = regex_replace ( word, re, "");
        // passe en lowercase
        transform(word.begin(),word.end(),word.begin(),::tolower);

        // word est maintenant "tout propre"
        if (nombre_lu % 100 == 0) {
            // on affiche un mot "propre" sur 100
            cout << nombre_lu << ": " << word << endl;
        }
        nombre_lu++;
    }
    input.close();

    cout << "Finished Parsing War and Peace" << endl;

    auto end = steady_clock::now();
    cout << "Parsing took "
         << duration_cast<milliseconds>(end - start).count()
         << "ms.\n";

    cout << "Found a total of " << nombre_lu << " words." << endl;
}

void Question2(){
    ifstream input = ifstream("WarAndPeace.txt");

    auto start = steady_clock::now();
    cout << "Parsing War and Peace" << endl;


    std::vector<string> mots(500);
    size_t nombre_lu = 0;
    // prochain mot lu
    string word;
    // une regex qui reconnait les caractères anormaux (négation des lettres)
    regex re( R"([^a-zA-Z])");
    while (input >> word) {
        // élimine la ponctuation et les caractères spéciaux
        word = regex_replace ( word, re, "");
        // passe en lowercase
        transform(word.begin(),word.end(),word.begin(),::tolower);


        bool contains = false;
        for( auto& tmp : mots){
            contains |= (tmp == word);
            if(contains){
                break;
            }
        }
        if( !contains){
            mots.push_back(word);
        }
        // word est maintenant "tout propre"
        if (nombre_lu % 100 == 0) {
            // on affiche un mot "propre" sur 100
            cout << nombre_lu << ": " << word << endl;
        }
        nombre_lu++;
    }
    input.close();

    cout << "Finished Parsing War and Peace" << endl;

    auto end = steady_clock::now();
    cout << "Parsing took "
         << duration_cast<milliseconds>(end - start).count()
         << "ms.\n";

    cout << "Found a total of " << nombre_lu << " words." << endl
         << "With " << mots.size() << " different words." << endl;
}


void Question3(){
    ifstream input = ifstream("WarAndPeace.txt");

    auto start = steady_clock::now();
    cout << "Parsing War and Peace" << endl;


    std::vector< pair<string,int> > mots(500);
    size_t nombre_lu = 0;
    // prochain mot lu
    string word;
    // une regex qui reconnait les caractères anormaux (négation des lettres)
    regex re( R"([^a-zA-Z])");
    while (input >> word) {
        // élimine la ponctuation et les caractères spéciaux
        word = regex_replace ( word, re, "");
        // passe en lowercase
        transform(word.begin(),word.end(),word.begin(),::tolower);


        bool contains = false;
        for( auto& tmp : mots){
            contains |= (tmp.first == word);
            if(contains){
                tmp.second++;
                break;
            }
        }
        if( !contains){
            mots.push_back( make_pair(word,1) );
        }
        nombre_lu++;
    }
    input.close();

    cout << "Finished Parsing War and Peace" << endl;

    auto end = steady_clock::now();
    cout << "Parsing took "
         << duration_cast<milliseconds>(end - start).count()
         << "ms.\n";

    for (auto& temp : mots) {
        if(temp.first == "war" || temp.first == "peace" || temp.first == "toto"){
            cout << temp.first << " : " << temp.second << endl;
        }
    }

    cout << "Found a total of " << nombre_lu << " words." << endl
         << "With " << mots.size() << " different words." << endl;
}

void Question6(){
    ifstream input = ifstream("WarAndPeace.txt");

    auto start = steady_clock::now();
    cout << "Parsing War and Peace" << endl;


    pr::HashMap<std::string, int> mots(500);
    size_t nombre_lu = 0;
    // prochain mot lu
    string word;
    // une regex qui reconnait les caractères anormaux (négation des lettres)
    regex re( R"([^a-zA-Z])");
    while (input >> word) {
        // élimine la ponctuation et les caractères spéciaux
        word = regex_replace ( word, re, "");
        // passe en lowercase
        transform(word.begin(),word.end(),word.begin(),::tolower);


        int * temp = mots.get(word) ;
        if( temp == nullptr){
            mots.put(word, 1);
        }else{
            mots.put(word, (*temp)+1);
        }
        nombre_lu++;
    }
    input.close();

    cout << "Finished Parsing War and Peace" << endl;

    auto end = steady_clock::now();
    cout << "Parsing took "
         << duration_cast<milliseconds>(end - start).count()
         << "ms.\n";

    int * nbWar = mots.get("war");
    int * nbPeace = mots.get("peace");
    int * nbToto = mots.get("toto");
    cout << "Found 'war' " << *nbWar << " times "<< endl;
    cout << "Found 'peace' " << *nbPeace << " times "<< endl;
    cout << "Found 'toto' " << (nbToto ? *nbToto : 0 ) << " times "<< endl;

    cout << "Found a total of " << nombre_lu << " words." << endl
         << "With " << mots.size() << " different words." << endl;
}

void Question7(){
    
}

int main () {

//    Question1();
//    Question2();
//    Question3();
    Question6();
    return 0;
}
