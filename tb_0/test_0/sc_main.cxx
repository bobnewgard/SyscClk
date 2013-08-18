/*
 * Copyright 2013 Robert Newgard
 *
 * This file is part of SyscClk.
 *
 * SyscClk is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * SyscClk is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with SyscClk.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "test.h"

int sc_main(int argc, char **argv)
{
    test test_0("test_0", 156.250e6);
    sc_start();
    return 0;
}
