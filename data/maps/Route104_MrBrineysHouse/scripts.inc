Route104_MrBrineysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_MrBrineysHouse_OnTransition
	.byte 0

Route104_MrBrineysHouse_OnTransition:
	setflag FLAG_LANDMARK_MR_BRINEY_HOUSE
	@call_if_eq VAR_BRINEY_HOUSE_STATE, 1, Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos
	end

Route104_MrBrineysHouse_EventScript_SetBrineyPeekoPos::
	setobjectxyperm LOCALID_BRINEYS_HOUSE_BRINEY, 9, 3
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_BRINEY, MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT
	setobjectxyperm LOCALID_BRINEYS_HOUSE_PEEKO, 9, 6
	setobjectmovementtype LOCALID_BRINEYS_HOUSE_PEEKO, MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN
	return

Route104_MrBrineysHouse_EventScript_Briney::
	lock
	faceplayer
	call_if_unset FLAG_MR_BRINEY_SAILING_INTRO, Route104_MrBrineysHouse_EventScript_SailingIntro
	@goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Route104_MrBrineysHouse_EventScript_SailBothDeliveries
	@goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route104_MrBrineysHouse_EventScript_SailDeliverPackage
	setspeaker SP_NAME_BOATBOY
	msgbox Route104_MrBrineysHouse_Text_Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
    goto Route104_MrBrineysHouse_EventScript_WhereAreWeBound
	end

Route104_MrBrineysHouse_EventScript_SailingIntro::
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	setspeaker SP_NAME_BOATBOY
	msgbox Route104_MrBrineysHouse_Text_NewIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_WhereAreWeBound
	end

Route104_MrBrineysHouse_EventScript_WhereAreWeBound::
	message Route104_MrBrineysHouse_Text_WhereAreWeBound
	waitmessage
	multichoicedefault 20, 8, MULTI_BRINEY_OFF_DEWFORD, 1, FALSE
	switch VAR_RESULT
	case 0, Route104_MrBrineysHouse_EventScript_CostToDewford
	case 1, Route104_MrBrineysHouse_EventScript_DeclineSailing
	case MULTI_B_PRESSED, Route104_MrBrineysHouse_EventScript_DeclineSailing
	end

Route104_MrBrineysHouse_EventScript_CostToDewford::
    goto_if_set FLAG_RECEIVED_DEVON_GOODS, Route104_MrBrineysHouse_EventScript_CostToDewford2 @
    msgbox Route104_MrBrineysHouse_Text_DewfordCost, MSGBOX_YESNO
    goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, Route104_MrBrineysHouse_EventScript_BringInMay
    goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
    msgbox Route104_MrBrineysHouse_Text_NoMoney, MSGBOX_DEFAULT
    end

Route104_MrBrineysHouse_EventScript_CostToDewford2::
    msgbox Route104_MrBrineysHouse_Text_DewfordCostDiscounted, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
    checkmoney 800, FALSE
    goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_NoMoney
    removemoney 800
    updatemoneybox
    goto Route104_MrBrineysHouse_EventScript_SailToDewford
    end

Route104_MrBrineysHouse_EventScript_NoMoney::
    msgbox Route104_MrBrineysHouse_Text_NoMoney, MSGBOX_DEFAULT
    release
    end

Route104_MrBrineysHouse_EventScript_SailBothDeliveries::
	msgbox Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_SailDeliverPackage::
	msgbox Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
	goto Route104_MrBrineysHouse_EventScript_SailToDewford
	end

Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing::
    setspeaker SP_NAME_BOATBOY
	msgbox Route104_MrBrineysHouse_Text_DeclineDeliverySail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_DeclineSailing::
	msgbox Route104_MrBrineysHouse_Text_DeclineDeliverySail, MSGBOX_DEFAULT
	release
	end

Route104_MrBrineysHouse_EventScript_BringInMay::
    closemessage
    playse SE_DOOR
    addobject LOCALID_BRINEYSHOUSE_RIVAL
    waitse
    playse SE_PIN
    applymovement LOCALID_BRINEYSHOUSE_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_BRINEYSHOUSE_RIVAL, Common_Movement_Delay48
    waitmovement 0
    applymovement LOCALID_PLAYER, Common_Movement_FaceDown
    waitmovement 0
    delay 20
    applymovement LOCALID_BRINEYSHOUSE_RIVAL, Route104_MrBrineysHouse_MayWalkUp
    waitmovement 0
    applymovement LOCALID_PLAYER, Common_Movement_FaceRight
    waitmovement 0
    setspeaker SP_NAME_MAY2
    msgbox Route104_MrBrineysHouse_Text_MayGivePass, MSGBOX_DEFAULT
    setspeaker 0
    giveitem ITEM_DEVON_PARTS
    setflag FLAG_RECEIVED_DEVON_GOODS
    setspeaker SP_NAME_MAY2
    msgbox Route104_MrBrineysHouse_Text_MayGivePass2, MSGBOX_DEFAULT
    applymovement LOCALID_BRINEYSHOUSE_RIVAL, Common_Movement_WalkDown
    waitmovement 0
    playse SE_DOOR
    removeobject LOCALID_BRINEYSHOUSE_RIVAL
    delay 30
    applymovement LOCALID_PLAYER, Common_Movement_FaceUp
    setspeaker SP_NAME_BOATBOY
    msgbox Route104_MrBrineysHouse_Text_DiscountedNow, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, Route104_MrBrineysHouse_EventScript_DeclineDeliverySailing
    goto Route104_MrBrineysHouse_EventScript_WhereAreWeBound
    end

Route104_MrBrineysHouse_MayWalkUp::
    walk_up
    face_left
    step_end


