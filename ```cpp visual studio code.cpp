```cpp
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Funzione per simulare un BTP
void simulaBTP() {
    double capitale, tassoLordo, inflazione;
    int anni;

    cout << "\n Simulazione BTP\n";
    cout << "Capitale investito (€): ";
    cin >> capitale;

    cout << "Tasso interesse annuo lordo (%): ";
    cin >> tassoLordo;

    cout << "Durata (anni): ";
    cin >> anni;

    cout << "Inflazione annua media prevista (%): ";
    cin >> inflazione;

    double cedolaSemestraleNetta = (capitale * (tassoLordo / 100.0) / 2.0) * (1.0 - 0.26);
    double guadagnoTotaleNetto = cedolaSemestraleNetta * anni * 2;
    double guadagnoReale = guadagnoTotaleNetto * pow(1.0 - inflazione / 100.0, anni);

    cout << fixed << setprecision(2);
    cout << "\n RISULTATI BTP:\n";
    cout << "Cedola semestrale netta: €" << cedolaSemestraleNetta << endl;
    cout << "Guadagno totale netto: €" << guadagnoTotaleNetto << endl;
    cout << "Guadagno reale (con inflazione): €" << guadagnoReale << endl;
}

// Funzione per simulare un BOT
void simulaBOT() {
    double capitale, rendimentoLordo, inflazione;
    int mesi;

    cout << "\n Simulazione BOT\n";
    cout << "Capitale investito (€): ";
    cin >> capitale;

    cout << "Rendimento lordo (% su base annua): ";
    cin >> rendimentoLordo;

    cout << "Durata (mesi): ";
    cin >> mesi;

    cout << "Inflazione annua media prevista (%): ";
    cin >> inflazione;

    double rendimentoEffettivo = rendimentoLordo * (mesi / 12.0);
    double guadagnoLordo = capitale * (rendimentoEffettivo / 100.0);
    double guadagnoNetto = guadagnoLordo * (1.0 - 0.26);
    double guadagnoReale = guadagnoNetto * pow(1.0 - inflazione / 100.0, mesi / 12.0);

    cout << fixed << setprecision(2);
    cout << "\n RISULTATI BOT:\n";
    cout << "Guadagno netto: €" << guadagnoNetto << endl;
    cout << "Guadagno reale (con inflazione): €" << guadagnoReale << endl;
}

// Funzione per simulare un BTP Italia
void simulaBTPI() {
    double capitale, tassoBase, inflazioneReale;
    int anni;

    cout << "\n Simulazione BTP Italia\n";
    cout << "Capitale investito (€): ";
    cin >> capitale;

    cout << "Tasso base annuo reale (%): ";
    cin >> tassoBase;

    cout << "Durata (anni): ";
    cin >> anni;

    cout << "Inflazione media reale prevista (%): ";
    cin >> inflazioneReale;

    double tassoEffettivo = tassoBase + inflazioneReale;
    double cedolaSemestraleNetta = (capitale * (tassoEffettivo / 100.0) / 2.0) * (1.0 - 0.26);
    double guadagnoTotaleNetto = cedolaSemestraleNetta * anni * 2;

    cout << fixed << setprecision(2);
    cout << "\n RISULTATI BTP Italia:\n";
    cout << "Tasso effettivo (base + inflazione): " << tassoEffettivo << "%" << endl;
    cout << "Cedola semestrale netta: €" << cedolaSemestraleNetta << endl;
    cout << "Guadagno totale netto: €" << guadagnoTotaleNetto << endl;
    cout << "Valore reale mantenuto: indicizzato all'inflazione\n";
}

int main() {
    int scelta;

    cout << "Simulatore di Titoli di Stato (Italia)\n";
    cout << "-----------------------------------------\n";
    cout << "1. Simula BTP\n";
    cout << "2. Simula BOT\n";
    cout << "3. Simula BTP Italia\n";
    cout << "Scegli un'opzione (1-3): ";
    cin >> scelta;

    switch (scelta) {
        case 1:
            simulaBTP();
            break;
        case 2:
            simulaBOT();
            break;
        case 3:
            simulaBTPI();
            break;
        default:
            cout << "Scelta non valida.\n";
    }

    return 0;
}