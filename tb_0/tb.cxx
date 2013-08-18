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

#include "tb.h"

tb::tb(sc_module_name parm_nm, double parm_hz)
{
    string uut_nm = string(parm_nm) + string("_clk");

    this->freq_hz = parm_hz;
    this->i_uut   = new Clk<bool>(uut_nm.c_str(), this->freq_hz, 0.5, 1.0, SC_NS, true);
    this->tb_clk  = bool(1);

    this->i_uut->clk_o ( tb_clk );
}

tb::~tb(void)
{
    delete this->i_uut;
}
