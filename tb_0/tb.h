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

#ifndef _TB_H_
    #define _TB_H_

    #include <systemc>
    #include <SyscClk.h>

    using namespace std;
    using namespace sc_core;
    using namespace sc_dt;
    using namespace SyscClk;

    class tb : public sc_module
    {
        private:
            double freq_hz;

        public:
            SC_HAS_PROCESS(tb);
            tb(sc_module_name, double);
            ~tb(void);

            Clk<bool> * i_uut;

            sc_signal <bool> tb_clk;
    };
#endif
