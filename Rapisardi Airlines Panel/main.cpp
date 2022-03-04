/*
Website: https://matt05.ml
GitHub: @Matt0550

Realizzare un programma che permetta di gestire il traffico aereo di un aeroporto.

In particolare ci saranno n vettori per registrare:
1) il codice del volo;
2) la compagnia aerea;
3) partenza o arrivo;
4) orario;
5) stato ();
6) destinazione.

Tenuto conto che nel vettore partenza o arrivo dovrà contenere un codice il cui contenuto dovrà essere P/A;
Il vettore relativo allo stato potrà contenere D = decollato, L = atterrato, A = annullato, D = ritardo, 
B = in fase di imbarco, S = programmato.

Visualizzare:
1) le informazioni di un determinato volo dato in input;
2) il codice volo, la città e l'orario dei voli in imbarco;
3) le informazioni dei voli in partenza per una città data in input;

A prescindere dall'ora attuale, visualizzare i voli il cui orario programmato è superato e non è ancora 
atterrato/partito e modificare lo in D.

Legenda:
D = Departured - decollato
L = Landed - atterrato
C = Canceled - cancellato
B = Boarding - in fase di imbarco
S = Scheduled - programmato
R = Ritardo

P = Partenze
A = Arrivi
*/

#include <iostream>
#include <algorithm> // begin, end
#include <vector>
#include <random>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

string AirlineCompany = "Rapisardi Airlines Panel";
string greenColorCode = "\033[92m";
string redColorCode = "\033[91m";
string cyanColorCode = "\033[96m";
string orangeColorCode = "\033[93m";
string purpleColorCode = "\033[95m";
string boldColorCode = "\033[1m";
string resetColorCode = "\033[0m";

vector<vector<string>>flights = {
    {"FR2537", "Ryanair", "A", "S", "2/3/2022 - 13:25", "2/3/2022 - 14:10", "Milano", "Catania"},
    {"AZ1714", "ITA Airways", "P", "S", "1/3/2022 - 14:05", "2/3/2022 - 15:55", "Catania", "Milano"},
    {"W68181", "Wizz Air", "P", "S", "1/3/2022 - 15:20", "2/3/2022 - 17:05", "Catania", "Venezia"},
    {"W68176", "Wizz Air", "A", "S", "1/3/2022 - 13:15", "1/3/2022 - 14:35", "Roma", "Catania"},
    {"FR9958", "Ryanair", "P", "S", "1/3/2022 - 19:30", "1/3/2022 - 21:10", "Catania", "Pisa"},
    {"FR6271", "Ryanair", "P", "S", "1/3/2022 - 17:50", "1/3/2022 - 19:30", "Catania", "Bologna"},
    {"AZ1714", "ITA Airways", "P", "S", "4/3/2022 - 19:35", "4/3/2022 - 21:25", "Catania", "Milano"},
    {"AZ1701", "ITA Airways", "A", "S", "4/3/2022 - 13:20", "4/3/2022 - 15:10", "Milano", "Catania"},
    {"AZ1714", "ITA Airways", "P", "S", "4/3/2022 - 12:00", "4/3/2022 - 14:00", "Catania", "Milano"},
    {"AZ1714", "ITA Airways", "P", "S", "4/3/2022 - 12:00", "4/3/2022 - 14:00", "Catania", "Milano"},
    {"AZ1714", "ITA Airways", "P", "S", "4/3/2022 - 12:00", "4/3/2022 - 14:00", "Catania", "Milano"},
    {"AZ1714", "ITA Airways", "P", "S", "4/3/2022 - 11:00", "4/3/2022 - 14:00", "Catania", "Milano"},
    {"AZ1714", "ITA Airways", "P", "S", "4/3/2022 - 11:00", "4/3/2022 - 14:00", "Catania", "Milano"},
    {"AZ1714", "ITA Airways", "P", "S", "4/3/2022 - 11:00", "4/3/2022 - 14:00", "Catania", "Milano"},

    // Codice volo, compagnia aerea, partenza o arrivo, status, orario partenza, orario arrivo, città partenza, città arrivo
};

