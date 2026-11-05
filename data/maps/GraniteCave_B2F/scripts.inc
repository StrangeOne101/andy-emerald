GraniteCave_B2F_MapScripts::
	.byte 0

GraniteCave_B2F_Louis::
	trainerbattle_single TRAINER_LOUIS, GraniteCave_B2F_Text_LouisIntro, GraniteCave_B2F_Text_LouisDefeated
	msgbox GraniteCave_B2F_Text_LouisPostBattle, MSGBOX_AUTOCLOSE
	end


GraniteCave_B2F_Text_LouisIntro:
    .string "My campaign has been running for\n"
    .string "over 5 years now.$"

GraniteCave_B2F_Text_LouisDefeated:
    .string "You don't want to join?$"

GraniteCave_B2F_Text_LouisPostBattle:
    .string "...$"

