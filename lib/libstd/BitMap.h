/*
 * Copyright (C) 2009 Niek Linnenbank
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __BITMAP_H
#define __BITMAP_H

#include "Macros.h"
#include "Assert.h"
#include "Types.h"

/**
 * Class capable of (un)marking bits inside a binary bitmap.
 */
class BitMap
{
    public:

        /**
         * Class constructor.
         * @param newMap Pointer to the bitmap to manage.
         * @param cnt Number of bits.
         */
        BitMap(u8 *newMap = ZERO, Size cnt = ZERO);

        /**
         * Mark a given bit used.
         * @param bit Bit number to mark used.
         */
        void mark(Size bit);

        /**
         * Mark a range of bits inside the map.
         * @param from Bit to start with.
         * @param to End bit (inclusive).
         */
        void markRange(Size from, Size to);

        /**
         * Marks the next free bit(s) used.
         * @param count Number of consequetive bits required.
         * @param offset Start bit number to start searching at inside the bitmap.
         * @return Start bit number on success and -1 otherwise.
         */
        Error markNext(Size count = 1, Size offset = 0);

        /**
         * Unmarks the given bit.
         * @param bit Bit number to unmark.
         */
        void unmark(Size bit);

        /**
         * Verify if a given bit is marked.
         * @param bit Bit number to check.
         * @return True if marked, false otherwise.
         */
        bool isMarked(Size bit) const;

        /**
         * Retrieve a pointer to the internal bitmap.
         * @return Internal bitmap.
         */
        u8 * getMap() const;

        /**
         * Use the given pointer as the bitmap buffer.
         * @param newMap New bitmap pointer.
         * @param newCount New number of bits. ZERO to keep the old value.
         */
        void setMap(u8 *newMap, Size newCount = ZERO);

        /**
         * Clears the given map.
         */
        void clear();

        /**
         * Get the number of bits used in the map.
         * @return Number of used bits.
         */
        Size getUsed() const;

        /**
         * Get the number of bits available in the map.
         * @return Number of free bits.
         */
        Size getFree() const;

    private:

        /** Total number of bits in the map. */
        Size m_size;

        /** Unmarked bits remaining. */
        Size m_free;

        /** Bitmap which represents free and used blocks. */
        u8 *m_map;
};

#endif /* __BITMAP_H */