void ClearScreen() {
    #ifdef _WIN32 // Check OS
    system("CLS"); // Windows os
    #else
    system("clear"); // Linux or Mac Windows
    #endif
}

// Class taken from my GitHub profile created by me
string CustomSeparatorWithText(string symbol, string text, int length = 10) {
    string center, text1, text2, text3, lati, sym;
    int length2;

    sym = symbol;

    int tex = text.length();

    for (int i = 1; i < tex+2 + length; i++) {
        symbol = symbol + sym;
    }

    text1 = symbol + "\n";
    length2 = length/2-0;

    for (int i = 0; i < length2; i++) {
        lati = lati + sym;
    }

    text3 = symbol + "\n" + lati + " " + text + " " + lati + "\n" + symbol + "\n";
    return text3;
}


int ChooseWhileINT(int choose, string text) {
    cout<< text << greenColorCode;
    cin>>choose;
    cout<<resetColorCode;
    
    while(!cin) {
        cout << text << greenColorCode; // Input verde
        cin.clear();
        cin.ignore(256,'\n');
        cin >> choose;
        cout<<resetColorCode; // Reset colori
    }
    return choose;
}

string get_right_of_delim(string const& str, string const& delim){
  return str.substr(str.find(delim) + delim.size());
}

string get_left_of_delim(string const &str, string const &delim) {
    return str.substr(0, str.find(delim));
}

string flight_status_formatter(string code, string schedule) {
    string status;
    if(code == "D") {
        status = greenColorCode+"D - Departured"+resetColorCode;
    } else if (code == "L") {
        status = greenColorCode+"L - Landed"+resetColorCode;
    } else if (code == "C") {
        status = redColorCode+"C - Canceled"+resetColorCode;
    } else if (code == "B") {
        status = orangeColorCode+"B - Boarding"+resetColorCode;
    } else if (code == "S") {
        status = cyanColorCode+"S - Scheduled at "+schedule+resetColorCode;
    } else if (code == "R") {
        status = purpleColorCode+"R - Delayed at "+schedule+resetColorCode;
    } else {
        status = redColorCode+"Unknown"+resetColorCode;
    }
    return status;
}

int year, month, day, hour, minute, seconds;
void setDate() {
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    
    year =  1900 + local_time->tm_year;
    month = 1 + local_time->tm_mon;
    day = local_time->tm_mday;
    hour = 1 + local_time->tm_hour-10;
    minute = local_time->tm_min;
    seconds = local_time->tm_sec;
}

class Program {
    public:
    void show_all_flight(string type = "normal") {
       ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Voli")<<resetColorCode;
        cout<<"Lista di tutti i voli del "<<day<<"/"<<month<<"/"<<year<<"/"<<" - "<<hour<<":"<<minute<<":"<<seconds<<endl<<endl;
        string status, status_2;
        for(int i = 0; i < flights.size(); i++) {
            status = flight_status_formatter(flights[i][3], flights[i][4]);
            
            if(flights[i][2] == "P") {
                status_2 = orangeColorCode+"P - Partenza"+resetColorCode;
            } else if (flights[i][2] == "A") {
                status_2 = greenColorCode+"A - Arrivo"+resetColorCode;
            } else {
                status_2 = redColorCode+"Unknown"+resetColorCode;
            }
            
            cout<<flights[i][0]<<" FROM "<<cyanColorCode<<flights[i][6]<<resetColorCode<<" ("<<flights[i][4]<<") TO "<<cyanColorCode<<flights[i][7]<<resetColorCode<<" ("<<flights[i][5]<<") - STATO VOLO " <<status<<" - STATUS "<<status_2<<cyanColorCode<<" - "<<flights[i][1]<<resetColorCode<<endl;
        }
        if(type == "normal") {
            cout<<endl<<"1. Aggiorna"<<endl;
            cout<<"2. Indietro"<<endl<<endl;
            cout<<"3. Esci"<<endl;
            int choose = 0;
            choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
            
            if(choose == 1) {
                set_flight_status();
                show_all_flight();
            } else if (choose == 2) {
                home();
                
            } else if(choose ==3) {
                cout<<endl<<redColorCode<<"Uscita in corso..."<<resetColorCode<<endl;
                exit(0);
            } else {
                cout<<endl<<redColorCode<<"Scelta non valida!"<<resetColorCode<<endl;
                
            }
        }
    }
    
