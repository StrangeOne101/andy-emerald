DewfordInland_MapScripts::
	.byte 0

DewfordInland_EventScript_Meowth::
    lock
    faceplayer
    setspeaker SP_NAME_MEOWTH
    msgbox DewfordInland_Text_Meowth, MSGBOX_NPC
    release
    end

DewfordInland_EventScript_May17::
    lock
    setspeaker SP_NAME_MAY17
    msgbox DewfordInland_Text_DDD, MSGBOX_DEFAULT
    release
    end

DewfordInland_EventScript_May4::
    lock
    setspeaker SP_NAME_MAY4
    msgbox DewfordInland_Text_DDD, MSGBOX_DEFAULT
    release
    end

DewfordInland_EventScript_May23::
    lock
    setspeaker SP_NAME_MAY23
    msgbox DewfordInland_Text_DDD, MSGBOX_DEFAULT
    release
    end

DewfordInland_EventScript_May2E::
    lock
    setspeaker SP_NAME_MAY2E
    msgbox DewfordInland_Text_DDD, MSGBOX_DEFAULT
    release
    end

DewfordInland_EventScript_Brendan::
    lock
    setspeaker SP_NAME_BRENDAN2
    msgbox DewfordInland_Text_DDD, MSGBOX_DEFAULT
    release
    end

DewfordInland_EventScript_Sign::
    lock
    msgbox DewfordInland_Text_Sign, MSGBOX_SIGN
    release
    end

SP_NAME_MEOWTH::
    .string "Meowth$"

SP_NAME_MAY17::
    .string "May 17$"

SP_NAME_MAY4::
    .string "May 4$"

SP_NAME_BRENDAN2::
    .string "{LQ}BRENDAN{LQ}$"

SP_NAME_MAY23::
    .string "May 23$"

SP_NAME_MAY2E::
    .string "May -2.14E9$"

DewfordInland_Text_Meowth::
    .string "Welcome to the MAY pile!\p"
    .string "Some red POKEMON flies in and dumps\n"
    .string "a MAY here occasionally, thus,\l"
    .string "the MAY pile!\p"
    .string "That said, we rarely get some others mixed\n"
    .string "in, too. Such as myself, and that BRENDAN\l"
    .string "over there.\p"
    .string "Don't bother talking to any of them!\n"
    .string "I think their dialogue got lost in\p"
    .string "stale memory. None of them can say\n"
    .string "anything, anymore. They used to, though!$"

DewfordInland_Text_DDD::
    .string "…$"

DewfordInland_Text_Sign::
    .string "(The sign is blank)$"

