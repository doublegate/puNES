/*
 *  Copyright (C) 2010-2021 Fabio Cavallo (aka FHorse)
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

#ifndef OS_JSTICK_H_
#define OS_JSTICK_H_

#if defined (HAVE_USB_H)
#include <usb.h>
#endif
#if defined (__DragonFly__)
#include <bus/usb/usb.h>
#include <bus/usb/usbhid.h>
#else
#include <dev/usb/usb.h>
#include <dev/usb/usbhid.h>
#endif

#if defined (HAVE_USBHID_H)
#include <usbhid.h>
#elif defined (HAVE_LIBUSB_H)
#include <libusb.h>
#elif defined (HAVE_LIBUSBHID_H)
#include <libusbhid.h>
#endif

#if defined (__FreeBSD__) || defined (__FreeBSD_kernel__)
#if !defined (__DragonFly__)
#include <osreldate.h>
#endif
#include <dev/usb/usb_ioctl.h>
#include <sys/joystick.h>
#endif

#if defined (USBHID_UCR_DATA)
#define REP_BUF_DATA(rep) (rep.buf->ucr_data)
#elif defined (__FreeBSD__)
#define REP_BUF_DATA(rep) (rep.buf)
#else
#define REP_BUF_DATA(rep) (rep.buf->data)
#endif

#if defined (__OpenBSD__)
#define HUG_D_PAD_UP        0x90
#define HUG_D_PAD_DOWN      0x91
#define HUG_D_PAD_RIGHT     0x92
#define HUG_D_PAD_LEFT      0x93
#endif

#define ABS_X               HUG_X
#define ABS_Y               HUG_Y
#define ABS_Z               HUG_Z
#define ABS_RX              HUG_RX
#define ABS_RY              HUG_RY
#define ABS_RZ              HUG_RZ
#define ABS_THROTTLE        HUG_SLIDER
#define ABS_WHEEL           HUG_WHEEL
#define ABS_HAT0X           HUG_HAT_SWITCH
#define ABS_HAT0Y           HUG_HAT_SWITCH + 1
#define ABS_HAT1X           HUG_HAT_SWITCH + 2
#define ABS_HAT1Y           HUG_HAT_SWITCH + 3
#define ABS_HAT2X           0xFFFFFF
#define ABS_HAT2Y           0xFFFFFF
#define ABS_HAT3X           0xFFFFFF
#define ABS_HAT3Y           0xFFFFFF
#define ABS_RUDDER          HUG_DIAL
#define ABS_GAS             0xFFFFFF
#define ABS_BRAKE           0xFFFFFF
#define ABS_PRESSURE        0xFFFFFF
#define ABS_DISTANCE        0xFFFFFF
#define ABS_TILT_X          0xFFFFFF
#define ABS_TILT_Y          0xFFFFFF
#define ABS_TOOL_WIDTH      0xFFFFFF

#define BTN_A               1
#define BTN_B               2
#define BTN_X               3
#define BTN_Y               4
#define BTN_TL              5
#define BTN_TR              6
#define BTN_SELECT          7
#define BTN_START           8
#define BTN_MODE            9
#define BTN_THUMBL          10
#define BTN_THUMBR          11
#define BTN_DPAD_UP         HUG_D_PAD_UP
#define BTN_DPAD_DOWN       HUG_D_PAD_DOWN
#define BTN_DPAD_LEFT       HUG_D_PAD_LEFT
#define BTN_DPAD_RIGHT      HUG_D_PAD_RIGHT
#define BTN_TL2             12
#define BTN_TR2             13
#define BTN_C               14
#define BTN_Z               15
#define BTN_TRIGGER         16
#define BTN_THUMB           17
#define BTN_THUMB2          18
#define BTN_TOP             19
#define BTN_TOP2            20
#define BTN_PINKIE          21
#define BTN_BASE            22
#define BTN_BASE2           23
#define BTN_BASE3           24
#define BTN_BASE4           25
#define BTN_BASE5           26
#define BTN_BASE6           27
#define BTN_DEAD            28
#define BTN_TRIGGER_HAPPY   29
#define BTN_TRIGGER_HAPPY1  30
#define BTN_TRIGGER_HAPPY2  31
#define BTN_TRIGGER_HAPPY3  32
#define BTN_TRIGGER_HAPPY4  33
#define BTN_TRIGGER_HAPPY5  34
#define BTN_TRIGGER_HAPPY6  35
#define BTN_TRIGGER_HAPPY7  36
#define BTN_TRIGGER_HAPPY8  37
#define BTN_TRIGGER_HAPPY9  38
#define BTN_TRIGGER_HAPPY10 39
#define BTN_TRIGGER_HAPPY11 40
#define BTN_TRIGGER_HAPPY12 41
#define BTN_TRIGGER_HAPPY13 42
#define BTN_TRIGGER_HAPPY14 43
#define BTN_TRIGGER_HAPPY15 44
#define BTN_TRIGGER_HAPPY16 45
#define BTN_TRIGGER_HAPPY17 46
#define BTN_TRIGGER_HAPPY18 47
#define BTN_TRIGGER_HAPPY19 48
#define BTN_TRIGGER_HAPPY20 49
#define BTN_TRIGGER_HAPPY21 50
#define BTN_TRIGGER_HAPPY22 51
#define BTN_TRIGGER_HAPPY23 52
#define BTN_TRIGGER_HAPPY24 53
#define BTN_TRIGGER_HAPPY25 54
#define BTN_TRIGGER_HAPPY26 55
#define BTN_TRIGGER_HAPPY27 56
#define BTN_TRIGGER_HAPPY28 57
#define BTN_TRIGGER_HAPPY29 58
#define BTN_TRIGGER_HAPPY30 59
#define BTN_TRIGGER_HAPPY31 60
#define BTN_TRIGGER_HAPPY32 61
#define BTN_TRIGGER_HAPPY33 62
#define BTN_TRIGGER_HAPPY34 63
#define BTN_TRIGGER_HAPPY35 64
#define BTN_TRIGGER_HAPPY36 65
#define BTN_TRIGGER_HAPPY37 66
#define BTN_TRIGGER_HAPPY38 67
#define BTN_TRIGGER_HAPPY39 68
#define BTN_TRIGGER_HAPPY40 69

#endif /* OS_JSTICK_H_ */
