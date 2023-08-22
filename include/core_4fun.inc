#if defined _core_4funo_included
	#endinput
#endif

#define _core_4fun_included
#include <amxmodx>
#include <amxmisc>
#include <cstrike>
#include <hamsandwich>
#include <reapi>
#include <fun>

#pragma semicolon 1

#if !defined isPlayer
	#define isPlayer(%1) ((1 <= %1 && %1 <= MAX_PLAYERS))
#endif

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

#if !defined _name
	#define _name(%1) fmt("%n", %1)
#endif

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

#define	HUD_HIDE_TIMER (1<<4)

#define OFFSET_LINUX_WEAPONS 4
#define OFFSET_LINUX_PLAYER 5
#define OFFSET_NEXT 42
#define OFFSET_ID 43
#define OFFSET_PRIMARY_ATTACK 46
#define OFFSET_SECONDARY_ATTACK 47
#define OFFSET_LASTHITGROUP 75
#define OFFSET_BUYZONE 235
#define OFFSET_ITEM_SLOT 367
#define OFFSET_ACTIVE_ITEM 373

#define CSW_SHIELD	2

#define NONE -1

/*#define LOG_ACTIVE // LOG DISCORD */

enum { Primary = 1, Secondary, Knife, Grenades, C4};

stock const VERSION[] 		= "1.1";
stock const AUTHOR[] 		= "KoRrNiK & Paweł";
stock const URL_AUTHOR[] 	= "https://cs-luzownia.pl/";

stock const menu_title[] 	= "\d© ONLYDD2 - 1s2k.pl^n\r[DD2]\w";
stock const menu_prefix[] 	= "\d›\w";

stock const CONFIG_PATH[] 	= "addons_configs/4fun";

enum _:VIP_TYPE {
	VIP_NONE = 0,  
	VIP_EVO, 
	VIP_GOD,
	VIP_GOD_FREE
}

enum {
	PREFIX_NORMAL,
	PREFIX_LINE,
	PREFIX_NONE,
}

enum (<<= 1) {B1 = 1, B2, B3, B4, B5, B6, B7, B8, B9, B0};

/**
	 * Multiforward called on start game round.
	 *
	 * @noreturn
**/
forward core_start_round();

/**
	 * Multiforward called on end game round.
	 *
	 * @noreturn
**/
forward core_end_round();

/**
	 * Multiforward called on reset game round.
	 *
	 * @noreturn
**/
forward core_reset_round();

/**
	 * Multiforward called on player spawn.
	 *
	 * @param victim        	Victim ID 
	 * @param attacker	    	Attacker ID
	 *
	 * @noreturn
**/
forward core_killed(victim, attacker);

/**
	 * Multiforward called on takedamage player.
	 *
	 * @param victim        	Victim ID 
	 * @param attacker	    	Attacker ID
	 * @param damage	    	Amount of damage to deal
	 * @param inflictor	    	Inflictor
	 *
	 * @noreturn
**/
forward core_takedamage(victim, attacker, Float:damage, inflictor);

/**
	 * Multiforward called on bomb defused.
	 * @param id        	Player id 
	 *
	 * @noreturn
**/
forward core_bomb_defused(id);

/**
	 * Multiforward called on bomb planted.
	 * @param id        	Player id 
	 *
	 * @noreturn
**/
forward core_bomb_planted(id);

/**
	 * Multiforward called on bomb defusing.
	 * @param id        	Player id 
	 *
	 * @noreturn
**/
forward core_bomb_defusing(id);

/**
	 * Multiforward called on bomb planting.
	 * @param id        	Player id 
	 *
	 * @noreturn
**/
forward core_bomb_planting(id);

/**
	 * Multiforward called on win tt.
	 *
	 * @noreturn
**/
forward core_win_tt();

/**
	 * Multiforward called on win ct.
	 *
	 * @noreturn
**/
forward core_win_ct();

/**
	 * Multiforward called on change speed.
	 * @param id        	Player id 
	 *
	 * @noreturn
**/
forward core_speed_change(id);

/**
	 * Multiforward called on current weapon.
	 * @param id        	Player id 
	 * @param weapon        Player weapon 
	 *
	 * @noreturn
**/
forward core_current_weapon(id, weapon);

/**
	 * Multiforward called on spawn player.
	 * @param id        	Player id 
	 *
	 * @noreturn
**/
forward core_player_spawn(id);

/**
	 * Multiforward called on end map
	 *
	 * @noreturn
**/
forward core_end_map();

/**
	* Get player data id from core 4fun
	*
	* @param id 	Player index
	*
	* @return		Player id
**/
native core_get_data_id(id);

/**
	* Get player data points from core 4fun
	*
	* @param id 	Player index
	*
	* @return		Player points
**/
native core_get_data_points(id);

