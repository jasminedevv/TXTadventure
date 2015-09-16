//These are all our struct declarations for the top floor of lincoln.  I haven’t gotten around to the other floors yet
#define NORTH 1
#define SOUTH 2
#define EAST 3
#define WEST 4

place _cs_room={
                {"To the east there is a window and to the west there is a closed door, presumably locked. Four rows of computers arranged east to west give off a subtle hum while a loud linux server whizzes away in the corner."},//The first message only shows the first time you walk into a room, the second message shows every turn.
                {"There is a door to the west."}
                };
place _top_main_hall={
                {"You find yourself in a hallway, lockers on both sides. Something on the east wall sounds like an old refrigerator which, along with the dull yellow lights, gives you goosebumps.  You can go north or south down the hall, west back to the computer science room or east to an open door with 'LIBRARY' over the entrance."},
                {"The old refrigerator sound echoes down the hall."}
                };
place _library1={
                {"This is the school library. Tables extend down the north length of the room, at the end of which is three rows of books.  To the south are three rounds of computers in island-like formations. All along the west wall is a large window though which you can see a football field."},
                {"Books sit on every wall."}
                };


place _library2={
                {"After stepping around chairs and tables, you make it to the back of the library.  There are four fancier computers here in an island formation. Books are stacked high onto shelves around you. The only way out is back where you came."},
                {"You can go back south."}
                };
place _sophomore1={
                {"You reach a fork in the hall.  To the west is a stairwell going down, to the east is a hallway littered with green paper and a window at the end."},
                {"You can go east or west down a stairwell."}
                };
place _sophomore2={
                {"As you walk down the rows of lockers, you see a bathroom labelled girls to the north and a stairwell going down to the south. The hall continues to the east."},
                {"There are lockers along the walls."}
                };
place _sophomore3={
                {"You see empty science classerooms on either side of you.  You know they are science classrooms because they have labels above the doors. The only unlocked one is a biology class on the south side of the hall. To the north there is a stairwell going down."},
                {"There are lockers along the wall."}
                };
place _bench_square={
                {"You find yourself in a small, pleasant square at the end of the hall with large windows through which you can see trees and an empty city street.  To the east there is an elevator with barred doors."},
                {"This is a pleasant little space with benches."}
                };
place _freshman1={
                {"You reach a fork in the hall.  To the west is a stairwell going down, to the east is a hallway that has been thoroughly TP-ed with cheap, double sided toilet paper. to the north is an other stairwell, also going down. You can go east up the hall, north down a stairwell or west down a stairwell."},
                {"This hallway has been TPed."}
                };
place _freshman2={
                {"As you walk down the rows of lockers, you see a bathroom labelled girls to the south and an inviting room that reminds you slightly of a hobbit hole. The hall continues to the east and west."},
                {"There are lockers along the walls."}
                };
place _freshman3={
                {"You come to the end of the toilet paper strewn hallway. You see a sad-looking statue of Abraham Lincoln made of some kind of yellowing white material.  Like bad teeth.  There is an open French class to the north and a stairwell to the south going down."},
                {"There is a statue here."}
                };
place _french={
    {"You see a variety of poorly designed posters plastered around the room with messages like 'Mon aeroglisseur est plein d'anguile' and 'Le gateau est un mensonge'. The board is blocked off by a wide wooden desk littered with papers, wires and a collection of toy eiffel towers."},
    {"This is a French classroom"}
};
place _bathroom_freshman={
    {"You walk into an ok smelling bathroom with red doors on the stalls.  Half of them have 'Does not lock' written in black sharpie across the top. One of the sinks seems to drip a blue liquid but on closer inspection you realise that it is a stain, possibly caused by some kind of chemical in the water."},
    {"This is an ok smelling bathroom."}
};
place _bathroom_sophomore={
    {"The first thing you notice about this bathroom is the rather confounding mirror above the sinks. It's confounding because you can't imagine why anyone would ever put a mirror there unless they were extremely tall ad liked to look at the top of their head."},
        {"This is an ok smelling bathroom."}
};
place _german={
    {"This room is surprisingly inviting for a classroom in a public school. It makes you think of a hobbit hole.  There are posters depicting places in what appears to be Europe.  Calligraphy materials are strewn across the desks, which are set up in a U formation and three rows."},
    {"This is the german room."}
};
place _biology={
    {"This is a long classroom.  The desks extend all the way to the back, facing towards a tall, wide desk that separates them from the white board.  On this desk is a large model of a DNA double helix."},
    {"This is a biology classroom."}
};

//I tried to find a way around this but I ended up accepting my fate and making pointers to all the place structs
place * cs_room = &_cs_room;
place * top_main_hall = &_top_main_hall;
place * library1 = &_library1;
place * library2 = &_library2;
place * sophomore1 = &_sophomore1;
place * sophomore2 = &_sophomore2;
place * sophomore3 = &_sophomore3;
place * bench_square = &_bench_square;
place * freshman1 = &_freshman1;
place * freshman2 = &_freshman2;
place * freshman3 = &_freshman3;
place * french = &_french;
place * bathroom_freshman = &_bathroom_freshman;
place * bathroom_sophomore = &_bathroom_sophomore;
place * german = &_german;
place * biology = &_biology;


item _blue_tape={
                {"tape"},
                {"hit"},
                {"There is a roll of blue tape on the teacher's desk"},
                1};
item _crowbar={
                {"crowbar"},
                {"hit"},
                {"If you get this message you sort of hacked the game. Good job."},
                5};
//Same thing as the rooms
item * blue_tape = &_blue_tape;
item * crowbar = &_crowbar;

place_things()
        {
        _cs_room.items[0] = &_crowbar;
        pickup(search_item_placetype("crowbar"));
        _cs_room.items[1]= &_blue_tape;
	return 1;
}

map_initialize()//initialises the map
{
        insert(cs_room, cs_room, NORTH);
        insert(top_main_hall, cs_room, WEST);
        insert(sophomore1, top_main_hall, SOUTH);
        insert(sophomore2, sophomore1, EAST);
        insert(sophomore3, sophomore2, EAST);
        insert(bench_square, sophomore3, EAST);
        insert(freshman1, top_main_hall, NORTH);
        insert(freshman2, freshman1, EAST);
        insert(freshman3, freshman2, EAST);
        insert(french, freshman3, NORTH);
        insert(german, freshman2, NORTH);
        insert(bathroom_sophomore, freshman2, SOUTH);
        insert(library1, top_main_hall, WEST);
        insert(library2, library1, SOUTH);
        insert(bathroom_sophomore, sophomore2, NORTH);
        insert(biology, sophomore3, SOUTH);
}

