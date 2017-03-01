/*
 *  Copyright (C) 2010-2017 Fabio Cavallo (aka FHorse)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef MAPPER_215_H_
#define MAPPER_215_H_

#include "common.h"

enum { M215_MK3E };

struct _m215 {
	BYTE reg[4];
	WORD prg_8k_bank[4];
} m215;

void map_init_215(void);
void extcl_cpu_wr_mem_215(WORD address, BYTE value);
BYTE extcl_save_mapper_215(BYTE mode, BYTE slot, FILE *fp);

#endif /* MAPPER_215_H_ */
