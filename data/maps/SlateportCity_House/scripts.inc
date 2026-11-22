SlateportCity_House_MapScripts::
    map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_House_OnFrame
	.byte 0

SlateportCity_House_OnFrame::
    map_script_2 VAR_SLATEPORT_CITY_STATE, 0, SlateportCity_House_EventScript_GameIntro
    .2byte 0

SlateportCity_House_EventScript_GameIntro::
    lock
    setvar VAR_SLATEPORT_CITY_STATE, 1
    setspeaker SP_NAME_DANIEL
    applymovement LOCALID_SLATEPORTHOUSE_DANIEL, Common_Movement_FaceDown
    waitmovement 0
    playse SE_PIN
    applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_Delay48
    waitmovement 0
    msgbox SlateportCity_House_Text_GameIntro, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_SLATEPORTHOUSE_DANIEL, Common_Movement_FaceOriginalDirection
    waitmovement 0
    release
    end

SlateportCity_House_EventScript_PokefanM::
    setspeaker SP_NAME_DANIEL
    goto_if_eq VAR_SLATEPORT_CITY_STATE, 2, SlateportCity_House_EventScript_ThanksForPlaying
    lock
    faceplayer
	msgbox SlateportCity_House_Text_ReadyToPlay, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, NO, SlateportCity_House_EventScript_GameNotReady
SlateportCity_House_EventScript_GameReady::
    msgbox SlateportCity_House_Text_GamePlay, MSGBOX_DEFAULT
    multichoice 20, 2, MULTI_PKMN_QUIZ_1, 0
    switch VAR_RESULT
    	case 0, SlateportCity_House_EventScript_GameCommonGoBack
    	case 1, SlateportCity_House_EventScript_GameCommonGoBack
    	case 2, SlateportCity_House_EventScript_GameCommonGoBack
    	case 3, SlateportCity_House_EventScript_GameCommonCorrect
    	case 4, SlateportCity_House_EventScript_GameGiveAnswer1
    	goto SlateportCity_House_EventScript_GameCommonGoBack
SlateportCity_House_EventScript_GameQuestion2:
    setvar VAR_TEMP_1, 1 @ Question 2
    msgbox SlateportCity_House_Text_Question2, MSGBOX_DEFAULT
    multichoice 20, 2, MULTI_PKMN_QUIZ_2, 0
    switch VAR_RESULT
        case 0, SlateportCity_House_EventScript_GameCommonGoBack
        case 1, SlateportCity_House_EventScript_GameCommonGoBack
        case 2, SlateportCity_House_EventScript_GameCommonCorrect
        case 3, SlateportCity_House_EventScript_GameCommonGoBack
        case 4, SlateportCity_House_EventScript_GameGiveAnswer2
        goto SlateportCity_House_EventScript_GameCommonGoBack
SlateportCity_House_EventScript_GameQuestion3:
    setvar VAR_TEMP_1, 2 @ Question 3
    msgbox SlateportCity_House_Text_Question3, MSGBOX_DEFAULT
    multichoice 20, 2, MULTI_PKMN_QUIZ_3, 0
    switch VAR_RESULT
        case 0, SlateportCity_House_EventScript_GameCommonGoBack
        case 1, SlateportCity_House_EventScript_GameCommonGoBack
        case 2, SlateportCity_House_EventScript_GameCommonCorrect
        case 3, SlateportCity_House_EventScript_GameCommonGoBack
        case 4, SlateportCity_House_EventScript_GameGiveAnswer3
        goto SlateportCity_House_EventScript_GameCommonGoBack
SlateportCity_House_EventScript_GameQuestion4:
    setvar VAR_TEMP_1, 3 @ Question 4
    msgbox SlateportCity_House_Text_Question4, MSGBOX_DEFAULT
    multichoice 20, 2, MULTI_PKMN_QUIZ_4, 0
    switch VAR_RESULT
        case 0, SlateportCity_House_EventScript_GameCommonGoBack
        case 1, SlateportCity_House_EventScript_GameCommonGoBack
        case 2, SlateportCity_House_EventScript_GameCommonGoBack
        case 3, SlateportCity_House_EventScript_GameCommonCorrect
        case 4, SlateportCity_House_EventScript_GameGiveAnswer4
        goto SlateportCity_House_EventScript_GameCommonGoBack
