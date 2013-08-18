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

#ifndef _SYSCCLK_H_
    #define _SYSCCLK_H_

    #include <systemc>
    #include <string>
    #include <iostream>
    #include <sstream>
    #include <SyscMsg.h>

    namespace SyscClk
    {
        using namespace std;
        using namespace sc_core;
        using namespace sc_dt;
        using namespace SyscMsg;
        using namespace SyscMsg::Chars;

        template <typename T_out>
        class Clk : public sc_module
        {
            private:
                unique_ptr<Msg>   msg;
                sc_clock        * clk_src;
                double            freq_hz;
                double            duty_cycle;
                double            start_time;
                sc_time_unit      start_time_unit;
                bool              posedge_first;
                string            clk_src_nm;

            public:
                SC_HAS_PROCESS(Clk);
                Clk(sc_module_name, double, double, double, sc_time_unit, bool);
                ~Clk(void);

                void run(void);

                sc_out < T_out > clk_o;
        };

        template <typename T_out>
        Clk<T_out>::Clk
        (
            sc_module_name arg_nm,
            double         arg_hz,
            double         arg_duty,
            double         arg_start,
            sc_time_unit   arg_unit,
            bool           arg_posedge
        )
        : sc_module ( arg_nm )
        {
            this->msg              = unique_ptr<Msg>(new Msg(this->name()));
            this->freq_hz          = arg_hz;
            this->duty_cycle       = arg_duty;
            this->start_time       = arg_start;
            this->start_time_unit  = arg_unit;
            this->posedge_first    = arg_posedge;
            this->clk_src_nm       = string(arg_nm) + string("_src");

            this->clk_src = new sc_clock
            (
                this->clk_src_nm.c_str(),
                (1.0 / this->freq_hz), SC_SEC,
                this->duty_cycle,
                this->start_time, this->start_time_unit,
                this->posedge_first
            );

            SC_THREAD(run);
        }

        template <typename T_out>
        Clk<T_out>::~Clk(void)
        {
            delete this->clk_src;
        }

        template <typename T_out>
        void Clk<T_out>::run(void)
        {
            ostringstream os;

            os << "Clk::run() starting with frequency" << SP << this->freq_hz << SP << "hz";
            this->msg->report_inf(os.str());

            while (true) {
                wait(this->clk_src->value_changed_event());

                if (this->clk_src->posedge())
                {
                    this->clk_o.write(T_out(1));
                }
                else if (this->clk_src->negedge())
                {
                    this->clk_o.write(T_out(0));
                }
            }
        }
    }
#endif
