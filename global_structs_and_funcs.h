//This is the version of global_structs_and_functs.h that Jasmine has been editing. It does not include the parser but everything works.
#define NORTH 1
#define SOUTH 2
#define EAST 3
#define WEST 4

int death = 0;

struct entity{
        char name[15];
        char attack_message[200];
        char winning_message[200];
        char win_message[200];
        char lose_message[200];
        char losing_message[200];
        int health;
        int attack;
}; //monsters!!
    typedef struct entity monster;

struct item{//Weapons and such
        char name[15];
        char adjective[100];
        char message[600];
        int damage;
};
    typedef struct item item;

struct place{
        char long_message[800];
        char message[50];
        int visit;
         struct place *north;
         struct place *south;
         struct place *east;
        struct place *west;
        item * items[10];

                }; //makes a struct room
        typedef struct place place;//sorry about that, it works.

       place *head; //this one's just for initializing the map, like a linked list

        place *character;//THIS IS THE MOST IMPORTANT POINTER WE HAVE

struct person{//contains all the character stats
        int health;//When it gets to zero you die
        char * name;//may or may not use this, the idea was to ask for the player’s name
        item * backpack [10];//The things you carry
        item * righthand;//may or may not use these
        item * lefthand;
};
typedef struct person person;//XD

person player;

insert(place *newitem, place *fromitem, char direct){  //the insert function that inserts rooms into the map

        place * walker;

        if(head == NULL){  //case 1; the map is empty
                head = newitem;
                character = newitem;
                head = fromitem;
        }else if(direct == 1){  //case 2; you want to put newitem to the north of fromitem
                newitem->south = fromitem;
                fromitem->north = newitem;

        }else if(direct == 2){ // case 3; you new place to the south of head
                newitem->north = fromitem;
                fromitem->south = newitem;

        }else if(direct == 3){  //case 2; you want to put newitem to the east of head
                newitem->west = fromitem;
                fromitem->east = newitem;

        }else if(direct == 4){  //case 2; you want to put newitem to the west of head
                newitem->east = fromitem;
                fromitem->west = newitem;

        }else{
        printf("soooo userin wasn't equal to 1, 2, 3, 4 or NULL");
        }
return 1;
}


walk(int direction)//moves the character pointer from one room to the next
{
    switch(direction)
    {
        case NORTH:
            if (character->north != NULL){
            character = character->north;
            printf("walked north\n");
            }
            else{
                printf("You can't walk that way\n");
            };
            break;
        case SOUTH:
            if (character->south != NULL){
            character = character->south;
            printf("walked south\n");
            }
            else{
                printf("You can't walk that way\n");
            };
            break;
        case EAST:
            if (character->east != NULL){
            character = character->east;
            printf("walked east\n");
            }
            else{
                printf("You can't walk that way\n");
            };
            break;
        case WEST:
            if (character->west != NULL){
            character = character->west;
            printf("walked west\n");
            }
            else{
                printf("You can't walk that way\n");
            };
            break;
        }
}


char sarcasm[20][100] = {"Could you repeat that?",
                        "Hahahahah... I don't get it.",
                        "Well, this is awkward.",
                        "I think we're breaking up... how's the connection on your side?",
                        "I really don't understand you.",
                        "The queen's english, please.",
                        "Are you getting static, too?",
                        "Verb, object.  That's how you do it.",
                        "Um.",
                        "Try again.",
                        "Could you repeat that?",
                        "I'm sorry I no speak your country language!",
                        "Pardon?",
                        "Excuse me?",
                        "Come again?",
                        "I simply can't catch what you're saying.",
                        "Would you mind saying that again?",
                        "I'm afraid that's as clear as mud to me.",
                        "Say whaaaaaat?",
                        "English.",
                };
sass(){// this is the function that tells the user they aren't being coherent
        srand(time(NULL));
        int well = (rand() % 19);
        printf("%s\n", sarcasm[well]);
                }


convert(char * command)//converts the user's command into an int that the walk, pickup, drop, fight etc functions can understand if it is passed a word it doesn't understand it sasses the player which was really annoying when I was debugging it
        {

if (strcmp(command, "north\n")==0)
        {return NORTH;}

else if (strcmp(command, "south\n")==0)
        {return SOUTH;}

else if (strcmp(command, "east\n")==0)
        {return EAST;}

else if (strcmp(command, "west\n")==0)
        {return WEST;}
else
        {
        sass();
        return 42;
}
}

item * search_item_placetype(char * name){ //searches the bag for an item based on the name it is passed
        int walk;
        for(walk=0; walk<10 ;walk++){
        if(strcmp(character->items[walk]->name, name)==0){
                return character->items[walk];
        }
}
printf("That item isn't in the room!");
}
printbagpointers(){
        int walk;
        for(walk = 0; walk<10; walk++){
                printf("%p\n", player.backpack[walk]);
return 0;
}
}
printbag(){//prints the contents of the backpack
        int walk;
        for(walk = 0; walk<10; walk++){
                if(player.backpack[walk] != NULL){
                printf("%s\n", player.backpack[walk]->name);
return 0;
}
}
}
int search_inv_null(){//searches the inventory for NULLs
        int walk;
        for(walk=0; walk<10; walk++){
                if(player.backpack[walk] == NULL){
                        return walk;
                        break;
                        }
                }
                return -1;
                }

int pickup(item * thing){//puts an object it is passed in the backpack
        int walk;
        if(search_inv_null() == -1){
                printf("Pack is full.\n");
        }
        else{
        for(walk=0; walk<10; walk++){
                if(player.backpack[walk] == NULL){
                                player.backpack[walk] = thing;
                                return walk;
                                break;
                        }
                }
        }
}
int drop(item * thing){ //drops an item it is passed from the backpack
        int walk;
        for(walk=0; walk<10; walk++){
                if(player.backpack[walk] == thing){
                        player.backpack[walk]= NULL;
                        return walk;
                        break;
        }
    }
}

