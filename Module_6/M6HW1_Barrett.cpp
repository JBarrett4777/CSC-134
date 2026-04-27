// M6HW1 - Gold
// CSC 134
// Janiya Barrett
// 4/27/26

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------
//  Named constants (enums). 
// ---------------------------------------------------------------------------
enum Direction {
    NORTH = 0,
    EAST  = 1,
    SOUTH = 2,
    WEST  = 3,
    NUM_DIRECTIONS = 4
};

enum Room {
    FOYER = 0,
    PARLOR = 1,
    KITCHEN = 2,
    BALLROOM = 3,
    GALLERY = 4,
    BALCONY = 5,
    NUM_ROOMS = 6
};

const int NO_CONNECTION = -1;

// ---------------------------------------------------------------------------
//  Function prototypes
// ---------------------------------------------------------------------------
void printRoom(const string names[], const string descriptions[], int room);
void printExits(int connections[][NUM_DIRECTIONS], int room);
int  commandToDirection(const string& command);

// ===========================================================================
//  main — sets up the mansion and runs the game loop.
// ===========================================================================
int main()
{
    // ----- Parallel arrays: both indexed by Room -----
    string roomNames[NUM_ROOMS] = {
        "Dusty Foyer",
        "The Parlor",
        "Gloomy Kitchen",
        "Grand Ballroom",
        "Art Gallery",
        "Moonlit Balcony"
    };

    string roomDescriptions[NUM_ROOMS] = {
        "The main entrance. A Poltergust 3000 leans against a cobwebbed statue.",
        "Candles flicker on a grand piano. There is a note on the keys.",
        "Flying pots clatter. A shiny Silver Key sits inside the vibrating fridge.",
        "A massive floor where ghost-couples spin. The exit to the balcony is here.",
        "Paintings of Boos line the walls. Professor E. Gadd is standing here!",
        "The cold night air bites. You've made it to the roof!"
    };

    // ----- The adjacency table (a 2D array) -----
    int connections[NUM_ROOMS][NUM_DIRECTIONS];

    for (int r = 0; r < NUM_ROOMS; r++)
    {
        for (int d = 0; d < NUM_DIRECTIONS; d++)
        {
            connections[r][d] = NO_CONNECTION;
        }
    }

    // Wiring up the mansion
    connections[FOYER][NORTH] = BALLROOM;
    connections[FOYER][EAST]  = PARLOR;
    connections[FOYER][WEST]  = GALLERY;

    connections[BALLROOM][SOUTH] = FOYER;
    connections[BALLROOM][NORTH] = BALCONY; // GOLD: This is for the locked door
    connections[BALCONY][SOUTH]  = BALLROOM;

    connections[PARLOR][WEST]  = FOYER;
    connections[PARLOR][NORTH] = KITCHEN;
    connections[KITCHEN][SOUTH] = PARLOR;

    connections[GALLERY][EAST] = FOYER;

    // ----- Game state -----
    int  currentRoom = FOYER;
    bool running = true;
    bool hasKey = false;        // lock & key
    bool hasVacuum = false;     // 

    cout << "========================================" << endl;
    cout << "    LUIGI'S MANSION: TEXT ADVENTURE" << endl;
    cout << "========================================" << endl;
    cout << "Commands: north, south, east, west, take, talk, quit" << endl;

    // ----- Game loop -----
    while (running)
    {
        printRoom(roomNames, roomDescriptions, currentRoom);
        printExits(connections, currentRoom);

        cout << "\n> ";
        string command;
        cin >> command;

        if (command == "quit" || command == "q")
        {
            running = false;
            continue;
        }

        // picking up items 
        if (command == "take" || command == "get")
        {
            if (currentRoom == FOYER && !hasVacuum) {
                cout << "You picked up the Poltergust 3000! Now you can face the ghosts." << endl;
                hasVacuum = true;
            }
            else if (currentRoom == KITCHEN && !hasKey) {
                cout << "You braved the vibrating fridge and grabbed the Silver Key!" << endl;
                hasKey = true;
            }
            else {
                cout << "There's nothing here to take." << endl;
            }
            continue;
        }

        // dialog (explaining the point of the game)
        if (command == "talk" || command == "read")
        {
            if (currentRoom == GALLERY) {
                cout << "E. Gadd: 'Luigi! You must find the Silver Key in the kitchen to reach the balcony and save Mario!'" << endl;
            }
            else if (currentRoom == PARLOR) {
                cout << "The note reads: 'The master of the house hides his keys where the food is cold.'" << endl;
            }
            else {
                cout << "There is no one to talk to here." << endl;
            }
            continue;
        }

        int direction = commandToDirection(command);
        if (direction == -1)
        {
            cout << "M-M-Mario? (I don't know that command!)" << endl;
            continue;
        }

        int next = connections[currentRoom][direction];
        
        if (next == NO_CONNECTION)
        {
            cout << "You bump into a wall. Ouch!" << endl;
        }
        // GOLD: Lock and Key situation
        else if (currentRoom == BALLROOM && direction == NORTH && !hasKey)
        {
            cout << "The door to the Balcony is locked tight! You need a key." << endl;
        }
        else
        {
            currentRoom = next;
            
            // GOLD: Ending
            if (currentRoom == BALCONY) {
                printRoom(roomNames, roomDescriptions, currentRoom);
                cout << "\n========================================" << endl;
                cout << "YOU WIN! You used the key to reach the balcony and escaped!" << endl;
                cout << "========================================" << endl;
                running = false;
            }
        }
    }

    return 0;
}

// ===========================================================================
//  Function definitions
// ===========================================================================

void printRoom(const string names[], const string descriptions[], int room)
{
    cout << "\n[ " << names[room] << " ]" << endl;
    cout << descriptions[room] << endl;
}

void printExits(int connections[][NUM_DIRECTIONS], int room)
{
    const string dirNames[NUM_DIRECTIONS] = { "north", "east", "south", "west" };

    cout << "Exits: ";
    bool any = false;
    for (int d = 0; d < NUM_DIRECTIONS; d++)
    {
        if (connections[room][d] != NO_CONNECTION)
        {
            if (any) cout << ", ";
            cout << dirNames[d];
            any = true;
        }
    }
    if (!any) cout << "(none)";
    cout << endl;
}

int commandToDirection(const string& command)
{
    if (command == "north" || command == "n") return NORTH;
    if (command == "east"  || command == "e") return EAST;
    if (command == "south" || command == "s") return SOUTH;
    if (command == "west"  || command == "w") return WEST;
    return -1;
}