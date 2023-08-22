#if defined _map_manager_included
  #endinput
#endif
#define _map_manager_included

#define NAME 	"Map Manager"
#define VER		"1.0"
#define AUTHOR 	"neygomon & dredek"

#if !defined ForPlayers
	#define ForPlayers(%1) for(new %1 = 1; %1 <= 32; %1++)
#endif

#if !defined ForArray
	#define ForArray(%1,%2) for(new %1 = 0; %1 < sizeof %2; %1++)
#endif

#if !defined ForDynamicArray
	#define ForDynamicArray(%1,%2) for(new %1 = 0; %1 < ArraySize(%2); %1++)
#endif

#if !defined ForRange
	#define ForRange(%1,%2,%3) for(new %1 = %2; %1 <= %3; %1++)
#endif

#if !defined ForFile
	#define ForFile(%1,%2,%3) for(new %1 = 0; read_file(%2, %1, %3, charsmax(%3)); %1++)
#endif

#if !defined _name
	#define _name(%1) fmt("%n", %1)
#endif

#define IsMapValidOnPlayers(%0,%1) (map_player_data[%0][1] <= %1 <= map_player_data[%0][2])

stock register_commands(const array[][], array_size, function[], flags = -1)
{
	ForRange(i, 0, array_size - 1)
	{
		ForRange(j, 0, 1)
		{
			register_clcmd(fmt("%s %s", !j ? "say" : "say_team", array[i]), function, flags);
		}
	}
}