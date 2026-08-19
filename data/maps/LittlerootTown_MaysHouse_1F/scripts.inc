LittlerootTown_MaysHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_MaysHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MaysHouse_1F_OnFrame
	.byte 0

LittlerootTown_MaysHouse_1F_OnLoad:
	end

LittlerootTown_MaysHouse_1F_EventScript_CheckShowShoesManual::
	return

LittlerootTown_MaysHouse_1F_OnTransition:
	end

LittlerootTown_MaysHouse_1F_ReprintMay:
    lockall
    setvar VAR_LITTLEROOT_INTRO_STATE, 7
    playse SE_PIN
    applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_ExclamationMark
    waitmovement 0
    delay 40
    @applymovement LOCALID_RIVALS_HOUSE_1F_MOM, LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach
    @waitmovement 0
    setspeaker MaysMumName
    msgbox RivalsHouse_1F_Text_RivalMum_KidnappedMay, MSGBOX_DEFAULT
    applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerSitDown
    waitmovement 0
    setspeaker MaysMumName
    msgbox RivalsHouse_1F_Text_RivalMum_KidnappedMay2, MSGBOX_DEFAULT
    applymovement LOCALID_RIVALS_HOUSE_1F_MOM, LittlerootTown_MaysHouse_1F_Movement_ApproachButton
    waitmovement 0
    applymovement LOCALID_PLAYER, Common_Movement_FaceUp
    delay 30
    playse SE_SWITCH
    delay 80
    playse SE_CONTEST_MONS_TURN
    delay 120
    playse SE_M_EARTHQUAKE
    delay 80
    playse SE_M_PAY_DAY
    waitse
    playse SE_ESCALATOR
    delay 120
    playse SE_M_COMET_PUNCH
    delay 20
    playse SE_M_COMET_PUNCH
    delay 20
    playse SE_M_COMET_PUNCH
    delay 20
    playse SE_DEX_SEARCH
    delay 60
    playse SE_M_THUNDERBOLT
    delay 20
    playse SE_M_THUNDERBOLT
    delay 20
    playse SE_M_THUNDERBOLT
    delay 40
    playse SE_UNLOCK
    delay 80
    playse SE_DING_DONG
    waitse
    delay 60
    playse SE_EXIT
    delay 10
    addobject LOCALID_RIVALS_HOUSE_1F_RIVAL
    delay 30
    applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_WalkDown
    waitmovement 0
    applymovement LOCALID_RIVALS_HOUSE_1F_MOM, Common_Movement_FaceDown
    delay 30
    playse SE_PIN
    applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_Delay48
    waitmovement 0
    setspeaker SP_NAME_MAY2
    msgbox LittlerootTown_MaysHouse_1F_Text_MayReborn, MSGBOX_DEFAULT
    applymovement LOCALID_RIVALS_HOUSE_1F_MOM, LittlerootTown_MaysHouse_1F_Movement_MomMoveToNewMay
    waitmovement 0
    applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_FaceRight
    setspeaker MaysMumName
    msgbox LittlerootTown_MaysHouse_1F_Text_MayReborn2, MSGBOX_DEFAULT
    setspeaker SP_NAME_MAY2
    msgbox LittlerootTown_MaysHouse_1F_Text_MayReborn3, MSGBOX_DEFAULT
    applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_FaceDown
    msgbox LittlerootTown_MaysHouse_1F_Text_MayReborn4, MSGBOX_DEFAULT
    applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_SendMayOutside
    waitmovement 0
    removeobject LOCALID_RIVALS_HOUSE_1F_RIVAL
    playse SE_EXIT
    delay 80
    applymovement LOCALID_RIVALS_HOUSE_1F_MOM, LittlerootTown_MaysHouse_1F_Movement_MumSitDownAgain
    setspeaker MaysMumName
    msgbox LittlerootTown_MaysHouse_1F_Text_MayReborn5, MSGBOX_DEFAULT
    setflag FLAG_MAY_REPRINTED
    setflag FLAG_ADVENTURE_STARTED
    setvar VAR_OLDALE_TOWN_STATE, 2
    setvar VAR_OLDALE_RIVAL_STATE, 3
    releaseall
    end


@ Many of the below scripts have no gender check because they assume youre in the correct house
LittlerootTown_MaysHouse_1F_OnFrame:
    map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_MaysHouse_1F_ReprintMay
	.2byte 0

LittlerootTown_MaysHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_MaysHouse_1F_Movement_ApproachButton:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	face_left
	step_end

