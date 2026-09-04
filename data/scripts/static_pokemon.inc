EventScript_RemoveStaticMon::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

EventScript_MonFlewAway::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox Text_MonFlewAway
	release
	end

EventScript_AwakenSnorlax::
	message Text_PlayedPokeFlute
	waitmessage
	playfanfare MUS_RG_POKE_FLUTE
	waitfanfare
	msgbox Text_SnorlaxWokeUp
	return

Common_EventScript_Marill::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_MARILL, CRY_MODE_NORMAL
    msgbox Common_Text_Marill, MSGBOX_DEFAULT
    waitmoncry
    release
    end

Common_Text_Marill:
    .string "Marill!$"

Common_EventScript_Skitty::
    lock
    faceplayer
    waitse
    playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
    msgbox Common_Text_Skitty, MSGBOX_DEFAULT
    waitmoncry
    release
    end

Common_Text_Marill:
    .string "Skiii!$"

