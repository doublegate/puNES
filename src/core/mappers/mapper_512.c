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

#include <string.h>
#include "mappers.h"
#include "irqA12.h"
#include "save_slot.h"

void chr_swap_mmc3_512(WORD address, WORD value);
void wram_swap_mmc3_512(WORD address, WORD value);
void mirroring_fix_mmc3_512(void);

struct _m512 {
	BYTE reg;
} m512;

void map_init_512(void) {
	EXTCL_AFTER_MAPPER_INIT(MMC3);
	EXTCL_CPU_WR_MEM(512);
	EXTCL_SAVE_MAPPER(512);
	EXTCL_CPU_EVERY_CYCLE(MMC3);
	EXTCL_PPU_000_TO_34X(MMC3);
	EXTCL_PPU_000_TO_255(MMC3);
	EXTCL_PPU_256_TO_319(MMC3);
	EXTCL_PPU_320_TO_34X(MMC3);
	EXTCL_UPDATE_R2006(MMC3);
	mapper.internal_struct[0] = (BYTE *)&m512;
	mapper.internal_struct_size[0] = sizeof(m512);
	mapper.internal_struct[1] = (BYTE *)&mmc3;
	mapper.internal_struct_size[1] = sizeof(mmc3);

	if (info.reset >= HARD) {
		memset(&nes[0].irqA12, 0x00, sizeof(nes[0].irqA12));
	}

	memset(&m512, 0x00, sizeof(m512));

	init_MMC3(info.reset);
	MMC3_chr_swap = chr_swap_mmc3_512;
	MMC3_wram_swap = wram_swap_mmc3_512;
	MMC3_mirroring_fix = mirroring_fix_mmc3_512;

	info.mapper.extend_wr = TRUE;

	nes[0].irqA12.present = TRUE;
	nes[0].irqA12.delay = 1;
}
void extcl_cpu_wr_mem_512(BYTE nidx, WORD address, BYTE value) {
	if ((address >= 0x4000) && (address <= 0x4FFF)) {
		if (address & 0x100) {
			m512.reg = value & 0x03;
			MMC3_chr_fix();
		}
		return;
	}
	if (address >= 0x8000) {
		extcl_cpu_wr_mem_MMC3(nidx, address, value);
	}
}
BYTE extcl_save_mapper_512(BYTE mode, BYTE slot, FILE *fp) {
	save_slot_ele(mode, slot, m512.reg);
	return (extcl_save_mapper_MMC3(mode, slot, fp));
}

void chr_swap_mmc3_512(WORD address, WORD value) {
	if ((m512.reg & 2) && vram_size(0)) {
		memmap_vram_1k(0, MMPPU(address), (value & 0x03));
	} else {
		chr_swap_MMC3_base(address, value);
	}
}
void wram_swap_mmc3_512(WORD address, WORD value) {
	memmap_auto_8k(0, MMCPU(address), value);
}
void mirroring_fix_mmc3_512(void) {
	if ((m512.reg == 1) && vram_size(0)) {
		memmap_nmt_vram_4k(0, MMPPU(0x2000), 1);
		memmap_nmt_vram_4k(0, MMPPU(0x3000), 1);
	} else {
		mirroring_fix_MMC3_base();
	}
}
