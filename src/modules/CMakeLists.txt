# MaNGOS is a full featured server for World of Warcraft, supporting
# the following clients: 1.12.x, 2.4.3, 3.3.5a, 4.3.4a and 5.4.8
#
# Copyright (C) 2005-2019  MaNGOS project <https://getmangos.eu>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

# Build the mangos script library if enabled
if(SCRIPT_LIB_SD3)
    add_subdirectory(SD3)
endif()

# Build the Eluna library if enabled
if(SCRIPT_LIB_ELUNA)

set(ELUNA_FILES
    Eluna/AuraMethods.h
    Eluna/BattleGroundHooks.cpp
    Eluna/BattleGroundMethods.h
    Eluna/BindingMap.h
    Eluna/CorpseMethods.h
    Eluna/CreatureHooks.cpp
    Eluna/CreatureMethods.h
    Eluna/ElunaCreatureAI.h
    Eluna/ElunaEventMgr.cpp
    Eluna/ElunaEventMgr.h
    Eluna/ElunaIncludes.h
    Eluna/ElunaInstanceAI.cpp
    Eluna/ElunaInstanceAI.h
    Eluna/ElunaQueryMethods.h
    Eluna/ElunaTemplate.h
    Eluna/ElunaUtility.cpp
    Eluna/ElunaUtility.h
    Eluna/GameObjectHooks.cpp
    Eluna/GameObjectMethods.h
    Eluna/GlobalMethods.h
    Eluna/GossipHooks.cpp
    Eluna/GroupHooks.cpp
    Eluna/GroupMethods.h
    Eluna/GuildHooks.cpp
    Eluna/GuildMethods.h
    Eluna/HookHelpers.h
    Eluna/Hooks.h
    Eluna/InstanceHooks.cpp
    Eluna/ItemHooks.cpp
    Eluna/ItemMethods.h
    Eluna/lmarshal.cpp
    Eluna/lmarshal.h
    Eluna/LuaEngine.cpp
    Eluna/LuaEngine.h
    Eluna/LuaFunctions.cpp
    Eluna/MapMethods.h
    Eluna/ObjectMethods.h
    Eluna/PacketHooks.cpp
    Eluna/PlayerHooks.cpp
    Eluna/PlayerMethods.h
    Eluna/QuestMethods.h
    Eluna/ServerHooks.cpp
    Eluna/SpellMethods.h
    Eluna/UnitMethods.h
    Eluna/VehicleHooks.cpp
    Eluna/VehicleMethods.h
    Eluna/WorldObjectMethods.h
    Eluna/WorldPacketMethods.h
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ELUNA_FILES})

add_library(ElunaIntf INTERFACE)
target_include_directories(ElunaIntf INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Eluna)

add_library(Eluna STATIC ${ELUNA_FILES})

target_link_libraries(Eluna
    PUBLIC
		game
)

endif()

# Include Player Bots if enabled
if(PLAYERBOTS)
    add_subdirectory(Bots)
endif()