/* Biohazard functions
*
*  by Cheap_Suit
* 
*  This file is provided as is (no warranties).
*/

#if defined _biohazard_included
	#endinput
#endif
#define _biohazard_included

#pragma reqlib "biohazardf"

#define MAX_NAME 		MAX_NAME_LENGTH 				// 32
#define MAX_SAFE_NAME   MAX_NAME * 2					// 64
#define MAX_DESC        MAX_MENU_LENGTH 				// 512
#define MAX_IP 	 		MAX_IP_LENGTH 					// 16
#define MAX_IP_PORT		MAX_IP_WITH_PORT_LENGTH 		// 22
#define MAX_AUTHID 		MAX_AUTHID_LENGTH 				// 64
#define MAX_PATH		MAX_RESOURCE_PATH_LENGTH * 2	// 128
#define MAX_MOTD 		MAX_MOTD_LENGTH 				// 1536
#define MAX_USER_INFO 	MAX_USER_INFO_LENGTH 			// 256
#define MAX_MENU 		MAX_MENU_LENGTH 				// 512
#define MAX_MESSAGE 	192

#if !defined ForPlayers
	#define ForPlayers(%1) for(new %1 = 1; %1 <= MAX_PLAYERS; %1++)
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

#if !defined ForLower
	#define ForLower(%1,%2) for(new %1 = 1; <= %2; %1++)
#endif

/* Returns the mods status */
stock is_biomod_active()
{
	if(!cvar_exists("bh_enabled"))
	{
		log_amx("Cvar: ^"bh_enabled^" does not exist.")
		return 0
	}
	return get_cvar_num("bh_enabled")
}

stock const menu_title[]  = "\dZOMBIE — Zakladkarny.org\w^n\y[ZOMBIE]\w";
stock const menu_prefix[] = "\d»\w";
stock const chat_prefix[] = "&x07[AMXX4U.pl | ZM]&x01";

stock register_commands(const array[][], array_size, function[], flags = -1)
{
	ForRange(i, 0, array_size - 1)
	{
		ForRange(j, 0, 1)
			register_clcmd(fmt("%s %s", !j ? "say" : "say_team", array[i]), function, flags);

	}
}

native get_human_points(index);
native add_human_points(index, vaule);
native set_human_points(index, vaule);

native get_zombie_points(index);
native add_zombie_points(index, vaule);
native set_zombie_points(index, vaule);

native bio_give_napalm(index);
native bio_give_frost(index);
native bio_give_mine(index);
native bio_give_infect(index);

/* Called when a survivor is infected */
forward event_infect(victim, attacker)

/* Called when a zombie is cure */
forward event_cure(id)

/* Called when the game starts */
forward event_gamestart()

/* Returns true if the game has started */
native bool:game_started()

/* Makes a user zombie */
native infect_user(victim, attacker)

/* Makes a user human */
native cure_user(index)

/* Infect user before game starts */
native preinfect_user(index, bool:yesno)

/* Returns 1 if user is a zombie */
native is_user_zombie(index)

/* Returns 1 if the user is infected (before game)*/
native is_user_infected(index)

/* Returns user zombie class */
native get_user_class(index)

/* Returns zombie class id, -1 otherwise */
native register_class(classname[], description[])

/* Sets zombie player model */
native set_class_pmodel(classid, player_model[])

/* Sets zombie weapon model */
native set_class_wmodel(classid, weapon_model[])

/* Returns zombie class id */
native get_class_id(classname[])

#define DATA_HEALTH      0  //Health value
#define DATA_SPEED       1  //Speed value
#define DATA_GRAVITY     2  //Gravity multiplier
#define DATA_ATTACK      3  //Zombie damage multiplier
#define DATA_DEFENCE     4  //Bullet damage multiplier
#define DATA_HEDEFENCE   5  //HE damage multiplier
#define DATA_HITSPEED    6  //Pain speed multiplier
#define DATA_HITDELAY    7  //Pain speed delay value
#define DATA_REGENDLY    8  //Regeneration delay value
#define DATA_HITREGENDLY 9  //Pain regeneration delay value
#define DATA_KNOCKBACK   10 //Knockback multiplier

/* Return/set value of zombie class data */
native Float:get_class_data(classid, dataid)
native set_class_data(classid, dataid, Float:value)

//moje natywy i forwardy
native bio_get_zombie_count()
native bio_get_human_count()
native can_get_weapons(id)
native choose_zombie_class(id)