SlateportCity_House_EventScript_GameQuestion5:
    setvar VAR_TEMP_1, 4 @ Question 5
    msgbox SlateportCity_House_Text_Question5, MSGBOX_DEFAULT
    multichoice 20, 2, MULTI_PKMN_QUIZ_5, 0
    switch VAR_RESULT
        case 0, SlateportCity_House_EventScript_GameCommonCorrect
        case 1, SlateportCity_House_EventScript_GameCommonGoBack
        case 2, SlateportCity_House_EventScript_GameGiveAnswer5
        goto SlateportCity_House_EventScript_GameCommonGoBack
    end

SlateportCity_House_EventScript_GameCommonCorrect:
    addvar VAR_TEMP_0, 1
SlateportCity_House_EventScript_GameCommonGoBack::
    goto_if_eq VAR_TEMP_1, 0, SlateportCity_House_EventScript_GameQuestion2
    goto_if_eq VAR_TEMP_1, 1, SlateportCity_House_EventScript_GameQuestion3
    goto_if_eq VAR_TEMP_1, 2, SlateportCity_House_EventScript_GameQuestion4
    goto_if_eq VAR_TEMP_1, 3, SlateportCity_House_EventScript_GameQuestion5
    goto_if_eq VAR_TEMP_1, 4, SlateportCity_House_EventScript_GameCountResults
    end

SlateportCity_House_EventScript_GameCountResults::
    goto_if_eq VAR_TEMP_0, 5, SlateportCity_House_EventScript_GameFinish
    setspeaker SP_NAME_DANIEL
    msgbox SlateportCity_House_Text_Wrong, MSGBOX_DEFAULT
    waitmessage
    addvar VAR_DANIEL_GAME_ATTEMPTS, 1
    call SlateportCity_House_EventScript_GameGiveAnswerCommon
    trainerbattle_no_intro TRAINER_DANIEL_WRONG, SlateportCity_House_Text_Defeat2
    setspeaker SP_NAME_DANIEL
    msgbox SlateportCity_House_Text_WrongPost, MSGBOX_DEFAULT
    release
    end

SlateportCity_House_EventScript_GameGiveAnswerCommon::
    setvar VAR_TEMP_1, 0
    setvar VAR_TEMP_0, 0
    return

SlateportCity_House_EventScript_GameGiveAnswer1::
    call SlateportCity_House_EventScript_GameGiveAnswerCommon
    addvar VAR_DANIEL_GAME_ATTEMPTS, 1
    trainerbattle_no_intro TRAINER_DANIEL_Q1, SlateportCity_House_Text_Defeat
    setspeaker SP_NAME_DANIEL
    msgbox SlateportCity_House_Text_Answer1, MSGBOX_DEFAULT
    closemessage
    end

SlateportCity_House_EventScript_GameGiveAnswer2::
    call SlateportCity_House_EventScript_GameGiveAnswerCommon
    addvar VAR_DANIEL_GAME_ATTEMPTS, 1
    trainerbattle_no_intro TRAINER_DANIEL_Q2, SlateportCity_House_Text_Defeat
    setspeaker SP_NAME_DANIEL
    msgbox SlateportCity_House_Text_Answer2, MSGBOX_DEFAULT
    closemessage
    end

SlateportCity_House_EventScript_GameGiveAnswer3::
    call SlateportCity_House_EventScript_GameGiveAnswerCommon
    addvar VAR_DANIEL_GAME_ATTEMPTS, 1
    trainerbattle_no_intro TRAINER_DANIEL_Q3, SlateportCity_House_Text_Defeat
    setspeaker SP_NAME_DANIEL
    msgbox SlateportCity_House_Text_Answer3, MSGBOX_DEFAULT
    closemessage
    end

SlateportCity_House_EventScript_GameGiveAnswer4::
    call SlateportCity_House_EventScript_GameGiveAnswerCommon
    addvar VAR_DANIEL_GAME_ATTEMPTS, 1
    trainerbattle_no_intro TRAINER_DANIEL_Q4, SlateportCity_House_Text_Defeat
    setspeaker SP_NAME_DANIEL
    msgbox SlateportCity_House_Text_Answer4, MSGBOX_DEFAULT
    closemessage
    end

