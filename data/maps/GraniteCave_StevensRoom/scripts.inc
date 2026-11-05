GraniteCave_StevensRoom_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, GraniteCave_StevensRoom_OnLoad
	.byte 0

GraniteCave_StevensRoom_OnLoad::
    call_if_unset FLAG_REGISTERED_STEVEN_POKENAV, GraniteCave_StevensRoom_SealDoor
    end

GraniteCave_StevensRoom_EventScript_Steven::
	lock
	faceplayer
	setspeaker SP_NAME_TOBY
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, GraniteCave_StevensRoom_EventScript_SecondRun @If already defeated
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_TOBY_2, GraniteCave_StevensRoom_Text_TobyLose1
	setspeaker SP_NAME_TOBY
	setflag FLAG_DELIVERED_STEVEN_LETTER
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
	setspeaker 0
	giveitem ITEM_TM_STEEL_WING
	setspeaker SP_NAME_TOBY
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	msgbox GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister, MSGBOX_DEFAULT
	closemessage
	release
	end

GraniteCave_StevensRoom_EventScript_BagFull::
    msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
    return
    end

GraniteCave_StevensRoom_EventScript_SecondRun::
    msgbox GraniteCave_StevensRoom_Text_TobyBattleAgainQuestion, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_SecondRunCancel
    trainerbattle_no_intro TRAINER_TOBY_3, GraniteCave_StevensRoom_Text_TobyLose2
GraniteCave_StevensRoom_EventScript_DebugLabel:
    setflag FLAG_REGISTERED_STEVEN_POKENAV
    setspeaker SP_NAME_TOBY
    msgbox GraniteCave_StevensRoom_Text_TobyBattle2Post, MSGBOX_DEFAULT
    closemessage
    setvar 0x8004, 1 @Vertical
    setvar 0x8005, 4 @Horizontal
    setvar 0x8006, 6 @Number of shakes
    setvar 0x8007, 4 @Shake delay
    special ShakeCamera
    waitstate
    delay 40
    setmetatile 10, 10, 0x207, FALSE   @Warp metatile
    setmetatile 10, 11, 0x259, 16  @Entrance main
    setmetatile 9, 11, 0x258, 16   @Entrance left
    setmetatile 11, 11, 0x25A, 16  @Entrance right
    playse SE_UNLOCK
    special DrawWholeMapView
    waitse
    setspeaker SP_NAME_TOBY
    msgbox GraniteCave_StevensRoom_Text_TobyBattle2Post2, MSGBOX_DEFAULT
    closemessage
    applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_TobyWarpMovement
    delay 70
    playse SE_WARP_OUT
    fadescreen FADE_TO_WHITE
    waitmovement 0
    removeobject LOCALID_GRANITE_CAVE_STEVEN
    fadescreen FADE_FROM_WHITE
    waitse
    releaseall
    end

GraniteCave_StevensRoom_SealDoor::
    setmetatile 10, 10, 0x201, 3    @Warp metatile   -> Blank cave
    setmetatile 10, 11, 0x221, 16   @Entrance main   -> Wall
    setmetatile 9, 11, 0x221, 16    @Entrance left   -> Wall
    setmetatile 11, 11, 0x221, 16   @Entrance right  -> Wall
    end

GraniteCave_StevensRoom_TobyWarpMovement::
    face_up
    delay_8
    face_left
    delay_8
    face_down
    delay_8
    face_right
    delay_8
    face_up
    delay_4
    face_left
    delay_4
    face_down
    delay_4
    face_right
    delay_4
    face_up
    delay_2
    face_left
    delay_2
    face_down
    delay_2
    face_right
    delay_2
    face_up
    delay_1
    face_left
    delay_1
    face_down
    delay_1
    face_right
    delay_1
    face_up
    delay_1
    face_left
    delay_1
    face_down
    delay_1
    face_right
    delay_1
    set_invisible
    step_end

GraniteCave_StevensRoom_EventScript_SecondRunCancel::
    msgbox GraniteCave_StevensRoom_Text_TobyNoWorries, MSGBOX_DEFAULT
    release
    end


GraniteCave_StevensRoom_Text_ImStevenLetterForMe:
	.string "Hah! Did you expect to see Steven?\n"
	.string "Well it is I, Toby - again!\p"
	.string "I mean… {LQ}Who is this Steven you\n"
	.string "speak of?{RQ}\p"
	.string "…\p"
	.string "Oh well. Time for a battle!\n"
	.string "Defeat me and I'll unlock the GYM!$"

GraniteCave_StevensRoom_Text_ThankYouTakeThis:
	.string "Oh, and because there is leftover\n"
	.string "code for this, I'll give you the TM\p"
	.string "that Steven was going to give you.$"

GraniteCave_StevensRoom_Text_TobyLose1::
    .string "You have to admit that the boat\n"
    .string "was funny as fuck.$"

GraniteCave_StevensRoom_Text_TobyLose2::
    .string "Maybe I should have kept Steven\n"
    .string "here but made him Steven Strange…$"

GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister:
	.string "Now, this is just bonus content, but\n"
	.string "you can battle me again and I'll\p"
	.string "unlock another secret. However,\n"
	.string "it will be more challenging than last\p"
	.string "time, so be prepared!\p"
	.string "Talk to me again whenever you want\n"
	.string "to battle!$"

GraniteCave_StevensRoom_Text_TobyBattleAgainQuestion:
    .string "You're back! Ready to take on my\n"
    .string "next challenge?$"

GraniteCave_StevensRoom_Text_TobyNoWorries:
    .string "No worries. I'll be here!$"

GraniteCave_StevensRoom_Text_OhBagIsFull:
	.string "Oh, your BAG is full…\n"
	.string "Why and how? No TM for you.$"

GraniteCave_StevensRoom_Text_TobyBattle2Post::
    .string "Solid battle!\p"
    .string "Now get ready!$"

GraniteCave_StevensRoom_Text_TobyBattle2Post2::
    .string "Go have a look!$"