LittlerootTown_MaysHouse_1F_Movement_PlayerSitDown:
    walk_up
    walk_up
    walk_up
    walk_right
    walk_right
    walk_right
    walk_down
    face_right
    step_end

LittlerootTown_MaysHouse_1F_Movement_MumSitDownAgain:
    walk_down
    walk_down
    walk_right
    walk_right
    walk_right
    walk_right
    walk_right
    walk_down
    face_left
    step_end

LittlerootTown_MaysHouse_1F_Movement_MomMoveToNewMay:
    walk_down
    walk_left
    step_end

LittlerootTown_MaysHouse_1F_Movement_SendMayOutside:
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

RivalsHouse_1F_EventScript_RivalMom::
	lock
	faceplayer
	setspeaker MaysMumName
	msgbox RivalsHouse_1F_Text_LikeChildLikeFather, MSGBOX_DEFAULT
	release
	end

MaysMumName:
    .string "May's Mum$"
MaxName:
    .string "Max$"

RivalsHouse_1F_EventScript_RivalSibling::
	lock
	faceplayer
	setspeaker MaxName
	goto_if_eq VAR_TEMP_2, 1, RivalsHouse_1F_EventScript_MaxScript2
	msgbox RivalsHouse_1F_Text_MaxText1, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1
	release
	end

RivalsHouse_1F_EventScript_MaxScript2:
    msgbox RivalsHouse_1F_Text_MaxText2, MSGBOX_DEFAULT
    release
    end

LittlerootTown_MaysHouse_1F_EventScript_PlayerFaceMay::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs0::
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit0
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs0
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs1::
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit1
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs1
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_MayGoUpstairs2::
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit2
	applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs2
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_TryGoUpstairs::
    lock
    playse SE_PIN
    applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_RIVALS_HOUSE_1F_RIVAL, Common_Movement_Delay48
    waitmovement 0
    setspeaker MaysMumName
    msgbox LittlerootTown_MaysHouse_1F_Text_Secret, MSGBOX_DEFAULT
    applymovement LOCALID_PLAYER, Common_Movement_WalkDown
    waitmovement 0
    release
    end

LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit0:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit1:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_PlayerWatchMayExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs0:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs1:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_MayGoUpstairs2:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

RivalsHouse_1F_Text_LikeChildLikeFather:
	.string "Don't worry about May. Just focus\n"
	.string "on other things!$"

LittlerootTown_MaysHouse_1F_Text_Secret:
    .string "Hey now, every household deserves to\n"
    .string "have their own secrets. No prying, okay?$"

LittlerootTown_MaysHouse_1F_Text_MayReborn:
    .string "Oh, Andrew! You're here!\n"
    .string "Ready to go house hunting today?$"

LittlerootTown_MaysHouse_1F_Text_MayReborn2:
    .string "Don't worry about that, honey. Why\n"
    .string "don't you go play with Torchic for\p"
    .string "a while?$"

LittlerootTown_MaysHouse_1F_Text_MayReborn3:
    .string "Alright!$"
LittlerootTown_MaysHouse_1F_Text_MayReborn4:
    .string "See you later, Andrew!$"
LittlerootTown_MaysHouse_1F_Text_MayReborn5:
    .string "And problem solved!\p"
    .string "{LQ}What was that?{RQ} Don't worry\n"
    .string "about it!\p"
    .string "Oh! And I see you got your own POKéMON\n"
    .string "now, too! Awesome! Make sure to get\l"
    .string "yourself a POKéDEX, too. I'm sure it\p"
    .string "will come in handy on your journey!$"

RivalsHouse_1F_Text_RivalMum_KidnappedMay:
    .string "Oh, hello Andrew!\p"
    .string "What brings you here?\p"
    .string "Come, grab a seat!$"
RivalsHouse_1F_Text_RivalMum_KidnappedMay2:
    .string "Now, what were you saying?"
    .string "…\p"
    .string "…\p"
    .string "…\p"
    .string "May got kidnapped? By a strange red\n"
    .string "POKéMON?"
    .string "…\p"
    .string "Not again…\p"
    .string "Oh, don't you worry, Andrew! It happens!\n"
    .string "You stay here for a bit.$"

RivalsHouse_1F_Text_MaxText1:
	.string "Believe it or not, this is not the first\n"
	.string "time May has been kidnapped.\p"
	.string "…\p"
	.string "Do you think there is just a collection\n"
	.string "of Mays out there somewhere?$"

RivalsHouse_1F_Text_MaxText2:
    .string "Let me know if you find them!$"
