RustboroCity_Flat2_3F_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_Flat2_3F_OnTransition
	.byte 0

RustboroCity_Flat2_3F_EventScript_DevonEmployee::
	msgbox RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_EventScript_Woman::
	msgbox RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones, MSGBOX_NPC
	end

RustboroCity_Flat2_3F_OnTransition::
    call_if_set FLAG_TRAINER_TOBY_RUSTBORO_CITY, RustboroCity_Flat2_3F_EventScript_ShowToby
    end

RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones:
	.string "WHY DOES IT SMELL IN HERE???$"

RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones:
	.string "I'm secretly watching porn right\n"
	.string "now. No one knows.$"

RustboroCity_Flat2_3F_MovementToby::
    reveal_trainer
    face_left
    emote_exclamation_mark
    delay_16
    step_end

RustboroCity_Flat2_3F_EventScript_TobyTrigger::
    lock
    addobject LOCALID_RUSTBOROCITY_FLAT2_3F_TOBY
    setspeaker SP_NAME_TOBY
    playse SE_PIN
    applymovement LOCALID_RUSTBOROCITY_FLAT2_3F_TOBY, RustboroCity_Flat2_3F_MovementToby
    waitmovement 0
    msgbox RustboroCity_Flat2_3F_Text_TobyIntro, MSGBOX_NPC
    trainerbattle_no_intro TRAINER_TOBY_RUSTBORO_CITY, RustboroCity_Flat2_3F_Text_TobyDefeat
    setvar VAR_TEMP_A, 1
RustboroCity_Flat2_3F_EventScript_TobyTalk::
    lock
    setspeaker SP_NAME_TOBY
    msgbox RustboroCity_Flat2_3F_Text_TobyAfter, MSGBOX_NPC
    release
    end

RustboroCity_Flat2_3F_EventScript_ShowToby::
    addobject LOCALID_RUSTBOROCITY_FLAT2_3F_TOBY
    setvar VAR_TEMP_A, 1
    end

RustboroCity_Flat2_3F_Text_TobyIntro::
    .string "Surprise! Bet I was hard to find\n"
    .string "this time!$"

RustboroCity_Flat2_3F_Text_TobyDefeat::
    .string "GG!$"

RustboroCity_Flat2_3F_Text_TobyAfter::
    .string "I have unblocked the boulder from\n"
    .string "ROUTE 116 now!\p"
    .string "Also, I still appear elsewhere on\n"
    .string "that route, so be sure to look!$"
