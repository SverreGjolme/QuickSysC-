#include <iostream>
using namespace std;

//Gjettelek, gjett det hemmelige tallet

int main()
{
    int hemmeligTall = 13;                                  //Det hemmelige tallet er 13
    int gjett;                                              //Variabel som holder brukeren sitt gjett
    int gjettAntall = 0;                                    //Hvor mange ganger brukeren har gjettet
    int gjettLimit = 5;                                     //Maks antall gjett brukeren har
    bool tomForGjett = false;                               //Spillet starter med at brukeren ikke er tom for gjett

    while(hemmeligTall != gjett && !tomForGjett) {          //Så lenge brukeren ikke har gjettet riktig OG ikke er tom for gjettinger
        if(gjettAntall < gjettLimit) {                      //Kan tippe så lenge man har igjen forsøk
            cout << "Gjett det hemmelige tallet: ";
            cin >> gjett;
            gjettAntall++;                                  //Teller opp antall gjettinger
        } else {
            tomForGjett = true;                             //Er tom for gjettinger
        }
    }

    if(tomForGjett) {                                       //Er man tom for gjettinger:
        cout << "Du klarte det ikke.";
    } else {                                                //Ellers klarte man det!
        cout << "Gratulerer, du gjettet riktig!";
    }


    return 0;
}
