// M6LAB2
// CSC 134
// Janiya Barrett
// 4/20/26

// ============================================================================
//  M6LAB2: Luigi's Mansion — Adjacency List Edition
//  CSC 134 — Module 6: Arrays
// ============================================================================
//
//  THE BIG IDEA
//  ------------
//  Our mansion has 6 rooms. Rooms connect to neighbors via N / E / S / W.
//  We need a way to answer: "If Luigi is in the Foyer and moves north, where 
//  does he end up?"
//
//  The answer: an ADJACENCY LIST stored as a 2D array.
//      connections[fromRoom][direction] = destination room
//
//  We ALSO use PARALLEL ARRAYS to hold each room's name and description —
//  the same index in every array points to the same room.
//
//
//  THE MANSION MAP
//  ---------------
//                         [ BALCONY ]
//                              |
//                              N (leads south to Ballroom)
//                              |
//                         [ BALLROOM ]
//                              |
//                              N (leads south to Foyer)
//                              |
//      [ GALLERY ] --E-- [   FOYER    ] --E-- [ PARLOR ]
//                                                |
//                                                N (leads south to Parlor)
//                                                |
//                                           [ KITCHEN ]
//
//  Start: FOYER. Explore with n / e / s / w. Type 'look' or 'quit'.
//
//
//  FUTURE REFACTOR NOTE
//  --------------------
//  Once we learn structs, rooms become a single struct with fields for
//  name, description, and exits. For now, parallel arrays keep everything
//  out in the open where we can see it.
// ============================================================================

#include <iostream>
#include <string>
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
        "Candles flicker on a grand piano that seems to be playing itself.",
        "Flying pots clatter in the air. The fridge is vibrating aggressively.",
        "A massive floor where ghost-couples spin in circles.",
        "Paintings of Boos line the walls. You feel watched.",
        "The cold night air bites. You can see the dark forest from here."
    };

    // ----- The adjacency table (a 2D array) -----
    int connections[NUM_ROOMS][NUM_DIRECTIONS];

    // Step 1: Initialize with NO_CONNECTION.
    for (int r = 0; r < NUM_ROOMS; r++)
    {
        for (int d = 0; d < NUM_DIRECTIONS; d++)
        {
            connections[r][d] = NO_CONNECTION;
        }
    }

    // Step 2: Wire up the mansion based on the ASCII map above.
    
    // FOYER connections
    connections[FOYER][NORTH] = BALLROOM;
    connections[FOYER][EAST]  = PARLOR;
    connections[FOYER][WEST]  = GALLERY;

    // BALLROOM and BALCONY (The North Wing)
    connections[BALLROOM][SOUTH] = FOYER;
    connections[BALLROOM][NORTH] = BALCONY;
    connections[BALCONY][SOUTH]  = BALLROOM;

    // PARLOR and KITCHEN (The East Wing)
    connections[PARLOR][WEST]  = FOYER;
    connections[PARLOR][NORTH] = KITCHEN;
    connections[KITCHEN][SOUTH] = PARLOR;

    // GALLERY (The West Wing)
    connections[GALLERY][EAST] = FOYER;

    // ----- Game state -----
    int  currentRoom = FOYER;
    bool running = true;

    cout << "========================================" << endl;
    cout << "   LUIGI'S MANSION: TEXT ADVENTURE" << endl;
    cout << "========================================" << endl;
    cout << "Commands: north, south, east, west, look, quit" << endl;

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
        if (command == "look" || command == "l")
        {
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
            cout << "The door is locked by a mysterious spectral force." << endl;
        }
        else
        {
            currentRoom = next;
        }
    }

    cout << "\nYou've escaped the mansion! For now..." << endl;
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