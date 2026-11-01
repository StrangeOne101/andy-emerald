GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	setspeaker SP_NAME_FLASHER
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
    setspeaker SP_NAME_FLASHER
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

SP_NAME_FLASHER::
    .string "Flasher$"

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Hey, you!\n"
	.string "Wanna see my titties???$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Oooohhhh yeah!!! I bet you\n"
	.string "loooooooove that!!!!$"