Route104_MrBrineysHouse_EventScript_SailToDewford::
	msgbox Route104_MrBrineysHouse_Text_SetSailForDewford, MSGBOX_DEFAULT
	call EventScript_BackupMrBrineyLocation
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 1
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setflag FLAG_HIDE_ROUTE_104_RIVAL
	warp MAP_ROUTE104, 13, 51
	waitstate
	releaseall
	end

Route104_MrBrineysHouse_EventScript_Peeko::
	lock
	faceplayer
	waitse
	setspeaker SP_NAME_PEEKO
	playmoncry SPECIES_PELIPPER, CRY_MODE_NORMAL
	msgbox Route104_MrBrineysHouse_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SP_NAME_PEEKO::
    .string "Peeko$"

Route104_MrBrineysHouse_Text_NewIntro::
    .string "Welcome to Briney Sea Voyages.\p"
    .string "I haven't seen you before. Are you\n"
    .string "looking to travel by sea?$"

Route104_MrBrineysHouse_Text_Intro::
    .string "Welcome back.\n"
    .string "Are you looking to travel by sea?$"

Route104_MrBrineysHouse_Text_ItsYouLetsSailToDewford:
	.string "Hm? You're {PLAYER}{KUN}!\n"
	.string "You saved my darling PEEKO!\l"
	.string "We owe so much to you!\p"
	.string "What's that?\n"
	.string "You want to sail with me?\p"
	.string "Hmhm…\p"
	.string "You have a LETTER bound for DEWFORD\n"
	.string "and a package for SLATEPORT, then?\p"
	.string "Quite the busy life you must lead!\p"
	.string "But, certainly, what you're asking is\n"
	.string "no problem at all.\p"
	.string "You've come to the right man!\n"
	.string "We'll set sail for DEWFORD.$"

Route104_MrBrineysHouse_Text_SetSailForDewford:
	.string "Alright, let's set sail to DEWFORD.\p"
	.string "Please keep your hands in the boat at\n"
	.string "all times! And do not put your fingers\p"
	.string "in the cracks!$"

Route104_MrBrineysHouse_Text_DeclineDeliverySail:
	.string "No worries. I'll be here if you ever\n"
	.string "need to sail.$"

Route104_MrBrineysHouse_Text_NoMoney::
    .string "Oh, you don't seem to have that\n"
    .string "on you.\p"
    .string "I'll be here. Come back when you\n"
    .string "have the money.$"

Route104_MrBrineysHouse_Text_NeedToMakeDeliveriesSailToDewford:
	.string "MR. BRINEY: Ahoy!\n"
	.string "I know exactly what you want to say!\p"
	.string "You're to deliver a LETTER to DEWFORD\n"
	.string "and a package to SLATEPORT.\p"
	.string "What you need me to do is no problem\n"
	.string "at all--I'm the man for the job!\p"
	.string "First, we'll set sail for DEWFORD.$"

Route104_MrBrineysHouse_Text_DewfordCost:
    .string "Alright. That will cost ¥8000.\n"
    .string "That okay?$"

Route104_MrBrineysHouse_Text_DewfordCostDiscounted:
    .string "Alright. With your trainer pass, that\n"
    .string "will cost ¥800. That okay?$"

Route104_MrBrineysHouse_Text_NeedToDeliverPackageSailToDewford:
	.string "MR. BRINEY: Ahoy!\n"
	.string "I know exactly what you want to say!\p"
	.string "You're to deliver a package to\n"
	.string "CAPT. STERN in SLATEPORT.\p"
	.string "What you need me to do is no problem\n"
	.string "at all--I'm the man for the job!\p"
	.string "First, we'll set sail for DEWFORD.$"

Route104_MrBrineysHouse_Text_WhereAreWeBound:
	.string "Where would you like to go?$"

Route104_MrBrineysHouse_Text_TellMeWheneverYouWantToSail:
	.string "MR. BRINEY: Is that so?\n"
	.string "Well, PEEKO owes her life to you.\p"
	.string "You just go on and tell me whenever\n"
	.string "you want to set sail!$"

Route104_MrBrineysHouse_Text_Peeko:
	.string "Pa pa palll!$"

SP_NAME_BOATBOY::
    .string "Gray$"

Route104_MrBrineysHouse_Text_MayGivePass::
    .string "Andrew! I just realized you never got\n"
    .string "a TRAINER PASS!\p"
    .string "Normally, trainers get them when they\n"
    .string "turn 10 and get their starter POKéMON.\p"
    .string "But obviously, you started your journey\n"
    .string "quite late, so you never got one.\p"
    .string "So here! I got one for you!$"

Route104_MrBrineysHouse_Text_MayGivePass2::
    .string "A TRAINER PASS tells vendors you are a\n"
    .string "POKéMON trainer and allows you to get\p"
    .string "discounts in certain places. Not many\n"
    .string "stores have taken it up yet, but it's\l"
    .string "still handy to have!\p"
    .string "Oh! It will also come in handy here!\p"
    .string "Alright, I'm off again! See you around,\n"
    .string "Andrew!$"

Route104_MrBrineysHouse_Text_DiscountedNow::
    .string "…\p"
    .string "I didn't even ask for the pass before\n"
    .string "since you didn't look like a trainer…\p"
    .string "But lets ignore that and move on.\p"
    .string "With a TRAINER PASS, fares are reduced\n"
    .string "to ¥800 a trip.\p"
    .string "(Thankfully for me, this subsidy is paid\n"
    .string "for by the POKéMON LEAGUE.)\p"
    .string "So? Still want to take a trip?$"
