MauvilleCity_House2_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_House2_OnTransition
	.byte 0

MauvilleCity_House2_OnTransition::
    call_if_set FLAG_ARTHER_BLACKLER_TRADE, MauvilleCity_House2_EventScript_ShowElectrike
    call_if_set FLAG_EVELYN_BLACKLER_TRADE, MauvilleCity_House2_EventScript_ShowMareep
    end

MauvilleCity_House2_EventScript_ShowElectrike::
    addobject LOCALID_BLACKLERHOUSE_ELECTRIKE
    return

MauvilleCity_House2_EventScript_ShowMareep::
    addobject LOCALID_BLACKLERHOUSE_MAREEP
    return

MauvilleCity_House2_EventScript_Christa::
    setspeaker SP_NAME_CHRISTA
    goto_if_set FLAG_DAVID_GIVEN_COINS, MauvilleCity_House2_EventScript_ChristaPost
    msgbox MauvilleCity_House2_Text_Christa, MSGBOX_NPC
    end

MauvilleCity_House2_EventScript_ChristaPost::
    msgbox MauvilleCity_House2_Text_ChristaPostTrade, MSGBOX_NPC
    end


MauvilleCity_House2_EventScript_DavidCount::
    addvar VAR_TEMP_2, 1
    return

MauvilleCity_House2_EventScript_David::
    setspeaker SP_NAME_DAVID
    goto_if_set FLAG_DAVID_GIVEN_COINS, MauvilleCity_House2_EventScript_DavidAfterTrade
    call_if_set FLAG_ARTHER_BLACKLER_TRADE, MauvilleCity_House2_EventScript_DavidCount
    call_if_set FLAG_EVELYN_BLACKLER_TRADE, MauvilleCity_House2_EventScript_DavidCount
    goto_if_eq VAR_TEMP_2, 2, MauvilleCity_House2_EventScript_DavidBothDown
    goto_if_eq VAR_TEMP_2, 1, MauvilleCity_House2_EventScript_DavidOneDown
    msgbox MauvilleCity_House2_Text_DavidPreTrade, MSGBOX_NPC
    release
    end

MauvilleCity_House2_EventScript_DavidOneDown::
    msgbox MauvilleCity_House2_Text_DavidPostTrade1, MSGBOX_NPC
    release
    end

MauvilleCity_House2_EventScript_DavidBothDown::
    lock
    message MauvilleCity_House2_Text_DavidPostTrade2
    checkitem ITEM_COIN_CASE
    goto_if_eq VAR_RESULT, FALSE, MauvilleCity_House2_EventScript_DavidNoCoinCase
    showcoinsbox 0, 0
    playse SE_SHOP
    addcoins 500
    delay 30
    hidecoinsbox 0, 0
    closemessage
    setflag FLAG_DAVID_GIVEN_COINS
    release
    end

MauvilleCity_House2_EventScript_DavidNoCoinCase::
    closemessage
    setspeaker SP_NAME_DAVID
    msgbox MauvilleCity_House2_Text_DavidPostTrade2Fail, MSGBOX_NPC
    end

MauvilleCity_House2_EventScript_DavidAfterTrade::
    msgbox MauvilleCity_House2_Text_DavidPostTrade3, MSGBOX_NPC
    end

MauvilleCity_House2_EventScript_Arthur::
    goto_if_set FLAG_ARTHER_BLACKLER_TRADE, MauvilleCity_House2_EventScript_ArthurAfterTrade
    lock
    faceplayer
    setspeaker SP_NAME_ARTHUR
    msgbox MauvilleCity_House2_Text_ArthurTrade, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, MauvilleCity_House2_EventScript_ArthurDeclineTrade
    special ChoosePartyMon
    goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_House2_EventScript_ArthurDeclineTrade
    specialvar VAR_RESULT, ScriptGetPartyMonSpecies
    goto_if_eq VAR_RESULT, SPECIES_ELECTRIKE, MauvilleCity_House2_EventScript_ArthurAcceptTrade
    goto_if_ne VAR_RESULT, SPECIES_ELECTRIKE, MauvilleCity_House2_EventScript_ArthurWrongPokemonTrade
    end

MauvilleCity_House2_EventScript_ArthurDeclineTrade::
    setspeaker SP_NAME_ARTHUR
    msgbox MauvilleCity_House2_Text_ArthurNoPokemon, MSGBOX_NPC
    release
    end

