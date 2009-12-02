/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou@yahoo.fr>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Lesser General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/

/**@file tcomp_nakinfo.h
 * @brief  RFC 4077 - A Negative Acknowledgement Mechanism for Signaling Compression (NACK)
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#ifndef TCOMP_NAKINFO_H
#define TCOMP_NAKINFO_H

#include "tinysigcomp_config.h"
#include "tcomp_buffer.h"
#include "tsk_sha1.h"
#include "tsk_object.h"

#include <stdint.h>

#define TCOMP_NACKINFO_CREATE()				tsk_object_new(tsk_nackinfo_def_t)
#define TCOMP_NACKINFO_SAFE_FREE(self)		tsk_object_unref(self), self = 0

/*
+---+---+---+---+---+---+---+---+
|         code_len = 0          |
+---+---+---+---+---+---+---+---+
| code_len = 0  |  version = 1  |
+---+---+---+---+---+---+---+---+
|          Reason Code          |
+---+---+---+---+---+---+---+---+
|  OPCODE of failed instruction |
+---+---+---+---+---+---+---+---+
|   PC of failed instruction    |
|                               |
+---+---+---+---+---+---+---+---+
|                               |
: SHA-1 Hash of failed message  :
|                               |
+---+---+---+---+---+---+---+---+
|                               |
:         Error Details         :
|                               |
+---+---+---+---+---+---+---+---+
*/
/**@typedef tcomp_nackinfo_t
* NACK info as per rfc 4077 subclause 3.1.
* You MUST use @ref TCOMP_NACKINFO_CREATE to create new nackinfo object.
*/
typedef struct tcomp_nackinfo_s
{
	TSK_DECLARE_OBJECT;

	uint8_t version; 	/**< Gives the version of the NACK mechanism being employed. */
	uint8_t reasonCode; /**< The Reason Code is a one-byte value that indicates the nature of the decompression failure. */
	uint8_t opcode; /**< The "OPCODE of failed instruction" is a one-byte field that includes the opcode to which the PC was pointing when the failure occurred */
	uint16_t pc; /**< "PC of failed instruction" is a two-byte field containing the value of the program counter when failure occurred (i.e., the memory address of the failed UDVM instruction) */
	uint8_t sha1[TSK_SHA1HashSize]; /**<"SHA-1 Hash of failed message" contains the full 20-byte SHA-1 hash of the SigComp message that could not be decompressed */
	tcomp_buffer_handle_t *details; /**< "Error Details" provides additional information that might be useful in correcting the problem that caused decompression failure.*/
}
tcomp_nackinfo_t;

TINYSIGCOMP_API const void *tcomp_nackinfo_def_t;

#endif /* TCOMP_NAKINFO_H */