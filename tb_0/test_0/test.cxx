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

test::test(sc_module_name nm, double parm_hz) : tb(nm, parm_hz)
{
    this->tf = sc_create_vcd_trace_file("test");

    sc_trace(this->tf, this->tb_clk, "tb_clk");

    SC_THREAD(test_timeout);
    SC_THREAD(test_execute);
    // set_stack_size(100000);
    // OSCI 5.2.16, sc_core::sc_module::set_stack_size(size_t);
}

test::~test(void) {}

void
test::test_execute(void)
{
    wait(1, SC_US);
    sc_stop();
}
void

test::test_timeout(void)
{
    wait(20, SC_MS);
    SC_REPORT_FATAL("test::test_timeout", "Simulation has run longer than 20 ms. Stopping Simulation.");
}
