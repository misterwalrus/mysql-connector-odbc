#ifndef MYSYS_MY_STATIC_INCLUDED
#define MYSYS_MY_STATIC_INCLUDED

// Copyright (c) 2000, 2015, Oracle and/or its affiliates. All rights reserved. 
// 
// This program is free software; you can redistribute it and/or modify 
// it under the terms of the GNU General Public License, version 2.0, as 
// published by the Free Software Foundation. 
// 
// This program is also distributed with certain software (including 
// but not limited to OpenSSL) that is licensed under separate terms, 
// as designated in a particular file or component or in included license 
// documentation. The authors of MySQL hereby grant you an 
// additional permission to link the program and your derivative works 
// with the separately licensed software that they have included with 
// MySQL. 
// 
// Without limiting anything contained in the foregoing, this file, 
// which is part of <MySQL Product>, is also subject to the 
// Universal FOSS Exception, version 1.0, a copy of which can be found at 
// http://oss.oracle.com/licenses/universal-foss-exception. 
// 
// This program is distributed in the hope that it will be useful, but 
// WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
// See the GNU General Public License, version 2.0, for more details. 
// 
// You should have received a copy of the GNU General Public License 
// along with this program; if not, write to the Free Software Foundation, Inc., 
// 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA 

/*
  Static variables for mysys library. All definied here for easy making of
  a shared library
*/

#include "my_global.h"
#include "my_sys.h"

C_MODE_START
extern char sys_curr_dir[FN_REFLEN], sys_home_dir_buff[FN_REFLEN];

extern const char *soundex_map;

extern USED_MEM* mysys_once_root_block;
extern uint	 mysys_once_extra;

extern struct st_my_file_info my_file_info_default[MY_NFILE];

extern ulonglong query_performance_frequency, query_performance_offset;

C_MODE_END

#endif /* MYSYS_MY_STATIC_INCLUDED */