/**
	* Get player data kills from core 4fun
	*
	* @param id 	Player index
	*
	* @return		Player kills
**/
native core_get_data_kills(id);

/**
	* Get player data killshs from core 4fun
	*
	* @param id 	Player index
	*
	* @return		Player killshs
**/
native core_get_data_killshs(id);

/**
	* Get player data deaths from core 4fun
	*
	* @param id 	Player index
	*
	* @return		Player deaths
**/
native core_get_data_deaths(id);

/**
	* Add player data points from core 4fun
	*
	* @param id 	Player index
	* @param val	Value Added
	*
	* @return		Player points
**/
native core_add_data_points(id, val);

/**
	* Add player data kills from core 4fun
	*
	* @param id 	Player index
	* @param val	Value Added
	*
	* @noreturn
**/
native core_add_data_kills(id, val);

/**
	* Add player data killshs from core 4fun
	*
	* @param id 	Player index
	* @param val	Value Added
	*
	* @noreturn
**/
native core_add_data_killshs(id, val);

/**
	* Add player data deaths from core 4fun
	*
	* @param id 	Player index
	* @param val	Value Added
	*
	* @noreturn
**/
native core_add_data_deaths(id, val);

/**
	* Get player addon points from addon mvp
	*
	* @param id 	Player index
	*
	* @return		Player points
**/
native addon_get_mvp_points(id);

/**
	* Get player addon kills from addon mvp
	*
	* @param id 	Player index
	*
	* @return		Player kills
**/
native addon_get_mvp_kills(id);

/**
	* Add player addon points from addon mvp
	*
	* @param id 	Player index
	* @param val	Value Added
	*
	* @noreturn
**/
native addon_add_mvp_points(id, val);

/**
	* Add player addon kills from addon mvp
	*
	* @param id 	Player index
	* @param val	Value Added
	*
	* @noreturn
**/
native addon_add_mvp_kills(id, val);

/**
	* Set player core speed from core 4fun
	*
	* @param id 	Player index
	* @param spee	Value Set
	*
	* @noreturn
**/
native core_set_data_speed(id, Float:speed);

/**
	* Get player core speed from core 4fun
	*
	* @param id 	Player index
	*
	* @return		Player speeed
**/
native core_get_data_speed(id);

/**
	* Get player core max health from core 4fun
	*
	* @param id 	Player index
	*
	* @return		Player max health
**/
native core_get_data_max_health(id);

/**
	* Get player addon rank name ( string ) from addon rank
	*
	* @param id 	Player index
	* @param data[] 
	* @param len
	*
	* @return		Player rank name
**/
native addon_get_rank_name(id, data[], len);

/**
	* Get player addon rank progress ( string [%d/%d] ) from addon rank
	*
	* @param id 	Player index
	* @param data[] 
	* @param len
	*
	* @return		Player rank progress
**/
native addon_get_rank_progress(id, data[], len);

/**
	* Get player addon money from addon money
	*
	* @param id 	Player index
	*
	* @return		Player speeed
**/
native addon_get_money(id);

native set_points(id, Float:amount);
native Float:get_points(id);

/**
	* Add player addon money from addon money
	*
	* @param id 	Player index
	* @param val	Value Added
	*
	* @noreturn
**/
native addon_add_money(id, val);

/**
	* Set player addon money from addon money
	*
	* @param id 	Player index
	* @param val	Value Set
	*
	* @noreturn
**/
native addon_set_money(id, val);

/**
	* Get player addon money bank from addon money
	*
	* @param id 	Player index
	*
	* @return		Player speeed
**/
native addon_get_money_bank(id);

/**
	* Add player addon money bank from addon money
	*
	* @param id 	Player index
	* @param val	Value Added
	*
	* @noreturn
**/
native addon_add_money_bank(id, val);

/**
	* Set player addon money bank from addon money
	*
	* @param id 	Player index
	* @param val	Value Set
	*
	* @noreturn
**/
native addon_set_money_bank(id, val);

/**
	* Get player addon password bank ( string ) from addon money
	*
	* @param id 	Player index
	* @param data[] 
	* @param len
	*
	* @return		Player rank name
**/
native addon_get_password_bank(id, data[], len);

/**
	* Get player addon vip status from vip
	*
	* @param id 	Player index
	*
	* @return		Player speeed
**/
native addon_get_vip(id);

/**
	* Get player data level vip from addon vip
	*
	* @param id 	Player index
	*
	* @noreturn
**/
native addon_get_vip_level(id);

/**
	* Set player data level vip from addon vip
	*
	* @param id 	Player index
	* @param val 	Value Set
	*
	* @noreturn
**/
native addon_set_vip_level(id, val);