SlateportCity_House_EventScript_GameGiveAnswer5::
    call SlateportCity_House_EventScript_GameGiveAnswerCommon
    addvar VAR_DANIEL_GAME_ATTEMPTS, 1
    trainerbattle_no_intro TRAINER_DANIEL_Q5, SlateportCity_House_Text_Defeat
    setspeaker SP_NAME_DANIEL
    msgbox SlateportCity_House_Text_Answer5, MSGBOX_DEFAULT
    closemessage
    end

SlateportCity_House_EventScript_GameFinish::
    buffernumberstring STR_VAR_1, VAR_DANIEL_GAME_ATTEMPTS
    setspeaker SP_NAME_DANIEL
    msgbox SlateportCity_House_Text_Right, MSGBOX_DEFAULT
    setspeaker 0
    giveitem ITEM_PP_UP
    setvar VAR_SLATEPORT_CITY_STATE, 2
    applymovement LOCALID_SLATEPORTHOUSE_DANIEL, Common_Movement_FaceRight
    release
    end

SlateportCity_House_EventScript_GameNotReady::
    setspeaker SP_NAME_DANIEL
    msgbox SlateportCity_House_Text_NotReady, MSGBOX_DEFAULT
    applymovement LOCALID_SLATEPORTHOUSE_DANIEL, Common_Movement_FaceOriginalDirection
    closemessage
    release
    end

SlateportCity_House_EventScript_Girl::
    setspeaker SP_NAME_MONIEKA
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	applymovement LOCALID_SLATEPORTHOUSE_MONIEKA, Common_Movement_FaceOriginalDirection
	end

SlateportCity_House_EventScript_TryExit::
    lock
    setspeaker SP_NAME_DANIEL
    applymovement LOCALID_SLATEPORTHOUSE_DANIEL, Common_Movement_FaceUp
    msgbox SlateportCity_House_Text_Esacping, MSGBOX_DEFAULT
    waitmessage
    applymovement LOCALID_SLATEPORTHOUSE_DANIEL, Common_Movement_FaceOriginalDirection
    waitmovement 0
    applymovement LOCALID_PLAYER, Common_Movement_WalkDown
    waitmovement 0
    release
    end


SlateportCity_House_EventScript_ThanksForPlaying::
    msgbox SlateportCity_House_Text_ThanksForPlaying, MSGBOX_NPC
    applymovement LOCALID_SLATEPORTHOUSE_DANIEL, Common_Movement_FaceOriginalDirection
    end

SP_NAME_DANIEL::
    .string "Daniel$"
SP_NAME_MONIEKA::
    .string "Monieka$"

SlateportCity_House_Text_GameIntro:
	.string "Andrew! So great you decided to join us\n"
	.string "for games night!\p"
	.string "Huh? You didn't know about it? I swear\n"
	.string "we sent you a message…\p"
	.string "Oh well. Why don't you just play one\n"
	.string "game with us? And if you win, we'll even\l"
	.string "let you use the hole in our house to get\l"
	.string "past those pests lining up outside on\l"
	.string "the streets!\p"
	.string "So what do you say? We're currently doing\n"
	.string "POKEMON Quizzes to see who knows the\l"
	.string "most about POKEMON.\p"
	.string "Oh, but because this is a POKEMON\n"
	.string "game, getting any wrong means you\l"
	.string "will have to battle me before trying\l"
	.string "again!$"

SlateportCity_House_Text_ReadyToPlay:
	.string "Ready to play? You won't know you\n"
	.string "got a question wrong until afterwards!$"

SlateportCity_House_Text_GamePlay:
	.string "Excellent! If you don't know the\n"
	.string "answer, you can give up and I will\l"
	.string "battle you with only one POKEMON for\l"
	.string "the answer. You will have to restart\l"
	.string "the quiz afterwards, though!\p"
	.string "First Question:\n"
	.string "Which of following POKEMON has the\l"
	.string "LOWEST health stat?$"
SlateportCity_House_Text_Question2:
    .string "Second Question:\n"
    .string "Which of the following POKEMON has\l"
    .string "NOT received an evolution in the\l"
    .string "latest POKEMON games?$"
SlateportCity_House_Text_Question3:
    .string "Third Question:\n"
    .string "In the original POKEMON EMERALD,\l"
    .string "which types were NOT considered\l"
    .string "SPECIAL attacks?$"
SlateportCity_House_Text_Question4:
    .string "Fourth Question:\n"
    .string "What was the first POKEMON ever\l"
    .string "created?$"
