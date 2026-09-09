RustboroCity_Flat1_1F_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_Flat1_SetFires
	.byte 0

RustboroCity_Flat1_1F_EventScript_Man::
	msgbox RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_EventScript_Woman::
	msgbox RustboroCity_Flat1_1F_Text_PokemonStrange, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility:
	.string "Every POKéMON has a special ability\n"
	.string "that it can use.$"

RustboroCity_Flat1_1F_Text_PokemonStrange:
	.string "POKéMON are such strange creatures.$"


RustboroCity_Flat1_FireInteract::
    lock
    goto_if_set FLAG_RECEIVED_WAILMER_PAIL, RustboroCity_Flat1_PutOutFire
    msgbox RustboroCity_Flat1_Text_FireHot, MSGBOX_DEFAULT
    release
    end

RustboroCity_Flat1_PutOutFire::
    msgbox RustboroCity_Flat1_Text_FireHot, MSGBOX_DEFAULT
    msgbox RustboroCity_Flat1_Text_FireInteract, MSGBOX_YES_NO
    call_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_PutOutFireForReal

RustboroCity_Flat1_PutOutFireForReal::
    msgbox RustboroCity_Flat1_Text_FireInteract2, MSGBOX_DEFAULT
    playse SE_PIN  @Temp sound
    special DoWateringBerryTreeAnim
    delay 20
    removeobject VAR_LAST_TALKED
    addvar VAR_RUSTBORO_FIRES_EXTINGUISHED, 1
    call_if_eq VAR_RUSTBORO_FIRES_EXTINGUISHED, 10, RustboroCity_Flat1_YouSavedUs
    end

RustboroCity_Flat1_YouSavedUs::

    end

RustboroCity_Flat1_SetFires::
    goto_if_eq VAR_RUSTBORO_FIRES_EXTINGUISHED, 10, RustboroCity_Flat1_DeleteFire10
    goto_if_eq VAR_RUSTBORO_FIRES_EXTINGUISHED, 9, RustboroCity_Flat1_DeleteFire9
    goto_if_eq VAR_RUSTBORO_FIRES_EXTINGUISHED, 8, RustboroCity_Flat1_DeleteFire8
    goto_if_eq VAR_RUSTBORO_FIRES_EXTINGUISHED, 7, RustboroCity_Flat1_DeleteFire7
    goto_if_eq VAR_RUSTBORO_FIRES_EXTINGUISHED, 6, RustboroCity_Flat1_DeleteFire6
    goto_if_eq VAR_RUSTBORO_FIRES_EXTINGUISHED, 5, RustboroCity_Flat1_DeleteFire5
    goto_if_eq VAR_RUSTBORO_FIRES_EXTINGUISHED, 4, RustboroCity_Flat1_DeleteFire4
    goto_if_eq VAR_RUSTBORO_FIRES_EXTINGUISHED, 3, RustboroCity_Flat1_DeleteFire3
    goto_if_eq VAR_RUSTBORO_FIRES_EXTINGUISHED, 2, RustboroCity_Flat1_DeleteFire2
    goto_if_eq VAR_RUSTBORO_FIRES_EXTINGUISHED, 1, RustboroCity_Flat1_DeleteFire1
    end

RustboroCity_Flat1_LockedDoor::
    goto_if_unset FLAG_ITM_DOOR_UNLOCKED, RustboroCity_Flat1_LockedDoor2
    end

RustboroCity_Flat1_LockedDoor2::
    msgbox RustboroCity_Flat1_Text_DoorLocked, MSGBOX_DEFAULT
    end

RustboroCity_Flat1_DeleteFire10::
    removeobject 10

RustboroCity_Flat1_DeleteFire9::
    removeobject 6

RustboroCity_Flat1_DeleteFire8::
    removeobject 14

RustboroCity_Flat1_DeleteFire7::
    removeobject 13

RustboroCity_Flat1_DeleteFire6::
    removeobject 8

RustboroCity_Flat1_DeleteFire5::
    removeobject 15

RustboroCity_Flat1_DeleteFire4::
    removeobject 7

RustboroCity_Flat1_DeleteFire3::
    removeobject 12

RustboroCity_Flat1_DeleteFire2::
    removeobject 5

RustboroCity_Flat1_DeleteFire1::
    removeobject 11
    end

RustboroCity_Flat1_Text_FireHot:
    .string "The fire is extremely hot!$"

RustboroCity_Flat1_Text_FireInteract:
    .string "Use the WAILMER PAIL to put out\n"
    .string "the fire?$"

RustboroCity_Flat1_Text_FireInteract2:
    .string "You used the WAILMER PAIL.\l"
    .string "The fire goes out.$"

RustboroCity_Flat1_Text_DoorLocked:
    .string "(People outside are blocking\nthe doors.)$"



