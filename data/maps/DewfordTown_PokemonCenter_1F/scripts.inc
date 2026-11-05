DewfordTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

DewfordTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_DEWFORD_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

DewfordTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_DEWFORD_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

DewfordTown_PokemonCenter_1F_EventScript_PokefanF::
	msgbox DewfordTown_PokemonCenter_1F_Text_StoneCavern, MSGBOX_NPC
	end

DewfordTown_PokemonCenter_1F_EventScript_Man::
	msgbox DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM, MSGBOX_NPC
	end

DewfordTown_PokemonCenter_1F_Text_StoneCavern:
	.string "Did you know GRAY is Mr. Briney's\n"
	.string "Grandson? He took over after\l"
	.string "Mr. Briney, well… You know…\p"
	.string "Although GRAY charges for his fares,\n"
	.string "that money is going towards buying a\l"
	.string "new boat - or so I heard!\p"
	.string "The old boat is looking a bit old…$"

DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM:
	.string "Did you know that if a POKéMON faints\n"
	.string "and can't battle, it can still use a\l"
	.string "HM? This is because you pick up said\p"
	.string "POKéMON and bash the obstacle until its\n"
	.string "gone!$"

