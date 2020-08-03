#include "a_samp"
#include "walking_styles"

main(){}

public OnGameModeExit()
{
    return 1;
}

#define SЙTASTILUS 22
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(dialogid == SЙTASTILUS)
	{
		if(response)
		{
			if(listitem == 0)
			{
				SetPlayerWalkingStyle (playerid, WALKING_STYLE_NORMAL);
			}
			if(listitem == 1)
			{
				SetPlayerWalkingStyle (playerid, WALKING_STYLE_PED);
			}
			if(listitem == 2)
			{
			    SetPlayerWalkingStyle (playerid, WALKING_STYLE_GANGSTA);
			}
			if(listitem == 3)
			{
				SetPlayerWalkingStyle (playerid, WALKING_STYLE_GANGSTA2);
			}
			if(listitem == 4)
			{
			    SetPlayerWalkingStyle (playerid, WALKING_STYLE_OLD);
			}
			if(listitem == 5)
			{
			    SetPlayerWalkingStyle (playerid, WALKING_STYLE_FAT_OLD);
			}
			if(listitem == 6)
			{
			    SetPlayerWalkingStyle (playerid, WALKING_STYLE_FAT);
			}
			if(listitem == 7)
			{
			    SetPlayerWalkingStyle (playerid, WALKING_STYLE_LADY);
			}
			if(listitem == 8)
			{
			    SetPlayerWalkingStyle (playerid, WALKING_STYLE_LADY2);
			}
			if(listitem == 9)
			{
			    SetPlayerWalkingStyle (playerid, WALKING_STYLE_WHORE);
			}
			if(listitem == 10)
			{
			    SetPlayerWalkingStyle (playerid, WALKING_STYLE_WHORE2);
			}
			if(listitem == 11)
			{
			    SetPlayerWalkingStyle (playerid, WALKING_STYLE_DRUNK);
			}
			if(listitem == 12)
			{
			    SetPlayerWalkingStyle (playerid, WALKING_STYLE_BLIND);
			}
			if(listitem == 13)
			{
			    SetPlayerWalkingStyle (playerid, WALKING_STYLE_DEFAULT);
			}
            if(listitem == 14)
			{
			    SetPlayerWalkingStyle (playerid, WALKING_STYLE_SHUFFLE);
			}
            if(listitem == 15)
			{
			    SetPlayerWalkingStyle (playerid, WALKING_STYLE_FAT_OLD);
			}
            if(listitem == 16)
			{
			    SetPlayerWalkingStyle (playerid, WALKING_STYLE_FAT);
			}
            
        }
	}
	return 1;
}
//=======================================
public OnPlayerCommandText(playerid, cmdtext[])
{
    if (strcmp("/walks", cmdtext, true, 10) == 0)
	{
	    if(IsPlayerConnected(playerid))
 	    {
        	ShowPlayerDialog(playerid, SЙTASTILUS, DIALOG_STYLE_LIST, "{FFF000}Stil za hodanje{FF0000}", "Normal\nSlabi\nGangsta\nGangsta2\nStaracki\nStaracki2\nNormalno1\nZenski\nZenski2\nKurvarski\nZenski3\nPijani\nCoravi \nNormalno\nShuffle\nWom Fat\nWom Fold", "Ok", "Zatvori");
		}
		return 1;
    }
    return 0;
}