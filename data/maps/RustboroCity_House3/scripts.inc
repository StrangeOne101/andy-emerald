RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	@msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	@msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

RustboroCity_House3_OnEnter::
    call_if_eq VAR_RUSTBORO_CITY_STATE, 2, RustboroCity_House3_CaitlinBattle
    end

RustboroCity_House3_Caitlin::
    setspeaker SP_NAME_CAITLIN
    lock
    msgbox RustboroCity_House3_Text_CaitlinGeneric, MSGBOX_NPC
    release
    end

RustboroCity_House3_Elly::
    setspeaker SP_NAME_ELLY
    lock
    msgbox RustboroCity_House3_Text_EllyGeneric, MSGBOX_NPC
    release
    end

RustboroCity_House3_CaitlinBattle::
    lock
    setspeaker SP_NAME_CAITLIN
    applymovement LOCALID_RUSTBORO_HOUSE3_CAITLIN, Common_Movement_FaceDown
    waitmovement 0
    applymovement LOCALID_RUSTBORO_HOUSE3_ELLY, Common_Movement_FaceDown
    waitmovement 0
    playse SE_PIN
    applymovement LOCALID_RUSTBORO_HOUSE3_CAITLIN, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_RUSTBORO_HOUSE3_CAITLIN, Common_Movement_Delay48
    waitmovement 0
    applymovement LOCALID_RUSTBORO_HOUSE3_CAITLIN, RustboroCity_House3_MovementCaitlin
    waitmovement 0
    msgbox RustboroCity_House3_Text_Caitlin, MSGBOX_DEFAULT
    applymovement LOCALID_RUSTBORO_HOUSE3_CAITLIN, Common_Movement_FaceLeft
    waitmovement 0
    msgbox RustboroCity_House3_Text_Caitlin2, MSGBOX_DEFAULT
    closemessage
    playse SE_PIN
    applymovement LOCALID_RUSTBORO_HOUSE3_ELLY, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement LOCALID_RUSTBORO_HOUSE3_ELLY, Common_Movement_Delay48
    waitmovement 0
    applymovement LOCALID_RUSTBORO_HOUSE3_ELLY, RustboroCity_House3_MovementElly
    waitmovement 0
    applymovement LOCALID_RUSTBORO_HOUSE3_CAITLIN, RustboroCity_House3_MovementCaitlin2
    waitmovement 0
    applymovement LOCALID_RUSTBORO_HOUSE3_ELLY, RustboroCity_House3_MovementElly2
    waitmovement 0
    setspeaker SP_NAME_ELLY
    msgbox RustboroCity_House3_Text_Elly, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_ELLY, RustboroCity_House3_Text_Elly_Defeat
    applymovement LOCALID_RUSTBORO_HOUSE3_ELLY, Common_Movement_FaceRight
    waitmovement 0
    setspeaker SP_NAME_ELLY
    msgbox RustboroCity_House3_Text_Elly2, MSGBOX_DEFAULT
    setspeaker SP_NAME_CAITLIN
    msgbox RustboroCity_House3_Text_Caitlin3, MSGBOX_DEFAULT
    applymovement LOCALID_RUSTBORO_HOUSE3_ELLY, RustboroCity_House3_MovementEllyStepAway
    waitmovement 0
    applymovement LOCALID_RUSTBORO_HOUSE3_CAITLIN, RustboroCity_House3_MovementCaitlinBattle
    waitmovement 0
    setspeaker SP_NAME_CAITLIN
    msgbox RustboroCity_House3_Text_Caitlin4, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_CAITLIN, RustboroCity_House3_Text_CaitlinDefeat
    setvar VAR_RUSTBORO_CITY_STATE, 3 @ Mark Caitlin and Elly defeated
    release
    end

RustboroCity_House3_MovementCaitlin:
    walk_down
    walk_down
    walk_left
    walk_left
    face_down
    step_end

RustboroCity_House3_MovementCaitlin2:
    walk_fast_right
    face_left
    step_end

RustboroCity_House3_MovementElly:
    walk_faster_down
    walk_faster_down
    face_right
    step_end

RustboroCity_House3_MovementElly2:
    walk_faster_right
    face_down
    step_end

RustboroCity_House3_MovementEllyStepAway:
    walk_up
    face_down
    step_end

RustboroCity_House3_MovementCaitlinBattle:
    walk_left
    face_down
    step_end


SP_NAME_CAITLIN::
    .string "Caitlin$"
SP_NAME_ELLY:
    .string "Elly$"

RustboroCity_House3_Text_Caitlin:
    .string "Who goes there!?\p"
    .string "Oh, it's just you, Andrew.\n"
    .string "How did you get in?\p"
    .string "A key left on the ground? Did\n"
    .string "Adam lose the house key again?\p"
    .string "That man… Can't leave him to\n"
    .string "anything on his own.\p"
    .string "…\p"
    .string "Oh, and I see you have a\n"
    .string "POKéMON now?$"

RustboroCity_House3_Text_Caitlin2:
    .string "Hey Elly, Andrew has a POKéMON\n"
    .string "now!$"

RustboroCity_House3_Text_Elly:
    .string "Wow, really? Let me see,\n"
    .string "Uncle Andrew!$"

RustboroCity_House3_Text_Elly_Defeat:
    .string "How could your POKéMON be\n"
    .string "stronger than my Miku????$"

RustboroCity_House3_Text_Elly2:
    .string "Mum! Come check out Andrew's\n"
    .string "POKéMON! They're strong!$"

RustboroCity_House3_Text_Caitlin3:
    .string "Okay, okay!$"

RustboroCity_House3_Text_Caitlin4:
    .string "Well, you heard her, Andrew.\p"
    .string "Time for a battle!$"

RustboroCity_House3_Text_CaitlinDefeat:
    .string "Impressive!$"

RustboroCity_House3_Text_EllyGeneric:
    .string "If you find any more Miku\n"
    .string "POKéMON, you have to show me!$"

RustboroCity_House3_Text_CaitlinGeneric:
    .string "You need to stop by more!\n"
    .string "We've been missing you, y'know?$"




