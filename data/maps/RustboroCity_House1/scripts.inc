RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	ingame_trade INGAME_TRADE_SEEDOT, RustboroCity_House1_Text_IllTradeIfYouWant, RustboroCity_House1_EventScript_DeclineTrade, RustboroCity_House1_EventScript_NotRequestedMon, RustboroCity_House1_Text_PleaseBeGoodToMyPokemon
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
    goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_Hiker2
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces0, MSGBOX_NPC
	end

RustboroCity_House1_EventScript_Hiker2::
    msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
    end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "Hey! Yeah, you!\p"
	.string "I have a KADABRA that I want to\n"
	.string "evolve. So how about it?\p"
	.string "I'll trade you my KADABRA for\p"
	.string "another KADABRA!\n"
	.string "How about it?$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "Enjoy!$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "Huh? That doesn't look anything like\n"
	.string "a {STR_VAR_1} to me.$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "No worries. I will be here if\n"
	.string "you change your mind.$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
    .string "Hahahaha! Sucker!\n"
    .string "I got an Alakazam now! Hahahahaha!$"

RustboroCity_House1_Text_AllSortsOfPlaces0:
    .string "Sigh… My brother will not listen\n"
    .string "to me…$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "My brother is an idiot. You don't even\n"
	.string "need to trade KADABRA to evolve it in\p"
	.string "this ROM hack.$"

