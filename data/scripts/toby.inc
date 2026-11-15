TobyProgress_Text_True::
    .string "{COLOR GREEN}{CIRCLE_HOLLOW}{COLOR DARK_GRAY}$"
TobyProgress_Text_False::
    .string "{COLOR RED}{BIG_MULT_X}{COLOR DARK_GRAY}$"

TobyProgress_Common_LoadTrue1::
    bufferstring STR_VAR_1, TobyProgress_Text_True
    setflag FLAG_TEMP_2
    return
    end
TobyProgress_Common_LoadFalse1::
    bufferstring STR_VAR_1, TobyProgress_Text_False
    setflag FLAG_TEMP_2
    return
    end
TobyProgress_Common_LoadTrue2::
    bufferstring STR_VAR_2, TobyProgress_Text_True
    clearflag FLAG_TEMP_2
    return
    end
TobyProgress_Common_LoadFalse2::
    bufferstring STR_VAR_2, TobyProgress_Text_False
    clearflag FLAG_TEMP_2
    return
    end

TobyProgress_Common_LoadTrue::
    call_if_unset FLAG_TEMP_2, TobyProgress_Common_LoadTrue1
    call_if_set FLAG_TEMP_2, TobyProgress_Common_LoadTrue2
    return
    end

TobyProgress_Common_LoadFalse::
    call_if_unset FLAG_TEMP_2, TobyProgress_Common_LoadFalse1
    call_if_set FLAG_TEMP_2, TobyProgress_Common_LoadFalse2
    return
    end

TobyProgress_List::
    setflag FLAG_TEMP_2
    call_if_set FLAG_TRAINER_TOBY_ROUTE_101, TobyProgress_Common_LoadTrue
    call_if_unset FLAG_TRAINER_TOBY_ROUTE_101, TobyProgress_Common_LoadFalse
    message TobyProgress_Text_List1
    waitmessage
    waitbuttonpress
    call_if_set FLAG_TRAINER_TOBY_ROUTE_102, TobyProgress_Common_LoadTrue
    call_if_unset FLAG_TRAINER_TOBY_ROUTE_102, TobyProgress_Common_LoadFalse
    call_if_set FLAG_TRAINER_TOBY_ODALE_TOWN, TobyProgress_Common_LoadTrue
    call_if_unset FLAG_TRAINER_TOBY_ODALE_TOWN, TobyProgress_Common_LoadFalse
    message TobyProgress_Text_List2
    waitmessage
    waitbuttonpress
    call_if_set FLAG_TRAINER_TOBY_PETALBURG_CITY, TobyProgress_Common_LoadTrue
    call_if_unset FLAG_TRAINER_TOBY_PETALBURG_CITY, TobyProgress_Common_LoadFalse
    call_if_set FLAG_TRAINER_TOBY_ROUTE_104, TobyProgress_Common_LoadTrue
    call_if_unset FLAG_TRAINER_TOBY_ROUTE_104, TobyProgress_Common_LoadFalse
    message TobyProgress_Text_List3
    waitbuttonpress
    call_if_set FLAG_TRAINER_TOBY_PETALBURG_WOODS, TobyProgress_Common_LoadTrue
    call_if_unset FLAG_TRAINER_TOBY_PETALBURG_WOODS, TobyProgress_Common_LoadFalse
    call_if_set FLAG_TRAINER_TOBY_RUSTBORO_CITY, TobyProgress_Common_LoadTrue
    call_if_unset FLAG_TRAINER_TOBY_RUSTBORO_CITY, TobyProgress_Common_LoadFalse
    message TobyProgress_Text_List4
    waitbuttonpress
    call_if_set FLAG_TRAINER_TOBY_ROUTE_115, TobyProgress_Common_LoadTrue
    call_if_unset FLAG_TRAINER_TOBY_ROUTE_115, TobyProgress_Common_LoadFalse
    call_if_set FLAG_TRAINER_TOBY_ROUTE_116, TobyProgress_Common_LoadTrue
    call_if_unset FLAG_TRAINER_TOBY_ROUTE_116, TobyProgress_Common_LoadFalse
    message TobyProgress_Text_List5
    waitbuttonpress
    call_if_set FLAG_TRAINER_TOBY_DEWFORD, TobyProgress_Common_LoadTrue
    call_if_unset FLAG_TRAINER_TOBY_DEWFORD, TobyProgress_Common_LoadFalse
    call_if_set FLAG_TRAINER_TOBY_SLATEPORT_CITY, TobyProgress_Common_LoadTrue
    call_if_unset FLAG_TRAINER_TOBY_SLATEPORT_CITY, TobyProgress_Common_LoadFalse
    message TobyProgress_Text_List7
    waitbuttonpress
    msgbox TobyProgress_Text_List8, MSGBOX_DEFAULT
    closemessage
    end

TobyProgress_Text_List1::
    .string "LIST OF TOBYS FOUND\n"
    .string "ROUTE 101 {STR_VAR_2}$"

TobyProgress_Text_List2::
    .string "ODALE TOWN {STR_VAR_1}\n"
    .string "ROUTE 102 {STR_VAR_2}$"

TobyProgress_Text_List3::
    .string "PETALBURG CITY {STR_VAR_1}\n"
    .string "ROUTE 104 {STR_VAR_2}$"
TobyProgress_Text_List4::
    .string "PETALBURG WOODS {STR_VAR_1}\n"
    .string "RUSTBORO CITY {STR_VAR_2}$"
TobyProgress_Text_List5::
    .string "ROUTE 115 {STR_VAR_1}\n"
    .string "ROUTE 116 {STR_VAR_2}$"
TobyProgress_Text_List7::
    .string "DEWFORD TOWN {STR_VAR_1}\n"
    .string "SLATEPORT CITY {STR_VAR_2}$"

TobyProgress_Text_List8::
    .string "(The remaining pages are\n"
    .string "blank)$"
