/**  
    @ Author: Ben Jackster
    @ Date: 23th June
    @ Git: github.com/Mergevos/samp-walking-styles
    @ Copyright (C) 2020
    @ About:
    	- This include gives you access to 15 walking styles
    @ Credits: 
        Me - Forking this and transforming into include
**/

#if defined _walking_Styles_inc
    #endinput
#endif

#include 				< a_samp >

#if !defined HOLDING 
	#define HOLDING(%0) \
		((newkeys & (%0)) == (%0))
#endif


// --
// Credits
// --

#if !defined WALKING_STYLES_NO_CREDITS_MSG
	public OnGameModeInit() {
		#if defined WS_OnGameModeInit
			WS_OnGameModeInit();
		#endif
		print("[1.0.0] Walking styles loaded \n\
			Created by Ben Jackster | Forked by Mergevos");
		return 1;
	}
#endif

// --
// Walking styles
// --

enum {
	WALKING_STYLE_DEFAULT = 0,
	WALKING_STYLE_NORMAL,
	WALKING_STYLE_PED,
	WALKING_STYLE_GANGSTA,
	WALKING_STYLE_GANGSTA2,
	WALKING_STYLE_OLD,
	WALKING_STYLE_FAT_OLD,
	WALKING_STYLE_FAT,
	WALKING_STYLE_WOMANOLD,
	WALKING_STYLE_WOMANFATOLD,
	WALKING_STYLE_SHUFFLE,
	WALKING_STYLE_LADY,
	WALKING_STYLE_LADY2,
	WALKING_STYLE_WHORE,
	WALKING_STYLE_WHORE2,
	WALKING_STYLE_DRUNK,
	WALKING_STYLE_BLIND
};

// --
// Vars
// --

static 
	timer_Walking[MAX_PLAYERS], 
	style_Walking[MAX_PLAYERS];

// --
// OnPlayerConnect
// --

public OnPlayerConnect(playerid) {

	#if defined WS_OnPlayerConnect
        WS_OnPlayerConnect(playerid);
    #endif
	style_Walking[playerid] = WALKING_STYLE_DEFAULT;
	KillTimer(timer_Walking[playerid]);
	return 1;
}

// --
// OnPlayerKeyStateChange
// --

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	#if defined WS_OnPlayerKeyStateChange
        WS_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
    #endif
    if(HOLDING(KEY_WALK) && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT) {
		timer_Walking[playerid] = SetTimerEx("timer_WalkAnimation",200,0,"d",playerid);
	}
	return 1;
}

// --
// <summary> Handles timer_WalkAnimation timer</summary>
// --

