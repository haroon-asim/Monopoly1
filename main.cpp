#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <time.h>



using namespace std;

// CONSTANTS

const int no_of_places = 40;
const int PIECES = 8;
const int NO_OF_CARDS = 16;
const int NO_OF_HOUSES = 32;
const int NO_OF_HOTELS = 12;
const int MAX_PLAYERS = 8;
const int BLUE = 2, GREEN = 3, PINK = 3, ORANGE = 3, RED = 3, BROWN = 2, LIGHT_BLUE = 3, YELLOW = 3;
const int NO_OF_DICE = 2;

//VALUES IN CRORES
const float TRAIN_VALUE = 20.0;
const float SALARY = 20.0;
const float ELECTRIC_VALUE = 15.0;
const float WATER_VALUE = 15.0;
const float PROPERTY_VALUE = 0.6;
const float TAX = 1.0;
const float INITIAL_BALANCE = 15.0;
const float HOUSE_VALUE = 5.0;
const float HOTEL_VALUE = 5.0;

// DEFINING BLOCK
typedef struct
{
    string owner;
    string name;
    int special; // 1 for TRAIN, 2 for ELECTRIC, 3 for WATER, 4 for CHANCE, 5 for COMMUNITY CHEST, 6 for LUXURY TAX, 7 for GO, 8 for JAIL/NO JAIL, 9 for FREE PARKING, 10 for GO TO JAIL
    double value;
    double rent;
    int houses;
    int hotels;
    string color;
    float house_value;
    float hotel_value;
    bool developed;
} places;

places blocks[no_of_places];




//DEFINIG PLAYER
typedef struct
{
    string name;
    string piece;
    bool jail;
    double balance;
} player;
player players[MAX_PLAYERS];

//DEFINING PIECES
string CHARS[8] = {"1. SHOE", "2. CAR", "3. SHIP", "4. HAT", "5. DOG", "6. MIC", "7. CART", "8. CANNON"};




//DEFINING FUNCTIONS
void start_values();
void player_numbers(int &);
void player_name_inputs(int &);
int dice_roll();





int main()
{
    int no_of_players;
    player_numbers(no_of_players);
    start_values();
    player_name_inputs(no_of_players);

}

















//STARTS THE ENTIRE BOARD