SlateportCity_House_Text_Question5:
    .string "Last Question:\n"
    .string "In POKEMON canon, can multiple\l"
    .string "legendary POKEMON of the same\l"
    .string "species exist at the same time?$"

SlateportCity_House_Text_Wrong::
    .string "Bzzztt! You got at least one question\n"
    .string "wrong! Know what that means? Battle\l"
    .string "time!$"

SlateportCity_House_Text_Right::
    .string "Wow, you got all 5 questions correct!\n"
    .string "And it only took you {STR_VAR_1} attempts!\p"
    .string "Well, a deal is a deal. Feel free\n"
    .string "to use our secret hole to get past\l"
    .string "the annoyances on the street!\p"
    .string "And take this for the road! It might\n"
    .string "come in handy!$"

SlateportCity_House_Text_NotReady:
    .string "Booooo!!$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "The hole in the wall keeps rent down.\n"
	.string "Houses are just so expensive!\p"
	.string "Plus, we gotta save up now that we are\n"
	.string "expecting, too!$"

SlateportCity_House_Text_Esacping::
    .string "Hey, are you trying to escape\n"
    .string "without playing? Come on, we have\l"
    .string "a game to play!$"

SlateportCity_House_Text_Defeat::
    .string "Ready for the answer?$"

SlateportCity_House_Text_Defeat2::
    .string "Ready to try again?$"

SlateportCity_House_Text_WrongPost::
    .string "Remember, if you don't know the\n"
    .string "answer, you can ask!\p"
    .string "Try again when you're ready.$"

SlateportCity_House_Text_Answer1::
    .string "The answer is actually DIGLETT!\n"
    .string "For some reason, it has a health stat\l"
    .string "of 10 - lower than even baby POKEMON!\p"
    .string "Ninjask was a trick to try make you\n"
    .string "think of Shedninja, who is the true\l"
    .string "lowest of 1. But out of the options,\l"
    .string "it is Diglett!$"

SlateportCity_House_Text_Answer2::
    .string "I am aware this was a mean question\n"
    .string "for someone who has never played any\l"
    .string "POKEMON game past EMERALD! But that\l"
    .string "is the point! Hahahaha!\p"
    .string "Tangela got an evolution in Gen 4\n"
    .string "called Tangrowth.\p"
    .string "Primeape got one in Gen 9 called\n"
    .string "Annihilape (this one is quite dumb.\l"
    .string "It gets so angry it dies and evolves\l"
    .string "into a FIGHTING/GHOST type!)\p"
    .string "And finally, Dusclops also got an\n"
    .string "evolution in Gen 4 - Dusknoir.\p"
    .string "So that leaves Golduck! Golduck is\n"
    .string "the answer as the only Pokemon that\l"
    .string "doesn't evolve in newer games!$"

SlateportCity_House_Text_Answer3::
    .string "The answer is Ghost type!\p"
    .string "Ghost is the only PHYSICAL type\n"
    .string "in the list - the rest were all\l"
    .string "SPECIAL type attacks.$"

SlateportCity_House_Text_Answer4::
    .string "The answer is Rhydon!!!!\p"
    .string "Although Mew is the mother of all\n"
    .string "POKEMON, Arceus is the God of\l"
    .string "all POKEMON and Bulbasaur is the\l"
    .string "first in the POKEDEX, the question\l"
    .string "was about which was CREATED first.\p"
    .string "And Rhydon was the first POKEMON ever\n"
    .string "designed.$"

SlateportCity_House_Text_Answer5::
    .string "The answer is TRUE!\p"
    .string "In canonical POKEMON lore, including\n"
    .string "POKEDEX entries and the anime, there\l"
    .string "can be multiple legendaries at once.\p"
    .string "The POKEDEX entry for ENTEI in Silver\n"
    .string "reads: {LQ}A Pokémon that races across\l"
    .string "the land. It is said that one is born\l"
    .string "every time a new volcano appears.{RQ}\p"
    .string "We also see shiny legendaries in the\n"
    .string "anime series, yet the originals have\l"
    .string "appeared in their normal colors, too.\p"
    .string "Plus, some trainers even caught\n"
    .string "Legendaries in the series.\p"
    .string "So there you go!$"

SlateportCity_House_Text_ThanksForPlaying:
    .string "Thanks for playing! Come and join\n"
    .string "us again sometime!$"
