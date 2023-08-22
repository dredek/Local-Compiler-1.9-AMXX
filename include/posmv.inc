/* 
Position / Movements include
*/

#if defined _posmv_included
	#endinput
#endif

#define _posmv_included

#if !defined _fakemeta_included
	#include <fakemeta>
#endif

enum Type
{
	NIE_IGNORUJ_SWOICH,
	IGNORUJ_SWOICH
};

stock bool:is_user_jumping(id){
	new Float:fVelo[3];
	pev(id, pev_velocity, fVelo);
	
	return fVelo[2] ? true : false;
}

stock bool:is_user_crouching(id){ 
	new Float:fMinsize[3];
	pev(id, pev_mins, fMinsize);
	
	if(fMinsize[2] == -18.0)
		return true;
	
	return false;
}

stock bool:is_user_moving(id){
	new Float:fVelo[3], Float:fLength;
	pev(id, pev_velocity, fVelo);
	
	fVelo[2] = 0.0;

	fLength = vector_length(fVelo);
	
	return fLength ? true : false;
}

stock bool:is_user_onground(id, targetentity=0){
	new iFlags = pev(id, pev_flags);
	new iGroundEntity = pev(id, pev_groundentity);
	
	if(targetentity)
		return (iFlags & FL_ONGROUND && iGroundEntity == targetentity) ? true : false;
		
	return (iFlags & FL_ONGROUND) ? true : false;
}

stock is_near_target(id, idtarget, Float:distance){
	new Float:fOrigin[2][3];
	pev(id, pev_origin, fOrigin[0]);
	pev(idtarget, pev_origin, fOrigin[1]);
	
	return get_distance_f(fOrigin[0], fOrigin[1]) <= distance ? true : false;
}

stock getClosestPlayer(id, Type:ignoreteammates){
	new iPlayers[32], iNum, iClosestPlayer = 0, Float:flClosestDist = 9999.9, iPlayer, Float:flDist, Float:fOrigin[2][3];
	ignoreteammates ? get_players(iPlayers, iNum, "ache", get_user_team(id) == 2 ? "TERRORIST" : "CT") : get_players(iPlayers, iNum, "ach");
	
	for(new i = 0; i < iNum; i++){	
		iPlayer = iPlayers[i];
		
		pev(iPlayer, pev_origin, fOrigin[0]);
		pev(id, pev_origin, fOrigin[1]);
		
		flDist = get_distance_f(fOrigin[0], fOrigin[1]);
		
		if(flDist <= flClosestDist){
			iClosestPlayer 	= iPlayer;
			flClosestDist 	= flDist;
		}
	}
	if(is_user_alive(iClosestPlayer))
		return iClosestPlayer;
	
	return -1;
}
