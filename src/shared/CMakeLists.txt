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


set(SRC_GRP_AUTH
  Auth/ARC4.cpp
  Auth/ARC4.h
  Auth/AuthCrypt.cpp
  Auth/AuthCrypt.h
  Auth/BigNumber.cpp
  Auth/BigNumber.h
  Auth/HMACSHA1.cpp
  Auth/HMACSHA1.h
  Auth/md5.cpp
  Auth/md5.h
  Auth/Sha1.cpp
  Auth/Sha1.h
  Auth/WardenKeyGeneration.h
)


set(SRC_GRP_COMMON
  Common/Common.cpp
  Common/Common.h
  Common/ServerDefines.h
)


set(SRC_GRP_CONFIG
  Config/Config.cpp
  Config/Config.h
)


set(SRC_GRP_DATABASE
  Database/Database.cpp
  Database/Database.h
  Database/DatabaseEnv.h
  Database/DatabaseImpl.h
  Database/DatabaseMysql.cpp
  Database/DatabaseMysql.h
  Database/DatabasePostgre.cpp
  Database/DatabasePostgre.h
  Database/Field.cpp
  Database/Field.h
  Database/PGSQLDelayThread.h
  Database/QueryResult.h
  Database/QueryResultMysql.cpp
  Database/QueryResultMysql.h
  Database/QueryResultPostgre.cpp
  Database/QueryResultPostgre.h
  Database/SqlDelayThread.cpp
  Database/SqlDelayThread.h
  Database/SqlOperations.cpp
  Database/SqlOperations.h
  Database/SqlPreparedStatement.cpp
  Database/SqlPreparedStatement.h
  Database/SQLStorage.cpp
  Database/SQLStorage.h
  Database/SQLStorageImpl.h
)


set(SRC_GRP_DATASTORE
  DataStores/DBCFileLoader.cpp
  DataStores/DBCFileLoader.h
  DataStores/DBCStore.h
)


set(SRC_GRP_DYNAMIC
  Dynamic/FactoryHolder.h
  Dynamic/ObjectRegistry.h
)


set(SRC_GRP_GSYS
  GameSystem/Grid.h
  GameSystem/GridLoader.h
  GameSystem/GridReference.h
  GameSystem/GridRefManager.h
  GameSystem/NGrid.h
  GameSystem/TypeContainer.h
  GameSystem/TypeContainerVisitor.h
)


if(NOT WIN32)
  set(SRC_GRP_SERVICE
    Linux/PosixDaemon.cpp
    Linux/PosixDaemon.h
)
else()
  set(SRC_GRP_SERVICE
    Win/ServiceWin32.cpp
    Win/ServiceWin32.h
)
endif()


set(SRC_GRP_LOCKQ
  LockedQueue/LockedQueue.h
)


set(SRC_GRP_LOG
  Log/Log.cpp
  Log/Log.h
)


set(SRC_GRP_PLATFORM
  Platform/CompilerDefs.h
  Platform/Define.h
)


set(SRC_GRP_POL
  Policies/CreationPolicy.h
  Policies/ObjectLifeTime.cpp
  Policies/ObjectLifeTime.h
  Policies/Singleton.h
  Policies/ThreadingModel.h
)


set(SRC_GRP_THREAD
  Threading/DelayExecutor.cpp
  Threading/DelayExecutor.h
  Threading/Threading.cpp
  Threading/Threading.h
)


set(SRC_GRP_UTIL
  Utilities/ByteBuffer.cpp
  Utilities/ByteBuffer.h
  Utilities/ByteConverter.h
  Utilities/Callback.h
  Utilities/Errors.h
  Utilities/EventProcessor.cpp
  Utilities/EventProcessor.h
  Utilities/LinkedList.h
  Utilities/LinkedReference/Reference.h
  Utilities/LinkedReference/RefManager.h
  Utilities/ProgressBar.cpp
  Utilities/ProgressBar.h
  Utilities/RNGen.h
  Utilities/Timer.h
  Utilities/TypeList.h
  Utilities/UnorderedMapSet.h
  Utilities/Util.cpp
  Utilities/Util.h
  Utilities/WorldPacket.h
)

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/SystemConfig.h.in" "${CMAKE_CURRENT_BINARY_DIR}/SystemConfig.h")

set(LIB_SRC
    ${SRC_GRP_AUTH}
	${SRC_GRP_COMMON}
	${SRC_GRP_CONFIG}
	${SRC_GRP_DATABASE}
	${SRC_GRP_DATASTORE}
	${SRC_GRP_DATABASE}
	${SRC_GRP_DYNAMIC}
	${SRC_GRP_GSYS}
	${SRC_GRP_LOCKQ}
	${SRC_GRP_LOG}
	${SRC_GRP_PLATFORM}
	${SRC_GRP_POL}
	${SRC_GRP_SERVICE}
	${SRC_GRP_THREAD}
	${SRC_GRP_UTIL}
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${LIB_SRC})

add_library(share STATIC
    ${LIB_SRC}
	${CMAKE_CURRENT_BINARY_DIR}/SystemConfig.h
    revision.h
)

target_include_directories(share
    PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}
      ${CMAKE_CURRENT_BINARY_DIR}
	  Common
	  Utilities
	  Log
	  Auth
)

target_link_libraries(share
    PUBLIC
	    ace
		TomLib::Crypt
		TomLib::Auth
		utf8
)

if(POSTGRESQL)
target_link_libraries(share
    PUBLIC
        PostgreSQL::PostgreSQL
)
else()
target_link_libraries(share
    PUBLIC
        MySQL::MySQL
)
endif()