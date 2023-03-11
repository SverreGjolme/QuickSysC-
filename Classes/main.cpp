#include <iostream>
#include <string>
using namespace std;

//Et lite program om klassen 'Person', noen klasse-funksjoner og loops

class Person {                                                          //Oppretter en class med navn Person
public:
    string navn;                                                        //En person består av navn, kjønn, hobby og alder
    string kjonn;
    string hobby;
    int alder;

    Person(string aNavn, string aKjonn, int aAlder, string aHobby) {    //Constructor, denne tar 4 argumenter, èn for hver variabel
        navn = aNavn;
        kjonn = aKjonn;                                                 //Vi bruker denne til å initialisere et par instanser av objektet Person lenger ned i koden
        alder = aAlder;
        hobby = aHobby;
    }

    Person() {                                                          //Constructor uten argumenter, dette er en default constructor.
        navn = "Ukjent";                                                //Alle objekter initialisert uten argumenter, blir initialisert på denne måten, default
        kjonn = "Ukjent";
        alder = 0;
        hobby = "Ukjent";
    }

    void printInfo() {                                                  //Funksjon for å printe informasjonen til objektet
        cout << "Navn: " << navn << endl;
        cout << "Kjønn: " << kjonn << endl;
        cout << "Alder: " << alder << endl;
        cout << "Hobby: " << hobby << "\n\n";
    }
};

int main() {
    Person person1("Sverre", "Mann", 36, "Warhammer");                  //person1, person2 og person3 blir initialisert
    Person person2("Nancy", "Glaeserud", 40, "Lese");
    Person person3;

    cout << "Du kjenner til disse personene: \n\n";
    person1.printInfo();                                                //Kaller på class-funksjonen printInfo() for å få informasjonen til objektene
    person2.printInfo();
    person3.printInfo();

    char valg;
    do {
        cout << "For å oppdatere informasjonen til en person, skriv 1, 2 eller 3: ";    //1, 2 eller 3 vil be om ny informasjon om den valgte personen.
        cin >> valg;                                                                    //Alt annet vil avslutte programmet
        if (valg == '1') {                                                              //Ved valg 1...
            cout << "Nytt navn: ";
            cin >> person1.navn;
            cout << "Nytt kjønn: ";
            cin >> person1.kjonn;
            cout << "Ny alder: ";
            cin >> person1.alder;
            cout << "Ny hobby: ";
            cin >> person1.hobby;
            cout << "Den nye informasjonen er: \n\n";
            person1.printInfo();                                                        //Printer den nye informasjonen til brukeren
        }
        else if (valg == '2') {                                                         //Ved valg 2...
            cout << "Nytt navn: ";
            cin >> person2.navn;
            cout << "Nytt kjønn: ";
            cin >> person2.kjonn;
            cout << "Ny alder: ";
            cin >> person2.alder;
            cout << "Ny hobby: ";
            cin >> person2.hobby;
            cout << "Den nye informasjonen er: \n\n";
            person2.printInfo();                                                        //Printer den nye informasjonen til brukeren
        }
        else if (valg == '3') {                                                         //Ved valg 3...
            cout << "Nytt navn: ";
            cin >> person3.navn;
            cout << "Nytt kjønn: ";
            cin >> person3.kjonn;
            cout << "Ny alder: ";
            cin >> person3.alder;
            cout << "Ny hobby: ";
            cin >> person3.hobby;
            cout << "Den nye informasjonen er: \n\n";
            person3.printInfo();                                                        //Printer den nye informasjonen til brukeren
        }
    } while (valg == '1' || valg == '2' || valg == '3');                              //Det er også et alternativ å gjøre om koden som endrer informasjonen til en klasse-funksjon,
                                                                                      //men for dette eksempelet gjorde jeg det i loopen.
    return 0;
}
