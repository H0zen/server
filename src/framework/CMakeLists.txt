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

include(TestBigEndian)
test_big_endian(IS_BIG_ENDIAN)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/SystemConfig.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/SystemConfig.h
)

add_library(framework STATIC
  Dynamic/FactoryHolder.h
  Dynamic/ObjectRegistry.h
  GameSystem/Grid.h
  GameSystem/GridLoader.h
  GameSystem/GridRefManager.h
  GameSystem/GridReference.h
  GameSystem/NGrid.h
  GameSystem/TypeContainer.h
  GameSystem/TypeContainerVisitor.h
  Policies/CreationPolicy.h
  Policies/ObjectLifeTime.cpp
  Policies/ObjectLifeTime.h
  Policies/Singleton.h
  Policies/ThreadingModel.h
  Utilities/ByteConverter.h
  Utilities/Callback.h
  Utilities/EventProcessor.cpp
  Utilities/EventProcessor.h
  Utilities/LinkedList.h
  Utilities/LinkedReference/RefManager.h
  Utilities/LinkedReference/Reference.h
  Utilities/TypeList.h
  Utilities/UnorderedMapSet.h
  Utilities/ByteBuffer.cpp
  Utilities/ByteBuffer.h
  Utilities/Errors.h
  Utilities/ProgressBar.cpp
  Utilities/ProgressBar.h
  Utilities/RNGen.h
  Utilities/Timer.h
  Utilities/Util.cpp
  Utilities/Util.h
  Utilities/WorldPacket.h
  Auth/ARC4.cpp
  Auth/ARC4.h
  Auth/AuthCrypt.cpp
  Auth/AuthCrypt.h
  Auth/BigNumber.cpp
  Auth/BigNumber.h
  Auth/HMACSHA1.cpp
  Auth/HMACSHA1.h
  Auth/Sha1.cpp
  Auth/Sha1.h
  Auth/WardenKeyGeneration.h
  Auth/md5.h
  Auth/md5.cpp
  Common/Common.h
  Common/Define.h
  Config/Config.cpp
  Config/Config.h
  DataStores/DBCFileLoader.cpp
  DataStores/DBCFileLoader.h
  DataStores/DBCStore.h
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
  Database/SQLStorage.cpp
  Database/SQLStorage.h
  Database/SQLStorageImpl.h
  Database/SqlDelayThread.cpp
  Database/SqlDelayThread.h
  Database/SqlOperations.cpp
  Database/SqlOperations.h
  Database/SqlPreparedStatement.cpp
  Database/SqlPreparedStatement.h
  LockedQueue/LockedQueue.h
  Log/Log.cpp
  Log/Log.h
  Threading/DelayExecutor.cpp
  Threading/DelayExecutor.h
  Threading/Threading.cpp
  Threading/Threading.h
  SystemConfig.h.in
  revision.h
  Locale/Locale.h
  Locale/Locale.cpp
  #Service/ServiceWin32.cpp
  #Service/ServiceWin32.h
  Service/PosixDaemon.cpp
  Service/PosixDaemon.h
  ${CMAKE_CURRENT_BINARY_DIR}/SystemConfig.h
)

target_include_directories(framework
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR}
)

target_compile_definitions(framework
    PUBLIC
        $<$<CONFIG:Debug>:MANGOS_DEBUG>
        MANGOS_ENDIAN=${IS_BIG_ENDIAN}
)

target_link_libraries(framework
    PUBLIC
        ace
        utf8
        OpenSSL::Crypto
        MySQL::MySQL
)
