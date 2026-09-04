PetalburgCity_House1_MapScripts::
	.byte 0

PetalburgCity_House1_EventScript_Man::
    lock
    faceplayer
    goto_if_set FLAG_SYS_NATIONAL_DEX, PetalburgCity_House1_SamsonOakAfter
	msgbox PetalburgCity_House1_Text_TravelingIsWonderful, MSGBOX_NPC
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex
	setflag FLAG_SYS_NATIONAL_DEX
    special EnableNationalPokedex
    msgbox PetalburgCity_House1_Text_SamsonOakGreeting2, MSGBOX_NPC
    release
	end

PetalburgCity_House1_EventScript_Woman::
	msgbox PetalburgCity_House1_Text_GoOnAdventure, MSGBOX_NPC
	end

Common_EventScript_Bewear::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_BEWEAR, CRY_MODE_NORMAL
    msgbox PetalburgCity_House1_Text_Bewear, MSGBOX_DEFAULT
    waitmoncry
    release
    end

PetalburgCity_House1_SamsonOakAfter::
    msgbox PetalburgCity_House1_Text_SamsonOakChill, MSGBOX_NPC
    release
    end

PetalburgCity_House1_Text_SamsonOakGreeting:
	.string "Oh, hello there!\p"
	.string "My name is Samson Oak. I'm visiting\n"
	.string "HOENN for a bit!\p"
	.string "Normally, I live in the ALOLA region.\n"
	.string "But my cousin Professor Oak asked\p"
	.string "me to come to HOENN for a bit as\n"
	.string "the professor that was here went\l"
	.string "missing.\p"
	.string "Have you seen them at all?\p"
	.string "Oh, and I see you have a POKéMON\n"
	.string "with you! And not one from the\l"
	.string "HOENN region, either!\p"
	.string "Do you have a POKéDEX? I am\n"
	.string "meant to give them out in place\p"
	.string "of the professor. Here,\l"
	.string "take one!$"

PetalburgCity_House1_Text_SamsonOakGreeting2:
    .string "There! They are pretty simple to\n"
    .string "use! Just catch a POKéMON and\l"
    .string "it will do the rest!\p"
    .string "Make sure to pick up some\n"
    .string "POKéBALLS at the POKéMART!$"

PetalburgCity_House1_Text_SamsonOakChill:
    .string "Best of luck!$"

PetalburgCity_House1_Text_GoOnAdventure:
	.string "Samson Oak and I traveled all\n"
	.string "the way here from ALOLA.\p"
	.string "That BEWEAR over there is also\n"
	.string "from ALOLA!"

PetalburgCity_House1_Text_Bewear:
    .string "Weaaaarr…$"

