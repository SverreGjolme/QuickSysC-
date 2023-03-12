#include <iostream>
#include <cstdlib>                  //Bibliotek for � bruke rand()
#include <ctime>                    //Bibliotek for � bruke time()
using namespace std;

//Har du lurt p� hvorfor du aldri vinner i lotto?
//Her er en kodesnutt som pr�ver � vise hvorfor

int randomNumber() {
    return rand() % 34 + 1;                                  //Funksjon som returnerer et tilfeldig generert tall mellom 1-34
}

bool finnesAllerede(int arr[], int num, int size) {           //Funksjon som sjekker hvorvidt et tall allerede eksisisterer i en array ved en gitt st�rrelse
    for(int i = 0; i < size; i++) {
        if(arr[i] == num) {
            return true;
        }
    }
    return false;
}

bool erLike(int arrSpiller[], int arrVinner[], int size) {       //Funksjon som sjekker hvorvidt summen av begge arrayene er like eller ikke
    int sum1 = 0;
    int sum2 = 0;                                            //Det er en litt lettere m�te � sammenlikne arrayene p� enn ved � omorganisere tallene
    for(int i = 0; i < size; i++) {                          //i stigende rekkef�lge, for s� � sammenlikne dem
        sum1 += arrSpiller[i];
        sum2 += arrVinner[i];
    }

    return sum1 == sum2;
}

int main()
{
    srand(time(nullptr));                                    //Initialiserer random-funksjonen basert p� tiden
    const int SIZE = 7;                                      //Definerer maks-st�rrlsen til arrayene(lottorekker)

    int vinnerrekke[SIZE] = {0};                             //Array som senere blir befolket med tilfeldig genererte tall mellom 1-34
    int spillerrekke[SIZE] = {99};                           //Array med spilleren sine tall

    int antallSpill = 0;


        for(int i = 0; i < SIZE; i++) {                             //S� lenge ikke hele arrayen har f�tt nye tall, kj�res loopen
            int randomNum = randomNumber();                         //Kalles p� randomNumber funksjonen og setter tallet inn i variabelen 'randomNum'
            while(finnesAllerede(vinnerrekke, randomNum, SIZE)) {   //S� lenge det er 'true' at tallet som er generert allerede eksisterer i arrayen, s� genererer vi et nytt tall
                randomNum = randomNumber();
            }
            vinnerrekke[i] = randomNum;                             //N�r det er false, i.e tallet eksisterer ikke fra f�r i arrayen, assigner vi det nye tallet til arrayen
        }

        while(!erLike(spillerrekke, vinnerrekke, SIZE)){                 //S� lenge arrayene ikke er like, kj�res koden nedenfor
          for(int i = 0; i < SIZE; i++) {
            spillerrekke[i] = 99;                                        //Spillerrekken resettes, dette betyr et nytt spill
          }
            for(int i = 0; i < SIZE; i++) {                              //S� lenge ikke hele arrayen har f�tt nye tall, kj�res loopen
                int randomNum = randomNumber();                          //Kalles p� randomNumber funksjonen og setter tallet inn i variabelen 'randomNum'
                while(finnesAllerede(spillerrekke, randomNum, SIZE)) {   //S� lenge det er 'true' at tallet som er generert allerede eksisterer i arrayen, s� genererer vi et nytt tall
                    randomNum = randomNumber();
                }
                spillerrekke[i] = randomNum;                             //N�r det er false, i.e tallet eksisterer ikke fra f�r i arrayen, assigner vi det nye tallet til arrayen
            }
            antallSpill++;                                               //Teller opp hvor mange ganger brukeren har spilt
        }

        cout << "Gratulerer, du vant! Du spillte " << antallSpill << " ganger for � vinne!\n";

    return 0;
}
