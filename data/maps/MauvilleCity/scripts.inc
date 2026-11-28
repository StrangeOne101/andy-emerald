MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_MAUVILLE_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_MAUVILLE_GYM_STATE, 0
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
    goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_EventScript_RichBoy2
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy2::
    msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike2, MSGBOX_NPC
    end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	closemessage
	delay 20
	msgbox MauvilleCity_Text_ExplainTV2, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

SP_NAME_WALLYUNCLE::
    .string "Wally's Uncle$"

MauvilleCity_EventScript_WallyLoser::
    lock
    hidefollower
    setvar VAR_MAUVILLE_CITY_STATE, 1
    setspeaker SP_NAME_WALLYUNCLE
    msgbox MauvilleCity_Text_WallyUncle1, MSGBOX_DEFAULT
    applymovement LOCALID_MAUVILLE_WALLY, Common_Movement_FaceRight
    waitmovement 0
    setspeaker SP_NAME_WALLY
    msgbox MauvilleCity_Text_WallyUncle2, MSGBOX_DEFAULT
    setspeaker SP_NAME_WALLYUNCLE
    msgbox MauvilleCity_Text_WallyUncle3, MSGBOX_DEFAULT
    setspeaker SP_NAME_WALLY
    msgbox MauvilleCity_Text_WallyUncle4, MSGBOX_DEFAULT
    applymovement LOCALID_MAUVILLE_WALLY, MauvilleCity_Movement_WallyRun
    waitmovement 0
    setflag FLAG_HIDE_MAUVILLE_CITY_WALLY
    setspeaker SP_NAME_WALLYUNCLE
    msgbox MauvilleCity_Text_WallyUncle5, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_MAUVILLE_WALLYS_UNCLE, MauvilleCity_Movement_UncleWalk
    waitmovement 0
    setflag FLAG_HIDE_MAUVILLE_CITY_WALLYS_UNCLE
    clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
    clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
    setflag FLAG_HIDE_MAUVILLE_GYM_GUIDE
    clearflag FLAG_HIDE_MAUVILLE_GYM_TOBY
    release
    end


MauvilleCity_Movement_WallyRun::
    delay_16
    delay_16
    delay_16
    face_left
    delay_16
    walk_fast_left
    walk_fast_left
    walk_fast_left
    walk_fast_left
    walk_fast_left
    walk_fast_left
    walk_fast_left
    walk_fast_left
    walk_fast_left
    set_invisible
    step_end

MauvilleCity_Movement_UncleWalk::
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    walk_left
    set_invisible
    step_end


MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

SP_NAME_WATSON::
    .string "Wattson$"
MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	setspeaker SP_NAME_WATSON
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	setspeaker 0
	giveitem ITEM_BASEMENT_KEY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	setspeaker SP_NAME_WATSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
    setspeaker SP_NAME_WATSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
    setspeaker SP_NAME_WATSON
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	setspeaker 0
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
	setspeaker SP_NAME_WATSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
    setspeaker SP_NAME_WATSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_Scott::
    setspeaker SP_NAME_SCOTT
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_NPC
	release
	end


MauvilleCity_Text_ScottYouDidntHoldBack:
	.string "I got kicked out of the GAMECORNER…\n"
	.string "I was so close to winning! I know it!\p"
	.string "Can you go in and convince them to\n"
	.string "let me back in? Please???$"

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "Oh, {PLAYER}{KUN}!\n"
	.string "You look like you have a lot of zip!\l"
	.string "That's a good thing, wahahahaha!\p"
	.string "Fine! I've decided!\n"
	.string "I need a favor, {PLAYER}{KUN}!\p"
	.string "MAUVILLE CITY has an underground\n"
	.string "sector called NEW MAUVILLE.\p"
	.string "{PLAYER}{KUN}, I'd like you to go there and\n"
	.string "switch off the GENERATOR.\p"
	.string "The GENERATOR has been running a bit\n"
	.string "haywire. It's getting unsafe.\p"
	.string "Here, this is the KEY to get into\n"
	.string "NEW MAUVILLE.$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "Don't you worry about it.\n"
	.string "It won't be a challenge to you.\p"
	.string "The entrance to NEW MAUVILLE is just\n"
	.string "a short SURF away from ROUTE 110.\p"
	.string "That's it, then, you have my trust!\n"
	.string "Wahahahaha!$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "Wahahahaha!\p"
	.string "I knew it, {PLAYER}{KUN}! I knew I'd made\n"
	.string "the right choice asking you!\p"
	.string "This is my thanks--a TM containing\n"
	.string "THUNDERBOLT!\p"
	.string "Go on, you've earned it!$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "Wahahahaha!\p"
	.string "It pleases me to no end to see\n"
	.string "the young step up and take charge!$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "My family is in crippling debt.\n"
	.string "My grandma lost our house from\l"
	.string "spending too much time at the game\l"
	.string "corner.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "That kid is such a fucking loser.\n"
	.string "Just seeing his face makes me want\l"
	.string "to kill myself.$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "Have you been to RYDEL'S CYCLES yet?\p"
	.string "RYDEL, the owner, is a very generous\n"
	.string "man.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "You don't have a bike?\n"
	.string "Didn't realize they let the poor\l"
	.string "live around here…$"

MauvilleCity_Text_PokemonCanJumpYouOnBike2:
	.string "They actually let the likes of YOU\n"
	.string "own a BIKE?\p"
	.string "What is the world coming to…$"

MauvilleCity_Text_CitySign:
	.string "MAUVILLE CITY\n"
	.string "“The bright and shiny city of fun!”$"

MauvilleCity_Text_GymSign:
	.string "MAUVILLE CITY POKéMON GYM\n"
	.string "LEADER: WATTSON\l"
	.string "“The cheerfully electrifying man!”$"

MauvilleCity_Text_BikeShopSign:
	.string "“Ride in gravel and shake up your\n"
	.string "soul!”\l"
	.string "RYDEL'S CYCLES$"

MauvilleCity_Text_GameCornerSign:
	.string "“The play spot for all!”\n"
	.string "MAUVILLE GAME CORNER$"

MauvilleCity_Text_ExplainTV:
	.string "Hi, do you check out TV at all?\p"
	.string "They've added a bunch of cool new\n"
	.string "shows recently.\p"
	.string "TV is so cool. I've seen my friends on\n"
	.string "TV just out of the blue.\p"
	.string "And, sometimes, they even put you on TV\n"
	.string "without telling you.\p"
	.string "I wish I would be on TV sometime.\p"
	.string "That's why I think you should check\n"
	.string "out TVs whenever you can.$"

MauvilleCity_Text_ExplainTV2::
    .string "(Bro came from the 90s.)$"

MauvilleCity_Text_BeenCheckingOutTV:
	.string "Hi, have you been checking out TVs?$"

MauvilleCity_Text_WallyUncle1::
    .string "For the last time, I said no!$"

MauvilleCity_Text_WallyUncle2::
    .string "But Uncle!$"

MauvilleCity_Text_WallyUncle3::
    .string "No buts! You are too much of a\n"
    .string "fucking loser to be decent trainer!\p"
    .string "You are way too pathetic! You will\n"
    .string "never EVER be a real trainer - let\l"
    .string "alone a champion!$"

MauvilleCity_Text_WallyUncle4::
    .string "Waaahhhh! Uncle, I hate you!!!!$"

MauvilleCity_Text_WallyUncle5::
    .string "Good fucking grief! Fucking kid.$"
