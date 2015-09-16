//This is the main function.  It needs cleaning up but it works.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"global_structs_and_funcs.h"
#include"lincoln2.h"
#define NORTH 1
#define SOUTH 2
#define EAST 3
#define WEST 4

main()
{
printf("uytv\n");
    map_initialize();//links all the rooms together
    place_things();//puts items and monsters on the map
        char * user_in;
        int user_int;
    printf("Welcome, this prototype of Crowbar doesn't understand commands besides 'north', 'south', 'east', 'west', 'look' (in case you forget where you are) and 'print bag' to show you the contents of your backpack. You can't pick up objects or fight monsters because they don't technically exist.\n\nYou wake up, surprised to still be alive but you can't remember why.  You seem to be in a highschool computer lab. ");

 printf("%s\n\n>",(*character).long_message);
        (*character).visit = 1;

   while(1){//this is the general walking and moving loop.  Eventually it will be while death != 1 but for no it's just infinite.

        fgets(user_in,600,stdin);//Gets the user's command

if (strcmp(user_in, "look\n")==0)//prints the long_message of the current room I'll put this in it's ow function soon
        {
        user_in = "xerces";//xerces is just a random word so the walk function knows not to sass the player
        printf("%s\n\n", (*character).long_message);
        printf(">");

        }else if (strcmp(user_in, "print bag\n") == 0)//prints the contents of the backpack
        {
        printbag();//THIS FUNCTION NEEDS TO BE FIXED #1 ON MY LIST
        user_in = "xerces";
        printf(">");
        }else{
        user_in = user_in;}

if (strcmp(user_in, "xerces") != 0)//the walk function is skipped if user_in == xerces
{
        walk(convert(user_in));

        if ((*character).visit != 1){
        printf("%s\n\n>",(*character).long_message);
        (*character).visit = 1;
                }
        else{
                printf("%s\n\n>",(*character).message);

 	       }
}
}
}

