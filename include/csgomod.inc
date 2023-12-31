#if defined _csgomod_included
  #endinput
#endif
#define _csgomod_included

#if !defined client_print_color || !defined MAX_NAME_LENGTH
    #error THIS VERSION IS NOT SUPPORTED! PLEASE USE AMXX 1.8.3+!
#endif

#define get_bit(%2,%1) (%1 & (1<<(%2&31)))
#define set_bit(%2,%1) (%1 |= (1<<(%2&31)))
#define rem_bit(%2,%1) (%1 &= ~(1 <<(%2&31)))

#define weapon_entity(%0) (get_pdata_int(%0, 43, 4))
#define is_user_valid(%1) (1 <= %1 <= MAX_PLAYERS)

/**
 * Checks if player is logged in his account.
 *
 * @note Account menu will be diplayed for player if not logged in.
 *
 * @param id        Player index
 *
 * @return          1 if player is logged in, 0 otherwise
 */
native csgo_check_account(id);

/**
 * Returns account balance (euro) for player.
 *
 * @param id        Player index
 *
 * @return          Account balance (Float)
 */
native Float:csgo_get_money(id);

/**
 * Adds value to player's account balance.
 *
 * @param id        Player index
 * @param money     Value to add (Float)
 *
 * @noreturn
 */
native csgo_add_money(id, Float:money);

/**
 * Sets player's account balance to given value.
 *
 * @param id        Player index
 * @param money     Value to set (Float)
 *
 * @noreturn
 */
native csgo_set_money(id, Float:money);
/**
 * Returns player buymenu type.
 *
 * @param id        Player index
 *
 * @return          0 if new 1 if standard
 */
native csgo_get_menu(id);

/**
 * Returns player skin id for current weapon.
 *
 * @param id        Player index
 *
 * @return          Skin index -1 if none
 */
native csgo_get_skin(id);

/**
 * Returns player skin id for given weapon.
 *
 * @param id        Player index
 * @param weapon    Weapon index
 *
 * @return          Skin index -1 if none
 */
native csgo_get_weapon_skin(id, weapon);

/**
 * Retrieves name of skin with given id.
 *
 * @note "Domyslny" if there is no skin.
 *
 * @param skin      Skin index
 * @param data      Buffer to copy text to
 * @param lenth     Maximum buffer size
 *
 * @noreturn
 */
native csgo_get_skin_name(skin, data[], length);

/**
 * Retrieves name of skin for current player weapon.
 *
 * @note "Domyslny" if there is no skin.
 *
 * @param id        Player index
 * @param data      Buffer to copy text to
 * @param lenth     Maximum buffer size
 *
 * @noreturn
 */
native csgo_get_current_skin_name(id, data[], length);

/**
 * Retrieves player clan id.
 *
 * @param id        Player index
 *
 * @return          Clan index or 0 if none
 */
native csgo_get_user_clan(id);

/**
 * Retrieves clan name for given clan id.
 *
 * @note "Brak" if there is no clan.
 *
 * @param clan      Clan index
 * @param data      Buffer to copy name to
 * @param lenth     Maximum buffer size
 *
 * @noreturn
 */
native csgo_get_clan_name(clan, data[], length);

/**
 * Retrieves members count for clan with given id.
 *
 * @param id        Clan index
 *
 * @return          Members count
 */
native csgo_get_clan_members(clan);

/**
 * Retrieves player rank id.
 *
 * @param id        Player index
 *
 * @return          Rank index
 */
native csgo_get_rank(id);

/**
 * Retrieves rank name for given rank id.
 *
 * @param rank      Rank index
 * @param data      Buffer to copy name to
 * @param lenth     Maximum buffer size
 *
 * @noreturn
 */
native csgo_get_rank_name(rank, data[], length);

/**
 * Retrieves current player rank name.
 *
 * @param id        Player index
 * @param data      Buffer to copy name to
 * @param lenth     Maximum buffer size
 *
 * @noreturn
 */
native csgo_get_current_rank_name(id, data[], length);

/**
 * Retrieves StatTrak for given player weapon.
 *
 * @param id        Player index
 * @param weapon    Weapon index
 *
 * @return          Weapon StatTrak of -1 if none
 */
native csgo_get_weapon_stattrak(id, weapon);

/**
 * Checks if player has VIP account.
 *
 * @param id        Player index
 *
 * @return          1 if player is VIP 0 otherwise
 */
native csgo_get_user_vip(id);
/**
 * Zwraca liczbe modeli na serwerze
*/
native csgo_liczba_modeli();
/**
 * Ustawia liczbe losowych skrzyn dla gracza
 *
 * @param id        Player index
 * @param wartosc        ilosc skrzyn
 * 
 */
native csgo_user_chest_random(id, wartosc);
/**
 * Zwraca liczbe kluczy gracza
*/
native csgo_get_user_key(id);
/**
 * Ustawia liczbe kluczy gracza
*/
native csgo_set_user_key(id, wartosc);

native csgo_losuj_skina(id);
native csgo_rozdaj_medale();

native csgo_get_assist(id);
native csgo_set_assist(id, wartosc);
native csgo_get_mvp(id);
native csgo_set_mvp(id, wartosc);

native csgo_set_user_premium(id, wartosc);
native csgo_get_user_premium(id);



/**
 * Multiforward called when player has logged in.
 *
 * @param id        Player index
 *
 * @noreturn
 */
forward csgo_user_login(id);


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

stock cmd_execute(id, const text[], any:...)
{
	#pragma unused text

	new message[256];

	format_args(message, charsmax(message), 1);

	message_begin(id == 0 ? MSG_ALL : MSG_ONE, SVC_DIRECTOR, _, id);
	write_byte(strlen(message) + 2);
	write_byte(10);
	write_string(message);
	message_end();
}