    void search_flight(string code) {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Informazioni volo")<<resetColorCode;
        cout<<"Informazioni per il volo "<<boldColorCode<<code<<resetColorCode<<endl<<endl;
        int x = 0;
        for(int i = 0; i < flights.size(); i++) {
            if(code == flights[i][0]) {
                x++;
                cout<<"Compagnia volo: "<<cyanColorCode<<flights[i][1]<<resetColorCode<<endl;
                cout<<"Aereoporto di partenza: "<<cyanColorCode<<flights[i][6]<<" - "<<flights[i][4]<<resetColorCode<<endl;
                cout<<"Aereoporto di arrivo: "<<cyanColorCode<<flights[i][7]<<" - "<<flights[i][5]<<resetColorCode<<endl<<endl;
                
                if(flights[i][2] == "P") {
                    cout<<"Status: "<<orangeColorCode<<"P - Partenza"<<resetColorCode<<endl;
                } else if (flights[i][2] == "A") {
                    cout<<"Status: "<<greenColorCode<<"A - Arrivo"<<resetColorCode<<endl;
                } else {
                    cout<<"Status: "<<redColorCode<<"Unknown"<<resetColorCode<<endl;
                }
                
                cout<<"Stato volo: "<<flight_status_formatter(flights[i][3], flights[i][4])<<endl;
            
            }
        }
        if(x < 1) {
            cout<<redColorCode<<"Nessun volo trovato"<<resetColorCode<<endl;
        }
        cout<<endl<<"1. Indietro"<<endl;
        cout<<"2. Esci"<<endl;
        int choose = 0;
        choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
        
        if(choose == 1) {
            home();
        } else if (choose == 2) {
            cout<<endl<<redColorCode<<"Uscita in corso..."<<resetColorCode<<endl;
            exit(0);
        } else {
            cout<<endl<<redColorCode<<"Scelta non valida!"<<resetColorCode<<endl;
            
        }
    }
    
    void search_flight_by_airport_departure(string airport) {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Voli")<<resetColorCode;
        cout<<"Lista voli per "<<boldColorCode<<airport<<resetColorCode<<endl<<endl;
        string status, status_2;
        int x = 0;
        for(int i = 0; i < flights.size(); i++) {
            if(airport == flights[i][6]) {
                x++;
                status = flight_status_formatter(flights[i][3], flights[i][4]);
                
                if(flights[i][2] == "P") {
                    status_2 = orangeColorCode+"P - Partenza"+resetColorCode;
                } else if (flights[i][2] == "A") {
                    status_2 = greenColorCode+"A - Arrivo"+resetColorCode;
                } else {
                    status_2 = redColorCode+"Unknown"+resetColorCode;
                }
                
                cout<<flights[i][0]<<" FROM "<<cyanColorCode<<flights[i][6]<<resetColorCode<<" ("<<flights[i][4]<<") TO "<<cyanColorCode<<flights[i][7]<<resetColorCode<<" ("<<flights[i][5]<<") - STATO VOLO " <<status<<" - STATUS "<<status_2<<cyanColorCode<<" - "<<flights[i][1]<<resetColorCode<<endl;
            }
        }
        
        if(x < 1) {
            cout<<redColorCode<<"Nessun volo trovato per questo aereoporto di partenza"<<resetColorCode<<endl;
        }
        
        cout<<endl<<"1. Indietro"<<endl;
        cout<<"2. Esci"<<endl;
        int choose = 0;
        choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
        
        if(choose == 1) {
            home();
        } else if (choose == 2) {
            cout<<endl<<redColorCode<<"Uscita in corso..."<<resetColorCode<<endl;
            exit(0);
        } else {
            cout<<endl<<redColorCode<<"Scelta non valida!"<<resetColorCode<<endl;
            
        }
    }
    