MauvilleCity_House2_EventScript_ArthurAfterTrade::
    lock
    faceplayer
    setspeaker SP_NAME_ARTHUR
    msgbox MauvilleCity_House2_Text_ArthurAfter, MSGBOX_DEFAULT
    release
    end

MauvilleCity_House2_EventScript_ArthurWrongPokemonTrade::
    setspeaker SP_NAME_ARTHUR
    msgbox MauvilleCity_House2_Text_ArthurWrongPokemon, MSGBOX_NPC
    release
    end

MauvilleCity_House2_EventScript_ArthurAcceptTrade::
    callnative DeleteChosenPartyMon
    getobjectxy LOCALID_BLACKLERHOUSE_ARTHUR, CURRENT_POSITION, VAR_TEMP_0, VAR_TEMP_1
    addvar VAR_TEMP_0, -1
    setspeaker SP_NAME_ARTHUR
    msgbox MauvilleCity_House2_Text_ArthurThanks, MSGBOX_NPC
    setobjectmovementtype LOCALID_BLACKLERHOUSE_ARTHUR, MOVEMENT_TYPE_FACE_LEFT
    addobject LOCALID_BLACKLERHOUSE_ELECTRIKE
    setobjectxy LOCALID_BLACKLERHOUSE_ELECTRIKE, VAR_TEMP_0, VAR_TEMP_1
    setflag FLAG_ARTHER_BLACKLER_TRADE
    release
    end

MauvilleCity_House2_EventScript_Evelyn::
    goto_if_set FLAG_EVELYN_BLACKLER_TRADE, MauvilleCity_House2_EventScript_EvelynAfterTrade
    lock
    faceplayer
    setspeaker SP_NAME_EVELYN
    msgbox MauvilleCity_House2_Text_EvelynTrade, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, MauvilleCity_House2_EventScript_EvelynDeclineTrade
    special ChoosePartyMon
    goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, MauvilleCity_House2_EventScript_EvelynDeclineTrade
    specialvar VAR_RESULT, ScriptGetPartyMonSpecies
    goto_if_eq VAR_RESULT, SPECIES_MAREEP, MauvilleCity_House2_EventScript_EvelynAcceptTrade
    goto_if_ne VAR_RESULT, SPECIES_MAREEP, MauvilleCity_House2_EventScript_EvelynWrongPokemonTrade
    end

MauvilleCity_House2_EventScript_EvelynDeclineTrade::
    setspeaker SP_NAME_EVELYN
    msgbox MauvilleCity_House2_Text_EvelynNoPokemon, MSGBOX_NPC
    release
    end

MauvilleCity_House2_EventScript_EvelynAfterTrade::
    lock
    faceplayer
    setspeaker SP_NAME_EVELYN
    msgbox MauvilleCity_House2_Text_EvelynAfter, MSGBOX_DEFAULT
    release
    end

MauvilleCity_House2_EventScript_EvelynWrongPokemonTrade::
    setspeaker SP_NAME_EVELYN
    msgbox MauvilleCity_House2_Text_EvelynWrongPokemon, MSGBOX_NPC
    release
    end

MauvilleCity_House2_EventScript_EvelynAcceptTrade::
    callnative DeleteChosenPartyMon
    getobjectxy LOCALID_BLACKLERHOUSE_EVELYN, CURRENT_POSITION, VAR_TEMP_0, VAR_TEMP_1
    addvar VAR_TEMP_0, 1
    setspeaker SP_NAME_EVELYN
    msgbox MauvilleCity_House2_Text_EvelynThanks, MSGBOX_NPC
    setobjectmovementtype LOCALID_BLACKLERHOUSE_EVELYN, MOVEMENT_TYPE_FACE_LEFT
    addobject LOCALID_BLACKLERHOUSE_MAREEP
    setobjectxy LOCALID_BLACKLERHOUSE_MAREEP, VAR_TEMP_0, VAR_TEMP_1
    setflag FLAG_EVELYN_BLACKLER_TRADE
    release
    end

MauvilleCity_House2_EventScript_Electrike::
    lock
    faceplayer
    playmoncry SPECIES_ELECTRIKE, 0
    msgbox MauvilleCity_House2_Text_Electrike, MSGBOX_DEFAULT
    waitmoncry
    end

