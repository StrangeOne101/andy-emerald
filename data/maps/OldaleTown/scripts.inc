OldaleTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
	.byte 0

OldaleTown_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	setflag FLAG_VISITED_OLDALE_TOWN
	call_if_unset FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_BlockWestEntrance
	call_if_unset FLAG_VISITED_PETALBURG_CITY, OldaleTown_EventScript_MoveMartEmployee
	call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_SetOldaleState
	end

@ This script seems pointless because nothing uses VAR_OLDALE_TOWN_STATE
OldaleTown_EventScript_SetOldaleState::
	setvar VAR_OLDALE_TOWN_STATE, 1
	return

OldaleTown_EventScript_BlockWestEntrance::
	setobjectxyperm LOCALID_FOOTPRINTS_MAN, 1, 11
	setobjectmovementtype LOCALID_FOOTPRINTS_MAN, MOVEMENT_TYPE_FACE_LEFT
	return

OldaleTown_EventScript_MoveMartEmployee::
	@setobjectxyperm LOCALID_OLDALE_MART_EMPLOYEE, 13, 14
	setobjectmovementtype LOCALID_OLDALE_MART_EMPLOYEE, MOVEMENT_TYPE_FACE_DOWN
	return

OldaleTown_EventScript_TownSign::
	msgbox OldaleTown_Text_TownSign, MSGBOX_SIGN
	end

OldaleTown_EventScript_Girl::
	msgbox OldaleTown_Text_SavingMyProgress, MSGBOX_NPC
	end

OldaleTown_EventScript_Man::
	msgbox OldaleTown_Text_TwinTowers, MSGBOX_NPC
	end

OldaleTown_EventScript_MartEmployee::
	lock
	faceplayer
	msgbox OldaleTown_Text_IWorkAtPokemonMart, MSGBOX_NPC
	applymovement LOCALID_OLDALE_MART_EMPLOYEE, Common_Movement_FaceDown
	end

OdaleTown_EventScript_RefuseEntry::
    lock
    playse SE_PIN
    applymovement LOCALID_OLDALE_MART_EMPLOYEE, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_OLDALE_MART_EMPLOYEE, Common_Movement_FaceRight
    waitmovement 0
    msgbox OldaleTown_Text_IWorkAtPokemonMart, MSGBOX_DEFAULT
    applymovement LOCALID_PLAYER, Common_Movement_WalkDown
    applymovement LOCALID_OLDALE_MART_EMPLOYEE, Common_Movement_FaceDown
    waitmovementall
    closemessage
    end

OldaleTown_Movement_PlayerEast:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_PlayerSouth:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_PlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_EventScript_FootprintsMan::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_NotBlockingPath
	msgbox OldaleTown_Text_DiscoveredFootprints, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOOTPRINTS_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

OldaleTown_EventScript_BlockedPath::
	lockall
	applymovement LOCALID_PLAYER, OldaleTown_Movement_PlayerStepBack
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_BackUp
	waitmovement 0
	msgbox OldaleTown_Text_WaitDontComeInHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_ReturnToOriginalPosition
	waitmovement 0
	releaseall
	end

OldaleTown_EventScript_NotBlockingPath::
	msgbox OldaleTown_Text_FinishedSketchingFootprints, MSGBOX_DEFAULT
	release
	end

OldaleTown_EventScript_Rival::
	lockall
	applymovement LOCALID_OLDALE_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	goto OldaleTown_EventScript_ShowMayMessage
	end

OldaleTown_EventScript_RivalTrigger1::
	lockall
	applymovement LOCALID_OLDALE_RIVAL, Common_Movement_FaceLeft
	waitmovement 0
	goto OldaleTown_EventScript_ShowMayMessage
	end

OldaleTown_EventScript_ShowMayMessage::
    setspeaker SP_NAME_MAY
	msgbox OldaleTown_Text_MayLetsGoBack, MSGBOX_NPC
	goto OldaleTown_EventScript_RivalFinish
	end

OldaleTown_EventScript_RivalFinish::
	closemessage
	applymovement LOCALID_OLDALE_RIVAL, OldaleTown_Movement_RivalExit
	waitmovement 0
	removeobject LOCALID_OLDALE_RIVAL
	setvar VAR_OLDALE_RIVAL_STATE, 2
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	releaseall
	end

OldaleTown_EventScript_DoExitMovement1::
	goto_if_ne VAR_FACING, DIR_SOUTH, OldaleTown_EventScript_DoExitMovement2
	applymovement LOCALID_OLDALE_RIVAL, OldaleTown_Movement_RivalExit
	waitmovement 0
	return

OldaleTown_EventScript_DoExitMovement2::
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_OLDALE_RIVAL, OldaleTown_Movement_RivalExit
	waitmovement 0
	return

OldaleTown_Movement_RivalExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

OldaleTown_Movement_PlayerStepBack:
	delay_8
    walk_faster_right
	step_end

OldaleTown_Movement_BackUp:
	walk_fast_up
	walk_in_place_faster_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

OldaleTown_Movement_ReturnToOriginalPosition:
	walk_down
	walk_left
	step_end

OldaleTown_Text_SavingMyProgress:
	.string "Make sure you talk to everyone and\n"
	.string "everything! Who knows what you'll\l"
	.string "find out!$"

OldaleTown_Text_IWorkAtPokemonMart:
	.string "Hi there. The POKéMON MART is\n"
	.string "currently closed.\p"
	.string "Why?\p"
	.string "A customer let off a ten-ton nuclear\n"
	.string "diarrhea explosion and the cleaning\l"
	.string "crews are still working.\p"
	.string "Come back again later.$"

OldaleTown_Text_WaitDontComeInHere:
	.string "FUCK OFF!!!\n"

OldaleTown_Text_DiscoveredFootprints:
	.string "I JUST FOUND A FUCKING SHINY!!!\p"
	.string "DON'T YOU DARE GET IN MY WAY!\n"
	.string "MOVE OUT OF THE WAY! IT'S MINE!$"

OldaleTown_Text_FinishedSketchingFootprints:
	.string "Some local shithead just painted\n"
	.string "it… It wasn't a shiny at all…\p"
	.string "Fuck my big chungus life.$"

OldaleTown_Text_MayLetsGoBack:
	.string "{PLAYER}{KUN}, we're going to continue\n"
	.string "south down ROUTE 103. Good job not\l"
	.string "running into any POKéMON!\p"
	.string "…\p"
	.string "Keep up!$"

OldaleTown_Text_TownSign:
	.string "OLDALE TOWN\n"
	.string "“You expected it to be different?”$"

OldaleTown_Text_TwinTowers:
    .string "Did you know that different POKéMON\n"
    .string "come out at night? Now the RTC is\l"
    .string "actually useful in Emerald!$"
