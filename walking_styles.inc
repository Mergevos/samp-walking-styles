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

#include <a_samp>

// --
// Credits
// --

#if !defined WALKING_STYLES_NO_CREDITS_MSG
	public OnGameModeInit() 
    {
		#if defined WStyle_OnGameModeInit
			WStyle_OnGameModeInit();
		#endif
		print("[2.1.2] Walking styles loaded \n\
			Created by Ben Jackster | Forked  by Mergevos | Fixed by MaximWizard");
		return 1;
	}
#endif

// --
// Walking styles
// --


static const TIME_UPDATE_ANIMATION = 300;


#define WALKING_STYLES: __TAG(WALKING_STYLES):
enum WALKING_STYLES:__WALKING_STYLES
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
static stock WALKING_STYLES:_@WALKING_STYLES() { return __WALKING_STYLES; }

// --
// Vars
// --

static 
	Walking_gsTimer[MAX_PLAYERS], 
	WALKING_STYLES: Walking_gsStyle[MAX_PLAYERS];

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
// <summary> Sets player's walking style </summary>
// --

stock bool: Player_SetWalkingStyle(playerid, WALKING_STYLES: style) 
{
    if(_:style >= sizeof(NameAnimations) || !IsPlayerConnected(playerid))
    {
        return false;
    }
    Walking_gsStyle[playerid] = style;
    return true;
}

// --
// <summary> Gets player's walking style </summary>
// --

stock WALKING_STYLES: Player_GetWalkingStyle(playerid) 
{
	return IsPlayerConnected(playerid) ? Walking_gsStyle[playerid] : WALKING_STYLES: INVALID_PLAYER_ID;
}

// --
// OnPlayerConnect
// --

public OnPlayerConnect(playerid) 
{

	#if defined WStyle_OnPlayerConnect
        WStyle_OnPlayerConnect(playerid);
    #endif
	Walking_gsStyle[playerid] = WALKING_STYLE_DEFAULT;
    Walking_gsTimer[playerid] = -1;
	return 1;
}
// --
// OnPlayerDisconnect
// --
public OnPlayerDisconnect(playerid, reason) 
{

    if(Walking_gsTimer[playerid] != -1)
    {
        KillTimer(Walking_gsTimer[playerid]);
    }
    return 1;
}

public OnPlayerUpdate(playerid)
{
    
	#if defined WStyle_OnPlayerUpdate
        WStyle_OnPlayerUpdate(playerid);
    #endif
    if(Player_GetWalkingStyle(playerid) > WALKING_STYLE_DEFAULT && Walking_gsTimer[playerid] == -1)
    {
        new KEY: keys, updown, leftright; 
        GetPlayerKeys(playerid,keys,updown,leftright);
        if (((!!updown  || !!leftright) && (keys & KEY_WALK)))
        {
            new temp_index_anim = GetPlayerAnimationIndex(playerid);
            for(new i = 0; i < sizeof indexes_animations; i++)
            {
                if(temp_index_anim == indexes_animations[i])
                {   
                    ApplyAnimation(playerid,"PED",NameAnimations[_:Walking_gsStyle[playerid]-1],4.1,true,true,true,true,1);
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
    Walking_gsTimer[playerid] = -1;
    if(Walking_gsStyle[playerid] <= WALKING_STYLE_DEFAULT) 
    {
        return false;
    }
    new KEY: keys, updown, leftright;
    GetPlayerKeys(playerid,keys,updown,leftright);
    if (((!!updown  || !!leftright) && (keys & KEY_WALK) ))
    {
        new temp_index_anim = GetPlayerAnimationIndex(playerid);
        for(new i = 0; i < sizeof indexes_animations; i++)
        {
            if(temp_index_anim == indexes_animations[i])
            {   
                Walking_gsTimer[playerid] = SetTimerEx("timer_WalkAnimation",TIME_UPDATE_ANIMATION,false,"d",playerid);
                return true;
            }
        }
    }
	ApplyAnimation(playerid,"PED",NameAnimations[_:Walking_gsStyle[playerid]-1],4.0,false,false,false,false,1); 
    return true;
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