MauvilleCity_House2_EventScript_Mareep::
    lock
    faceplayer
    playmoncry SPECIES_MAREEP, 0
    msgbox MauvilleCity_House2_Text_Mareep, MSGBOX_DEFAULT
    waitmoncry
    end

SP_NAME_DAVID:
    .string "David$"

SP_NAME_CHRISTA:
    .string "Christa$"

SP_NAME_ARTHUR:
    .string "Arthur$"

SP_NAME_EVELYN:
    .string "Evelyn$"

MauvilleCity_House2_Text_UseCoinCaseAtGameCorner::
    .string "Thanks! Enjoy the coins!$"

MauvilleCity_House2_Text_DavidPreTrade::
    .string "Hey bro. Think you could help me\n"
    .string "out with something?\p"
    .string "ARTHUR and EVELYN have been so\n"
    .string "obsessed with POKEMON lately and\l"
    .string "they want one of their own.\p"
    .string "I don't really understand what they\n"
    .string "are after, though. Can you talk to\l"
    .string "them and try figure it out?\p"
    .string "And if you do figure it out, could\n"
    .string "you give them one, too?\l"
    .string "I appreciate it, bro.\p"
    .string "Oh, and the POKEMON they want do\n"
    .string "live in the area. I was able to\l"
    .string "figure that much out! Cheers!$"

MauvilleCity_House2_Text_DavidPostTrade1::
    .string "You found one! You're a legend!\n"
    .string "Just one more to go!$"

MauvilleCity_House2_Text_DavidPostTrade2::
    .string "You legend! You managed to track\n"
    .string "them both down! Thank you so much!\p"
    .string "Here, take these. I don't really\n"
    .string "visit the Gamecorner much anymore so\l"
    .string "you'll have more use for these than I\l"
    .string "will.$"

MauvilleCity_House2_Text_DavidPostTrade2Fail::
    .string "Oh, you don't have the COINCASE yet?\p"
    .string "You were meant to pick one up from\n"
    .string "TOBY in the GYM entrance. Grab one\l"
    .string "and come back!$"

MauvilleCity_House2_Text_DavidPostTrade3::
    .string "Thanks again for helping me out,\n"
    .string "bro! Enjoy the coins! Use them on\l"
    .string "The Gacha machines or something!$"

MauvilleCity_House2_Text_Christa::
    .string "Good to see you, Andrew. Think you\n"
    .string "can figure out what the kids are\l"
    .string "after?$"

MauvilleCity_House2_Text_ChristaPostTrade::
    .string "You're always so helpful. Thanks,\n"
    .string "Andrew. We do appreciate it.$"

MauvilleCity_House2_Text_ArthurTrade::
    .string "Uncle Andrew! I see you have a\n"
    .string "POKEMON now! Could you get me one?\p"
    .string "I want a really cool and fast one!\n"
    .string "And green! I love green! Can you do\l"
    .string "that? Please?$"

MauvilleCity_House2_Text_EvelynTrade::
    .string "Uncle! I want a POKEMON too!\n"
    .string "It has to be cute! And fluffy!\p"
    .string "Do you know it? Can you get it for\n"
    .string "me? Please?$"

MauvilleCity_House2_Text_ArthurWrongPokemon::
    .string "That isn't it!$"

MauvilleCity_House2_Text_EvelynWrongPokemon::
    .string "Nooo! It has to be cute!$"

MauvilleCity_House2_Text_ArthurNoPokemon::
    .string "Awww! Please???$"

MauvilleCity_House2_Text_EvelynNoPokemon::
    .string "Waaaahhhh!$"

MauvilleCity_House2_Text_ArthurThanks::
    .string "You found it! Wow! Thanks,\n"
    .string "Uncle Andrew! You're the best!$"

MauvilleCity_House2_Text_EvelynThanks::
    .string "It's so cute!!! Thank you!!!!\p"
    .string "You're the best Uncle!!!!$"

MauvilleCity_House2_Text_ArthurAfter::
    .string "Electrike is so cool! We are\n"
    .string "going to be best friends!$"

MauvilleCity_House2_Text_EvelynAfter::
    .string "It's so cute!!!! I love it!$"

MauvilleCity_House2_Text_Electrike::
    .string "Wooooooofff!$"

MauvilleCity_House2_Text_Mareep::
    .string "Maaaaaaaaa!$"

