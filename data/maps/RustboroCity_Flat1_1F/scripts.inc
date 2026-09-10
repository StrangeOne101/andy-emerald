RustboroCity_Flat1_1F_MapScripts::
    map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_Flat1_SetFires
	.byte 0


RustboroCity_Flat1_FireInteract1::
    setvar VAR_TEMP_2, FLAG_TEMP_1
    goto RustboroCity_Flat1_FireInteract

RustboroCity_Flat1_FireInteract2::
    setvar VAR_TEMP_2, FLAG_TEMP_2
    goto RustboroCity_Flat1_FireInteract

RustboroCity_Flat1_FireInteract3::
    setvar VAR_TEMP_2, FLAG_TEMP_3
    goto RustboroCity_Flat1_FireInteract

RustboroCity_Flat1_FireInteract4::
    setvar VAR_TEMP_2, FLAG_TEMP_4
    goto RustboroCity_Flat1_FireInteract

RustboroCity_Flat1_FireInteract5::
    setvar VAR_TEMP_2, FLAG_TEMP_5
    goto RustboroCity_Flat1_FireInteract

RustboroCity_Flat1_FireInteract6::
    setvar VAR_TEMP_2, FLAG_TEMP_6
    goto RustboroCity_Flat1_FireInteract

RustboroCity_Flat1_FireInteract7::
    setvar VAR_TEMP_2, FLAG_TEMP_7
    goto RustboroCity_Flat1_FireInteract

RustboroCity_Flat1_FireInteract8::
    setvar VAR_TEMP_2, FLAG_TEMP_8
    goto RustboroCity_Flat1_FireInteract

RustboroCity_Flat1_FireInteract9::
    setvar VAR_TEMP_2, FLAG_TEMP_9
    goto RustboroCity_Flat1_FireInteract

RustboroCity_Flat1_FireInteract10::
    setvar VAR_TEMP_2, FLAG_TEMP_10
    goto RustboroCity_Flat1_FireInteract

RustboroCity_Flat1_FireInteract11::
   setvar VAR_TEMP_2, FLAG_TEMP_11
   goto RustboroCity_Flat1_FireInteract

RustboroCity_Flat1_FireInteract::
    lock
    goto_if_set FLAG_RECEIVED_WAILMER_PAIL, RustboroCity_Flat1_PutOutFire
    msgbox RustboroCity_Flat1_Text_FireHot, MSGBOX_SIGN
    closemessage
    release
    end

RustboroCity_Flat1_PutOutFire::
    msgbox RustboroCity_Flat1_Text_FireHot, MSGBOX_SIGN
    closemessage
    msgbox RustboroCity_Flat1_Text_FireInteract, MSGBOX_YESNO
    goto_if_eq VAR_RESULT, YES, RustboroCity_Flat1_PutOutFireForReal
    release
    end

RustboroCity_Flat1_PutOutFireForReal::
    msgbox RustboroCity_Flat1_Text_FireInteract2, MSGBOX_SIGN
    closemessage
    playse SE_PUDDLE  @Temp sound
    special DoWateringBerryTreeAnim
    removeobject VAR_LAST_TALKED
    applymovement VAR_LAST_TALKED, Common_Movement_SetInvisible
    setflag VAR_TEMP_2
    msgbox RustboroCity_Flat1_Text_FireInteract3, MSGBOX_SIGN
    closemessage
    addvar VAR_RUSTBORO_FIRES_EXTINGUISHED, 1
    call_if_eq VAR_RUSTBORO_FIRES_EXTINGUISHED, 11, RustboroCity_Flat1_YouSavedUs
    release
    end

RustboroCity_Flat1_YouSavedUs::
    setobjectmovementtype 1, MOVEMENT_TYPE_WANDER_AROUND
    setobjectmovementtype 4, MOVEMENT_TYPE_WANDER_AROUND
    setobjectmovementtype 2, MOVEMENT_TYPE_LOOK_AROUND
    setobjectmovementtype 3, MOVEMENT_TYPE_LOOK_AROUND
    msgbox RustboroCity_Flat1_Text_YouSavedUs1, MSGBOX_DEFAULT
    closemessage
    end

RustboroCity_Flat1_SetFires::
    goto_if_eq VAR_RUSTBORO_FIRES_EXTINGUISHED, 11, RustboroCity_Flat1_DeleteFire11
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

RustboroCity_Flat1_DeleteFire11::
    removeobject 10
    setflag FLAG_TEMP_11

RustboroCity_Flat1_DeleteFire10::
    removeobject 6
    setflag FLAG_TEMP_10

RustboroCity_Flat1_DeleteFire9::
    removeobject 14
    setflag FLAG_TEMP_9

RustboroCity_Flat1_DeleteFire8::
    removeobject 13
    setflag FLAG_TEMP_8

RustboroCity_Flat1_DeleteFire7::
    removeobject 9
    setflag FLAG_TEMP_7

RustboroCity_Flat1_DeleteFire6::
    removeobject 8
    setflag FLAG_TEMP_6