void start_values()
{

    //ASSIGNING NAMES AND COLOR OF EACH BLOCK
    blocks[0].name = "GO";
    blocks[1].name = "SHAD BAGH";
    blocks[1].color = "BROWN";
    blocks[2].name = "COMMUNITY CHEST";
    blocks[3].name = "MISTRI SHAH";
    blocks[3].color = "BROWN";
    blocks[4].name = "TAX (INCOME)";
    blocks[5].name = "TRAIN STATION KOT LAKHPAT";
    blocks[6].name = "SAMNABAD";
    blocks[6].color = "LIGHT BLUE";
    blocks[7].name = "CHANCE";
    blocks[8].name = "MUGHALPURA";
    blocks[8].color = "LIGHT BLUE";
    blocks[9].name = "ICHRA";
    blocks[8].color = "LIGHT BLUE";
    blocks[10].name = "JAIL PLACE";
    blocks[11].name = "GULSHAN-E-RAVI";
    blocks[11].color = "PINK";
    blocks[12].name = "ELECTRIC COMPANY";
    blocks[13].name = "HARBANSPURA";
    blocks[13].color = "PINK";
    blocks[14].name = "SHADMAN";
    blocks[14].color = "PINK";
    blocks[15].name = "TRAIN STATION RAIWIND";
    blocks[16].name = "LDA AVENUE";
    blocks[16].color = "ORANGE";
    blocks[17].name = "COMMUNITY CHEST";
    blocks[18].name = "TOWNSHIP";
    blocks[18].color = "ORANGE";
    blocks[19].name = "GREEN TOWN";
    blocks[19].color = "ORANGE";
    blocks[20].name = "FREE PARKING";
    blocks[21].name = "FAISAL TOWN";
    blocks[21].color = "RED";
    blocks[22].name = "CHANCE";
    blocks[23].name = "ALLAMA IQBAL TOWN";
    blocks[23].color = "RED";
    blocks[24].name = "GARDEN TOWN";
    blocks[24].color = "RED";
    blocks[25].name = "TRAIN STATION CANTT";
    blocks[26].name = "JOHAR TOWN";
    blocks[26].color = "YELLOW";
    blocks[27].name = "LAKE CITY";
    blocks[27].color = "YELLOW";
    blocks[28].name = "WATER WORKS";
    blocks[29].name = "VALENCIA";
    blocks[29].color = "YELLOW";
    blocks[30].name = "GO TO JAIL";
    blocks[31].name = "MODEL TOWN";
    blocks[31].color = "GREEN";
    blocks[32].name = "WAPDA TOWN";
    blocks[32].color = "GREEN";
    blocks[33].name = "COMMUNITY CHEST";
    blocks[34].name = "EME";
    blocks[34].color = "GREEN";
    blocks[35].name = "TRAIN STATION JUNCTION";
    blocks[36].name = "CHANCE";
    blocks[37].name = "BAHRIA TOWN";
    blocks[37].color = "BLUE";
    blocks[38].name = "TAX (LUXURY)";
    blocks[39].name = "DHA";
    blocks[39].color = "BLUE";



    //ASSIGNING VALUE AND SPECIAL VALUE TO SPECIAL BLOCKS AND INITIALIZING OWNER TO NO ONE
    for (int i = 0; i < no_of_places; i++)
    {
        blocks[i].owner = "";
        int train = 0, property = 0, chance = 0, community = 0, tax = 0;

        if (blocks[i].name.substr(0, 5) == "TRAIN")
        {
            blocks[i].special = 1;
            blocks[i].value = (train + 1) * TRAIN_VALUE;
            train++;
        }
        else if (blocks[i].name.substr(0, 8) == "ELECTRIC")
        {
            blocks[i].special = 2;
            blocks[i].value = ELECTRIC_VALUE;
        }
        else if (blocks[i].name.substr(0, 5) == "WATER")
        {
            blocks[i].special = 3;
            blocks[i].value = WATER_VALUE;
        }
        else if (blocks[i].name == "CHANCE")
        {
            blocks[i].special = 4;
        }
        else if (blocks[i].name == "COMMUNITY CHEST")
        {
            blocks[i].special = 5;
        }
        else if (blocks[i].name.substr(0, 3) == "TAX")
        {
            blocks[i].special = 6;
            blocks[i].value = TAX * (tax + 1);
        }
        else
        {
            //Filling In Values For Areas
            if(blocks[i].color == "BROWN" || blocks[i].color == "LIGHT BLUE")
            {
                blocks[i].house_value = HOUSE_VALUE;
                blocks[i].hotel_value = HOTEL_VALUE;
            }
            else if(blocks[i].color == "PINK" || blocks[i].color == "ORANGE")
            {
                blocks[i].house_value = 2*HOUSE_VALUE;
                blocks[i].hotel_value = 2*HOTEL_VALUE;
            }
            else if(blocks[i].color == "YELLOW" || blocks[i].color == "RED")
            {
                blocks[i].house_value = 3*HOUSE_VALUE;
                blocks[i].hotel_value = 3*HOTEL_VALUE;
            }
            else if(blocks[i].color == "GREEN" || blocks[i].color == "BLUE")
            {
                blocks[i].house_value = 4*HOUSE_VALUE;
                blocks[i].hotel_value = 4*HOTEL_VALUE;
            }


            blocks[i].special = 0;
            blocks[i].value = (property + 1) * PROPERTY_VALUE;
            blocks[i].developed = false;
            property++;
        }
    }
}







//TAKING IN NO. OF PLAYERS FROM USER
void player_numbers(int &no_of_players)
{

    bool validInput = false;

    while (!validInput)
    {
        cout << "Enter number of players: ";
        if ((cin >> no_of_players && !cin.fail() ) && !(no_of_players < 1 || no_of_players > 8))
        {
            validInput = true; // Input is valid
        }
        else
        {
            cout << "Invalid input. Please enter values between 1 and 8." << endl;
            cin.clear();            // Clear error flags
            cin.ignore(1000, '\n');     
        }
    }
}


//TAKING INPUTS FROM USER FOR NAMES AND THEIR PIECES
void player_name_inputs(int & no_of_players)
{
    for (int i = 0; i < no_of_players; i++)
    {
        cout << "Player Number " << i + 1 << " Enter Your Name: ";
        cin >> players[i].name;
        players[i].jail = false;
        players[i].balance = INITIAL_BALANCE;

        cout << "Player Number " << i + 1 << " Select A Piece From Following: " << endl;
        for (int j = 0; j < 9; j++)
        {
            cout << CHARS[j] << endl;
        }
        int p;
        do
        {
            cout << "Enter The Number Of The Piece Of Your Choice: ";
            cin >> p;
        } while (p < 1 || p > 8 || CHARS[p - 1].substr(CHARS[p - 1].length() - 1, 1) == ")");


        CHARS[p - 1] += "(TAKEN)";

        players[i].piece = CHARS[p - 1];
    }
}

int dice_roll()
{
    srand(time(NULL));
    int dice = 0;
    for(int i = 0; i < NO_OF_DICE; i++)
    {
        dice += rand() % 6 + 1;
    }
    return dice;

}