    void search_flight_by_airport_landed(string airport) {
        ClearScreen();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Voli")<<resetColorCode;
        cout<<"Lista voli per "<<boldColorCode<<airport<<resetColorCode<<endl<<endl;
        string status, status_2;
        int x = 0;
        for(int i = 0; i < flights.size(); i++) {
            if(airport == flights[i][7]) {
                status = flight_status_formatter(flights[i][3], flights[i][4]);
                
                if(flights[i][2] == "P") {
                    status_2 = orangeColorCode+"P - Partenza"+resetColorCode;
                } else if (flights[i][2] == "A") {
                    status_2 = greenColorCode+"A - Arrivo"+resetColorCode;
                } else {
                    status_2 = redColorCode+"Unknown"+resetColorCode;
                }
                
                cout<<flights[i][0]<<" FROM "<<cyanColorCode<<flights[i][6]<<resetColorCode<<" ("<<flights[i][4]<<") TO "<<cyanColorCode<<flights[i][7]<<resetColorCode<<" ("<<flights[i][5]<<") - STATO VOLO " <<status<<" - STATUS "<<status_2<<cyanColorCode<<" - "<<flights[i][1]<<resetColorCode<<endl;
            }
        }
        
        if(x < 1) {
            cout<<redColorCode<<"Nessun volo trovato per questo aereoporto di arrivo"<<resetColorCode<<endl;
        }
        
        cout<<endl<<"1. Indietro"<<endl;
        cout<<"2. Esci"<<endl;
        int choose = 0;
        choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
        
        if(choose == 1) {
            home();
        } else if (choose == 2) {
            cout<<endl<<redColorCode<<"Uscita in corso..."<<resetColorCode<<endl;
            exit(0);
        } else {
            cout<<endl<<redColorCode<<"Scelta non valida!"<<resetColorCode<<endl;
            
        }
    }
    
    void flights_departing() {
        ClearScreen();
        string system_date = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Voli")<<resetColorCode;
        cout<<"Voli in arrivo per il "<<boldColorCode<<system_date<<resetColorCode<<endl<<endl;
        string status, status_2;
        int x = 0;
        for(int i = 0; i < flights.size(); i++) {
            string flight_date = get_left_of_delim(flights[i][4], " - ");
            if(flight_date == system_date) {
                if(flights[i][2] == "P") {
                    x++;
                    status = flight_status_formatter(flights[i][3], flights[i][4]);
                
                    if(flights[i][2] == "P") {
                        status_2 = orangeColorCode+"P - Partenza"+resetColorCode;
                    } else if (flights[i][2] == "A") {
                        status_2 = greenColorCode+"A - Arrivo"+resetColorCode;
                    } else {
                        status_2 = redColorCode+"Unknown"+resetColorCode;
                    }
                    
                    cout<<flights[i][0]<<" FROM "<<cyanColorCode<<flights[i][6]<<resetColorCode<<" ("<<flights[i][4]<<") TO "<<cyanColorCode<<flights[i][7]<<resetColorCode<<" ("<<flights[i][5]<<") - STATO VOLO " <<status<<" - STATUS "<<status_2<<cyanColorCode<<" - "<<flights[i][1]<<resetColorCode<<endl;
                }
            }
        }
        if(x < 1) {
            cout<<redColorCode<<"Nessun volo in arrivo"<<resetColorCode<<endl;
        }
    
        cout<<endl<<"1. Indietro"<<endl;
        cout<<"2. Esci"<<endl;
        int choose = 0;
        choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
        
        if(choose == 1) {
            home();
        } else if (choose == 2) {
            cout<<endl<<redColorCode<<"Uscita in corso..."<<resetColorCode<<endl;
            exit(0);
        } else {
            cout<<endl<<redColorCode<<"Scelta non valida!"<<resetColorCode<<endl;
            
        }
    }
    