/**
	* Add player data level vip from addon vip
	*
	* @param id 	Player index
	* @param val 	Value Add
	*
	* @noreturn
**/
native addon_add_vip_level(id, val);

stock load_database()
{
	new sql_config[MAX_PATH];
	new DATABASE_CONFIG[] = "database/database.cfg";
	get_localinfo("amxx_configsdir", sql_config, charsmax(sql_config));

	new path[128];
	formatex(path, charsmax(path), "%s/%s/%s", sql_config, CONFIG_PATH, DATABASE_CONFIG);

	if(!file_exists(path))
		set_fail_state(fmt("=== Nie znaleziono pliku: %s ===", path));

	server_cmd("exec %s/%s/%s", sql_config, CONFIG_PATH, DATABASE_CONFIG);
	server_exec();
}

stock mysql_escape_string(const source[], dest[], length)
{
	copy(dest, length, source);

	replace_all(dest, length, "\\", "\\\\");
	replace_all(dest, length, "\0", "\\0");
	replace_all(dest, length, "\n", "\\n");
	replace_all(dest, length, "\r", "\\r");
	replace_all(dest, length, "\x1a", "\Z");
	replace_all(dest, length, "'", "\'");
	replace_all(dest, length, "`", "\`");
	replace_all(dest, length, "^"", "\^"");
}

stock menu_setprops(menu) {
	menu_setprop(menu, MPROP_EXITNAME, fmt("%s Wyjdz", menu_prefix));
	menu_setprop(menu, MPROP_BACKNAME, fmt("%s Wroc", menu_prefix));
	menu_setprop(menu, MPROP_NEXTNAME, fmt("%s Dalej", menu_prefix));
}

stock cmd_execute(id, const text[], any:...) {
	#pragma unused text
	#define OFFSET_DIRECTOR_STUFFTEXT_ID 10

	new message[MAX_MESSAGE];
	format_args(message, charsmax(message), 1);

	message_begin(id == 0 ? MSG_ALL : MSG_ONE, SVC_DIRECTOR, _, id);

	write_byte(strlen(message) + 2);
	write_byte(OFFSET_DIRECTOR_STUFFTEXT_ID);

	write_string(message);
	message_end();
}

stock refresh_stats(id) {	

	if(!is_user_connected(id)) 
		return;


	new deaths = get_member(id, m_iDeaths);
	new team = get_member(id, m_iTeam);

	message_begin(MSG_ALL, get_user_msgid("ScoreInfo"));
	write_byte(id);
	write_short(floatround(get_entvar(id, var_frags)));
	write_short(deaths);
	write_short(0);
	write_short(team);
	message_end();
}

stock give_weapon(id, weapon[], bool:strip = false) { 
	
	if (is_user_alive(id)) { 
		
		if(strip) {
			rg_remove_items_by_slot(id, PISTOL_SLOT);
			rg_remove_items_by_slot(id, PRIMARY_WEAPON_SLOT);
			give_item(id, "weapon_knife");
		}
		
		new weaponid = get_weaponid(weapon);
		if(!user_has_weapon(id, weaponid))
			give_item(id, weapon); 
		
		new weaponsBp[] ={ 0, 52, 0, 90, 1, 32, 1, 100, 90, 1, 120, 100, 100, 90, 90, 90, 100, 120, 30,	120, 200, 32, 90, 120, 90, 1 /*flashbang*/, 35, 90, 90, 0, 100 };
		
		cs_set_user_bpammo(id, weaponid, weaponsBp[weaponid]);
	}		
}

stock register_commands(const array[][], array_size, function[])
{
	ForRange(i, 0, array_size - 1)
	{
		ForRange(j, 0, 1)
			register_clcmd(fmt("%s %s", !j ? "say" : "say_team", array[i]), function);
	}
}

#pragma semicolon 0

#include <cromchat>

#pragma semicolon 1

stock core_chat(id, prefix, const text[], any:...) {

	new message[MAX_MESSAGE], duplicate[MAX_MESSAGE];

	vformat(message, charsmax(message), text, 4);

	new prefix_text[MAX_SAFE_NAME];
	get_cvar_string("4fun_chat_prefix", prefix_text, charsmax(prefix_text));

	switch(prefix) {
		case PREFIX_NORMAL: formatex(duplicate, charsmax(duplicate), "^4%s^1 %s", prefix_text, message);
		case PREFIX_LINE: formatex(duplicate, charsmax(duplicate), "^4---^1 %s^4 ---",  message);
		default: formatex(duplicate, charsmax(duplicate), "%s", message);
	}

	if(!id) {
		ForPlayers(i) {
			if(!is_user_connected(i))
				continue;
			CC_SendMessage(i, "%s", duplicate);
		}
	} else CC_SendMessage(id, "%s", duplicate);
}

