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


#define TIME_UPDATE_ANIMATION   (200)


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

static const indexes_animations[] = {1231,1224,1226,1276,1278,1280,1228,1230,1458};
//indexes animations for checking walking

static const IndexesAnimation[][] =
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

public OnPlayerConnect(playerid) {

	#if defined WS_OnPlayerConnect
        WS_OnPlayerConnect(playerid);
    #endif
	style_Walking[playerid] = WALKING_STYLE_DEFAULT;
    timer_Walking[playerid] = -1;
	return 1;
}
// --
// OnPlayerKeyStateChange
// --
public OnPlayerUpdate(playerid)
{
    if(GetPlayerWalkingStyle(playerid) > 0 && timer_Walking[playerid] == -1)
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
                    timer_WalkAnimation(playerid);
                    break;
                }
            }
        }        
    }
    #if defined gf_OnPlayerUpdate
        return gf_OnPlayerUpdate(playerid);
    #else
        return 1;
    #endif
}
#if defined _ALS_OnPlayerUpdate
    #undef OnPlayerUpdate
#else
    #define _ALS_OnPlayerUpdate
#endif

#define OnPlayerUpdate gf_OnPlayerUpdate
#if defined gf_OnPlayerUpdate
    forward gf_OnPlayerUpdate(playerid);
#endif


// --
// <summary> Handles timer_WalkAnimation timer</summary>
// --



forward timer_WalkAnimation(playerid);
public timer_WalkAnimation(playerid)
{
    timer_Walking[playerid] = -1;
    new keys, updown, leftright;
    GetPlayerKeys(playerid,keys,updown,leftright);
    switch(style_Walking[playerid]) 
    {
        case WALKING_STYLE_NORMAL..WALKING_STYLE_BLIND: 
        {
            if (((!!updown  || !!leftright) && (keys & KEY_WALK) ))
            {
                new temp_index_anim = GetPlayerAnimationIndex(playerid);
                for(new i = 0; i < sizeof indexes_animations; i++)
                {
                    if(temp_index_anim == indexes_animations[i])
                    {   
                        ApplyAnimation(playerid,"PED",IndexesAnimation[style_Walking[playerid]-1],4.1,1,1,1,1,1);
                        timer_Walking[playerid] = SetTimerEx("timer_WalkAnimation",TIME_UPDATE_ANIMATION,false,"d",playerid);
                        return true;
                    }
                }
            }
        }
    }
    return ApplyAnimation(playerid,"PED",IndexesAnimation[style_Walking[playerid]-1],4.0,0,0,0,0,1); 
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
