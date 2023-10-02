/*
 *  Copyright (C) 2010-2023 Fabio Cavallo (aka FHorse)
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

#include "mappers.h"
#include "save_slot.h"

INLINE static void prg_fix_060(void);
INLINE static void chr_fix_060(void);

struct _m060 {
	BYTE index;
} m060;

void map_init_060(void) {
	EXTCL_AFTER_MAPPER_INIT(060);
	EXTCL_CPU_WR_MEM(060);
	EXTCL_SAVE_MAPPER(060);
	mapper.internal_struct[0] = (BYTE *)&m060;
	mapper.internal_struct_size[0] = sizeof(m060);

	m060.index = info.reset >= HARD ? 0 : m060.index + 1;
}
void extcl_after_mapper_init_060(void) {
	prg_fix_060();
	chr_fix_060();
}
void extcl_cpu_wr_mem_060(UNUSED(BYTE nidx), UNUSED(WORD address), UNUSED(BYTE value)) {}
BYTE extcl_save_mapper_060(BYTE mode, BYTE slot, FILE *fp) {
	save_slot_ele(mode, slot, m060.index);
	return (EXIT_OK);
}

INLINE static void prg_fix_060(void) {
	memmap_auto_16k(0, MMCPU(0x8000), m060.index);
	memmap_auto_16k(0, MMCPU(0xC000), m060.index);
}
INLINE static void chr_fix_060(void) {
	memmap_auto_8k(0, MMPPU(0x0000), m060.index);
}
