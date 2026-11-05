GraniteCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, GraniteCave_B1F_SetHoleWarp
	.byte 0

GraniteCave_B1F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_GRANITE_CAVE_B2F
	end

GraniteCave_B1F_Matt::
	trainerbattle_single TRAINER_MATT_P, GraniteCave_B1F_Text_MattIntro, GraniteCave_B1F_Text_MattDefeated
	msgbox GraniteCave_B1F_Text_MattPostBattle, MSGBOX_AUTOCLOSE
	end

GraniteCave_B1F_Sam::
	trainerbattle_single TRAINER_SAM_H, GraniteCave_B1F_Text_SamIntro, GraniteCave_B1F_Text_SamDefeated
	msgbox GraniteCave_B1F_Text_SamPostBattle, MSGBOX_AUTOCLOSE
	end


GraniteCave_B1F_Text_MattIntro:
    .string "Lunch was awesome.$"

GraniteCave_B1F_Text_MattDefeated:
    .string "(Photo of a dead possum)$"

GraniteCave_B1F_Text_MattPostBattle:
    .string "I just want to dance all the time.$"

GraniteCave_B1F_Text_SamIntro:
    .string "Matt just doing Matt things.\nClassic.$"

GraniteCave_B1F_Text_SamDefeated::
    .string "My Trump!$"

GraniteCave_B1F_Text_SamPostBattle:
    .string "Darfield has some banger pies.$"