RustboroCity_Flat1_DeleteFire5::
    removeobject 15
    setflag FLAG_TEMP_5

RustboroCity_Flat1_DeleteFire4::
    removeobject 7
    setflag FLAG_TEMP_4

RustboroCity_Flat1_DeleteFire3::
    removeobject 12
    setflag FLAG_TEMP_3

RustboroCity_Flat1_DeleteFire2::
    removeobject 5
    setflag FLAG_TEMP_2

RustboroCity_Flat1_DeleteFire1::
    removeobject 11
    setflag FLAG_TEMP_1
    end

RustboroCity_Flat1_RightPerson::
    goto_if_eq VAR_RUSTBORO_FIRES_EXTINGUISHED, 10, RustboroCity_Flat1_WrongPerson2
    end

RustboroCity_Flat1_RightPerson2::
    lock
    faceplayer
    goto_if_eq VAR_RUSTBORO_CITY_STATE, 2, RustboroCity_Flat1_RightPerson3
    msgbox RustboroCity_Flat1_Text_RightPerson, MSGBOX_NPC
    playfanfare MUS_OBTAIN_ITEM
    message RustboroCity_Flat1_Text_GetKey
    waitfanfare
    setvar VAR_RUSTBORO_CITY_STATE, 2
    release
    end

RustboroCity_Flat1_RightPerson3::
    msgbox RustboroCity_Flat1_Text_RightPerson2, MSGBOX_NPC
    delay 20
    msgbox RustboroCity_Flat1_Text_RightPerson3, MSGBOX_DEFAULT
    release
    end

RustboroCity_Flat1_WrongPerson::
    goto_if_eq VAR_RUSTBORO_FIRES_EXTINGUISHED, 10, RustboroCity_Flat1_WrongPerson2
    lock
    msgbox RustboroCity_Flat1_Text_WrongPerson1OnFire, MSGBOX_NPC
    release
    end

RustboroCity_Flat1_WrongPerson2::
    lock
    call_if_eq VAR_TEMP_1, 0, RustboroCity_Flat1_WrongPersonMsg1
    call_if_eq VAR_TEMP_1, 1, RustboroCity_Flat1_WrongPersonMsg2
    call_if_eq VAR_TEMP_1, 2, RustboroCity_Flat1_WrongPersonMsg3
    call_if_gt VAR_TEMP_1, 2, RustboroCity_Flat1_WrongPersonMsg4
    addvar VAR_TEMP_1, 1
    release
    end

RustboroCity_Flat1_WrongPersonMsg1::
    msgbox RustboroCity_Flat1_Text_WrongPerson1, MSGBOX_NPC
    end

RustboroCity_Flat1_WrongPersonMsg2::
    msgbox RustboroCity_Flat1_Text_WrongPerson2, MSGBOX_NPC
    end

RustboroCity_Flat1_WrongPersonMsg3::
    msgbox RustboroCity_Flat1_Text_WrongPerson3, MSGBOX_NPC
    end

RustboroCity_Flat1_WrongPersonMsg4::
    msgbox RustboroCity_Flat1_Text_WrongPerson4, MSGBOX_NPC
    end

RustboroCity_Flat1_Text_FireHot:
    .string "The fire is extremely hot!$"

RustboroCity_Flat1_Text_FireInteract:
    .string "Use the WAILMER PAIL to put out\n"
    .string "the fire?$"

RustboroCity_Flat1_Text_FireInteract2:
    .string "You used the WAILMER PAIL.$"
RustboroCity_Flat1_Text_FireInteract3:
    .string "The fire goes out.$"

RustboroCity_Flat1_Text_DoorLocked:
    .string "(People outside are blocking\nthe doors.)$"

RustboroCity_Flat1_Text_YouSavedUs1:
    .string "You saved us! Thank you,\n"
    .string "thank you!\p"
    .string "How can we ever repay you?\p"
    .string "Since you are so good at helping\n"
    .string "people, why don't you try find\l"
    .string "the person who dropped this?\p"
    .string "A customer dropped it in the store.\n"
    .string "It seems to be some kind of key!\p"
    .string "Come grab it off me!$"

RustboroCity_Flat1_Text_WrongPerson1OnFire:
    .string "Help us!$"

RustboroCity_Flat1_Text_WrongPerson1:
    .string "Wrong person.$"
RustboroCity_Flat1_Text_WrongPerson2:
    .string "Wrong person again.$"
RustboroCity_Flat1_Text_WrongPerson3:
    .string "Still the wrong person!$"
RustboroCity_Flat1_Text_WrongPerson4:
    .string "How are you so bad at this?!$"
RustboroCity_Flat1_Text_RightPerson:
    .string "Finally! Here you go!$"
RustboroCity_Flat1_Text_RightPerson2:
    .string "Go on, then! Go find the key\n"
    .string "owner!$"
RustboroCity_Flat1_Text_RightPerson3:
    .string "(She definitely belongs in an ITM.\n"
    .string "What a tool.)$"
RustboroCity_Flat1_Text_GetKey:
    .string "Andrew got the Mysterious Key!$"