    void flights_incoming() {
        ClearScreen();
        string system_date = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
        cout<<cyanColorCode<<CustomSeparatorWithText("=", "Voli")<<resetColorCode;
        cout<<"Voli in arrivo per il "<<boldColorCode<<system_date<<resetColorCode<<endl<<endl;
        string status, status_2;
        int x = 0;
        for(int i = 0; i < flights.size(); i++) {
            string flight_date = get_left_of_delim(flights[i][4], " - ");
            if(flight_date == system_date) {
                if(flights[i][2] == "A") {
                    x++;
                    status = flight_status_formatter(flights[i][3], flights[i][4]);
                
                    if(flights[i][2] == "P") {
                        status_2 = orangeColorCode+"P - Partenza"+resetColorCode;
                    } else if (flights[i][2] == "A") {
                        status_2 = greenColorCode+"A - Arrivo"+resetColorCode;
                    } else {
                        status_2 = redColorCode+"Unknown"+resetColorCode;
                    }
                    
                    cout<<flights[i][0]<<" FROM "<<cyanColorCode<<flights[i][6]<<resetColorCode<<" ("<<flights[i][4]<<") TO "<<cyanColorCode<<flights[i][7]<<resetColorCode<<" ("<<flights[i][5]<<") - STATO VOLO " <<status<<" - STATUS "<<status_2<<cyanColorCode<<" - "<<flights[i][1]<<resetColorCode<<endl;
                }
            }
        }
        if(x < 1) {
            cout<<redColorCode<<"Nessun volo in arrivo"<<resetColorCode<<endl;
        }
    
        cout<<endl<<"1. Indietro"<<endl;
        cout<<"2. Esci"<<endl;
        int choose = 0;
        choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
        
        if(choose == 1) {
            home();
        } else if (choose == 2) {
            cout<<endl<<redColorCode<<"Uscita in corso..."<<resetColorCode<<endl;
            exit(0);
        } else {
            cout<<endl<<redColorCode<<"Scelta non valida!"<<resetColorCode<<endl;
            
        }
    }

    void set_flight_status() {
        setDate();
        //string flight_time, flight_hour, flight_minute, flight_date, flight_time_landed, flight_hour_landed, flight_minute_landed, flight_date_landed, system_date, flight_date_day, flight_date_month, flight_date_month_tmp, flight_date_year;
        string system_date = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
        for(int i = 0; i < flights.size(); i++) {
            string flight_time = get_right_of_delim(flights[i][4], " - ");
            string flight_hour = get_left_of_delim(flight_time, ":");
            string flight_minute = get_right_of_delim(flight_time, ":");
            string flight_date = get_left_of_delim(flights[i][4], " - ");
            string flight_date_day = get_left_of_delim(flight_date, "/");
            string flight_date_month_tmp = get_right_of_delim(flight_date, "/");
            string flight_date_month = get_left_of_delim(flight_date_month_tmp, "/");
            string flight_date_year = get_right_of_delim(flight_date_month_tmp, "/");
            
            string flight_time_landed = get_right_of_delim(flights[i][5], " - ");
            string flight_hour_landed = get_left_of_delim(flight_time_landed, ":");
            string flight_minute_landed = get_right_of_delim(flight_time_landed, ":");
            string flight_date_landed = get_left_of_delim(flights[i][5], " - ");
            
            string minute_back = flight_minute;
            string minute_back_landed = flight_minute_landed;
            
            if(system_date == flight_date) {
                
               if(hour == stoi(flight_hour)-1 && minute >= stoi(flight_minute)) {
                    flights[i][3] = "B";
                } else if((hour == stoi(flight_hour_landed) && minute >= stoi(flight_minute_landed)) or hour > stoi(flight_hour_landed)) {
                    flights[i][3] = "L";
                } else if (hour < stoi(flight_hour)){
                    flights[i][3] = "S";
                } else {
                    flights[i][3] = "D";
                }
 
            } else if ((day > stoi(flight_date_day) && month == stoi(flight_date_month) && year == stoi(flight_date_year)) or (year > stoi(flight_date_year)) or (month > stoi(flight_date_month))) {
                flights[i][3] = "L";  
            } 
                
            // string array_rand[20] = {"C"}; // Random set flight status to Canceled
            // string array_rand_2[30] = {"S"}; // Random set flight status to Scheduled

            // if (flights[i][3] == "S" or flights[i][3] == "B") { 
            //     int index = rand() % 20;
            //     if(array_rand[index] != "") {
            //         flights[i][3] = array_rand[index];
            //     }
            // } else if(flights[i][3] == "C") { // If the flight is canceled set to scheduled with a low probability
            //     int index = rand() % 30;
            //     if(array_rand_2[index] != "") {
            //         flights[i][3] = array_rand_2[index];
            //     }
            // }

            int random = rand() % 40;
            int random2 = rand() % 100;
            if(random == 0) {
               if (flights[i][3] == "S" or flights[i][3] == "B") { 
                    flights[i][3] = "C";
                }
            }
            if(random2 == 0) {
                if(flights[i][3] == "C") { // If the flight is canceled set to scheduled with a low probability
                    flights[i][3] = "S";
                }
            }
            if(random == 1 && system_date == flight_date) {
                if(flights[i][3] == "B" or flights[i][3] == "S") { // If the flight is canceled set to scheduled with a low probability
                    int minute = rand() % 60;
                    string minute_tot;
                    if(minute < 10) {
                        minute_tot = "0"+to_string(minute);
                    } else {
                        minute_tot = to_string(minute);
                    }
                    flights[i][3] = "R";
                    flights[i][4] = system_date + " - " + flight_hour + ":" + minute_tot;
                    flights[i][5] = system_date + " - " + flight_hour_landed + ":" + minute_tot;
                }
            }
        }
    }
    