forward timer_WalkAnimation(playerid);
public timer_WalkAnimation(playerid)
{
	new keys, updown, leftright;
	GetPlayerKeys(playerid,keys,updown,leftright);
	switch(style_Walking[playerid]) {
	
		case WALKING_STYLE_NORMAL: {
			if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT)) {
				KillTimer(timer_Walking[playerid]);
				ApplyAnimation(playerid,"PED","WALK_player",4.1,1,1,1,1,1);
				timer_Walking[playerid] = SetTimerEx("timer_WalkAnimation",200,0,"d",playerid);
			}
			else {
				ApplyAnimation(playerid,"PED","WALK_player",4.0,0,0,0,0,1); 
				KillTimer(timer_Walking[playerid]);
			}
		}
		case WALKING_STYLE_PED: {
			if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT)) {
				KillTimer(timer_Walking[playerid]);
				ApplyAnimation(playerid,"PED","WALK_civi",4.1,1,1,1,1,1);
				timer_Walking[playerid] = SetTimerEx("timer_WalkAnimation",200,0,"d",playerid);
			}
			else {
				ApplyAnimation(playerid,"PED","WALK_civi",4.0,0,0,0,0,1);
				KillTimer(timer_Walking[playerid]);
			}
		}
		case WALKING_STYLE_GANGSTA: {
			if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT)) {
				KillTimer(timer_Walking[playerid]);
				ApplyAnimation(playerid,"PED","WALK_gang1",4.1,1,1,1,1,1);
				timer_Walking[playerid] = SetTimerEx("timer_WalkAnimation",200,0,"d",playerid);
			}
			else {
				ApplyAnimation(playerid,"PED","WALK_gang1",4.0,0,0,0,0,1); 
				KillTimer(timer_Walking[playerid]);
			}
		}
		case WALKING_STYLE_GANGSTA2: {
			if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT)) {
				KillTimer(timer_Walking[playerid]);
				ApplyAnimation(playerid,"PED","WALK_gang2",4.1,1,1,1,1,1);
				timer_Walking[playerid] = SetTimerEx("timer_WalkAnimation",200,0,"d",playerid);
			}
			else {
				ApplyAnimation(playerid,"PED","WALK_gang2",4.0,0,0,0,0,1); 
				KillTimer(timer_Walking[playerid]);
			}
		}
		case WALKING_STYLE_OLD: {
			if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT)) {
				KillTimer(timer_Walking[playerid]);
				ApplyAnimation(playerid,"PED","WALK_old",4.1,1,1,1,1,1);
				timer_Walking[playerid] = SetTimerEx("timer_WalkAnimation",200,0,"d",playerid);
			}
			else {
				ApplyAnimation(playerid,"PED","WALK_old",4.0,0,0,0,0,1); 
				KillTimer(timer_Walking[playerid]);
			}
		}
		case WALKING_STYLE_FAT_OLD: {
			if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT)) {
				KillTimer(timer_Walking[playerid]);
				ApplyAnimation(playerid,"PED","WALK_fatold",4.1,1,1,1,1,1);
				timer_Walking[playerid] = SetTimerEx("timer_WalkAnimation",200,0,"d",playerid);
			}
			else {
				ApplyAnimation(playerid,"PED","WALK_fatold",4.0,0,0,0,0,1); 
				KillTimer(timer_Walking[playerid]);
			}
		}
		case WALKING_STYLE_FAT: {
			if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT)) {
				KillTimer(timer_Walking[playerid]);
				ApplyAnimation(playerid,"PED","WALK_fat",4.1,1,1,1,1,1);
				timer_Walking[playerid] = SetTimerEx("timer_WalkAnimation",200,0,"d",playerid);
			}
			else {
				ApplyAnimation(playerid,"PED","WALK_fat",4.0,0,0,0,0,1); 
				KillTimer(timer_Walking[playerid]);
			}
		}	
		case WALKING_STYLE_WOMANOLD: {
			if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT)) {
				KillTimer(timer_Walking[playerid]);
				ApplyAnimation(playerid,"PED","WOMAN_walkold",4.1,1,1,1,1,1);
				timer_Walking[playerid] = SetTimerEx("timer_WalkAnimation",200,0,"d",playerid);
			}
			else {
				ApplyAnimation(playerid,"PED","WOMAN_walkold",4.0,0,0,0,0,1); 
				KillTimer(timer_Walking[playerid]);
			}
		}
		case WALKING_STYLE_WOMANFATOLD: {
			if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT)) {
				KillTimer(timer_Walking[playerid]);
				ApplyAnimation(playerid,"PED","WOMAN_walkfatold",4.1,1,1,1,1,1);
				timer_Walking[playerid] = SetTimerEx("timer_WalkAnimation",200,0,"d",playerid);
			}
			else {
				ApplyAnimation(playerid,"PED","WOMAN_walkfatold",4.0,0,0,0,0,1); 
				KillTimer(timer_Walking[playerid]);
			}
		}
		case WALKING_STYLE_SHUFFLE: {
			if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT)) {
				KillTimer(timer_Walking[playerid]);
				ApplyAnimation(playerid,"PED","WALK_shuffle",4.1,1,1,1,1,1);
				timer_Walking[playerid] = SetTimerEx("timer_WalkAnimation",200,0,"d",playerid);
			}
			else {
				ApplyAnimation(playerid,"PED","WALK_shuffle",4.0,0,0,0,0,1); 
				KillTimer(timer_Walking[playerid]);
			}
		}
		case WALKING_STYLE_LADY: {
			if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT)) {
				KillTimer(timer_Walking[playerid]);
				ApplyAnimation(playerid,"PED","WOMAN_walknorm",4.1,1,1,1,1,1);
				timer_Walking[playerid] = SetTimerEx("timer_WalkAnimation",200,0,"d",playerid);
			}
			else {
				ApplyAnimation(playerid,"PED","WOMAN_walknorm",4.0,0,0,0,0,1); 
				KillTimer(timer_Walking[playerid]);
			}
		}
		case WALKING_STYLE_LADY2: {
			if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT)) {
				KillTimer(timer_Walking[playerid]);
				ApplyAnimation(playerid,"PED","WOMAN_walkbusy",4.1,1,1,1,1,1);
				timer_Walking[playerid] = SetTimerEx("timer_WalkAnimation",200,0,"d",playerid);
			}
			else {
				ApplyAnimation(playerid,"PED","WOMAN_walkbusy",4.0,0,0,0,0,1); 
				KillTimer(timer_Walking[playerid]);
			}
		}
		case WALKING_STYLE_WHORE: {
			if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT)) {
				KillTimer(timer_Walking[playerid]);
				ApplyAnimation(playerid,"PED","WOMAN_walkpro",4.1,1,1,1,1,1);
				timer_Walking[playerid] = SetTimerEx("timer_WalkAnimation",200,0,"d",playerid);
			}
			else {
				ApplyAnimation(playerid,"PED","WOMAN_walkpro",4.0,0,0,0,0,1); 
				KillTimer(timer_Walking[playerid]);
			}
		}
		case WALKING_STYLE_WHORE2: {
			if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT)) {
				KillTimer(timer_Walking[playerid]);
				ApplyAnimation(playerid,"PED","WOMAN_walksexy",4.1,1,1,1,1,1);
				timer_Walking[playerid] = SetTimerEx("timer_WalkAnimation",200,0,"d",playerid);
			}
			else {
				ApplyAnimation(playerid,"PED","WOMAN_walksexy",4.0,0,0,0,0,1); 
				KillTimer(timer_Walking[playerid]);
			}
		}
		case WALKING_STYLE_DRUNK: {
			if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT)) {
				KillTimer(timer_Walking[playerid]);
				ApplyAnimation(playerid,"PED","WALK_drunk",4.1,1,1,1,1,1);
				timer_Walking[playerid] = SetTimerEx("timer_WalkAnimation",200,0,"d",playerid);
			}
			else {
				ApplyAnimation(playerid,"PED","WALK_drunk",4.0,0,0,0,0,1); 
				KillTimer(timer_Walking[playerid]);
			}
		}
		case WALKING_STYLE_BLIND: {
			if ((keys & KEY_WALK && updown & KEY_UP) || (keys & KEY_WALK && updown & KEY_DOWN) || (keys & KEY_WALK && leftright & KEY_LEFT) || (keys & KEY_WALK && leftright & KEY_RIGHT)) {
				KillTimer(timer_Walking[playerid]);
				ApplyAnimation(playerid,"PED","WALK_Wuzi",4.1,1,1,1,1,1);
				timer_Walking[playerid] = SetTimerEx("timer_WalkAnimation",200,0,"d",playerid);
			}
			else {
				ApplyAnimation(playerid,"PED","WALK_Wuzi",4.0,0,0,0,0,1); 
				KillTimer(timer_Walking[playerid]);
			}
		}
	}
	return 1;
}

// --
// <summary> Sets player's walking style </summary>
// --

stock SetPlayerWalkingStyle(const playerid, const style) {
	style_Walking[playerid] = style;
}

// --
// <summary> Gets player's walking style </summary>
// --

stock GetPlayerWalkingStyle(const playerid) {
	return style_Walking[playerid];
}

// --
// ALS OnPlayerKeyStateChange
// --

#if defined _ALS_OnPlayerKeyStateChange
    #undef OnPlayerKeyStateChange
#else
    #define _ALS_OnPlayerKeyStateChange
#endif
#define OnPlayerKeyStateChange WS_OnPlayerKeyStateChange
#if defined WS_OnPlayerKeyStateChange
    forward WS_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif

// --
// ALS OnPlayerConnect
// --

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect WS_OnPlayerConnect
#if defined WS_OnPlayerConnect
    forward WS_OnPlayerConnect(playerid);
#endif

// --
// ALS OnGameModeInit
// --

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#define OnGameModeInit WS_OnGameModeInit
#if defined WS_OnGameModeInit
    forward WS_OnGameModeInit();
#endif
