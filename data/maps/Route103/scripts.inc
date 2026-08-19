Route103_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route103_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route103_OnLoad
	.byte 0

Route103_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	@call ProfBirch_EventScript_UpdateLocation
	hideobjectat LOCALID_ROUTE103_LATIAS, MAP_ROUTE103
	call_if_unset FLAG_SYS_POKEMON_GET, Route103_HideBag
	end

Route103_HideBag:
    removeobject LOCALID_ROUTE103_BAG
    end

Route103_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_OpenAlteringCave
	setflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
	call_if_unset FLAG_SYS_POKEMON_GET, Route103_HideBag
	end

Route103_EventScript_OpenAlteringCave::
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, TRUE
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, FALSE
	return

Route103_Latias_Movement2:
    walk_faster_right
    walk_faster_right
    walk_faster_right
    walk_faster_right
Route103_Latias_Movement:
    walk_faster_right
    walk_faster_right
    walk_faster_right
    walk_faster_right
    walk_faster_right
    walk_faster_right
    step_end

Route103_Kidnap_Movement2:
    walk_faster_up
    walk_faster_up
    walk_faster_up
    walk_faster_up

Route103_Kidnap_Movement:
    walk_faster_up
    walk_faster_up
    walk_faster_up
    walk_faster_up
    step_end

Route103_Bag_Movement:
    walk_slow_down
    walk_down
    walk_fast_down
    step_end

Route103_EventScript_RivalMay::
    lockall
    faceplayer
    setspeaker SP_NAME_MAY
	msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
	closemessage
	fadeoutbgm 1
	playmoncry SPECIES_LATIAS, 0
    waitse
    delay 40
    addobject LOCALID_ROUTE103_LATIAS
    applymovement LOCALID_ROUTE103_LATIAS, Route103_Latias_Movement
    playse SE_PIN
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FaceUp
    waitmovement LOCALID_ROUTE103_RIVAL
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
    waitmovement LOCALID_ROUTE103_RIVAL
    delay 20
    playmoncry SPECIES_LATIAS, 0
    addobject LOCALID_ROUTE103_BAG
    setobjectxy LOCALID_ROUTE103_BAG, 8, 12
    playse SE_FALL
    getplayerxy VAR_TEMP_0, VAR_TEMP_1
    call_if_eq VAR_TEMP_0, 8, Route103_CheckPlayerY
    applymovement LOCALID_ROUTE103_LATIAS, Route103_Latias_Movement2
    applymovement LOCALID_ROUTE103_BAG, Route103_Bag_Movement
    waitmovement 0
    playse SE_UNLOCK
    waitse
    removeobject LOCALID_ROUTE103_LATIAS
    delay 60
    faceplayer
    fadeinbgm 1
    setspeaker SP_NAME_MAY
    msgbox Route103_Text_MayRoute103Bag, MSGBOX_NPC
    playmoncry SPECIES_TOTODILE, 0
    delay 60
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FaceRight
    waitmovement 0
    applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0
    delay 50
    faceplayer
    setspeaker SP_NAME_MAY
    msgbox Route103_Text_MayRoute103Bag2, MSGBOX_NPC
    setflag FLAG_SYS_POKEMON_GET
    setflag FLAG_RESCUED_BIRCH
    @setflag FLAG_ADVENTURE_STARTED
    setvar VAR_OLDALE_TOWN_STATE, 1
    fadescreen FADE_TO_BLACK
    special ChooseStarter
    waitstate
    fadescreen FADE_FROM_BLACK
    setspeaker SP_NAME_MAY
    msgbox Route103_Text_MayRoute103Bag3, MSGBOX_NPC
    savebgm MUS_DUMMY
	playbgm MUS_ENCOUNTER_MAY, FALSE
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartMayBattleTreecko
	case 1, Route103_EventScript_StartMayBattleTorchic
	case 2, Route103_EventScript_StartMayBattleMudkip
	releaseall
	end

Route103_CheckPlayerY:
    call_if_eq VAR_TEMP_1, 15, Route103_BumpPlayer
    return

Route103_BumpPlayer:
    applymovement LOCALID_PLAYER, Common_Movement_WalkRightFaster
    applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
    return

