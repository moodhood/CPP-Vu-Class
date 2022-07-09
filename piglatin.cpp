//Benjamin van Rhee PigLatin vertaalprogramma

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <vector>

std::string piglatin_woord( std::string woord);

int main(){
    //Hier vraagt hij het woord of de zin op.
    std::string antwoord;
    //[] = {"hallo", "Benjamin", "eerste", "alien"};
    
    //std::cout << "Geef mij een zin of een woord alsjeblieft:" << std::endl;


    std::getline(std::cin, antwoord);
    std::istringstream iss(antwoord);

    std::string piglatinzin;

    //Hier zet de code woord voor woord de zin om in pig latin en voegt het samen tot een zin.
    while (iss >> woord)
    {
        piglatin_woord(woord.c_str());
        piglatinzin +=  piglatin_woord(woord.c_str()) + " ";
    }

    std::cout << piglatinzin << "\n";

    return 0;
}

//Dit checkt voor als de input een medeklinker is of niet. 
bool isMedeklinker(char input){

    char medeklinker[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r','s', 't', 'y', 'v', 'w', 'x', 'z', '\0'};

    for(int x = 0; x < 21; x++){
        if (tolower(input) == medeklinker[x]){
            return true;
        }
    }
    return false;
}

//Dit checkt voor als de input een klinker is of niet 
bool isKlinker(char input){
    
    char klinker[] = {'a', 'e', 'i', 'o', 'u', '\0'};
    
    for(int x = 0; x < 5; x++){
        if(tolower(input) == klinker[x]){
            return true;
        }
    }
    return false;

}

//Hier maak ik een functie die de woorden om zet in piglatin
std::string piglatin_woord( std::string woord){

    std::string leesteken;
    char klinker[] = {'a', 'e', 'i', 'o', 'u'};

    //Hier kijkt het als het woord een medeklinker is op het karakter 0.
    if(isMedeklinker(woord[0])){
        
        //Hier kijkt het hoeveel medeklinkers tot de eerste klinker er zijn.
        std::string eersteMedeklinkers;
        while(isMedeklinker(woord[0]))
        {
            eersteMedeklinkers += woord[0];
            woord.erase(0,1);
        }
        
        //Dit kijkt als het eerste karakter een hoofdletter is, indien maakt het vervolgens het nieuwe eerste karakter een hoofdletter.
        if (isupper(eersteMedeklinkers[0])){
            eersteMedeklinkers[0] = tolower(eersteMedeklinkers[0]);
            woord[0] = toupper(woord[0]);
        }
        
        //Hier kijkt het naar de leestekens, eerst verwijderd het alle lees tekens daarna bewaard hij het in een variabele. 
        while(ispunct(woord[woord.length()-1])){ 
            leesteken = woord[woord.length()-1] + leesteken;
            woord.resize(woord.length()-1);
        }

        //Hier wordt de output gegeven om uitgeprint te worden in de main.
        std::string output = woord + eersteMedeklinkers + "ay" + leesteken; 
        return output;
    }
    //Hier kijkt het als het eerste karakter een klinker.
    else if(isKlinker(woord[0])){

        //Hier kijkt het naar de leestekens, eerst verwijderd het alle lees tekens daarna bewaard hij het in een variabele. 
        while(ispunct(woord[woord.length()-1])){ 
            leesteken = woord[woord.length()-1] + leesteken;
            woord.resize(woord.length()-1);
        }

        //Hier wordt de output gegeven om uitgeprint te worden.
        std::string output = woord + "way" + leesteken;
        return output;
    }
    
    return woord;
}



