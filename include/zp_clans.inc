#if defined _zp_clans_included
	#endinput
#endif
#define _zp_clans_included

native amxx4u_get_user_clan(index);
native amxx4u_get_clan_name(index, data[], len);
native amxx4u_get_user_clan_name(index, data[], len);
native amxx4u_get_clan_members(index);

native amxx4u_get_bonus_hpzom(index);
native amxx4u_get_bonus_hphum(index);
native Float:amxx4u_get_bonus_dmg(index);
native amxx4u_get_bonus_armor(index);
native Float:amxx4u_get_bonus_xpkill(index);