Route103_EventScript_StartMayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_AfterMayBattle::
    lock
    fadedefaultbgm
    setspeaker SP_NAME_MAY
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
	closemessage
	@special HealPlayerParty
    setflag FLAG_DEFEATED_RIVAL_ROUTE103
    setvar VAR_OLDALE_RIVAL_STATE, 1
    fadeoutbgm 3
	playmoncry SPECIES_LATIAS, 0
	addobject LOCALID_ROUTE103_LATIAS
	setobjectxy LOCALID_ROUTE103_LATIAS, 7, 19
	applymovement LOCALID_ROUTE103_LATIAS, Route103_Kidnap_Movement
	delay 20
	applymovement LOCALID_ROUTE103_LATIAS, Route103_Kidnap_Movement2
	delay 2
	applymovement LOCALID_ROUTE103_RIVAL, Route103_Kidnap_Movement2
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
    setspeaker SP_NAME_MAY
    msgbox Route103_Text_MayKidnapped, MSGBOX_DEFAULT
    delay 20
    removeobject LOCALID_ROUTE103_RIVAL
    removeobject LOCALID_ROUTE103_LATIAS
    closemessage
    delay 60
    msgbox Route103_Text_MayKidnapped2, MSGBOX_DEFAULT
    playbgm MUS_ROUTE101, TRUE
    release
	end

Route103_EventScript_Bag::
    call_if_set FLAG_VISITED_RUSTBORO_CITY, Route103_GetSecondMon
    msgbox Route103_Text_BagNotEmpty, MSGBOX_DEFAULT
    closemessage
    delay 60
    msgbox Route103_Text_BagNotEmpty2, MSGBOX_DEFAULT
    closemessage
    end

Route103_GetSecondMon:
    call_if_unset FLAG_GOT_SECOND_STARTER, Route103_BattleSecondMon
    setflag FLAG_GOT_SECOND_STARTER
    msgbox Route103_Text_BagEmpty, MSGBOX_DEFAULT
    closemessage
    end

Route103_BattleSecondMon:
    switch VAR_STARTER_MON
    case 0, Route103_Prepare_Totodile
    case 1, Route103_Prepare_Chikorita
    case 2, Route103_Prepare_Cyndaquil
    dowildbattle
    return

Route103_Prepare_Chikorita::
    setwildbattle SPECIES_CHIKORITA, 5

Route103_Prepare_Totodile::
    setwildbattle SPECIES_TOTODILE, 5

Route103_Prepare_Cyndaquil::
    setwildbattle SPECIES_CYNDAQUIL, 5

Route103_EventScript_Boy::
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
	end

Route103_EventScript_Man::
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
	end

Route103_EventScript_RouteSign::
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
	end

Route103_EventScript_Daisy::
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Amy::
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_AmyRematch
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_AmyRegisterMatchCallAfterBattle::
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route102_EventScript_AmyRematch::
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Liv::
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_LivRematch
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_LivRegisterMatchCallAfterBattle::
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route102_EventScript_LivRematch::
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Andrew::
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Miguel::
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Route102_EventScript_MiguelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route103_EventScript_MiguelRematch
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_MiguelRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_MIGUEL_1
	release
	end

Route103_EventScript_MiguelRematch::
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Marcos::
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Rhett::
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Pete::
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Isabelle::
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_Text_MayRoute103Pokemon:
	.string "So… I think I screwed up coming here.\l"
	.string "There is no way back for you without\n"
	.string "going through the grass…\lOops.$"

Route103_Text_MayRoute103Bag:
    .string "What the heck!?\p"
    .string "Why did this bag just drop out of\n"
    .string "the sky?$"

Route103_Text_MayRoute103Bag2:
    .string "Holy Arceus! It has pokemon in it!\p"
    .string "Quick, Andrew! Grab one so we can get\l"
    .string "out of the grass!$"

Route103_Text_MayRoute103Bag3:
    .string "You chose one?\p"
    .string "Sweet! Let's have a quick POKéMON\n"
    .string "battle! I'll go easy on you and even\l"
    .string "use one of these POKéMON, too!$"

Route103_Text_MayDefeated:
	.string "Nice one!\n"
	.string "You managed to beat me!$"

Route103_Text_BagEmpty:
	.string "(The bag is empty)$"

Route103_Text_BagNotEmpty:
	.string "(You want another one? Seriously?)$"

Route103_Text_BagNotEmpty2:
	.string "(Check back later…)$"

Route103_Text_MayTimeToHeadBack:
	.string "That was some nice battling! Are you\n"
	.string "sure you haven't battled before?\p"
	.string "Well, nevermind that. Come on!\n"
	.string "Let's go!$"

Route103_Text_MayKidnapped:
    .string "AHHHH!!!!! HELP!!!!!!!!$"

Route103_Text_MayKidnapped2:
    .string "(I should probably inform May's\n"
    .string "Mum that she got kidnapped…)$"

Route103_Text_ShouldHaveBroughtPotion:
	.string "h-h-heLP… I t-t-thiNK I mi-i-ight\n"
	.string "be having a-a-a-a stroKE!…$"

Route103_Text_ShortcutToOldale:
	.string "If you cross the sea from here,\n"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
	.string "Fufufu, that's useful, isn't it?$"

Route103_Text_RouteSign:
	.string "ROUTE 103\n"
	.string "{DOWN_ARROW} OLDALE TOWN$"

