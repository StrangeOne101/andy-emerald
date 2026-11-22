SlateportCity_Harbor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_OnTransition
	.byte 0

SlateportCity_Harbor_OnTransition:
	setescapewarp MAP_SLATEPORT_CITY, 28, 13
	setvar VAR_TEMP_1, 0
	call_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_ShowSSTidal
	end

SlateportCity_Harbor_EventScript_ShowSSTidal::
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
	return


SlateportCity_Harbor_Movement_SubmarineExit:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer0:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer1:
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

SlateportCity_Harbor_Movement_SternApproachPlayer:
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Harbor_Movement_PlayerWalkUp:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_FerryAttendant::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_AskForTicket
	msgbox SlateportCity_Harbor_Text_FerryServiceUnavailable, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_WailordGuy::
    msgbox SlateportCity_Harbor_Text_Wailord, MSGBOX_NPC
    release
    end

SlateportCity_Harbor_EventScript_AskForTicket::
	msgbox SlateportCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message SlateportCity_Harbor_Text_FlashedTicketWhereTo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_ChooseDestination::
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier
	multichoicedefault 18, 8, MULTI_SSTIDAL_SLATEPORT_NO_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier::
	multichoicedefault 17, 6, MULTI_SSTIDAL_SLATEPORT_WITH_BF, 2, FALSE
	switch VAR_RESULT
	case 0, SlateportCity_Harbor_EventScript_Lilycove
	case 1, SlateportCity_Harbor_EventScript_BattleFrontier
	case 2, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
	end

@ Unused. Should be impossible for player to reach Ferry without having received SS Tidal ticket
SlateportCity_Harbor_EventScript_NoTicket::
	msgbox SlateportCity_Harbor_Text_YouMustHaveTicket, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_Lilycove::
	msgbox SlateportCity_Harbor_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_BattleFrontier::
	msgbox SlateportCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
	waitstate
	release
	end

SlateportCity_Harbor_EventScript_ChooseNewDestination::
	message SlateportCity_Harbor_Text_WhereWouldYouLikeToGo
	waitmessage
	goto SlateportCity_Harbor_EventScript_ChooseDestination
	end

SlateportCity_Harbor_EventScript_BoardFerry::
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
	call_if_eq VAR_FACING, DIR_NORTH, SlateportCity_Harbor_EventScript_BoardFerryNorth
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_Harbor_EventScript_BoardFerryEast
	delay 30
	hideplayer
	setvar VAR_0x8004, LOCALID_SLATEPORT_HARBOR_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

SlateportCity_Harbor_EventScript_CancelDestinationSelect::
	msgbox SlateportCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_BoardFerryEast::
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryEast
	waitmovement 0
	return

SlateportCity_Harbor_EventScript_BoardFerryNorth::
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryNorth
	waitmovement 0
	return

SlateportCity_Harbor_Movement_BoardFerryEast:
	walk_right
	walk_in_place_faster_up
	step_end

SlateportCity_Harbor_Movement_BoardFerryNorth:
	walk_up
	step_end

SlateportCity_Harbor_EventScript_Sailor::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	call_if_set FLAG_DEFEATED_GROUDON, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
	goto_if_eq VAR_0x8004, 2, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather  @ Defeated both
	msgbox SlateportCity_Harbor_Text_AbnormalWeather, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather::
	msgbox SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_CountDefeatedLegendary::
	addvar VAR_0x8004, 1
	return

SlateportCity_Harbor_EventScript_FatMan::
	msgbox SlateportCity_Harbor_Text_SubTooSmallForMe, MSGBOX_NPC
	end

@ TODO Put this elsewhere
SlateportCity_Harbor_EventScript_DeepSeaTooth::
	@msgbox SlateportCity_Harbor_Text_TradeForDeepSeaTooth, MSGBOX_YESNO
	@goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_TOOTH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	@msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeepSeaScale::
	@ msgbox SlateportCity_Harbor_Text_TradeForDeepSeaScale, MSGBOX_YESNO
	@goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
	giveitem ITEM_DEEP_SEA_SCALE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_SCANNER
	@msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
	setflag FLAG_EXCHANGED_SCANNER
	goto SlateportCity_Harbor_EventScript_TradedScanner
	end

SlateportCity_Harbor_EventScript_DeclineTrade::
	@ msgbox SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_EventScript_ChooseDifferentTrade::
	@ message SlateportCity_Harbor_Text_WhichOneDoYouWant
	waitmessage
	@ goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
	end

SlateportCity_Harbor_EventScript_TradedScanner::
	setvar VAR_TEMP_1, 1
	@ msgbox SlateportCity_Harbor_Text_ThisWillHelpResearch, MSGBOX_DEFAULT
	release
	end

SlateportCity_Harbor_Text_FerryServiceUnavailable:
	.string "I beg your pardon?\n"
	.string "You're looking for a ship?\p"
	.string "I'm sorry, the ferry service isn't\n"
	.string "available at present…$"

SlateportCity_Harbor_Text_MayISeeYourTicket:
	.string "Hello, are you here for the ferry?\n"
	.string "May I see your TICKET?$"

SlateportCity_Harbor_Text_YouMustHaveTicket:
	.string "{PLAYER} doesn't have the TICKET…\p"
	.string "I'm terribly sorry.\p"
	.string "You must have a TICKET to board\n"
	.string "the ferry.$"

SlateportCity_Harbor_Text_FlashedTicketWhereTo:
	.string "{PLAYER} flashed the TICKET.\p"
	.string "Perfect! That's all you need!\p"
	.string "And where would you like to go?$"

SlateportCity_Harbor_Text_SailAnotherTime:
	.string "Please sail with us another time!$"

SlateportCity_Harbor_Text_LilycoveItIs:
	.string "LILYCOVE CITY it is, then!$"

SlateportCity_Harbor_Text_BattleFrontierItIs:
	.string "BATTLE FRONTIER it is, then!$"

SlateportCity_Harbor_Text_PleaseBoardFerry:
	.string "Please board the ferry and wait for\n"
	.string "departure.$"

SlateportCity_Harbor_Text_WhereWouldYouLikeToGo:
	.string "Then, where would you like to go?$"

SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday:
	.string "A journey to the bottom of the sea…\n"
	.string "I wonder what it'd be like?\p"
	.string "I'd love to go deep underwater like\n"
	.string "that someday.$"

SlateportCity_Harbor_Text_AbnormalWeather:
	.string "For a ship to sail safely, we need to\n"
	.string "know about the weather!\p"
	.string "Speaking of weather, I heard something\n"
	.string "from a guy at the WEATHER INSTITUTE.\p"
	.string "He was saying abnormal weather has\n"
	.string "been reported all over the place!\p"
	.string "You should visit the WEATHER INSTITUTE\n"
	.string "and ask around!$"

SlateportCity_Harbor_Text_SubTooSmallForMe:
	.string "I wanted to go with CAPT. STERN on\n"
	.string "the ocean floor exploration.\p"
	.string "But the sub's too small for me.\p"
	.string "If I squeezed in, there wouldn't be\n"
	.string "any room for the CAPTAIN…$"

SlateportCity_Harbor_Text_Wailord::
    .string "The damn WAILORD is blocking the\n"
    .string "ferry in again! How am I meant to\l"
    .string "watch the ferry depart now???$"
