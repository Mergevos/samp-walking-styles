/** 
    @ Author: Mergevos
    @ Date: 29th July
    @ Git: github.com/Mergevos/samp-walking-styles
    @ Copyright (C) 2021
    @ About:
    	- This include gives you access to 15 walking styles
    @ Credits: 
        Me - Forking this and transforming into include
        MaximWizard - Fixing and rewritting this system
**/

#if defined _walking_Styles_inc
    #endinput
#endif

#include 				< a_samp >

// --
// Credits
// --

#if !defined WALKING_STYLES_NO_CREDITS_MSG
	public OnGameModeInit() 
    {
		#if defined WStyle_OnGameModeInit
			WStyle_OnGameModeInit();
		#endif
		print("[2.0.1] Walking styles loaded \n\
			Created by Ben Jackster | Forked  by Mergevos | Fixed by MaximWizard");
		return 1;
	}
#endif

// --
// Walking styles
// --


static const TIME_UPDATE_ANIMATION = 300;


enum 
{
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

static const indexes_animations[] = {1231,1224,1226,1276,1278,1280,1228,1230,1458};
//indexes animations for checking walking

static const NameAnimations[][] =
{
    "WALK_player",
    "WALK_civi",
    "WALK_gang1",
    "WALK_gang2",
    "WALK_old",
    "WALK_fatold",
    "WALK_fat",
    "WOMAN_walkold",
    "WOMAN_walkfatold",
    "WALK_shuffle",
    "WOMAN_walknorm",
    "WOMAN_walkbusy",
    "WOMAN_walkpro",
    "WOMAN_walksexy",
    "WALK_drunk",
    "WALK_Wuzi"
};
// --
// OnPlayerConnect
// --

public OnPlayerConnect(playerid) 
{

	#if defined WStyle_OnPlayerConnect
        WStyle_OnPlayerConnect(playerid);
    #endif
	style_Walking[playerid] = WALKING_STYLE_DEFAULT;
    timer_Walking[playerid] = -1;
	return 1;
}
// --
// OnPlayerDisconnect
// --
public OnPlayerDisconnect(playerid, reason) 
{

    if(timer_Walking[playerid] != -1)
        KillTimer(timer_Walking[playerid]);
	return 1;
}

public OnPlayerUpdate(playerid)
{
    
	#if defined WStyle_OnPlayerUpdate
        WStyle_OnPlayerUpdate(playerid);
    #endif
    if(Player_GetWalkingStyle(playerid) > 0 && timer_Walking[playerid] == -1)
    {
        new keys, updown, leftright;
        GetPlayerKeys(playerid,keys,updown,leftright);
        if (((!!updown  || !!leftright) && (keys & KEY_WALK) ))
        {
            new temp_index_anim = GetPlayerAnimationIndex(playerid);
            for(new i = 0; i < sizeof indexes_animations; i++)
            {
                if(temp_index_anim == indexes_animations[i])
                {   
                    ApplyAnimation(playerid,"PED",NameAnimations[style_Walking[playerid]-1],4.1,1,1,1,1,1);
                    timer_WalkAnimation(playerid);
                    break;
                }
            }
        }        
    }
    return 1;
}

// --
// <summary> Handles timer_WalkAnimation timer</summary>
// --



forward timer_WalkAnimation(playerid);
public timer_WalkAnimation(playerid)
{
    timer_Walking[playerid] = -1;
    if(style_Walking[playerid] <= 0) 
        return false;
    new keys, updown, leftright;
    GetPlayerKeys(playerid,keys,updown,leftright);
    if (((!!updown  || !!leftright) && (keys & KEY_WALK) ))
    {
        new temp_index_anim = GetPlayerAnimationIndex(playerid);
        for(new i = 0; i < sizeof indexes_animations; i++)
        {
            if(temp_index_anim == indexes_animations[i])
            {   
                timer_Walking[playerid] = SetTimerEx("timer_WalkAnimation",TIME_UPDATE_ANIMATION,false,"d",playerid);
                return true;
            }
        }
    }
	return ApplyAnimation(playerid,"PED",NameAnimations[style_Walking[playerid]-1],4.0,0,0,0,0,1); 
}

// --
// <summary> Sets player's walking style </summary>
// --
#pragma deprecated Use Player_SetWalkingStyle instead.
stock SetPlayerWalkingStyle(const playerid, const style)
{
    return Player_SetWalkingStyle(playerid, style);
}

stock Player_SetWalkingStyle(const playerid, const style) 
{
    if(style >= sizeof(NameAnimations))
        return false;
	style_Walking[playerid] = style;
    return true;
}

// --
// <summary> Gets player's walking style </summary>
// --


#pragma deprecated Use Player_GetWalkingStyle instead.
stock GetPlayerWalkingStyle(const playerid)
{
    return Player_GetWalkingStyle(playerid);
}

stock Player_GetWalkingStyle(const playerid) 
{
	return style_Walking[playerid];
}

// --
// ALS OnPlayerConnect
// --

#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect WStyle_OnPlayerConnect
#if defined WStyle_OnPlayerConnect
    forward WStyle_OnPlayerConnect(playerid);
#endif


#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define _ALS_OnPlayerUpdate
#endif

#define OnPlayerUpdate WStyle_OnPlayerUpdate
#if defined WStyle_OnPlayerUpdate
    forward WStyle_OnPlayerUpdate(playerid);
#endif


// --
// ALS OnPlayerDisonnect
// --

#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect WStyle_OnPlayerDisconnect
#if defined WStyle_OnPlayerDisconnect
    forward WStyle_OnPlayerDisconnect(playerid, reason);
#endif

// --
// ALS OnGameModeInit
// --

#if defined _ALS_OnGameModeInit
    #undef OnGameModeInit
#else
    #define _ALS_OnGameModeInit
#endif
#define OnGameModeInit WStyle_OnGameModeInit
#if defined WStyle_OnGameModeInit
    forward WStyle_OnGameModeInit();
#endif