    void home() {
        ClearScreen();
        setDate();
        set_flight_status();
        cout<<cyanColorCode<<CustomSeparatorWithText("=", AirlineCompany)<<resetColorCode;
        cout<<"Benvenuto in "<<AirlineCompany<<endl;
        cout<<"Oggi è il "<<day<<"/"<<month<<"/"<<year<<endl<<endl;
        cout<<"1. Informazioni su un volo"<<endl;
        cout<<"2. Visualizza tutti i voli"<<endl;
        cout<<"3. Visualizza tutti i voli per un aereoporto di partenza"<<endl;
        cout<<"4. Visualizza tutti i voli per un aereoporto di arrivo"<<endl;
        cout<<"5. Visualizza tutti i voli in partenza"<<endl;
        cout<<"6. Visualizza tutti i voli in arrivo"<<endl;
        cout<<"7. Visualizza tutti i voli in live update"<<endl<<endl;
        cout<<"8. Esci"<<endl;
        int choose = 0;
        choose = ChooseWhileINT(choose, "Cosa vuoi fare? ");
        if(choose == 1) {
            string code;
            while(code != "exit") {
                cout<<endl<<"Inserisci il codice volo: "<<greenColorCode;
                cin>>code;
                cout<<resetColorCode;
                search_flight(code);
            }
            
        } else if (choose == 2) {
            setDate();
            set_flight_status();
            show_all_flight();

        } else if (choose == 3) {
            string airport;
            while(airport != "exit") {
                cout<<endl<<"Inserisci l'aereoporto di partenza: "<<greenColorCode;
                cin>>airport;
                cout<<resetColorCode;
                search_flight_by_airport_departure(airport);
            }
        } else if (choose == 4) {
            string airport;
            while(airport != "exit") {
                cout<<endl<<"Inserisci l'aereoporto di arrivo: "<<greenColorCode;
                cin>>airport;
                cout<<resetColorCode;
                search_flight_by_airport_landed(airport);
            }
        } else if (choose == 5) {
            flights_departing();
            
        } else if (choose == 6) {
            flights_incoming();
            
        } else if (choose == 7) {
            while(true) {
                setDate();
                set_flight_status();
                show_all_flight("live");
                sleep(3);
            }
        } else if (choose == 8) {
            cout<<redColorCode<<"Uscita..."<<resetColorCode<<endl;
            exit(0);
            
        } else {
            cout<<redColorCode<<"Scelta non valida!"<<resetColorCode<<endl;
        }
    }
};

int main() {
    srand(time(NULL));

    setDate();

    Program program;
    program.home();

    return 0;
}

